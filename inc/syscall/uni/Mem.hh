#pragma once
#include "error/Error.hh"
#include "error/Result.hh"
#include "type/Alias.hh"

namespace cmn::syscall::uni::mem
{
    enum class MEMORY : error::ERROR
    {
        NONE = 0,
    };

    error::Result<void *, MEMORY> allocate(const s64 _length);
    error::Result<void  , MEMORY> free    (void *_memory, s64 _length);
}