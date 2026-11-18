#pragma once
#include "syscall/win/type.hh"

// I don't really like this setup because it involves calling this at the beginning and unless known it does so, is
// just magic functions basically, but for now it's better than checking each time if it's already been resolved.

namespace cmn::syscall::win_
{
    struct LibraryExport
    {
        /// The address of the export directory.
        void *ptr;
        /// The relative buffer name addresses of each function.
        u32  *names;
        /// The relative proc addresses of each function.
        u32  *functions;
        /// The index of the function array.
        u16  *ordinals;
        /// The amount of names, functions, and ordinals contained within the DLL's export directory.
        u32   count;
    };

    extern PEB           *peb;
    extern LibraryExport  ntdll;

    /// Resolves internal globals for `func.hh` to use for obtaining Nt* funcction proc addresses.
    void resolve_nt();
}