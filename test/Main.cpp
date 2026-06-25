#include "system/abi/Entry.hpp"
#include "system/syscall/Call.hpp"


i32 main(const i32, const c08**)
{
    c08 _buffer[14] = "Hello, world!";
    cmn::system::syscall::write(1, _buffer, 14);

    return 0;
}