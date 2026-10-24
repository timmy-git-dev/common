#include "abi/Entry.hh"
#include "error/Result.hh"
#include "syscall/uni/IO.hh"
#include "syscall/uni/Terminal.hh"
#include "syscall/win/Func.hh"

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
    #if CMN_SYS_OS_WIN
        UNICODE_STRING test = cmn::syscall::win_::resolve_peb()->ProcessParameters->CurrentDirectory.DosPath;
        c08 _bufferD[512];
        for (int _i = 0; _i < test.Length / 2; ++_i)
        {
            _bufferD[_i] = test.Buffer[_i];
        }
        _bufferD[test.Length / 2] = '\n';
        cmn::syscall::uni::terminal::print(_bufferD, test.Length / 2 + 1);
    #endif

    c08 _bufferA[11];
    static constexpr c08 _bufferC[] = "Z:\\home\\timmy\\code\\common\\test.txt";
    cmn::error::Result<cmn::syscall::uni::io::PathHandle, cmn::syscall::uni::io::CREATE> _file = cmn::syscall::uni::io::create(cmn::syscall::uni::io::PathHandle(nullptr), _bufferC, sizeof(_bufferC) - 1);

    int_to_hex(u32(_file.error.code), _bufferA);
    cmn::syscall::uni::terminal::print(_bufferA, sizeof(_bufferA) - 1);

    c08 _bufferB[] = "\nHello, world!\n";
    cmn::syscall::uni::terminal::print(_bufferB, sizeof(_bufferB) - 1);

    return 0;
}