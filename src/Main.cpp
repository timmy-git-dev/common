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
constexpr u64 random(u64 _seed)
{
    _seed ^= _seed >> 12;
    _seed ^= _seed << 25;
    _seed ^= _seed >> 27;
    return _seed * 2685821657736338717ull;
}

constexpr c08* to_string(i64 _value, c08* _bufferEnd)
{
    u64 _uValue = _value < 0 ? static_cast<u64>(-_value) : static_cast<u64>(_value);

    *--_bufferEnd = '\0';

    do
    {
        *--_bufferEnd = static_cast<c08>('0' + (_uValue % 10));
        _uValue /= 10;
    }
    while (_uValue);

    if (_value < 0)
        *--_bufferEnd = '-';

    return _bufferEnd;
}

i08 main()
{
//     cmn::container::Span<i64, 32> _span = cmn::container::Span<i64, 32>();

//     c08 _buffer[32];
//     print("Span: ");
//     print("\n fill: ");
//     _span.fill(69u, 7, 19);
//     print("[");
//     for (s64 _i = 0; _i < _span.LENGTH() - 1; ++_i)
//     {
//         print(to_string(_span[_i], _buffer + 32));
//         print(", ");
//     }
//     if (_span.LENGTH() > 0) {print(to_string(_span[_span.LENGTH() - 1], _buffer + 32));}
//     print("]");

//     print("\n replace: ");
//     _span.replace(69u, 420u, 14, 23);
//     print("[");
//     for (s64 _i = 0; _i < _span.LENGTH() - 1; ++_i)
//     {
//         print(to_string(_span[_i], _buffer + 32));
//         print(", ");
//     }
//     if (_span.LENGTH() > 0) {print(to_string(_span[_span.LENGTH() - 1], _buffer + 32));}
//     print("]");


//     print("\n contains [0]: ");
//     print(_span.contains(0u, 0ul, _span.LENGTH()) ? "true" : "false");

//     print("\n count [0]: ");
//     print(to_string(_span.count   (0u, 0ul, _span.LENGTH()), _buffer + 32));

//     print("\n first_of [0]: ");
//     print(to_string(_span.first_of(0u, 0ul, _span.LENGTH()), _buffer + 32));

//     print("\n last_of [0]: ");
//     print(to_string(_span.last_of (0u, 0ul, _span.LENGTH()), _buffer + 32));

//     print("\n");

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
[[noreturn]]
void _program()
{
    cmn::system::run_global_ctors();
    i08 _exitCode = main();
    cmn::system::__cxa_finalize(nullptr);
    cmn::system::run_global_dtors();
    cmn::system::exit_group(_exitCode);
    __builtin_unreachable();
}