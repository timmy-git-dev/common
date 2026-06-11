#pragma once
#include "type/Alias.hpp"

namespace cmn::system
{
    void run_global_ctors();
    void run_global_dtors();

    extern "C"
    {
        [[gnu::used]]
        [[noreturn]]
        void _program(const i32 _argCount, const c08** _args);
        [[gnu::naked]]
        void _start();
    }
}