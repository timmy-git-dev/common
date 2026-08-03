#include "abi/Entry.hpp"
#include "abi/Cxa.hpp"
#include "abi/InitFini.hpp"

#include "syscall/lin/Call.hpp" // TODO: replace syscall with universal "exit".

extern "C" void start__()
{
    cmn::sys::abi::initialize_static_funcs();

    i32 _result = main(0, nullptr);

    cmn::sys::abi::destruct_static_funcs(       );
    cmn::sys::abi::destruct_static_vars (nullptr);

    cmn::syscall::exit(_result);
    while (true) { }
}


// TODO: implement mac's + windows' InitFini.cpp:

// extern "C" void __main() { }

// using ctor_t = void(*)();
// using dtor_t = void(*)();

// extern "C"
// {
//     __attribute__((section(".CRT$XCA"))) ctor_t __xc_a = nullptr;
//     __attribute__((section(".CRT$XCZ"))) ctor_t __xc_z = nullptr;
//     __attribute__((section(".CRT$XTA"))) dtor_t __xt_a = nullptr;
//     __attribute__((section(".CRT$XTZ"))) dtor_t __xt_z = nullptr;
// }

// void init_ctors()
// {
//     for (ctor_t* _ctor = &__xc_a + 1; _ctor < &__xc_z; ++_ctor)
//     {
//         if (*_ctor)
//             (*_ctor)();
//     }
// }

// void fini_dtors()
// {
//     for (dtor_t* _dtor = &__xt_a + 1; _dtor < &__xt_z; ++_dtor)
//     {
//         if (*_dtor)
//             (*_dtor)();
//     }
// }