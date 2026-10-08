#include "abi/Entry.hh"
#include "sys/platform/OS.hh"

#if CMN_SYS_OS_LIN
#include "syscall/lin/Call.hh"
i32 main(const i32, const c08**)
{
    c08 _buffer[15] = "Hello, world!\n";
    cmn::syscall::write(1, _buffer, 14);

    return 0;
}
#elif CMN_SYS_OS_WIN
#include "syscall/win/Nt.hh"
#include "syscall/win/Resolve.hh"

int test(int _result)
{
    return _result;
}

i32 main(const i32, const c08**)
{
    constexpr c08 _text[] = "Hello, world!\n";
    IO_STATUS_BLOCK iosb { };

    cmn::syscall::win::nt_write_file
    (
        cmn::syscall::win_::resolve_peb()->ProcessParameters->StandardOutput,
        0,
        0,
        0,
        &iosb,
        (PVOID)_text,
        sizeof(_text) - 1,
        0,
        0
    );

    return 0;
}
#elif CMN_SYS_OS_MAC
#include "sys/xnu/Call.hh"

i32 main(const i32, const c08**)
{
    constexpr c08 _text[] = "Hello, world!\n";
    cmn::sys::xnu::write(1, reinterpret_cast<user_addr_t>(_text), sizeof(_text) - 1);

    return 0;
}
#endif