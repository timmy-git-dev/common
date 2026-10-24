#include "abi/Entry.hh"
#include "syscall/uni/IO.hh"
#include "syscall/uni/Terminal.hh"

i32 main(const i32, const c08**)
{
    c08 _bufferB[] = "\nHello, world!\n";
    cmn::syscall::uni::terminal::print(_bufferB, sizeof(_bufferB) - 1);

    return 0;
}