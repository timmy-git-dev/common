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


i32 main(const i32, const c08**)
{
    // #define FILE_WRITE_DATA              0x0002
    // #define SYNCHRONIZE                  0x00100000
    // #define OBJ_CASE_INSENSITIVE         0x40
    // #define FILE_ATTRIBUTE_NORMAL        0x80
    // #define FILE_SHARE_READ              0x01
    // #define FILE_SHARE_WRITE             0x02
    // #define FILE_OVERWRITE_IF            0x05
    // #define FILE_NON_DIRECTORY_FILE      0x40
    // #define FILE_SYNCHRONOUS_IO_NONALERT 0x20

    constexpr u32 DIRECTORY_TRAVERSE  = 0x0002;
    constexpr u32 OBJ_CASE_INSENSITIVE = 0x0040;

    c16 _rootPath[] = u"\\??";

    UNICODE_STRING _name
        {
        u16(sizeof(_rootPath) - sizeof(c16)),
        u16(sizeof(_rootPath)),
        _rootPath
    };

    OBJECT_ATTRIBUTES _attributes
        {
        sizeof(OBJECT_ATTRIBUTES),
        nullptr,
        &_name,
        OBJ_CASE_INSENSITIVE,
        nullptr,
        nullptr
    };

    HANDLE _handle = nullptr;

    NTSTATUS _status = cmn::syscall::win::NtOpenDirectoryObject(
        &_handle,
        DIRECTORY_TRAVERSE,
        POBJECT_ATTRIBUTES(&_attributes)
    );

    c08 _x[20];
    int_to_hex(u32(_status), _x);
    cmn::syscall::uni::terminal::print(_x, 11);
    if (_status >= 0)
    {
        const c08* _filePath = "Z:\\home\\timmy\\code\\common\\test.txt";
        cmn::error::Result<cmn::syscall::uni::io::PathHandle, cmn::syscall::uni::io::CREATE> _file = cmn::syscall::uni::io::create(cmn::syscall::uni::io::PathHandle(_handle), _filePath, 34);
        int_to_hex(u32(_file.error.code), _x);
        cmn::syscall::uni::terminal::print(_x, 11);

        if (_file.error.code == cmn::syscall::uni::io::CREATE::NONE)
        {
            cmn::syscall::win::NtClose(HANDLE(_file.value));
        }



        // _handle references the \?? Object Manager directory.
        // Close when finished:
        cmn::syscall::win::NtClose(_handle);
    }

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