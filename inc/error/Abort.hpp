#pragma once
#include "error/Print.hpp"
#include "system/Syscall.hpp"
#include "type/Alias.hpp"
// TODO: Needs much better organization.
namespace cmn::error
{
    [[gnu::noreturn]]
    inline void abort_(const c08 *_message, const c08 *_file, const int, const c08 *_function)
    {
        print_("ABORT:");
        print_("\n MESSAGE:    ");
        print_(_message);
        print_("\n FILE:       ");
        print_(_file);
        print_("\n FUNC:       ");
        print_(_function);
        // print_("\n LINE:       ");
        // print_(_line);
        print_("\n");

        system::exit_group(1);
        __builtin_unreachable();
    }

    #define ABORT(_message) \
        cmn::error::abort_(_message, __FILE__, __LINE__, __func__)
}