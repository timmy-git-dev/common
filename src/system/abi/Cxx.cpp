#include "system/abi/Cxx.hpp"

extern "C"
{
    i32 __cxa_atexit(void(*)(void*), void*, void*)
    {
        return 0;
    }

    void __cxa_finalize(void*)
    { }

    [[noreturn]]
    void __cxa_pure_virtual()
    {
        while (true) { }
    }
}