#pragma once
#include "system/Syscall.hpp"
#include "type/Alias.hpp"
// TODO: TEMP FILE FOR PRINT, REPLACE WITH PROPER PRINT.
namespace cmn::error
{
    inline void print_(const c08 *_text) // TODO: Replace with proper print function.
    {
        s64 _length = 0;
        while (_text[_length] != '\0') {_length++;}
        system::write(1, _text, _length);
    };
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
    constexpr c08* to_string(u32 _value, c08* _buffer)
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
}