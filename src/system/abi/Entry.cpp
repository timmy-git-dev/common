#include "system/abi/Entry.hpp"
#include "system/syscall/Call.hpp"

namespace cmn::system::abi_
{
    extern "C"
    {
        using ctor_t = void(*)();

        extern ctor_t __init_array_start[];
        extern ctor_t __init_array_end[];

        extern ctor_t __fini_array_start[];
        extern ctor_t __fini_array_end[];
    }

    static void initialize_ctors()
    {
        for (ctor_t* p = __init_array_start; p != __init_array_end; ++p)
        {
            (*p)();
        }
    }

    static void destruct_dtors()
    {
        for (ctor_t* p = __fini_array_start; p != __fini_array_end; ++p)
        {
            (*p)();
        }
    }

    extern "C"
    void _start()
    {
        initialize_ctors();

        i32 _result = main(0, nullptr);

        destruct_dtors();

        cmn::system::syscall::exit(_result);

        while (true) { }
    }
}
