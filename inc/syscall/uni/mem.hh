#pragma once
#include "error/status.hh"
#include "error/result.hh"
#include "type/alias.hh"

namespace cmn::syscall::uni::mem
{
    enum class Memory : error::Code
    {
        NONE = 0,
    };

    error::Result<void *, Memory> allocate(const s64 _length);
    error::Result<void  , Memory> free    (void *_memory, s64 _length);
}