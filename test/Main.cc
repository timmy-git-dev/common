#include "abi/Entry.hh"
#include "error/Result.hh"
#include "syscall/uni/IO.hh"
#include "syscall/uni/Terminal.hh"
#include "syscall/win/Call.hh"
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




void print_entry(const c08 *_name, s64 _length, void *_context)
{
    // _name contains only the entry name.
    // Example: "file.txt" or "subfolder"

    cmn::syscall::uni::terminal::print(_name, _length);
    cmn::syscall::uni::terminal::print("\n", 1);
}


static c08 hex[22];
static c08 _buffer[512];
static c08 _filePath[] = "\\??\\Z:\\home\\timmy\\code\\common";
// static c08 _testPath[] = "/C:/./././//test.txt";

i32 main(const i32, const c08**)
{
    // u64 _len = cmn::syscall::util::path::native_size(_testPath, sizeof(_testPath) - 1);
    // cmn::syscall::uni::terminal::print(hex, int_to_str(_len, hex));


    cmn::error::Result<cmn::syscall::uni::io::PathHandle, cmn::syscall::uni::io::CREATE> _file = cmn::syscall::uni::io::create(cmn::syscall::uni::io::PathHandle(nullptr), _filePath, sizeof(_filePath) - 1);
    int_to_hex(u32(_file.error.code), hex);
    cmn::syscall::uni::terminal::print(hex, 11);

    if (_file.error.code == cmn::syscall::uni::io::CREATE::NONE)
    {
        cmn::syscall::uni::io::for_each_name(_file.value, print_entry);


        cmn::syscall::uni::io::get_name(_file.value, _buffer);
        s64 _length = -1;
        while (_buffer[++_length] != '\0') { }
        _buffer[_length++] = '\n';
        _buffer[_length] = '\0';
        cmn::syscall::uni::terminal::print(_buffer, _length);


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