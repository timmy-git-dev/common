#include "sys/abi/InitFini.hpp"
#include "sys/platform/OS.hpp"

#if CMN_SYS_OS_LIN
namespace cmn::sys::abi
{
    using Constructor = void(*)();
    using Destructor  = void(*)();

    extern "C"
    {
        extern Constructor __init_array_start[];
        extern Constructor __init_array_end  [];

        extern Destructor __fini_array_start[];
        extern Destructor __fini_array_end  [];
    }

    void initialize_static_funcs()
    {
        for (Constructor* _ctor = __init_array_start; _ctor != __init_array_end; ++_ctor)
        {
            if (*_ctor != nullptr)
            {
                (*_ctor)();
            }
        }
    }

    void destruct_static_funcs()
    {
        for (Destructor* _dtor = __fini_array_start; _dtor != __fini_array_end; ++_dtor)
        {
            if (*_dtor != nullptr)
            {
                (*_dtor)();
            }
        }
    }
}
#elif CMN_SYS_OS_WIN
#elif CMN_SYS_OS_MAC
#endif