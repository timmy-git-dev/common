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
            case 0:  _code =  _char;                                                                                                                                             _index += 1; break;

            case 2:  _code = (_char & 0b00011111 <<  6) |  (_utf8[_index + 1] & 0b00111111);                                                                                     _index += 2; break;
            case 3:  _code = (_char & 0b00001111 << 12) | ((_utf8[_index + 1] & 0b00111111) <<  6) |  (_utf8[_index + 2] & 0b00111111);                                          _index += 3; break;
            case 4:  _code = (_char & 0b00000111 << 18) | ((_utf8[_index + 1] & 0b00111111) << 12) | ((_utf8[_index + 2] & 0b00111111) << 6) | (_utf8[_index + 3] & 0b00111111); _index += 4; break;

            default: return error::Result<u32, UTF>(0, UTF::INVALID_INPUT);
        }

        return error::Result<u32, UTF>(_code, UTF::NONE);
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