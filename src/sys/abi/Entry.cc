#include "abi/Entry.hh"
#include "syscall/Sys.hh"

extern "C" void start__()
{
    i32 _result = main(0, nullptr);
    cmn::syscall::exit(_result);
}

extern "C" void __main() { }