#pragma once
#include <cstdio>
#include <cstdlib>

namespace cmn::generic
{
#if defined(NDEBUG)
    #define ASSERT(_expression, _message) \
        void(0)
#else
    #if defined(_MSC_VER)
        #define DEBUG_BREAK() __debugbreak()
    #else
        #define DEBUG_BREAK() __builtin_trap()
    #endif

    constexpr void assert_(const char* _expression, const char* _message, bool _value, const char* _file, const int _line, const char* _function)
    {
        if (!_value)
        {
            std::fprintf
            (
                stderr,
                "ASSERT FAILED -\n"
                "  Expression: %s\n"
                "  Message   : %s\n"
                "  File      : %s\n"
                "  Line      : %d\n"
                "  Function  : %s\n",
                _expression, _message, _file, _line, _function
            );
            std::fflush(stderr);

            DEBUG_BREAK();
            std::abort();
        }
    }

    #define ASSERT(_expression, _message) \
        cmn::generic::assert_(#_expression, _message, _expression, __FILE__, __LINE__, __func__);
#endif
}