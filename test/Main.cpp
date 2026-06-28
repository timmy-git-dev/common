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
extern "C" void ExitProcess(u32);
extern "C" void* CreateFileA(const char*, u32, u32, void*, u32, u32, void*);

#define GENERIC_WRITE 0x40000000
#define CREATE_ALWAYS 2
#define FILE_ATTRIBUTE_NORMAL 0x80

i32 main(const i32, const c08**)
{
    void* _fileHandle = CreateFileA(
        "test.txt",
        GENERIC_WRITE,
        0,
        nullptr,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
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