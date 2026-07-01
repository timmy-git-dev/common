#include "system/abi/Entry.hpp"
#include "system/platform/OS.hpp"

// #if CMN_SYSTEM_OS_LIN
// #include "system/syscall/Call.hpp"

// i32 main(const i32, const c08**)
// {
//     c08 _buffer[14] = "Hello, world!";
//     cmn::system::syscall::write(1, _buffer, 14);

//     return 0;
// }

// #elif CMN_SYSTEM_OS_WIN
#include "system/phnt.hpp"

#define FILE_GENERIC_WRITE 0x40000000
#define FILE_CREATE_ALWAYS 2
#define FILE_ATTRIBUTE_NORMAL 0x80

i32 main(const i32, const c08**)
{
    void* fileHandle = nullptr;

    IO_STATUS_BLOCK iosb{};

    NtCreateFile
    (
        &fileHandle,
        FILE_GENERIC_WRITE,
        nullptr,              // OBJECT_ATTRIBUTES (must be properly built in real usage)
        &iosb,
        nullptr,
        FILE_ATTRIBUTE_NORMAL,
        0,
        FILE_CREATE_ALWAYS,
        0,
        nullptr,
        0
    );

    // NtTerminateProcess(nullptr, 0);
    return 0;
}
// #elif CMN_SYSTEM_OS_MAC
// i32 main(const i32, const c08**)
// {
//     return 0;
// }
// #endif