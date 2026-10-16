#include "abi/Entry.hh"
#include "error/Result.hh"
#include "syscall/uni/IO.hh"
#include "syscall/uni/Terminal.hh"

void int_to_hex(u32 _value, c08 _output[11])
{
    constexpr c08 _digits[] = "0123456789ABCDEF";

    _output[0] = '0';
    _output[1] = 'x';

    for (i32 _i = 0; _i < 8; ++_i)
        _output[_i + 2] = _digits[(_value >> (28 - _i * 4)) & 0xF];

    _output[10] = '\0';
}

i32 main(const i32, const c08**)
{

    c08 _bufferA[11];
    static constexpr c08 _bufferC[] = "test.txt";
    cmn::error::Result<cmn::syscall::uni::file::PathHandle, cmn::syscall::uni::file::CREATE> _test = cmn::syscall::uni::file::create(_bufferC, sizeof(_bufferC) - 1);
    int_to_hex(u32(_test.error.code), _bufferA);
    cmn::syscall::uni::terminal::print(_bufferA, sizeof(_bufferA) - 1);

    c08 _bufferB[] = "\nHello, world!\n";
    cmn::syscall::uni::terminal::print(_bufferB, sizeof(_bufferB) - 1);

    return 0;
}