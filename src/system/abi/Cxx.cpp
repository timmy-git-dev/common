#include "system/abi/Cxx.hpp"
#include "system/platform/Arch.hpp"

#if CMN_SYSTEM_ARCH_X64
    #define DEBUG_BREAK() asm volatile("int3")
#elif CMN_SYSTEM_ARCH_ARM64
    #define DEBUG_BREAK() asm volatile("brk #0")
#endif

extern "C"
{
    using dtor_t = void(*)(void*);

    struct cxa_entry
    {
        dtor_t dtor;
        void* object;
        void* dso;
    };

    static constexpr s64 MAX_CXA = 256;

    static cxa_entry cxa_table[MAX_CXA];
    static s64 cxa_count = 0;


    i32 __cxa_atexit(dtor_t dtor, void* object, void* dso)
    {
        DEBUG_BREAK();
        if (cxa_count >= MAX_CXA)
            return -1;

        cxa_table[cxa_count++] =
        {
            dtor,
            object,
            dso
        };

        return 0;
    }


    void __cxa_finalize(void* _dso)
    {
        for (s64 _i = cxa_count; _i-- > 0;)
        {
            cxa_entry& e = cxa_table[_i];

            if (!e.dtor)
                continue;

            if (_dso && e.dso != _dso)
                continue;

            dtor_t dtor = e.dtor;
            void* obj = e.object;

            e.dtor = nullptr;

            dtor(obj);
        }
    }


    [[noreturn]]
    void __cxa_pure_virtual()
    {
        __builtin_trap();
    }
}