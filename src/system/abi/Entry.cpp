#include "system/platform/OS.hpp"
#include "system/abi/Entry.hpp"

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

    static void initialize_ctors()
    {
        for (ctor_t* _ctor = __init_array_start; _ctor != __init_array_end; ++_ctor)
        {
            (*_ctor)();
        }
    }

    static void destruct_dtors()
    {
        for (dtor_t* _dtor = __fini_array_start; _dtor != __fini_array_end; ++_dtor)
        {
            (*_dtor)();
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
extern "C"
{
    // using ctor_t = void(*)();
    // using dtor_t = void(*)();

    // // You define these symbols yourself in linker script OR object file aggregation
    // extern ctor_t __init_array_start[];
    // extern ctor_t __init_array_end[];

    // extern dtor_t __fini_array_start[];
    // extern dtor_t __fini_array_end[];
}

extern "C" [[noreturn]] void ExitProcess(u32);
extern "C" __main() { }

// static void initialize_ctors()
// {
//     for (ctor_t* p = __init_array_start; p < __init_array_end; ++p)
//         if (*p) (*p)();
// }

// static void run_dtors()
// {
//     for (dtor_t* p = __fini_array_end; p != __fini_array_start; )
//     {
//         --p;
//         if (*p) (*p)();
//     }
// }

extern "C" [[noreturn]] void _start()
{
    // initialize_ctors();

    // i32 result = main(0, nullptr);
    main(0, nullptr);

    // run_dtors();

    ExitProcess(0);

    while (true) { }
}
#elif CMN_SYSTEM_OS_MAC
#include "system/platform/Arch.hpp"

namespace cmn::system::abi_
{
    [[noreturn]] inline void exit(i32 code)
    {
        #if defined(__x86_64__)
        asm volatile
        (
            "movq %0, %%rdi\n\t"
            "movq $0x2000001, %%rax\n\t" // SYS_exit
            "syscall"
            :
            : "r"(static_cast<i64>(code))
            : "rax", "rdi", "rcx", "r11", "memory"
        );
        #elif defined(__aarch64__)
        register i64 x0 asm("x0") = code;
        register i64 x16 asm("x16") = 1; // SYS_exit
        asm volatile
        (
            "svc #0x80"
            :
            : "r"(x0), "r"(x16)
            : "memory"
        );
        #else
        #error Unsupported macOS architecture.
        #endif
    }

    extern "C" void _start()
    {
        main(0, nullptr);

        exit(0);
        while (true) { }
    }
}
#endif