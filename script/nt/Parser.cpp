#include <clang-c/CXString.h>
#include <clang-c/Index.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <regex>
#include <string>

static std::ofstream outputTypes;
static std::ofstream outputFuncs;

static std::vector<std::string> definedTypes;

static bool define_type(CXType _type, CXCursor _baseCursor)
{
                _type   = clang_getUnqualifiedType(_type);
    CXCursor    _cursor = clang_getTypeDeclaration(_type);
    CXString    _name   = clang_getTypeSpelling   (_type);
    const char* _str    = clang_getCString        (_name);

    if (std::find(definedTypes.begin(), definedTypes.end(), _str) == definedTypes.end())
    {
        definedTypes.push_back(_str);

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
                        outputTypes << "using " << _str << " = " << _underlyingStr << ";\n";
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
                    outputTypes << _str << ";\n";
                    break;
                }
                case CXType_Enum:
                {
                    outputTypes << _str << " { };\n";
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

                    outputTypes << "using " << _baseStr << " = " << _baseValueStr << ";\n";

                    clang_disposeString(_baseName     );
                    clang_disposeString(_baseValueName);
                    return false;
                }

                default:
                {
                    std::cout << "Unsupported type [" << _type.kind << "]: " << _str << "\n";
                    return false;
                }
            }
        }
    }

    clang_disposeString(_name);
    return true;
}

static void emit_param(std::ostream& out, CXType type, const std::string& name)
{
    type = clang_getUnqualifiedType(type);

    switch (type.kind)
    {
        case CXType_Pointer:
        {
            emit_param(out,
                clang_getPointeeType(type),
                "*" + name);
            break;
        }

        case CXType_ConstantArray:
        {
            emit_param(out,
                clang_getArrayElementType(type),
                name + "[" + std::to_string(clang_getArraySize(type)) + "]");
            break;
        }

        case CXType_IncompleteArray:
        {
            emit_param(out,
                clang_getArrayElementType(type),
                name + "[]");
            break;
        }

        case CXType_FunctionProto:
        {
            std::string decl = "(" + name + ")(";

            int count = clang_getNumArgTypes(type);

            for (int i = 0; i < count; ++i)
            {
                if (i)
                    decl += ", ";

                CXString s = clang_getTypeSpelling(clang_getArgType(type, i));
                decl += clang_getCString(s);
                clang_disposeString(s);
            }

            decl += ")";

            emit_param(out,
                clang_getResultType(type),
                decl);
            break;
        }

        default:
        {
            CXString s = clang_getTypeSpelling(type);

            out << clang_getCString(s);

            if (!name.empty())
                out << " " << name;

            clang_disposeString(s);
            break;
        }
    }
}

static std::vector<std::string> definedFuncs;

static CXChildVisitResult visitor(CXCursor _funcCursor, CXCursor, CXClientData)
{
    if (clang_getCursorKind(_funcCursor) != CXCursor_FunctionDecl)
        return CXChildVisit_Recurse;

    static const std::regex FUNC_PATTERN(R"(Nt.*)");

    CXString    _funcName = clang_getCursorSpelling(_funcCursor);
    const char* _funcStr  = clang_getCString       (_funcName);
    if (std::regex_match(_funcStr, FUNC_PATTERN) && std::find(definedFuncs.begin(), definedFuncs.end(), _funcStr) == definedFuncs.end())
    {
        definedFuncs.push_back(_funcStr);

        CXType      _returnType = clang_getCursorResultType(_funcCursor);
        CXString    _returnName = clang_getTypeSpelling(_returnType);
        const char* _returnStr  = clang_getCString(_returnName);

        define_type(_returnType, _funcCursor);
        outputFuncs << "    " << _returnStr << " " << _funcStr << "(";

        int _argCount = clang_Cursor_getNumArguments(_funcCursor);
        for (int _i = 0; _i < _argCount; ++_i)
        {
            CXCursor    _paramCursor = clang_Cursor_getArgument(_funcCursor, _i);
            CXType      _paramType   = clang_getCursorType     (_paramCursor   );
            CXString    _paramName   = clang_getCursorSpelling (_paramCursor   );
            const char* _paramStr    = clang_getCString        (_paramName     );

            define_type(_paramType, _paramCursor);
            emit_param(outputFuncs, _paramType, _paramStr);

            if (_i < _argCount - 1)
            {
                outputFuncs << ", ";
            }
        }


        outputFuncs << ");";
        outputFuncs << "\n";

        clang_disposeString(_returnName);
    }

    clang_disposeString(_funcName);
    return CXChildVisit_Recurse;
}


int main()
{
    CXIndex     _index  = clang_createIndex(0, 0);
    const char* _file   = "script/nt/Includes.cpp";
    const char* _args[] =
    {
        "--target=x86_64-w64-windows-gnu",
        "-I/home/timmy/code/test/phnt"
    };

    CXTranslationUnit _translationUnit = clang_parseTranslationUnit
    (
        _index,
        _file,
        _args, 2,
        nullptr, 0,
        CXTranslationUnit_None
    );

    if (!_translationUnit)
    {
        outputTypes << "Failed to parse file.";
        return 1;
    }

    CXCursor _rootCursor = clang_getTranslationUnitCursor(_translationUnit);

    outputTypes = std::ofstream("inc/system/nt/Type.hpp");
    outputFuncs = std::ofstream("inc/system/nt/Func.hpp");

    outputTypes << "#pragma once\n\n";
    outputFuncs << "#pragma once\n#include \"Type.hpp\"\n\nextern \"C\"\n{\n";

    clang_visitChildren(_rootCursor, visitor, nullptr);

    outputFuncs << "}";

    clang_disposeTranslationUnit(_translationUnit);
    clang_disposeIndex(_index);
}