#include "system/platform/OS.hpp"
#include "system/abi/Entry.hpp"

#if CMN_SYSTEM_OS_LIN
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
#elif CMN_SYSTEM_OS_WIN
namespace cmn::system::abi_
{
    extern "C"
    {
        using ctor_t = void(*)();

        __attribute__((section(".CRT$XCA"))) ctor_t __xc_a[] = { nullptr };

        __attribute__((section(".CRT$XCZ"))) ctor_t __xc_z[] = { nullptr };

        void __main()
        { }

        [[noreturn]] void ExitProcess(u32);
    }

    static void initialize_ctors()
    {
        for (ctor_t* p = __xc_a + 1; p < __xc_z; ++p)
        {
            if (*p) (*p)();
        }
    }

    extern "C" void mainCRTStartup()
    {
        initialize_ctors();

        i32 _result = main(0, nullptr);

        ExitProcess(static_cast<u32>(_result));

        while (true) { }
    }
}

#elif CMN_SYSTEM_OS_MAC
namespace cmn::system::abi_
{
    extern "C"
    {
        using ctor_t = void(*)();

        // Mach-O constructor sections
        extern ctor_t __mod_init_func_start[];
        extern ctor_t __mod_init_func_end[];

        extern ctor_t __mod_term_func_start[];
        extern ctor_t __mod_term_func_end[];

        [[noreturn]]
        void _exit(i32);
    }

    static void initialize_ctors()
    {
        for (ctor_t* p = __mod_init_func_start; p < __mod_init_func_end; ++p)
        {
            if (*p) (*p)();
        }
    }

    static void destruct_dtors()
    {
        for (ctor_t* p = __mod_term_func_start; p < __mod_term_func_end; ++p)
        {
            if (*p) (*p)();
        }
    }

    extern "C"
    void _start()
    {
        initialize_ctors();

        i32 result = main(0, nullptr);

        destruct_dtors();

        _exit(result);

        while (true) { }
    }
}
#endif