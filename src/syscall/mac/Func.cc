#include "sys/platform/Arch.hh"
#include "syscall/mac/Func.hh"

namespace cmn::syscall::mac
{
    long syscall(long _id, long _arg0, long _arg1, long _arg2, long _arg3, long _arg4, long _arg5, long _arg6, long _arg7)
    {
        #if CMN_SYS_ARCH_ARM64

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

        #elif CMN_SYS_ARCH_X64

            _id |= 0x2000000;

            register long r10 asm("r10") = _arg3;

            asm volatile(
                "syscall"
                : "+a"(_id )
                : "D"(_arg0),
                  "S"(_arg1),
                  "d"(_arg2),
                  "r"(r10  ),
                  "r"(_arg4),
                  "r"(_arg5)
                : "rcx", "r11", "memory"
            );

            return _id;

        #endif
    }
}