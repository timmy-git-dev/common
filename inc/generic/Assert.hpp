#pragma once
#include "system/Syscall.hpp"
#include "type/Alias.hpp"

namespace cmn::generic
{
    #define COMPILER_ASSERT static_assert

    #ifndef RELEASE__
        inline void print_(const char *_text) // TODO: Replace with proper print function.
        {
            s64 _length = 0;
            while (_text[_length] != '\0') {_length++;}
            cmn::system::write(1, _text, _length);
        };
        inline void assert_(const char *_expression, const char *_message, bool _value, const char *_file, const int, const char *_function)
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
            // cmn::syscall::write(1, "\n LINE:       ", 14);
            // print_(_line);
            print_("\n");

            system::exit_group(1);
        }

        #define RUNTIME_ASSERT(_expression, _message) \
            cmn::generic::assert_(#_expression, _message, _expression, __FILE__, __LINE__, __func__)
    #else
        #define RUNTIME_ASSERT(_expression, _message) \
            void(0)
    #endif

    inline void abort_(const char *_message, const char *_file, const int, const char *_function)
    {
        print_("ABORT:");
        print_("\n MESSAGE:    ");
        print_(_message);
        print_("\n FILE:       ");
        print_(_file);
        print_("\n FUNC:       ");
        print_(_function);
        // cmn::syscall::write(1, "\n LINE:       ", 14);
        // print_(_line);
        print_("\n");

        system::exit_group(1);
    }

    #define ABORT(_message) \
        cmn::generic::abort_(_message, __FILE__, __LINE__, __func__)
}