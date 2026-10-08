#pragma once

namespace cmn::sys::platform
{
    #if defined(__GNUC__) && !defined(__clang__)
        #define CMN_SYS_COMPILER_GCC 1
    #else
        #define CMN_SYS_COMPILER_GCC 0
    #endif

    #if defined(__clang__)
        #define CMN_SYS_COMPILER_CLANG 1
    #else
        #define CMN_SYS_COMPILER_CLANG 0
    #endif

    #if defined(_MSC_VER)
        #define CMN_SYS_COMPILER_MSVC 1
    #else
        #define CMN_SYS_COMPILER_MSVC 0
    #endif
}