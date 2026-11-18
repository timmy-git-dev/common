#include "sys/platform/os.hh"
#include "syscall/win/type.hh"

#if CMN_SYS_OS_WIN

#include "syscall/win/loader.hh"
#include "sys/platform/arch.hh"

namespace cmn::syscall::win_
{
    /// Obtains the PEB from a segment register or TEB.
    PEB *resolve_peb()
    {
        #if CMN_SYS_ARCH_X64
        PEB *_peb;
        asm volatile
        (
            "mov %%gs:0x60, %0"
            : "=r"(_peb)
        );
        return _peb;
        #elif CMN_SYS_ARCH_ARM64
        volatile TEB* _teb;
        asm volatile
        (
            "mov %0, x18"
            : "=r"(_teb)
        );
        return (PEB*)_teb->ProcessEnvironmentBlock;

        #endif
    };

    /// Obtains an existing library from the PEB.
    LibraryExport resolve_library(const c08 *_libraryName, const s64 _libraryLength)
    {
        const LIST_ENTRY *_head = &peb->Ldr->InLoadOrderModuleList;
        for (const LIST_ENTRY* _entry = _head->Flink; _entry != _head; _entry = _entry->Flink)
        {
            const LDR_DATA_TABLE_ENTRY *_entryLib    = reinterpret_cast<const LDR_DATA_TABLE_ENTRY*>(_entry);
            const c16                  *_entryName   = _entryLib->BaseDllName.Buffer;
            const s64                   _entryLength = _entryLib->BaseDllName.Length / 2;

            if (_entryLength != _libraryLength)
            {
                continue;
            }

            bool _equal = true;
            for (s64 _i = 0; _i < _libraryLength; ++_i)
            {
                if ((c08)_entryName[_i] != _libraryName[_i])
                {
                    _equal = false;
                    break;
                }
            }

            if (_equal)
            {
                void                   *_ptr       = _entryLib->DllBase;
                IMAGE_EXPORT_DIRECTORY *_directory = (IMAGE_EXPORT_DIRECTORY*)((u08*)_ptr + ((IMAGE_NT_HEADERS64*)((u08*)_ptr + ((IMAGE_DOS_HEADER*)_ptr)->e_lfanew))->OptionalHeader.DataDirectory[0].VirtualAddress);

                return LibraryExport
                {
                    .ptr       = _ptr,
                    .names     = (u32*)(_directory->AddressOfNames        + (u08*)_ptr),
                    .functions = (u32*)(_directory->AddressOfFunctions    + (u08*)_ptr),
                    .ordinals  = (u16*)(_directory->AddressOfNameOrdinals + (u08*)_ptr),
                    .count     =        _directory->NumberOfNames,
                };

                break;
            }
        }

        return { };
    };

    PEB           *peb   = nullptr;
    LibraryExport  ntdll = { };


    void resolve_nt()
    {
        // Resolve peb.
        peb   = resolve_peb();
        // Resolve ntdll.dll.
        ntdll = resolve_library("ntdll.dll", 9);
    }
}

#endif