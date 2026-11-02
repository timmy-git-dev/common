#include "abi/Entry.hh"
#include "syscall/uni/IO.hh"
#include "dbg/Print.hh"
#include "syscall/uni/IO_Error.hh"

c08 buffer[4096];

bool cwd()
{
    cmn::error::Result<s64, cmn::syscall::uni::io::Cwd> _invalid = cmn::syscall::uni::io::cwd(buffer, 0   );
    cmn::error::Result<s64, cmn::syscall::uni::io::Cwd> _correct = cmn::syscall::uni::io::cwd(buffer, 1024);

    bool _success =
        _invalid.status.code == cmn::syscall::uni::io::Cwd::INVALID_CAPACITY && _invalid.value != 0 &&
        _correct.status.code == cmn::syscall::uni::io::Cwd::SUCCESS          && _correct.value != 0;

    if (!_success)
    {
        PRINT
        (
            _invalid.status.code, _invalid.value,
            _correct.status.code, _correct.value
        );
    }

    return _success;
}
bool exists()
{
    s64 _length = cmn::syscall::uni::io::cwd(buffer, 1024).value;

    cmn::error::Result<cmn::syscall::uni::io::Type, cmn::syscall::uni::io::Exists> _dir  = cmn::syscall::uni::io::exists(buffer, _length);

    c08 _buffer[] = "/file.txt";
    for (s64 _i = 0; _i < sizeof(_buffer); ++_i)
    {
        buffer[_length + _i] = _buffer[_i];
    }
    cmn::error::Result<cmn::syscall::uni::io::Type, cmn::syscall::uni::io::Exists> _file = cmn::syscall::uni::io::exists(buffer, _length + sizeof(_buffer) - 1);

    bool _success =
        _dir .status.code == cmn::syscall::uni::io::Exists::SUCCESS && _dir .value == cmn::syscall::uni::io::Type::DIRECTORY &&
        _file.status.code == cmn::syscall::uni::io::Exists::SUCCESS && _file.value == cmn::syscall::uni::io::Type::FILE;

    if (!_success)
    {
        PRINT
        (
            buffer,
            _dir .status.code, _dir .value,
            _file.status.code, _file.value
        );
    }

    return _success;
}

i32 main(const i32, const c08**)
{
    PRINT(cwd());
    PRINT(exists());

    return 0;
}