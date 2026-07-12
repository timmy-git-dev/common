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

i32 main(const i32, const c08**)
{
    PROCESS_BASIC_INFORMATION pbi{};
    NtQueryInformationProcess(
        (HANDLE)-1,
        (PROCESSINFOCLASS)0, // ProcessBasicInformation
        &pbi,
        sizeof(pbi),
        __null
    );

    auto peb = (PEB*)pbi.PebBaseAddress;
    HANDLE stdout = peb->ProcessParameters->StandardOutput;

    static constexpr c08 text[] = "Hello, World!\n";

    NtWriteFile(
        stdout,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        (void*)text,
        sizeof(text) - 1,
        nullptr,
        nullptr
    );

    return 0;
}
#elif CMN_SYSTEM_OS_MAC
i32 main(const i32, const c08**)
{
    return 0;
}
#endif