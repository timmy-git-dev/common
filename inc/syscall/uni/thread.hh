#pragma once
#include "type/alias.hh"

namespace cmn::syscall::uni::thread
{
    /// Exits all threads for this process with the given status code.
    [[noreturn]]
    void exit(const i32 _status);
}