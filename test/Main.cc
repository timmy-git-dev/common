#include "abi/Entry.hh"
#include "syscall/Terminal.hh"

i32 main(const i32, const c08**)
{
    c08 _buffer[15] = "Hello, world!\n";
    cmn::syscall::print(_buffer, 14);

    return 0;
}