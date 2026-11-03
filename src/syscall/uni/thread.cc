#include "syscall/uni/thread.hh"
#include "sys/platform/os.hh"

#if CMN_SYS_OS_LIN
#include "syscall/lin/call.hh"
#elif CMN_SYS_OS_MAC
#include "syscall/mac/call.hh"
#elif CMN_SYS_OS_WIN
#include "syscall/win/call.hh"
#endif

namespace cmn::syscall::uni::thread
{
    [[noreturn]]
    void exit(const i32 _status)
    {
        #if CMN_SYS_OS_LIN
            cmn::syscall::lin::exit_group(_status);
        #elif CMN_SYS_OS_MAC
            cmn::syscall::mac::exit(_status);
        #elif CMN_SYS_OS_WIN
            cmn::syscall::win::NtTerminateProcess((HANDLE)-1, _status);
        #endif

        while (true) { }
    }
}
