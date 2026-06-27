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
#include "system/platform/Arch.hpp"

namespace cmn::system::abi_
{
    [[noreturn]] inline void exit(i32 code)
    {
#if defined(CMN_SYSTEM_ARCH_X64)

        asm volatile
        (
            "movq %0, %%rdi\n\t"
            "movq $0x2000001, %%rax\n\t" // SYS_exit
            "syscall"
            :
            : "r"(static_cast<i64>(code))
            : "rax", "rdi", "rcx", "r11", "memory"
        );

#else
#error Unsupported macOS architecture.
#endif

        while (true) { }
    }

    extern "C" void _start()
    {
        exit(0);
    }
}
#endif