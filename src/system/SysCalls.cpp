#include "system/SysCalls.hpp"

namespace cmn::system
{
    long sys_call(long _type, long _arg0, long _arg1, long _arg2, long _arg3, long _arg4)
    {
        long _returnValue;
        register long _reg10 __asm__("r10") = _arg3;
        register long _reg08 __asm__("r8")  = _arg4;

        asm volatile
        (
            "syscall" :
            "=a"(_returnValue) :
            "a"(_type),
            "D"(_arg0),
            "S"(_arg1),
            "d"(_arg2),
            "r"(_reg10),
            "r"(_reg08) :
            "rcx",
            "r11",
            "memory"
        );
        return _returnValue;
    }

    void write(const char* _output)
    {
        long _length = 0;
        while (_output[_length] != '\0')
        {
            ++_length;
        }
        sys_call(SYS_CALL::WRITE, 1, (long)_output, _length);
    }

    [[noreturn]] void exit(int _exitCode)
    {
        sys_call(SYS_CALL::EXIT, _exitCode, 0, 0);
        __builtin_unreachable();
    }
}