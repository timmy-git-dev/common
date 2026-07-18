#pragma once
#include "system/platform/Arch.hpp"

namespace cmn::system::xnu
{
    #if CMN_SYSTEM_ARCH_ARM64
    inline long syscall(long _id, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0, long _arg5 = 0, long _arg6 = 0, long _arg7 = 0)
    {
        register long x16 __asm__("x16") = _id;
        register long x0  __asm__("x0" ) = _arg0;
        register long x1  __asm__("x1" ) = _arg1;
        register long x2  __asm__("x2" ) = _arg2;
        register long x3  __asm__("x3" ) = _arg3;
        register long x4  __asm__("x4" ) = _arg4;
        register long x5  __asm__("x5" ) = _arg5;

        asm volatile
        (
            "svc #0x80"
            : "+r"(x0 )
            :  "r"(x16),
               "r"(x1 ),
               "r"(x2 ),
               "r"(x3 ),
               "r"(x4 ),
               "r"(x5 )
            : "memory"
        );

        return x0;
    }
    #elif CMN_SYSTEM_ARCH_X64
    inline long syscall(long id, long a0 = 0, long a1 = 0, long a2 = 0, long a3 = 0, long a4 = 0, long a5 = 0, long a6 = 0, long a7 = 0)
    {
        id |= 0x2000000;

        register long r10 asm("r10") = a3;

        asm volatile(
            "syscall"
            : "+a"(id)
            : "D"(a0),
              "S"(a1),
              "d"(a2),
              "r"(r10),
              "r"(a4),
              "r"(a5)
            : "rcx", "r11", "memory"
        );

        return id;
    }
    #endif
}