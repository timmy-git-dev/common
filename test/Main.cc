#include "abi/Entry.hh"
#include "syscall/uni/IO.hh"
#include "dbg/Print.hh"
#include "syscall/uni/IO_Error.hh"

i32 main(const i32, const c08**)
{
    c08 _cwdBuffer[1024];
    cmn::error::Result<s64, cmn::syscall::uni::io::Cwd> _path = cmn::syscall::uni::io::cwd(_cwdBuffer, 1024);

    if (_path.error.code == cmn::syscall::uni::io::Cwd::NONE)
    {
        PRINT(_cwdBuffer);
    }

    c08 _helloWorld[] = "Hello, world!";

    PRINT(_helloWorld, _path.error.code);

    return 0;
}