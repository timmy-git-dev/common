#include "sys/platform/os.hh"
#include "syscall/win/loader.hh"

#if CMN_SYS_OS_WIN

#include "syscall/win/func.hh"

namespace cmn::syscall::win
{
    const PEB  *get_peb()
    {
        return win_::peb;
    }

    void *get_nt_func(const char* _func, const s64 _funcLength)
    {
        for (u32 _i = 0; _i < win_::ntdll.count; ++_i)
        {
            c08* _name   = (c08*)win_::ntdll.ptr + win_::ntdll.names[_i];
            s64  _length = 0;
            while (_name[_length] != '\0')
            {
                ++_length;
            }

            if (_funcLength != _length)
            {
                continue;
            }

            if (__builtin_memcmp(_name, _func, _funcLength) == 0)
            {
                return (u08*)win_::ntdll.ptr + (win_::ntdll.functions[win_::ntdll.ordinals[_i]]);
            }
        }

        return nullptr;
    }
}

#endif