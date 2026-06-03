#include "container/Array.hpp"
#include "container/Span.hpp"
#include "container/Array.hpp"
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

c08* to_string(i64 value, c08* end)
{
    c08* ptr = end;
    *--ptr = '\0';

    b08 negative = value < 0;
    u64 magnitude = negative
        ? static_cast<u64>(-(value + 1)) + 1
        : static_cast<u64>(value);

    do
    {
        *--ptr = static_cast<c08>('0' + (magnitude % 10));
        magnitude /= 10;
    }
    while (magnitude != 0);

    if (negative)
    {
        *--ptr = '-';
    }

    return ptr;
}
c08* to_fstring(f32 value, c08* end)
{
    c08* ptr = end;
    *--ptr = '\0';

    b08 negative = value < 0.0f;
    if (negative)
    {
        value = -value;
    }

    constexpr u32 precision = 1;

    f32 fractional_f = value - static_cast<u32>(value);
    u32 fractional = 0;

    for (u32 i = 0; i < precision; ++i)
    {
        fractional_f *= 10.0f;
    }

    fractional = static_cast<u32>(fractional_f + 0.5f);

    for (u32 i = 0; i < precision; ++i)
    {
        *--ptr = static_cast<c08>('0' + (fractional % 10));
        fractional /= 10;
    }

    *--ptr = '.';

    u32 integer = static_cast<u32>(value);

    do
    {
        *--ptr = static_cast<c08>('0' + (integer % 10));
        integer /= 10;
    }
    while (integer != 0);

    if (negative)
    {
        *--ptr = '-';
    }

    return ptr;
}

i08 main()
{
    c08 _buffer[32];

    cmn::container::Array<f32    > _array = cmn::container::Array<f32    >(32, 32, 6.9f);
    cmn::container::Span <i32, 32> _span  = cmn::container::Span <i32, 32>(0);

    print("Array: ");
    print("\n fill: ");
    _array.fill(69.0f, 7, 19);
    print("[");
    for (const f32& _x : _array)
    {
        print(to_fstring(_x, _buffer + 32));
        print(", ");
    }
    if (_array.length() > 0) {print(to_fstring(_array[_array.length() - 1], _buffer + 32));}
    print("]");

    print("\n replace: ");
    _array.replace(69.0f, 4.20f, 14, 23);
    print("[");
    for (f32& _x : _array)
    {
        print(to_fstring(_x, _buffer + 32));
        print(", ");
    }
    if (_array.length() > 0) {print(to_fstring(_array[_array.length() - 1], _buffer + 32));}
    print("]");


    print("\n contains [0]: ");
    print(_array.contains          (0u, 0ul, _array.length()) ? "true" : "false");

    print("\n count [0]: ");
    print(to_string(_array.count   (0u, 0ul, _array.length()), _buffer + 32));

    print("\n index_first [0]: ");
    print(to_string(_array.index_first(0u, 0ul, _array.length()), _buffer + 32));

    print("\n index_last [0]: ");
    print(to_string(_array.index_last (0u, 0ul, _array.length()), _buffer + 32));

    print("\n");


    print("Span: ");
    print("\n fill: ");
    _span.fill(69u, 7, 19);
    print("[");
    for (const i32& _x : _span)
    {
        print(to_string(_x, _buffer + 32));
        print(", ");
    }
    if (_span.length() > 0) {print(to_string(_span[_span.length() - 1], _buffer + 32));}
    print("]");

    print("\n replace: ");
    _span.replace(69u, 420u, 14, 23);
    print("[");
    for (i32& _x : _span)
    {
        print(to_string(_x, _buffer + 32));
        print(", ");
    }
    if (_span.length() > 0) {print(to_string(_span[_span.length() - 1], _buffer + 32));}
    print("]");


    print("\n contains [0]: ");
    print(_span.contains          (0u, 0ul, _span.length()) ? "true" : "false");

    print("\n count [0]: ");
    print(to_string(_span.count   (0u, 0ul, _span.length()), _buffer + 32));

    print("\n index_first [0]: ");
    print(to_string(_span.index_first(0u, 0ul, _span.length()), _buffer + 32));

    print("\n index_last [0]: ");
    print(to_string(_span.index_last (0u, 0ul, _span.length()), _buffer + 32));

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