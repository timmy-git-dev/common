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
typedef struct _IO_STATUS_BLOCK {
    union {
        NTSTATUS Status;
        void *Pointer;
    };
    unsigned long long Information;
} IO_STATUS_BLOCK;

extern "C" HANDLE GetStdHandle(unsigned long);

#define STD_INPUT_HANDLE  ((u64)-10)
#define STD_OUTPUT_HANDLE ((u64)-11)
#define STD_ERROR_HANDLE  ((u64)-12)

typedef struct _UNICODE_STRING
{
    u16 Length;          // bytes, not characters
    u16 MaximumLength;   // bytes, not characters
    wchar_t *Buffer;
} UNICODE_STRING;

typedef struct _RTL_USER_PROCESS_PARAMETERS
{
    b08 Unneeded[32];

    HANDLE StandardInput;
    HANDLE StandardOutput;
    HANDLE StandardError;
} RTL_USER_PROCESS_PARAMETERS;

typedef struct PEB
{
    BYTE Reserved1[2];
    BYTE BeingDebugged;
    BYTE Reserved2[21];
    void* LoaderData;
    PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
    BYTE Reserved3[520];
    void* PostProcessInitRoutine;
    BYTE Reserved4[136];
    ULONG SessionId;
} PEB;

static PEB *get_peb()
{
    PEB *peb;
    asm volatile(
        "movq %%gs:0x60, %0"
        : "=r"(peb)
    );
    return peb;
}

static HANDLE get_std(u64 id)
{
    PEB *peb = get_peb();

    if (!peb || !peb->ProcessParameters)
        return 0;

    switch (id)
    {
        case STD_INPUT_HANDLE:
            return peb->ProcessParameters->StandardInput;

        case STD_OUTPUT_HANDLE:
            return peb->ProcessParameters->StandardOutput;

        case STD_ERROR_HANDLE:
            return peb->ProcessParameters->StandardError;
    }

    return (HANDLE)4;
}

void write(const char* _text)
{
    s64 _length = 0;
    while (_text[_length] != '\0') {++_length;}

    IO_STATUS_BLOCK iosb { };

    NtWriteFile
    (
        get_std(STD_OUTPUT_HANDLE),
        0,
        0,
        0,
        &iosb,
        (PVOID)_text,
        _length,
        0,
        0
    );
}

i32 main(const i32, const c08**)
{
    write("Hello, world!\n");

    return 0;
}
#elif CMN_SYSTEM_OS_MAC
#include "system/xnu/Call.hpp"

i32 main(const i32, const c08**)
{
    static constexpr c08 _text[] = "Hello, world!\n";
    cmn::system::xnu::write(1, reinterpret_cast<user_addr_t>(_text), sizeof(_text) - 1);

    return 0;
}
#endif