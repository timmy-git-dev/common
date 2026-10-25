#include "error/Result.hh"
#include "syscall/util/UTF.hh"

namespace cmn::syscall::util::utf
{
    error::Result<u32, UTF> str8_to_code(const c08 *_utf8 , s64 &_index)
    {
        u32 _code;
        u32 _char = _utf8[_index];

        switch (__builtin_clz((~_char & 0xFF) << 24))
        {
            case 0:  _code = u32(_char);                                                                                                                                                _index += 1; break;

            case 2:  _code = u32(_char & 0b00011111) <<  6 | u32(_utf8[_index + 1] & 0b00111111);                                                                                        _index += 2; break;
            case 3:  _code = u32(_char & 0b00001111) << 12 | u32(_utf8[_index + 1] & 0b00111111) <<  6 | u32(_utf8[_index + 2] & 0b00111111);                                            _index += 3; break;
            case 4:  _code = u32(_char & 0b00000111) << 18 | u32(_utf8[_index + 1] & 0b00111111) << 12 | u32(_utf8[_index + 2] & 0b00111111) << 6 | u32(_utf8[_index + 3] & 0b00111111); _index += 4; break;

            default: return error::Result<u32, UTF>(0, UTF::INVALID_FORMAT);
        }

        return error::Result<u32, UTF>(_code, UTF::NONE);
    }
    error::Result<u32, UTF> str16_to_code(const c16 *_utf16, s64 &_index)
    {
        u32 _char = _utf16[_index++];
        u32 _code = _char;

        if (_char >= 0xD800 && _char <= 0xDBFF)
        {
            u32 _next = _utf16[_index++];

            if (_next < 0xDC00 || _next > 0xDFFF)
                return error::Result<u32, UTF>(0, UTF::INVALID_FORMAT);

            _code = 0x10000 | ((_char & 0x3FF) << 10) | (_next & 0x3FF);
        }
        else if (_char >= 0xDC00 && _char <= 0xDFFF)
        {
            return error::Result<u32, UTF>(0, UTF::INVALID_FORMAT);
        }

        return error::Result<u32, UTF>(_code, UTF::NONE);
    }

    void code_to_str8(const u32 _code, c08 *_utf8, s64 &_index)
    {
        if (_code <= 0x7F)
        {
            _utf8[_index++] = c08(_code);
        }
        else if (_code <= 0x7FF)
        {
            _utf8[_index++] = c08(0b11000000 |  (_code >> 6));
            _utf8[_index++] = c08(0b10000000 |  (_code & 0x3F));
        }
        else if (_code <= 0xFFFF)
        {
            _utf8[_index++] = c08(0b11100000 |  (_code >> 12));
            _utf8[_index++] = c08(0b10000000 | ((_code >> 6) & 0x3F));
            _utf8[_index++] = c08(0b10000000 |  (_code & 0x3F));
        }
        else
        {
            _utf8[_index++] = c08(0b11110000 |  (_code >> 18));
            _utf8[_index++] = c08(0b10000000 | ((_code >> 12) & 0x3F));
            _utf8[_index++] = c08(0b10000000 | ((_code >> 6) & 0x3F));
            _utf8[_index++] = c08(0b10000000 |  (_code & 0x3F));
        }
    }
    void code_to_str16(const u32 _code, c16 *_utf16, s64 &_index)
    {
        if (_code > 0b1111111111111111)
        {
            _utf16[_index++] = c16(0b1101100000000000 | ((_code - 0x10000) >> 10));
            _utf16[_index++] = c16(0b1101110000000000 | ((_code - 0x10000) & 0b1111111111));
        }
        else
        {
            _utf16[_index++] = _code;
        }
    }
}