#include "system/abi/Entry.hpp"
#include "system/platform/OS.hpp"

#if CMN_SYSTEM_OS_LIN
#include "system/syscall/Call.hpp"
i32 main(const i32, const c08**)
{
    c08 _buffer[15] = "Hello, world!\n";
    cmn::system::syscall::write(1, _buffer, 14);

    return 0;
}
#elif CMN_SYSTEM_OS_WIN
// #include "syscall/win/Nt.hpp"
#include "syscall/win/Resolve.hpp"

i32 main(const i32, const c08**)
{
    // constexpr c08 _text[] = "Hello, world!\n";
    // IO_STATUS_BLOCK iosb { };

    PEB *_peb = cmn::syscall::win_::resolve_peb();

    // cmn::syscall::win::nt_write_file
    // (
    //     _peb->ProcessParameters->StandardOutput,
    //     0,
    //     0,
    //     0,
    //     &iosb,
    //     (PVOID)_text,
    //     sizeof(_text) - 1,
    //     0,
    //     0
    // );

    return reinterpret_cast<s64>(_peb);
}
#elif CMN_SYSTEM_OS_MAC
#include "system/xnu/Call.hpp"

i32 main(const i32, const c08**)
{
    constexpr c08 _text[] = "Hello, world!\n";
    cmn::system::xnu::write(1, reinterpret_cast<user_addr_t>(_text), sizeof(_text) - 1);

    return 0;
}
#endif