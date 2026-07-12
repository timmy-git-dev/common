#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <clang-c/CXString.h>
#include <clang-c/Index.h>
#include <unordered_set>

namespace fs = std::filesystem;

constexpr const char* PATH_REPO     = "script/bin/xnu/repo";
constexpr const char* PATH_BSD      = "script/bin/xnu/repo/bsd";
constexpr const char* PATH_CLANGD   = "script/bin/xnu/.clangd";
constexpr const char* PATH_INCLUDES = "script/bin/xnu/Includes.cpp";
constexpr const char* PATH_SYSCALLS = "script/bin/xnu/repo/bsd/kern/syscalls.master";
constexpr const char* PATH_FUNCS    = "inc/system/xnu/Call.hpp";
constexpr const char* PATH_IDS      = "inc/system/xnu/ID.hpp";
constexpr const char* PATH_TYPES    = "inc/system/xnu/Type.hpp";

static std::unordered_set<std::string> typeAliases;
static std::unordered_set<std::string> definedTypes;
static std::string                     currentAlias;

static std::ofstream types;

static std::string strip_line(std::string _line)
{
    static constexpr const char* QUALIFIERS[] = {
        "*"            ,
        "&"            ,
        "const "       ,
        "volatile "    ,
        "restrict "    ,
        "struct "      ,
        "__restrict "  ,
        "__restrict__ ",
    };

    if (_line[0] == '#')
    {
        return {};
    }

    std::size_t _pos;
    while ((_pos = _line.find('\t')) != std::string::npos)
    {
        _line[_pos] = ' ';
    }

    for (const char *_qualifier : QUALIFIERS)
    {
        while ((_pos = _line.find(_qualifier)) != std::string::npos)
        {
            _line.replace(_pos, std::strlen(_qualifier), " ");
        }
    }

    while ((_pos = _line.find(", ")) != std::string::npos)
    {
        _line.erase(_pos + 1, 1);
    }

    while ((_pos = _line.find("  ")) != std::string::npos)
    {
        _line.erase(_pos, 1);
    }

    size_t _start = _line.find_first_not_of(" \t");
    size_t _end   = _line.find_last_not_of (" \t");

    if (_start == std::string::npos)
    {
        return {};
    }

    return _line.substr(_start, _end - _start + 1);
}

static bool define_type(CXType _type, CXCursor _baseCursor)
{
                _type   = clang_getUnqualifiedType(_type);
    CXCursor    _cursor = clang_getTypeDeclaration(_type);
    CXString    _name   = clang_getTypeSpelling   (_type);
    std::string _str    = clang_getCString        (_name);

    if (definedTypes.contains(_str))
    {
        return true;
    }

    if (_type.kind < CXType_FirstBuiltin || _type.kind > CXType_LastBuiltin)
    {
        switch (_type.kind)
        {
            case CXType_Typedef:
            {
                CXType      _underlyingType = clang_getTypedefDeclUnderlyingType(_cursor        );
                CXString    _underlyingName = clang_getTypeSpelling             (_underlyingType);
                const char* _underlyingStr  = clang_getCString                  (_underlyingName);
                if (define_type(_underlyingType, _baseCursor))
                {
                    definedTypes.insert(           _str );
                    definedTypes.insert(strip_line(_str));
                    types << "using " << _str << " = " << _underlyingStr << ";\n";
                }
                clang_disposeString(_underlyingName);
                break;
            }
            case CXType_Pointer:
            {
                CXType _underlyingType = clang_getPointeeType(_type);
                return define_type(_underlyingType, _baseCursor);
                break;
            }
            case CXType_IncompleteArray:
            {
                CXType _underlyingType = clang_getArrayElementType(_type);
                return define_type(_underlyingType, _baseCursor);
                break;
            }
            case CXType_ConstantArray:
            {
                CXType _underlyingType = clang_getArrayElementType(_type);
                return define_type(_underlyingType, _baseCursor);
            }
            case CXType_Record:
            {
                definedTypes.insert(           _str );
                definedTypes.insert(strip_line(_str));
                types << _str << ";\n";
                break;
            }
            case CXType_Enum:
            {
                definedTypes.insert(           _str );
                definedTypes.insert(strip_line(_str));
                types << "enum " << _str << " { };\n";
                break;
            }
            case CXType_FunctionProto:
            {
                CXType      _baseType      = clang_getCursorType                       (_baseCursor   ); // Ensure return value + params are defined & ignore adding typedef/ptr if FunctionProto exists.
                CXString    _baseName      = clang_getTypeSpelling                     (_baseType     );
                const char* _baseStr       = clang_getCString                          (_baseName     );
                CXType      _baseValueType = clang_getCanonicalType(clang_getCursorType(_baseCursor   ));
                CXString    _baseValueName = clang_getTypeSpelling                     (_baseValueType);
                const char* _baseValueStr  = clang_getCString                          (_baseValueName);

                int _argCount = clang_getNumArgTypes(_type);
                for (int _i = 0; _i < _argCount; _i++)
                {
                    CXType      _paramType   = clang_getArgType        (_type, _i);
                    CXCursor    _paramCursor = clang_getTypeDeclaration(_type             );
                    define_type(_paramType, _paramCursor);
                }

                definedTypes.insert(           _baseStr );
                definedTypes.insert(strip_line(_baseStr));
                types << "using " << _baseStr << " = " << _baseValueStr << ";\n";

                clang_disposeString(_baseName     );
                clang_disposeString(_baseValueName);
                return false;
            }
            case CXType_Unexposed:
            {
                // CXType      _underlyingType = clang_getTypedefDeclUnderlyingType(_cursor        );
                // CXString    _underlyingName = clang_getTypeSpelling             (_underlyingType);
                // const char* _underlyingStr  = clang_getCString                  (_underlyingName);
                // std::cout << "? -> " << _str << ": " << _underlyingStr << "\n";
                return true;
            }

            default:
            {
                std::cout << "Unsupported type [" << _type.kind << "]: " << _str << "\n";
                return false;
            }
        }
    }

    clang_disposeString(_name);
    return true;
}

static CXChildVisitResult type_visitor(CXCursor _cursor, CXCursor, CXClientData)
{
    CXString    _aliasName = clang_getCursorSpelling(_cursor   );
    std::string _aliasStr  = clang_getCString       (_aliasName);
    clang_disposeString(_aliasName);

    if (currentAlias == strip_line(_aliasStr))
    {
        CXType _type = clang_getCursorType(_cursor);
        define_type(_type, _cursor);
        return CXChildVisit_Break;
    }

    return CXChildVisit_Recurse;
}

void parse_header(std::string _alias, std::string _path)
{
    currentAlias = _alias;
    CXIndex     _index  = clang_createIndex(0, 0);
    const char* _args[] =
    {
        "--target=x86_64-linux-gnu",
        "-D__arm64__"              ,
        "-DPRIVATE"                ,
        "-DKERNEL"                 ,
        "-DBSD_KERNEL_PRIVATE"     ,
        "-D__APPLE_API_PRIVATE"    ,
        "-Iscript/bin/xnu/repo/bsd",
        "-Iscript/bin/xnu/repo"    ,
    };

    CXTranslationUnit _translationUnit = clang_parseTranslationUnit
    (
        _index,
        _path.c_str(),
        _args, 5,
        nullptr, 0,
        CXTranslationUnit_None
    );

    if (!_translationUnit)
    {
        std::cout << "Failed to parse file: " << _path << "\n";
    }

    CXCursor _rootCursor = clang_getTranslationUnitCursor(_translationUnit);

    clang_visitChildren(_rootCursor, type_visitor, nullptr);

    clang_disposeTranslationUnit(_translationUnit);
    clang_disposeIndex(_index);
}

std::string find_header(const std::string& _alias)
{
    for (const auto& _entry : std::filesystem::recursive_directory_iterator(PATH_BSD))
    {
        if (!_entry.is_regular_file() || _entry.path().extension() != ".h")
            continue;

        std::ifstream _file(_entry.path());

        if (!_file)
            continue;


        std::string _line;
        while (std::getline(_file, _line))
        {
            if (_line.contains(_alias))
            {
                parse_header(_alias, _entry.path().string());
                if (definedTypes.contains(_alias))
                {
                    return _entry.path().string();
                }

                break;
            }
        }
    }

    for (const auto& _entry : std::filesystem::recursive_directory_iterator(PATH_REPO))
    {
        if (!_entry.is_regular_file() || _entry.path().extension() != ".h")
            continue;

        std::ifstream _file(_entry.path());

        if (!_file)
            continue;


        std::string _line;
        while (std::getline(_file, _line))
        {
            if (_line.contains(_alias))
            {
                parse_header(_alias, _entry.path().string());
                if (definedTypes.contains(_alias))
                {
                    return _entry.path().string();
                }

                break;
            }
        }
    }

    return {};
}

void parse_types()
{
    fs::create_directories(fs::path(PATH_TYPES).parent_path());
    types = std::ofstream(PATH_TYPES);
    types << "#pragma once\n\n";

    for (std::string _alias : typeAliases)
    {
        std::string _path = find_header(_alias);
        if (_path.empty())
        {
            std::cout << _alias << "?\n";
        }
    }

    // std::cout << "Aliases:\n";
    // for (std::string _alias : typeAliases)
    // {
    //     // if (!definedTypes.contains(_alias))
    //         std::cout << _alias << "\n";
    // }
    // std::cout << "Undefined:\n";
    // for (std::string _alias : definedTypes)
    // {
    //     if (!definedTypes.contains(_alias))
    //         std::cout << _alias << "\n";
    // }

    types.close();
}

int main()
{
    fs::create_directories(fs::path(PATH_CLANGD  ).parent_path());
    fs::create_directories(fs::path(PATH_INCLUDES).parent_path());
    fs::create_directories(fs::path(PATH_FUNCS   ).parent_path());
    fs::create_directories(fs::path(PATH_IDS     ).parent_path());

    std::ofstream clangd  (PATH_CLANGD  );
    std::ofstream includes(PATH_INCLUDES);
    std::ifstream syscalls(PATH_SYSCALLS);
    std::ofstream funcs   (PATH_FUNCS   );
    std::ofstream ids     (PATH_IDS     );

    clangd << "CompileFlags:\n"
              "Add:\n"
              "    - -std=c++23\n"
              "    - -lclang\n"
              "    - -Iscript/bin/xnu/repo/bsd\n"
              "Remove:\n"
              "    - -ffreestanding\n"
              "    - -fno-exceptions\n"
              "    - -fno-rtti\n"
              "    - -fno-stack-protector\n"
              "    - -fno-asynchronous-unwind-tables\n"
              "    - -fno-unwind-tables\n"
              "    - -nostdlib\n"
              "    - -nostartfiles\n"
              "    - -nodefaultlibs\n"
              "    - -static\n"
              "    - -no-pie\n";

    funcs << "#include \"system/xnu/Func.hpp\"\n"
             "#include \"system/xnu/ID.hpp\"\n"
             "#include \"system/xnu/Type.hpp\"\n"
             "\n"
             "namespace cmn::system::xnu\n"
             "{\n";

    ids << "namespace cmn::system::xnu\n"
           "{\n";

    bool _inElse = false;

    std::string _line;
    while (std::getline(syscalls, _line))
    {
        size_t _start = _line.find_first_not_of(" \t\r\n");
        if (_start == std::string::npos)
        {
            continue;
        }

        size_t _end = _line.find_last_not_of(" \t\r\n");
        _line = _line.substr(_start, _end - _start + 1);

        if (_line.empty() || _line.starts_with(';'))
            continue;

        if (_line.starts_with("#else"))
        {
            _inElse = true;
            continue;
        }
        else if (_line.starts_with("#endif"))
        {
            _inElse = false;
            continue;
        }
        else if (_line.starts_with("#include"))
        {
            includes << _line << '\n';
            continue;
        }
        else if (_line.starts_with('#') || _inElse)
        {
            continue;
        }

        size_t _pos;
        while ((_pos = _line.find(", ")) != std::string::npos) { _line.erase(_pos + 1, 1);     }
        while ((_pos = _line.find(" (")) != std::string::npos) { _line.erase(_pos    , 1);     }
        while ((_pos = _line.find("\t")) != std::string::npos) { _line[_pos] = ' ';            }


        _start = _line.find('{');
        _end   = _line.find('}', _start);
        std::string _func = _line.substr(_start + 1, _end - _start - 1);

        _start = _func.find_first_not_of(" \t");
        _end = _func.find_last_not_of(" \t");
        _func = _func.substr(_start, _end - _start + 1);

        constexpr const char stub[] = " NO_SYSCALL_STUB";
        if (auto pos = _func.find(stub); pos != std::string::npos)
        {
            _func.erase(pos, sizeof(stub) - 1);
        }

        if (_func.find("nosys(") != std::string::npos)
        {
            continue;
        }

        std::string _id = _line.substr(0, _line.find_first_of(" \t\r\n"));

        _line = _func;
        _line = strip_line(_line);

        size_t _mid;
        _end   = _line.find ('('      );
        _start = _line.rfind(' ', _end);
        std::string _name = _line.substr(_start + 1, _end - _start - 1);

        _end = _start;
        _start = 0;
        std::string _returnType = _line.substr(0, _end);
        typeAliases.insert(strip_line(_returnType));

        funcs << "    " << _func.erase(_func.length() - 1) << (_returnType == "void" ? " {syscall(" : " {return syscall(");

        std::string _upper = _name;
        std::transform(_upper.begin(), _upper.end(), _upper.begin(), [](unsigned char _char)
        {
            return static_cast<char>(std::toupper(_char));
        });

        funcs << _upper;

        _start = _line.find('(') + 1;
        while ((_end = _line.find(',', _start)) != std::string::npos)
        {
            _mid = _line.rfind(' ', _end);

            std::string _paramType = _line.substr(_start  , _mid - _start  );
            std::string _paramName = _line.substr(_mid + 1, _end - _mid - 1);

            funcs << ",(long)" << _paramName;
            typeAliases.insert(strip_line(_paramType));

            _start = _end + 1;
        }

        _end = _line.find (')', _start);
        _mid = _line.rfind(' ', _end  );

        if (_mid > _start)
        {
            std::string _paramType = _line.substr(_start  , _mid - _start  );
            std::string _paramName = _line.substr(_mid + 1, _end - _mid - 1);

            funcs << ",(long)" << _paramName;
            typeAliases.insert(strip_line(_paramType));
        }

        funcs << ");}\n";
        ids << "    #define " << _upper << ' ' << _id << '\n';
    }

    funcs << "}";
    ids   << "}";

    syscalls.close();
    funcs   .close();
    ids     .close();
    includes.close();
    clangd  .close();

    parse_types();
}