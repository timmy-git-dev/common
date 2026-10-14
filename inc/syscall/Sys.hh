#pragma once
#include "type/Alias.hh"

namespace cmn::syscall
{
    [[noreturn]]
    void exit(const i32 _status);
}