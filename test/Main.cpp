#include "system/abi/Entry.hpp"
#include "system/platform/OS.hpp"

#if CMN_SYSTEM_OS_LIN
#include "system/syscall/Call.hpp"

i32 main(const i32, const c08**)
{
    c08 _buffer[14] = "Hello, world!";
    cmn::system::syscall::write(1, _buffer, 14);

    return 0;
}

#elif CMN_SYSTEM_OS_WIN
#include "system/nt/Func.hpp"

struct PROCESS_BASIC_INFORMATION
{
    void* Reserved1;
    void* PebBaseAddress;
    void* Reserved2[2];
    u64 UniqueProcessId;
    void* Reserved3;
};

struct RTL_USER_PROCESS_PARAMETERS
{
    u08 Reserved1[0x20];
    void* Reserved2[10];
    HANDLE StandardInput;
    HANDLE StandardOutput;
    HANDLE StandardError;
};

struct PEB
{
    u08 Reserved1[0x20];
    RTL_USER_PROCESS_PARAMETERS* ProcessParameters;
};

struct IO_STATUS_BLOCK
{
    union
    {
        i64 Status;
        void* Pointer;
    };

    s64 Information;
};

struct _TEB
{
    void* Reserved1[12];
    void* ProcessEnvironmentBlock;
    void* Reserved2[399];
};

i32 main(const i32, const c08**)
{
    // PEB* _peb = (PEB*)(NtCurrentTeb()->ProcessEnvironmentBlock);
    // HANDLE _stdout = _peb->ProcessParameters->StandardOutput;

    // static constexpr c08 text[] = "Hello, world!\n";

    // IO_STATUS_BLOCK iosb;

    // NtWriteFile(
    //     _stdout,
    //     nullptr,
    //     nullptr,
    //     nullptr,
    //     PIO_STATUS_BLOCK(&iosb),
    //     (void*)text,
    //     sizeof(text) - 1,
    //     nullptr,
    //     nullptr
    // );

    return 0;
}
#elif CMN_SYSTEM_OS_MAC
i32 main(const i32, const c08**)
{
    static constexpr c08 _text[] = "Hello, world!\n";
    syscall(SYS_write, 1, _text, sizeof(_text) - 1);

    return 0;
}
#endif