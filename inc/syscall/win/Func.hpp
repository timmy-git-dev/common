#pragma once
#include "syscall/win/Type.hpp"

namespace cmn::syscall::win_
{
    extern PEB                    *PROCESS_ENV_BLOCK;

    extern void                   *NTDLL;
    extern IMAGE_EXPORT_DIRECTORY *EXPORT_DIRECTORY;
    extern u32                    *EXPORT_NAMES;
    extern u32                    *EXPORT_FUNCTIONS;
    extern u16                    *EXPORT_ORDINALS;
    extern u32                     EXPORT_COUNT;

    PEB  *resolve_peb         ();
    void *resolve_library     (const c08 *_libraryName);
    void *resolve_proc_address(const char* _func, const s64 _funcLength);
}