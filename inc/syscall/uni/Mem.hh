#pragma once
#include "error/Error.hh"
#include "error/Result.hh"
#include "type/Alias.hh"

namespace cmn::syscall::uni::mem
{
    enum class Memory : error::Code
    {
        NONE = 0,
    };

    error::Result<void *, Memory> allocate(const s64 _length);
    error::Result<void  , Memory> free    (void *_memory, s64 _length);
}