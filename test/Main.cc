#include "abi/Entry.hh"
#include "error/Result.hh"
#include "syscall/uni/IO.hh"
#include "syscall/uni/Mem.hh"
#include "syscall/uni/Terminal.hh"
#include "syscall/win/Call.hh"
#include "syscall/win/Type.hh"

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

static c08 hex[20];

i32 main(const i32, const c08**)
{

    const c08* _filePath = "\\??\\Z:\\home\\timmy\\code\\common\\test.txt";
    cmn::error::Result<cmn::syscall::uni::io::PathHandle, cmn::syscall::uni::io::CREATE> _file = cmn::syscall::uni::io::create(cmn::syscall::uni::io::PathHandle(nullptr), _filePath, 38);
    int_to_hex(u32(_file.error.code), hex);
    cmn::syscall::uni::terminal::print(hex, 11);

    if (_file.error.code == cmn::syscall::uni::io::CREATE::NONE)
    {
        cmn::syscall::win::NtClose(HANDLE(_file.value));
    }


    c08 _a[] = "Hello, world!\n";
    cmn::syscall::uni::terminal::print(_a, sizeof(_a) - 1);

    // cmn::error::Result<void *, cmn::syscall::uni::mem::MEMORY> _memory = cmn::syscall::uni::mem::allocate(64);
    // int_to_hex(u32(_memory.error.code), hex);
    // cmn::syscall::uni::terminal::print(hex, 11);

    // if (_memory.error.code == cmn::syscall::uni::mem::MEMORY::NONE)
    // {
    //     int_to_hex(u64(_memory.value), hex);
    //     cmn::syscall::uni::terminal::print(hex, 19);

    //     cmn::error::Result<void, cmn::syscall::uni::mem::MEMORY> _free = cmn::syscall::uni::mem::free(_memory.value, 64).error.code;
    //     int_to_hex(u32(_free.error.code), hex);
    //     cmn::syscall::uni::terminal::print(hex, 11);
    // }

    return 0;
}