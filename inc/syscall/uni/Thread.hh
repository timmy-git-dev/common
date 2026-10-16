#pragma once
#include "type/Alias.hh"

namespace cmn::syscall::uni::thread
{
    /// Exits all threads for this process with the given status code.
    [[noreturn]]
    void exit(const i32 _status);
}