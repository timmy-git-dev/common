#include "system/CxxABI.hpp"
#include "system/EntryExit.hpp"
#include "system/SysCalls.hpp"

struct Demo
{
    Demo()  { cmn::system::write("ctor\n"); }
    ~Demo() { cmn::system::write("dtor\n"); }
} demo;


int main()
{
    Demo _demo = Demo();
    cmn::system::write("main\n");
    return 0;
}

extern "C" void _start()
{
    cmn::system::create_global_ctors();
    int _exitCode = main();
    cmn::system::__cxa_finalize(nullptr);
    cmn::system::delete_global_dtors();
    cmn::system::exit(_exitCode);
}