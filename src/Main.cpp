#include "container/Array.hpp"
#include "system/CxxABI.hpp"
#include "system/EntryExit.hpp"
#include "system/Syscall.hpp"
#include "type/Alias.hpp"

void print(const c08* _text)
{
    s64 _length = 0;
    while (_text[_length] != '\0') ++_length;
    cmn::system::write(1, _text, _length);
}

i08 main()
{
    // c08 _buffer[28];
    //     _buffer[26] = '\n';
    //     _buffer[27] = '\0';

    // for (s64 _i = 0; _i < 26; _i++)
    // {
    //     _buffer[_i] = c08('A' + _i);
    // }
    // print(_buffer);

    cmn::container::Array<u32> _array = cmn::container::Array<u32>(16, 16, 3);
    c08 _buffer[3];
        _buffer[1] = '\n';
        _buffer[2] = '\0';
    _buffer[0] = '0' + c08(_array[0]);
    _buffer[0] = '0';
    print(_buffer);

    return 0;
}


extern "C"
[[gnu::naked]]
void _start()
{
    // Align stack to 16-byte for addresses.
    asm volatile
    (
        "andq $-16, %%rsp\n"
        "call _program\n"
        "ud2\n"
        :
        :
        : "memory"
    );
}
extern "C"
[[gnu::used]]
void _program()
{
    cmn::system::run_global_ctors();
    i08 _exitCode = main();
    cmn::system::__cxa_finalize(nullptr);
    cmn::system::run_global_dtors();
    cmn::system::exit(_exitCode);
}