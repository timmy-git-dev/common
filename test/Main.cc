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
        _invalid.status.code == cmn::syscall::uni::io::Cwd::SHORT_CAPACITY && _invalid.value != 0 &&
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
bool query()
{
    s64 _length = cmn::syscall::uni::io::cwd(buffer, 1024).value;

    cmn::error::Result<cmn::syscall::uni::io::Info, cmn::syscall::uni::io::Query> _dir  = cmn::syscall::uni::io::query(buffer, _length);

    c08 _buffer[] = "/file.txt";
    for (s64 _i = 0; _i < sizeof(_buffer); ++_i)
    {
        buffer[_length + _i] = _buffer[_i];
    }
    cmn::error::Result<cmn::syscall::uni::io::Info, cmn::syscall::uni::io::Query> _file = cmn::syscall::uni::io::query(buffer, _length + sizeof(_buffer) - 1);

    bool _success =
        _dir .status.code == cmn::syscall::uni::io::Query::SUCCESS && _dir .value.type == cmn::syscall::uni::io::Type::DIRECTORY &&
        _file.status.code == cmn::syscall::uni::io::Query::SUCCESS && _file.value.type == cmn::syscall::uni::io::Type::FILE;

    PRINT
    (
        _dir.status.code,
        _dir.value.type            ,
        _dir.value.length          ,
        _dir.value.allocated       ,
        _dir.value.linkCount       ,
        _dir.value.id              ,
        _dir.value.filesystemID    ,
        _dir.value.created .seconds, _dir.value.created .nanoseconds,
        _dir.value.accessed.seconds, _dir.value.accessed.nanoseconds,
        _dir.value.edited  .seconds, _dir.value.edited  .nanoseconds,
        _dir.value.updated .seconds, _dir.value.updated .nanoseconds,
    );

    PRINT
    (
        _file.status.code,
        _file.value.type            ,
        _file.value.length          ,
        _file.value.allocated       ,
        _file.value.linkCount       ,
        _file.value.id              ,
        _file.value.filesystemID    ,
        _file.value.created .seconds, _file.value.created .nanoseconds,
        _file.value.accessed.seconds, _file.value.accessed.nanoseconds,
        _file.value.edited  .seconds, _file.value.edited  .nanoseconds,
        _file.value.updated .seconds, _file.value.updated .nanoseconds,
    );

    // if (!_success)
    // {
    //     PRINT
    //     (
    //         buffer,
    //         _dir .status.code, _dir .value,
    //         _file.status.code, _file.value
    //     );
    // }

    return _success;
}

i32 main(const i32, const c08**)
{
    PRINT(cwd());
    PRINT(query());

    return 0;
}