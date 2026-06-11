#include "Main.hpp"
#include "system/CxxABI.hpp"
#include "system/EntryExit.hpp"
#include "system/Syscall.hpp"

namespace cmn::system
{
    void run_global_ctors()
    {
        for (void (**_instance)() = __init_array_start; _instance != __init_array_end; ++_instance)
        {
            (*_instance)();
        }
    }
    void run_global_dtors()
    {
        for (void (**_instance)() = __fini_array_end; _instance != __fini_array_start; )
        {
            (--_instance)[0]();
        }
    }

    extern "C"
    {
        [[gnu::used]]
        [[noreturn]]
        void _program(i32 _argCount, c08** _args)
        {
            cmn::system::run_global_ctors();

            i08 _exitCode = main(_argCount, _args);

            cmn::system::__cxa_finalize(nullptr);
            cmn::system::run_global_dtors();

            cmn::system::exit_group(_exitCode);
            __builtin_unreachable();
        }

        [[gnu::naked]]
        void _start()
        {
            asm volatile(
                "movq (%%rsp), %%rdi\n"      // argc
                "leaq 8(%%rsp), %%rsi\n"    // argv
                "andq $-16, %%rsp\n"
                "call _program\n"
                "ud2\n"
                :
                :
                : "rdi", "rsi", "memory"
            );
        }
    }
}