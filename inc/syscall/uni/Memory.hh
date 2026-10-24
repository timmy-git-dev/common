#pragma once
#include "type/Alias.hh"

namespace cmn::syscall::uni::terminal
{
    void *allocate  (const s64 _length);
    void *deallocate(const s64 _length);
}