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
}