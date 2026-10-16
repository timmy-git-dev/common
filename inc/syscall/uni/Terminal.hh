#pragma once
#include "type/Alias.hh"

namespace cmn::syscall::uni::terminal
{
    // TODO: Return some universal error value.
    void print(const char *_output, const s64 _length);
    void read (const char *_buffer, const s64 _length);
}