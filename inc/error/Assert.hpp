#pragma once
#include "error/Print.hpp"
#include "system/Syscall.hpp"
#include "type/Alias.hpp"
// TODO: Needs much better organization.
namespace cmn::error
{
    #define ASSERT_COMPILE(_expression, _message) \
        static_assert(_expression, _message)

    #ifdef DEBUG__
        inline void assert_runtime(const c08 *_expression, const c08 *_message, bool _value, const c08 *_file, const int, const c08 *_function)
        {
            if (_value) {return;}

            print_("ASSERT:");
            print_("\n MESSAGE:    ");
            print_(_message);
            print_("\n EXPRESSION: ");
            print_(_expression);
            print_("\n FILE:       ");
            print_(_file);
            print_("\n FUNC:       ");
            print_(_function);
            // print_("\n LINE:       ");
            // print_(_line);
            print_("\n");

            system::exit_group(1);
        }

        #define ASSERT_RUNTIME(_expression, _message) \
            error::assert_runtime_(#_expression, _message, _expression, __FILE__, __LINE__, __func__)
    #else
        #define ASSERT_RUNTIME(_expression, _message) \
            void(0)
    #endif
}