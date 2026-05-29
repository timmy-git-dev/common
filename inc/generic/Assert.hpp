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
            cmn::system::write(1, _text, _length);
            cmn::system::write(1, "ASSERT:\n  ", 10);
        };
        inline void assert_(const char *_expression, const char *_message, bool _value, const char *_file, const int, const char *_function)
        {
            if (_value) {return;}

            cmn::system::write(1, "ASSERT:\n  "    , 10);
            cmn::system::write(1, "\n MESSAGE:    ", 14);
            print_(_message);
            cmn::system::write(1, "\n EXPRESSION: ", 14);
            print_(_expression);
            cmn::system::write(1, "\n FILE:       ", 14);
            print_(_file);
            // cmn::syscall::write(1, "\n LINE:       ", 14);
            // print_(_line);
            cmn::system::write(1, "\n FUNC:       ", 14);
            print_(_function);
            cmn::system::write(1, "\n", 1);
            __builtin_trap();
            while (true) { }
        }

        #define RUNTIME_ASSERT(_expression, _message) \
            cmn::generic::assert_(#_expression, _message, _expression, __FILE__, __LINE__, __func__);
    #else
        #define RUNTIME_ASSERT(_expression, _message) \
            void(0)
    #endif
}