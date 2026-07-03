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
i32 main(const i32, const c08**)
{
    return 0;
}
#elif CMN_SYSTEM_OS_MAC
i32 main(const i32, const c08**)
{
    return 0;
}
#endif