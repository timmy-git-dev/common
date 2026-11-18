#pragma once
#include "syscall/win/type.hh"

namespace cmn::syscall::win
{
    /// Obtains the Process Environment Block from a specific address in memory.
    const PEB  *get_peb();
    /// Obtains the function address of a windows NT function from ntdll.dll.
          void *get_nt_func(const c08 *_func, const s64 _length);
}