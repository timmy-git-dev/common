#pragma once

namespace cmn::syscall
{
    long syscall(long _id, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0, long _arg5 = 0);
}