#include "system/abi/Entry.hpp"
#include "system/abi/Cxx.hpp"
#include "system/platform/OS.hpp"

#if CMN_SYSTEM_OS_LIN
#include "system/syscall/Call.hpp"

namespace cmn::system::abi_
{

    using ctor_t = void(*)();
    using dtor_t = void(*)();

    extern "C"
    {
        extern ctor_t __init_array_start[];
        extern ctor_t __init_array_end  [];

        extern dtor_t __fini_array_start[];
        extern dtor_t __fini_array_end  [];
    }

    void init_ctors()
    {
        for (ctor_t* _ctor = __init_array_start; _ctor != __init_array_end; ++_ctor)
        {
            if (*_ctor)
                (*_ctor)();
        }
    }

    void fini_dtors()
    {
        for (dtor_t* _dtor = __fini_array_start; _dtor != __fini_array_end; ++_dtor)
        {
            if (*_dtor)
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
}
#elif CMN_SYSTEM_OS_WIN
// #include "syscall/win/Resolve.hpp"
#include "syscall/win/Type.hpp"
#include "syscall/win/Nt.hpp"

namespace cmn::system::abi_
{
    extern "C" void __main() { }

    using ctor_t = void(*)();
    using dtor_t = void(*)();

    extern "C"
    {
        __attribute__((section(".CRT$XCA"))) ctor_t __xc_a = nullptr;
        __attribute__((section(".CRT$XCZ"))) ctor_t __xc_z = nullptr;
        __attribute__((section(".CRT$XTA"))) dtor_t __xt_a = nullptr;
        __attribute__((section(".CRT$XTZ"))) dtor_t __xt_z = nullptr;
    }

    void init_ctors()
    {
        for (ctor_t* _ctor = &__xc_a + 1; _ctor < &__xc_z; ++_ctor)
        {
            if (*_ctor)
                (*_ctor)();
        }
    }

    void fini_dtors()
    {
        for (dtor_t* _dtor = &__xt_a + 1; _dtor < &__xt_z; ++_dtor)
        {
            if (*_dtor)
                (*_dtor)();
        }
    }

    int test(int _result)
    {
        return _result;
    }

    extern "C" void start__()
    {
        // init_ctors();

        NTSTATUS _result = main(0, nullptr);

        // __cxa_finalize(nullptr);
        // fini_dtors();

        // cmn::syscall::win_::resolve_proc_address("NtTerminateProcess", 18);
        test(_result);
        syscall::win::nt_terminate_process((void*)-1, 7);
    }
}
#elif CMN_SYSTEM_OS_MAC
#include "system/xnu/Call.hpp"

namespace cmn::system::abi_
{
    extern "C" void start__()
    {
        i32 _result = main(0, nullptr);

        cmn::system::xnu::exit(_result);
        while (true) { }
    }
}
#endif