#pragma once

namespace cmn::system
{
    long sys_call(long _type, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0);

    enum SYS_CALL: long
    {
        WRITE =  1,
        EXIT  = 60,
    };

                 void write(const char* _output);
    [[noreturn]] void exit (int _exitCode);
}