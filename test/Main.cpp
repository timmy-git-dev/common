#include "system/abi/Entry.hpp"
// #include "system/platform/OS.hpp"

// #if CMN_SYSTEM_OS_LIN
// #include "system/syscall/Call.hpp"

// i32 main(const i32, const c08**)
// {
//     c08 _buffer[14] = "Hello, world!";
//     cmn::system::syscall::write(1, _buffer, 14);

//     return 0;
// }

// #elif CMN_SYSTEM_OS_WIN
#include "system/nt/Func.hpp"

typedef struct _IO_STATUS_BLOCK {
    union {
        NTSTATUS Status;
        void *Pointer;
    };
    SIZE_T Information;
} IO_STATUS_BLOCK;

typedef struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    wchar_t *Buffer;
} UNICODE_STRING;

typedef struct _RTL_USER_PROCESS_PARAMETERS {
    unsigned char Reserved1[16];
    void *Reserved2[10];
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
    HANDLE StandardInput;
    HANDLE StandardOutput;
    HANDLE StandardError;
} RTL_USER_PROCESS_PARAMETERS;

typedef struct _PEB {
    unsigned char Reserved1[24];
    RTL_USER_PROCESS_PARAMETERS *ProcessParameters;
} PEB;

static PEB *get_peb(void)
{
    PEB *peb;
    __asm__ volatile (
        "movq %%gs:0x60, %0"
        : "=r"(peb)
    );
    return peb;
}

i32 main(const i32, const c08**)
{
    static char msg[] = "Hello, world!\n";

    PEB *peb = get_peb();

    HANDLE stdout_handle =
        peb->ProcessParameters->StandardOutput;

    IO_STATUS_BLOCK iosb;

    NtWriteFile(
        stdout_handle,
        0,
        0,
        0,
        &iosb,
        msg,
        sizeof(msg) - 1,
        0,
        0
    );


    return 0;
}
// #elif CMN_SYSTEM_OS_MAC
// #include "system/xnu/Call.hpp"

// i32 main(const i32, const c08**)
// {
//     static constexpr c08 _text[] = "Hello, world!\n";
//     cmn::system::xnu::write(1, reinterpret_cast<user_addr_t>(_text), sizeof(_text) - 1);

//     return 0;
// }
// #endif