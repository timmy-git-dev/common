#pragma once

namespace cmn::system::platform
{
    #if defined(__i386__) || defined(_M_IX86)
        #define CMN_SYSTEM_ARCH_X86 1
    #else
        #define CMN_SYSTEM_ARCH_X86 0
    #endif

    #if defined(__x86_64__) || defined(_M_X64)
        #define CMN_SYSTEM_ARCH_X64 1
    #else
        #define CMN_SYSTEM_ARCH_X64 0
    #endif

    #if defined(__arm__) || defined(_M_ARM)
        #define CMN_SYSTEM_ARCH_ARM32 1
    #else
        #define CMN_SYSTEM_ARCH_ARM32 0
    #endif

    #if defined(__aarch64__) || defined(_M_ARM64)
        #define CMN_SYSTEM_ARCH_ARM64 1
    #else
        #define CMN_SYSTEM_ARCH_ARM64 0
    #endif

    #if defined(__riscv)
        #define CMN_SYSTEM_ARCH_RISCV 1
    #else
        #define CMN_SYSTEM_ARCH_RISCV 0
    #endif
}