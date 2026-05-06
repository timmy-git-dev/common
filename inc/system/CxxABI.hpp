#pragma once

namespace cmn::system
{
    extern "C"
    {
        using func = void(*)(void*);

        extern void (*__init_array_start[])();
        extern void (*__init_array_end  [])();
        extern void (*__fini_array_start[])();
        extern void (*__fini_array_end  [])();

        struct AtExitDtor
        {
            func  function;
            void* argument;
            void* sharedObj;
            bool  valid;
        };

        extern void* __dso_handle;

        int  __cxa_atexit  (func _function, void* _argument, void* _sharedObj);
        void __cxa_finalize(void* _sharedObj);

        int  __cxa_guard_acquire(unsigned long long* _guard);
        void __cxa_guard_release(unsigned long long* _guard);
        void __cxa_guard_abort  (unsigned long long* _guard);

        void __cxa_pure_virtual();
    }
}