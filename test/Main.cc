#include "abi/Entry.hh"
#include "syscall/lin/Call.hh"

i32 main(const i32, const c08**)
{
    c08 _buffer[15] = "Hello, world!\n";
    cmn::syscall::write_data(1, _buffer, 14);

    return 0;
}