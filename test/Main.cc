#include "abi/Entry.hh"
#include "error/Result.hh"
#include "syscall/uni/IO.hh"
#include "syscall/uni/Mem.hh"
#include "syscall/uni/Terminal.hh"

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


i32 main(const i32, const c08**)
{
    c08 _a[] = "Hello, world!\n";
    cmn::syscall::uni::terminal::print(_a, sizeof(_a) - 1);

    cmn::error::Result<void *, cmn::syscall::uni::mem::MEMORY> _memory = cmn::syscall::uni::mem::allocate(64);
    c08 _b[20];
    int_to_hex(u32(_memory.error.code), _b);
    cmn::syscall::uni::terminal::print(_b, 11);

    if (_memory.error.code == cmn::syscall::uni::mem::MEMORY::NONE)
    {
        int_to_hex(u64(_memory.value), _b);
        cmn::syscall::uni::terminal::print(_b, 19);

        cmn::error::Result<void, cmn::syscall::uni::mem::MEMORY> _free = cmn::syscall::uni::mem::free(_memory.value, 64).error.code;
        int_to_hex(u32(_free.error.code), _b);
        cmn::syscall::uni::terminal::print(_b, 11);
    }

    return 0;
}