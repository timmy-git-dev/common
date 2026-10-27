#include "abi/Entry.hh"
#include "error/Result.hh"
#include "syscall/uni/IO.hh"
#include "syscall/uni/Mem.hh"
#include "syscall/uni/Terminal.hh"
#include "syscall/win/Call.hh"
#include "syscall/win/Func.hh"
#include "syscall/win/Type.hh"
#include "syscall/util/Path.hh"

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




// void print_entry(const c08 *_name, s64 _length, void *_context)
// {
//     // _name contains only the entry name.
//     // Example: "file.txt" or "subfolder"

//     cmn::syscall::uni::terminal::print(_name, _length);
//     cmn::syscall::uni::terminal::print("\n", 1);
// }


static c08 hex[22];

i32 main(const i32, const c08**)
{
    UNICODE_STRING _dosCWD = cmn::syscall::win_::resolve_peb()->ProcessParameters->CurrentDirectory.DosPath;

    c08 _buf[512];
    s64 _len = cmn::syscall::util::path::from_native_absolute(_dosCWD, _buf);

    _buf[_len++] = 't';
    _buf[_len++] = 'e';
    _buf[_len++] = 's';
    _buf[_len++] = 't';
    _buf[_len++] = '.';
    _buf[_len++] = 't';
    _buf[_len++] = 'x';
    _buf[_len++] = 't';

    _buf[_len] = '\n';
    cmn::syscall::uni::terminal::print(_buf, _len + 1);



    cmn::error::Result<cmn::syscall::uni::io::PathHandle, cmn::syscall::uni::io::CREATE> _file = cmn::syscall::uni::io::create(_buf, _len);
    int_to_hex(u32(_file.error.code), hex);
    cmn::syscall::uni::terminal::print(hex, 11);

    if (_file.error.code == cmn::syscall::uni::io::CREATE::NONE)
    {
        cmn::syscall::win::NtClose(HANDLE(_file.value));
    }


    c08 _a[] = "Hello, world!\n";
    cmn::syscall::uni::terminal::print(_a, sizeof(_a) - 1);

    cmn::error::Result<void *, cmn::syscall::uni::mem::MEMORY> _memory = cmn::syscall::uni::mem::allocate(64);
    int_to_hex(u32(_memory.error.code), hex);
    cmn::syscall::uni::terminal::print(hex, 11);

    if (_memory.error.code == cmn::syscall::uni::mem::MEMORY::NONE)
    {
        int_to_hex(u64(_memory.value), hex);
        cmn::syscall::uni::terminal::print(hex, 19);

        cmn::error::Result<void, cmn::syscall::uni::mem::MEMORY> _free = cmn::syscall::uni::mem::free(_memory.value, 64).error.code;
        int_to_hex(u32(_free.error.code), hex);
        cmn::syscall::uni::terminal::print(hex, 11);
    }

    return 0;
}