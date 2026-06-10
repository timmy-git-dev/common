#pragma once
#include "system/Syscall.hpp"
#include "type/Alias.hpp"

namespace cmn::terminal
{
    inline void read(c08 *_output, const s64 _length)
    {
        system::read(0, _output, _length);
    }
    inline void write(const c08 *_text, const s64 _length)
    {
        system::write(1, _text, _length);
    }
}