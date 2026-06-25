#pragma once
#include "type/Alias.hpp"

extern "C"
{
    i32  __cxa_atexit(void(*)(void*), void*, void*);
    void __cxa_finalize(void*);

    [[noreturn]]
    void __cxa_pure_virtual();
}