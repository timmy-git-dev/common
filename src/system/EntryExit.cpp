#include "system/EntryExit.hpp"
#include "system/CxxABI.hpp"

namespace cmn::system
{
    void run_global_ctors()
    {
        for (void (**_instance)() = __init_array_start; _instance != __init_array_end; ++_instance)
        {
            (*_instance)();
        }
    }
    void run_global_dtors()
    {
        for (void (**_instance)() = __fini_array_end; _instance != __fini_array_start; )
        {
            (--_instance)[0]();
        }
    }
}