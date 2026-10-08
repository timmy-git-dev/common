#pragma once
#include "error/Result.hh"
#include "syscall/lin/Errno.hh"
#include "type/Alias.hh"
namespace cmn::syscall
{
    inline error::Result<i64, ERRNO> syscall(long _id, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0, long _arg5 = 0)
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
        return error::Result<i64, ERRNO>(_returnValue, (-4096 < _returnValue && _returnValue < 0 ? ERRNO::NONE : static_cast<ERRNO>(_returnValue)));
    }
}