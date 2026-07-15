#include "system/abi/Cxx.hpp"

extern "C"
{
    // using dtor_t = void(*)(void*);

    // struct cxa_entry
    // {
    //     dtor_t dtor;
    //     void* object;
    //     void* dso;
    // };

    // static constexpr s64 MAX_CXA = 256;

    // static cxa_entry cxa_table[MAX_CXA];
    // static s64 cxa_count = 0;


    // i32 __cxa_atexit(dtor_t dtor, void* object, void* dso)
    // {
    //     if (cxa_count >= MAX_CXA)
    //         return -1;

    //     cxa_table[cxa_count++] =
    //     {
    //         dtor,
    //         object,
    //         dso
    //     };

    //     return 0;
    // }


    // void __cxa_finalize(void* dso)
    // {
    //     for (s64 i = cxa_count - 1; i >= 0; --i)
    //     {
    //         cxa_entry& e = cxa_table[i];

    //         if (!e.dtor)
    //             continue;

    //         if (dso && e.dso != dso)
    //             continue;

    //         dtor_t dtor = e.dtor;
    //         void* obj = e.object;

    //         e.dtor = nullptr;

    //         dtor(obj);
    //     }
    // }


    // [[noreturn]]
    // void __cxa_pure_virtual()
    // {
    //     while (true) {}
    // }
}