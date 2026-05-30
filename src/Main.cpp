#include "container/Array.hpp"
#include "container/Span.hpp"
#include "system/CxxABI.hpp"
#include "system/EntryExit.hpp"
#include "system/Syscall.hpp"
#include "type/Alias.hpp"

void print(const c08* _text)
{
    s64 _length = 0;
    while (_text[_length] != '\0') _length++;
    cmn::system::write(1, _text, _length);
}

i08 main()
{
    cmn::container::Span<u32, 5> _span = cmn::container::Span<u32, 5>(9u);
    c08 _buffer[3];
        _buffer[1] = ' ';
        _buffer[2] = '\0';
    print("Span: ");
    for (s64 _i = 0; _i < _span.LENGTH(); ++_i)
    {
        _buffer[0] = '0' + c08((_span.data() + _i)[0]);
        print(_buffer);
    }
    print("\n");

    cmn::container::Array<u32> _array = cmn::container::Array<u32>(10, 5, 2);
    _array.append_copy(0);
    _array.append_copy(3);
    _array.append_copy(19);
    _array.append_copy(4);
    _array.remove(3);
    _array.remove();
    _array.insert_copy(9, 1);
    _array.insert_copy(6, 1);
    _array.insert_copy(1, 1);
    print("Array: ");
    for (s64 _i = 0; _i < _array.length(); ++_i)
    {
        _buffer[0] = '0' + c08((_array.data() + _i)[0]);
        print(_buffer);
    }
    print("\n");

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
    cmn::system::exit_group(_exitCode);
}