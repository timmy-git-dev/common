#include "syscall/Sys.hh"
#include "sys/platform/OS.hh"

#if CMN_SYS_OS_LIN
#include "syscall/lin/Call.hh"
#elif CMN_SYS_OS_MAC
#include "syscall/mac/Call.hh"
#elif CMN_SYS_OS_WIN
#include "syscall/win/Call.hh"
#endif

namespace cmn::syscall
{
    [[noreturn]]
    void exit(i32 _status)
    {
        #if CMN_SYS_OS_LIN
            cmn::syscall::lin::exit(_status);
        #elif CMN_SYS_OS_MAC
            cmn::syscall::mac::exit(_status);
        #elif CMN_SYS_OS_WIN
            cmn::syscall::win::NtTerminateProcess((HANDLE)-1, _status);
        #endif

        while (true) { }
    }
}
