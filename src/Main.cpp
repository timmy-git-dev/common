#include "allocator/Arena.hpp"
#include "allocator/Region.hpp"
#include "container/Array.hpp"
#include "container/Span.hpp"
#include "container/Array.hpp"
#include "container/String.hpp"
#include "math/Util.hpp"
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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmultichar"
static constexpr u16 CHARS2_10_[100] =
{
    '00', '10', '20', '30', '40', '50', '60', '70', '80', '90',
    '01', '11', '21', '31', '41', '51', '61', '71', '81', '91',
    '02', '12', '22', '32', '42', '52', '62', '72', '82', '92',
    '03', '13', '23', '33', '43', '53', '63', '73', '83', '93',
    '04', '14', '24', '34', '44', '54', '64', '74', '84', '94',
    '05', '15', '25', '35', '45', '55', '65', '75', '85', '95',
    '06', '16', '26', '36', '46', '56', '66', '76', '86', '96',
    '07', '17', '27', '37', '47', '57', '67', '77', '87', '97',
    '08', '18', '28', '38', '48', '58', '68', '78', '88', '98',
    '09', '19', '29', '39', '49', '59', '69', '79', '89', '99',
};
#pragma GCC diagnostic pop
c08* to_string(u32 _value, c08* _buffer)
{
    u32 _length =
        (_value >= 1000000000) ? 10 :
        (_value >= 100000000)  ? 9  :
        (_value >= 10000000)   ? 8  :
        (_value >= 1000000)    ? 7  :
        (_value >= 100000)     ? 6  :
        (_value >= 10000)      ? 5  :
        (_value >= 1000)       ? 4  :
        (_value >= 100)        ? 3  :
        (_value >= 10)         ? 2  : 1;

    u16* _buff = reinterpret_cast<u16*>(_buffer + (_length & 1));

    u32 _i = _length >> 1;
    while (_i > 0)
    {
        u32 _quo = _value / 100;
        u32 _rem = _value - _quo * 100;
        _value = _quo;

        _buff[--_i] = CHARS2_10_[_rem];
    }

    if (_length & 1) _buffer[0] = '0' + _value;
    _buffer[_length] = '\0';

    return _buffer;
}

i08 main()
{
    c08 _buffer[32];
    c08* _end = _buffer + 32;

    cmn::allocator::Arena  _arena (4096);
    cmn::allocator::Region _region( 512);

    cmn::container::Span <i32, 32>                     _span(0);
    cmn::container::Array<f32, cmn::allocator::Region> _array(_region, 32, 32, 0.0f);
    cmn::container::String<cmn::allocator::Region>     _string(_region, "Hello, world!\n");

    _string.c_string(_buffer);
    print(_buffer);

    print("Array:");
    print("\n fill:        ");
    _array.fill(6.9f, 7, 19);
    print("[");
    for (const f32& _x : _array)
    {
        print(to_fstring(_x, _end));
        print(", ");
    }
    if (_array.length() > 0) {print(to_fstring(_array[_array.length() - 1], _end));}
    print("]");

    print("\n replace:     ");
    _array.replace(6.9f, 4.2f, 14, 23);
    print("[");
    for (f32& _x : _array)
    {
        print(to_fstring(_x, _end));
        print(", ");
    }
    if (_array.length() > 0) {print(to_fstring(_array[_array.length() - 1], _end));}
    print("]");


    print("\n contains:    ");
    print(_array.contains          (0u, 0ul, _array.length()) ? "true" : "false");

    print("\n count:       ");
    print(to_string(_array.count   (0u, 0ul, _array.length()), _buffer));

    print("\n index_first: ");
    print(to_string(_array.index_first(0u, 0ul, _array.length()), _buffer));

    print("\n index_last:  ");
    print(to_string(_array.index_last (0u, 0ul, _array.length()), _buffer));

    print("\n");


    print("Span:");
    print("\n fill:        ");
    _span.fill(472, 7, 19);
    print("[");
    for (const i32& _x : _span)
    {
        print(to_string(_x, _buffer));
        print(", ");
    }
    if (_span.length() > 0) {print(to_string(_span[_span.length() - 1], _buffer));}
    print("]");

    print("\n replace:     ");
    _span.replace(472, 748912, 14, 23);
    print("[");
    for (i32& _x : _span)
    {
        print(to_string(_x, _buffer));
        print(", ");
    }
    if (_span.length() > 0) {print(to_string(_span[_span.length() - 1], _buffer));}
    print("]");


    print("\n contains:    ");
    print(_span.contains          (0u, 0ul, _span.length()) ? "true" : "false");

    print("\n count:       ");
    print(to_string(_span.count   (0u, 0ul, _span.length()), _buffer));

    print("\n index_first: ");
    print(to_string(_span.index_first(0u, 0ul, _span.length()), _buffer));

    print("\n index_last:  ");
    print(to_string(_span.index_last (0u, 0ul, _span.length()), _buffer));

    print("\n");


    for (s64 _i = 0; _i < _region.capacity();)
    {
        s64 _length = static_cast<s64>(cmn::math::abs(reinterpret_cast<i64*>(_region.heap())[_i]));
        _i += sizeof(s64);

        print("[");
        print(to_string(     _length, _buffer));
        print(": ");
        print(to_string(_i          , _buffer));
        print("-");
        print(to_string(_i + _length - 1, _buffer));
        print("] ");

        _i += _length;
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