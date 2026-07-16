#pragma once
#include "system/platform/Arch.hpp"

namespace cmn::system::syscall
{
    #if CMN_SYSTEM_ARCH_ARM64
    inline long syscall(long _id, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0, long _arg5 = 0)
    {
        register long x8 __asm__("x8") = _id;
        register long x0 __asm__("x0") = _arg0;
        register long x1 __asm__("x1") = _arg1;
        register long x2 __asm__("x2") = _arg2;
        register long x3 __asm__("x3") = _arg3;
        register long x4 __asm__("x4") = _arg4;
        register long x5 __asm__("x5") = _arg5;

        asm volatile
        (
            "svc #0"
            : "+r"(x0)
            :  "r"(x8),
               "r"(x1),
               "r"(x2),
               "r"(x3),
               "r"(x4),
               "r"(x5)
            : "memory"
        );

        return x0;
    }
    #elif CMN_SYSTEM_ARCH_X64
    inline long syscall(long _id, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0, long _arg5 = 0)
    {
        long _returnValue;
        register long _rax __asm__("rax") = _id;
        register long _rdi __asm__("rdi") = _arg0;
        register long _rsi __asm__("rsi") = _arg1;
        register long _rdx __asm__("rdx") = _arg2;
        register long _r10 __asm__("r10") = _arg3;
        register long _r8  __asm__("r8")  = _arg4;
        register long _r9  __asm__("r9")  = _arg5;
        asm volatile
        (
            "syscall"
            : "=a"(_returnValue)
            :  "r"(_rax),
               "r"(_rdi),
               "r"(_rsi),
               "r"(_rdx),
               "r"(_r10),
               "r"(_r8 ),
               "r"(_r9 )
            : "rcx", "r11", "memory"
        );
        return _returnValue;
    }
    #endif
}