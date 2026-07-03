#include <clang-c/Index.h>
#include <iostream>
#include <string>

static CXChildVisitResult visitor(CXCursor c, CXCursor, CXClientData)
{
    if (clang_getCursorKind(c) == CXCursor_FunctionDecl)
    {
        CXString name = clang_getCursorSpelling(c);
        const char* str = clang_getCString(name);

        if (str && str[0]=='N' && str[1]=='t')
            std::cout << str << "\n";

        clang_disposeString(name);
    }

    return CXChildVisit_Recurse;
}

int main()
{
    CXIndex index = clang_createIndex(0, 0);

    const char* file = "script/bin/nt/phnt.h";

    const char* args[] = {
        "--target=x86_64-w64-windows-gnu",
        "-D_AMD64_",
        "-D_WIN64"
    };

    CXTranslationUnit tu =
        clang_parseTranslationUnit(
            index,
            file,
            args, 3,
            nullptr, 0,
            CXTranslationUnit_None);

    if (!tu)
        return 1;

    CXCursor root = clang_getTranslationUnitCursor(tu);

    clang_visitChildren(root, visitor, nullptr);

    clang_disposeTranslationUnit(tu);
    clang_disposeIndex(index);
}