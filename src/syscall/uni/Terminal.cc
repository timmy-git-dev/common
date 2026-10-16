#include "syscall/uni/Terminal.hh"
#include "sys/platform/OS.hh"

#if CMN_SYS_OS_LIN
#include "syscall/lin/Call.hh"
#elif CMN_SYS_OS_MAC
#include "syscall/mac/Call.hh"
#elif CMN_SYS_OS_WIN
#include "syscall/win/Call.hh"
#include "syscall/win/Func.hh"
#endif

namespace cmn::syscall::uni::terminal
{
    #if CMN_SYS_OS_WIN
        PRTL_USER_PROCESS_PARAMETERS processParameters;
    #endif

    void print(const char *_output, const s64 _length)
    {
        #if CMN_SYS_OS_LIN
            cmn::syscall::lin::write(1, _output, _length);
        #elif CMN_SYS_OS_MAC
            cmn::syscall::mac::write(1, reinterpret_cast<user_addr_t>(_output), _length);
        #elif CMN_SYS_OS_WIN
            if (processParameters == nullptr)
            {
                processParameters = cmn::syscall::win_::resolve_peb()->ProcessParameters;
            }

            IO_STATUS_BLOCK _ioStatus { };
            cmn::syscall::win::NtWriteFile
            (
                processParameters->StandardOutput,
                0,
                0,
                0,
                &_ioStatus,
                (PVOID)_output,
                _length,
                0,
                0
            );
        #endif
    }
}