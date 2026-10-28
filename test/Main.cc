#include "abi/Entry.hh"
#include "error/Result.hh"
#include "syscall/uni/IO.hh"
#include "syscall/uni/IO_Error.hh"
#include "syscall/uni/Terminal.hh"

s64 int_to_str(u64 _value, c08 _output[22])
{
    i32 _count = 0;

    do
    {
        _output[_count++] = c08('0' + _value % 10);
        _value /= 10;
    }
    while (_value);

    for (i32 _i = 0; _i < _count / 2; ++_i)
    {
        c08 _temp = _output[_i];
        _output[_i] = _output[_count - 1 - _i];
        _output[_count - 1 - _i] = _temp;
    }

    _output[_count++] = '\n';
    _output[_count] = '\0';
    return _count;
}
void int_to_hex(u64 _value, c08 _output[20])
{
    constexpr c08 _digits[] = "0123456789ABCDEF";

    _output[0] = '0';
    _output[1] = 'x';

    for (i32 _i = 0; _i < 16; ++_i)
        _output[_i + 2] = _digits[(_value >> (60 - _i * 4)) & 0xF];

    _output[18] = '\n';
    _output[19] = '\0';
}
void int_to_hex(u32 _value, c08 _output[12])
{
    constexpr c08 _digits[] = "0123456789ABCDEF";

    _output[0] = '0';
    _output[1] = 'x';

    for (i32 _i = 0; _i < 8; ++_i)
        _output[_i + 2] = _digits[(_value >> (28 - _i * 4)) & 0xF];

    _output[10] = '\n';
    _output[11] = '\0';
}

// static c08 hex[22];

i32 main(const i32, const c08**)
{
    c08 _buffer[1024];
    cmn::error::Result<s64, cmn::syscall::uni::io::Cwd> _path = cmn::syscall::uni::io::cwd(_buffer, 1024);

    if (_path.error.code == cmn::syscall::uni::io::Cwd::NONE)
    {
        cmn::syscall::uni::terminal::print(_buffer, _path.value);
        cmn::syscall::uni::terminal::print("\n", 1);
    }


    c08 _a[] = "Hello, world!\n";
    cmn::syscall::uni::terminal::print(_a, sizeof(_a) - 1);


    return 0;
}