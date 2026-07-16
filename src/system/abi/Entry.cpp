#include "system/platform/OS.hpp"
#include "system/abi/Entry.hpp"

namespace cmn::system::abi_
{
    #if CMN_SYSTEM_OS_LIN
    #include "system/syscall/Call.hpp"

    using ctor_t = void(*)();
    using dtor_t = void(*)();

    extern "C"
    {
        extern ctor_t __init_array_start[];
        extern ctor_t __init_array_end  [];

        extern dtor_t __fini_array_start[];
        extern dtor_t __fini_array_end  [];
    }

    static void init_ctors()
    {
        for (ctor_t* _ctor = __init_array_start; _ctor != __init_array_end; ++_ctor)
        {
            (*_ctor)();
        }
    }

    static void fini_dtors()
    {
        for (dtor_t* _dtor = __fini_array_start; _dtor != __fini_array_end; ++_dtor)
        {
            (*_dtor)();
        }
    }

    extern "C"
    void start__()
    {
        init_ctors();
        i32 _result = main(0, nullptr);
        fini_dtors();

        cmn::system::syscall::exit(_result);
        while (true) { }
    }
    #elif CMN_SYSTEM_OS_WIN
    #include "system/nt/Func.hpp"

    extern "C"
    {
        using ctor_t = void(*)();

        __attribute__((section(".CRT$XCA"))) ctor_t __xc_a[] = { nullptr };

        __attribute__((section(".CRT$XCZ"))) ctor_t __xc_z[] = { nullptr };

        void __main()
        { }
    }

    static void initialize_ctors()
    {
        for (ctor_t* p = __xc_a + 1; p < __xc_z; ++p)
        {
            if (*p) (*p)();
        }
    }

    extern "C" void start__()
    {
        // initialize_ctors();

        NTSTATUS _result = main(0, nullptr);

        NtTerminateProcess((void*)-1, _result);

        while (true) { }
    }
    #elif CMN_SYSTEM_OS_MAC
    #include "system/xnu/Call.hpp"

    extern "C" void start__()
    {
        i32 _result = main(0, nullptr);

        cmn::system::xnu::exit(_result);
        while (true) { }
    }
    #endif
}