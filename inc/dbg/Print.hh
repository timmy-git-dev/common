#include "syscall/uni/Terminal.hh"

// NOTE/TODO: This is simply some helper funcs while developing this common library, for general use,
// these should be removed, and also likely added and cleaned up to some plugin which can be used for other plugin development.

namespace dbg
{
    static c08 buffer_[4096];

    inline s64 stringify(const c08* _x)
    {
        s64 _length = 0;

        while (_length < sizeof(buffer_) - 1 && _x[_length] != '\0')
        {
            buffer_[_length] = _x[_length];
            ++_length;
        }

        buffer_[_length] = '\0';
        return _length;
    }

    inline s64 stringify(c08* _x)
    {
        return stringify(static_cast<const c08*>(_x));
    }

    // Converts UTF-16 to UTF-8; replaces invalid surrogates with U+FFFD.
    inline s64 stringify(const c16* _x)
    {
        s64 _length = 0;

        while (*_x != u'\0')
        {
            u32 _code = u32(*_x++);

            if (_code >= 0xD800 && _code <= 0xDBFF)
            {
                const u32 _low = u32(*_x);

                if (_low >= 0xDC00 && _low <= 0xDFFF)
                {
                    ++_x;
                    _code = 0x10000
                          + ((_code - 0xD800) << 10)
                          + (_low - 0xDC00);
                }
                else
                    _code = 0xFFFD;
            }
            else if (_code >= 0xDC00 && _code <= 0xDFFF)
                _code = 0xFFFD;

            const s64 _bytes = _code < 0x80    ? 1
                             : _code < 0x800   ? 2
                             : _code < 0x10000 ? 3
                             :                  4;

            // Preserve complete UTF-8 sequences and space for NUL.
            if (_length + _bytes >= sizeof(buffer_))
                break;

            if (_bytes == 1)
                buffer_[_length++] = c08(_code);
            else
            {
                const u32 _prefix = _bytes == 2 ? 0xC0
                                  : _bytes == 3 ? 0xE0
                                  :               0xF0;

                buffer_[_length++] =
                    c08(_prefix | (_code >> (6 * (_bytes - 1))));

                for (s64 _remaining = _bytes - 1; _remaining != 0; --_remaining)
                {
                    buffer_[_length++] = c08(
                        0x80 | ((_code >> (6 * (_remaining - 1))) & 0x3F)
                    );
                }
            }
        }

        buffer_[_length] = '\0';
        return _length;
    }

    inline s64 stringify(c16* _x)
    {
        return stringify(static_cast<const c16*>(_x));
    }

    inline s64 stringify(b08 _x)
    {
        return stringify(_x ? "true" : "false");
    }

    inline s64 stringify(u64 _x)
    {
        c08 _digits[20];
        s64 _length = 0;

        do
        {
            _digits[_length++] = c08('0' + _x % 10);
            _x /= 10;
        } while (_x != 0);

        for (s64 _i = 0; _i < _length; ++_i)
            buffer_[_i] = _digits[_length - 1 - _i];

        buffer_[_length] = '\0';
        return _length;
    }

    inline s64 stringify(u32 _x) { return stringify(u64(_x)); }
    inline s64 stringify(u16 _x) { return stringify(u32(_x)); }
    inline s64 stringify(u08 _x) { return stringify(u16(_x)); }

    inline s64 prepend_minus_(s64 _length)
    {
        // Move the digits and terminating NUL.
        for (s64 _i = _length + 1; _i != 0; --_i)
            buffer_[_i] = buffer_[_i - 1];

        buffer_[0] = '-';
        return _length + 1;
    }

    inline s64 stringify(i64 _x)
    {
        const b08 _negative = _x < 0;

        // Unsigned subtraction safely handles the minimum signed value.
        const u64 _magnitude = _negative ? u64(0) - u64(_x) : u64(_x);
        const s64 _length = stringify(_magnitude);

        return _negative ? prepend_minus_(_length) : _length;
    }

    inline s64 stringify(i32 _x) { return stringify(i64(_x)); }
    inline s64 stringify(i16 _x) { return stringify(i32(_x)); }
    inline s64 stringify(i08 _x) { return stringify(i16(_x)); }

    template<typename Type_>
        requires (__is_enum(Type_))
    s64 stringify(Type_ _x)
    {
        return stringify(static_cast<__underlying_type(Type_)>(_x));
    }

    // IEEE-754 binary64: supports the full finite range without libc.
    inline s64 stringify(f64 _x)
    {
        const u64 _bits = __builtin_bit_cast(u64, _x);
        const b08 _negative = (_bits >> 63) != 0;
        const u32 _exponent = u32((_bits >> 52) & 0x7FF);
        u64 _significand = _bits & 0x000FFFFFFFFFFFFFull;

        if (_exponent == 0x7FF)
            return stringify(
                _significand ? "nan" : (_negative ? "-inf" : "inf")
            );

        const i32 _shift = _exponent
            ? i32(_exponent) - 1023 - 52
            : -1074;

        if (_exponent != 0)
            _significand |= u64(1) << 52;

        s64 _length;
        u32 _fraction = 0;

        if (_shift >= 0)
        {
            _length = stringify(_significand);

            // Multiply decimal digits by 2 for each remaining binary shift.
            for (i32 _bit = 0; _bit < _shift; ++_bit)
            {
                u32 _carry = 0;

                for (s64 _i = _length; _i != 0;)
                {
                    --_i;
                    const u32 _digit =
                        u32(buffer_[_i] - '0') * 2 + _carry;

                    buffer_[_i] = c08('0' + _digit % 10);
                    _carry = _digit / 10;
                }

                if (_carry != 0)
                {
                    for (s64 _i = _length; _i != 0; --_i)
                        buffer_[_i] = buffer_[_i - 1];

                    buffer_[0] = c08('0' + _carry);
                    ++_length;
                }
            }
        }
        else
        {
            const u32 _fractionBits = u32(-_shift);

            if (_fractionBits < 64)
            {
                _length = stringify(_significand >> _fractionBits);

                const u64 _mask = (u64(1) << _fractionBits) - 1;
                _fraction = u32(
                    ((_significand & _mask) * 1000) >> _fractionBits
                );
            }
            else
                _length = stringify(u64(0));
        }

        buffer_[_length++] = '.';
        buffer_[_length++] = c08('0' + _fraction / 100);
        buffer_[_length++] = c08('0' + _fraction / 10 % 10);
        buffer_[_length++] = c08('0' + _fraction % 10);
        buffer_[_length] = '\0';

        return _negative ? prepend_minus_(_length) : _length;
    }

    inline s64 stringify(f32 _x) { return stringify(f64(_x)); }



    template<typename... Types_>
    void print(const Types_&... _values)
    {
        auto _print = [&](const auto& _value)
        {
            if constexpr (requires { stringify(_value); })
            {
                const s64 _length = stringify(_value);
                cmn::syscall::uni::terminal::print(buffer_, _length);
            }
        };

        (_print(_values), ...);
    }

    // Repeated rescanning permits deferred macro expansion.
    #define CMN_EVAL0_(...) __VA_ARGS__
    #define CMN_EVAL1_(...) CMN_EVAL0_(CMN_EVAL0_(CMN_EVAL0_(__VA_ARGS__)))
    #define CMN_EVAL2_(...) CMN_EVAL1_(CMN_EVAL1_(CMN_EVAL1_(__VA_ARGS__)))
    #define CMN_EVAL3_(...) CMN_EVAL2_(CMN_EVAL2_(CMN_EVAL2_(__VA_ARGS__)))
    #define CMN_EVAL_(...)  CMN_EVAL3_(CMN_EVAL3_(CMN_EVAL3_(__VA_ARGS__)))

    #define CMN_PARENS_ ()

    #define CMN_EACH_(_macro, ...) \
        __VA_OPT__(CMN_EVAL_(CMN_EACH_STEP_(_macro, __VA_ARGS__)))

    #define CMN_EACH_STEP_(_macro, _first, ...) \
        _macro(_first) \
        __VA_OPT__(CMN_EACH_AGAIN_ CMN_PARENS_ (_macro, __VA_ARGS__))

    #define CMN_EACH_AGAIN_() CMN_EACH_STEP_

    #define CMN_PRINT_VALUE_(_value) \
        dbg::print("  ", #_value, ": ", (_value), "\n");

    #define PRINT(...) \
        do { \
            dbg::print(__FILE__, ":", u32(__LINE__), "\n"); \
            CMN_EACH_(CMN_PRINT_VALUE_, __VA_ARGS__) \
        } while (false)
}