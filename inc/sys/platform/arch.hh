#pragma once

namespace cmn::sys::platform
{
    #if defined(__x86_64__) || defined(_M_X64)
        #define CMN_SYS_ARCH_X64 1
    #else
        #define CMN_SYS_ARCH_X64 0
    #endif

    #if defined(__aarch64__) || defined(_M_ARM64)
        #define CMN_SYS_ARCH_ARM64 1
    #else
        #define CMN_SYS_ARCH_ARM64 0
    #endif
}