#pragma once
#include "system/Syscall.hpp"
#include "type/Alias.hpp"

namespace cmn::error
{
    inline void print_(const char *_text) // TODO: Replace with proper print function.
    {
        s64 _length = 0;
        while (_text[_length] != '\0') {_length++;}
        cmn::system::write(1, _text, _length);
    };
    [[gnu::noreturn]]
    inline void abort_(const char *_message, const char *_file, const int, const char *_function)
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