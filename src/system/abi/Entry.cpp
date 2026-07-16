#include "system/abi/Entry.hpp"


#include "system/nt/Func.hpp"
namespace cmn::system::abi_
{
    extern "C"
    {
        using ctor_t = void(*)();

        __attribute__((section(".CRT$XCA"))) ctor_t __xc_a[] = { nullptr };

        __attribute__((section(".CRT$XCZ"))) ctor_t __xc_z[] = { nullptr };

        void __main()
        { }
    }

    extern "C"
    {
        using HANDLE = void*;
        using NTSTATUS = i32;
    }

    static void initialize_ctors()
    {
        for (ctor_t* p = __xc_a + 1; p < __xc_z; ++p)
        {
            if (*p) (*p)();
        }
    }

    extern "C" void _start()
    {
        initialize_ctors();

        NTSTATUS _result = main(0, nullptr);

        NtTerminateProcess((void*)-1, _result);

        while (true) { }
    }
}