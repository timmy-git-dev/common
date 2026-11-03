#include "abi/entry.hh"
#include "syscall/uni/thread.hh"

extern "C" void start__()
{
    i32 _result = main(0, nullptr);
    cmn::syscall::uni::thread::exit(_result);
}

extern "C" void __main() { }