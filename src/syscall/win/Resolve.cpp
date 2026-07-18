#include "syscall/win/Resolve.hpp"
#include "system/platform/Arch.hpp"

namespace cmn::syscall::win_
{
    // TODO: implement decent mem* funcs and organize them somewhere else.
    inline s64 memcmp(const void* _a, const void* _b, s64 _length)
    {
        const u08* _x = (const u08*)_a;
        const u08* _y = (const u08*)_b;

        for (s64 _i = 0; _i < _length; ++_i)
        {
            if (_x[_i] != _y[_i])
            {
                return _x[_i] - _y[_i];
            }
        }

        return 0;
    }

    PEB                    *PROCESS_ENV_BLOCK = nullptr;

    void                   *NTDLL             = nullptr;
    IMAGE_EXPORT_DIRECTORY *EXPORT_DIRECTORY  = nullptr;
    u32                    *EXPORT_NAMES      = nullptr;
    u32                    *EXPORT_FUNCTIONS  = nullptr;
    u16                    *EXPORT_ORDINALS   = nullptr;
    u32                     EXPORT_COUNT      = 0;


    PEB *resolve_peb()
    {
        #if CMN_SYSTEM_ARCH_X64
        PEB *_peb;
        asm volatile
        (
            "mov %%gs:0x60, %0"
            : "=r"(_peb)
        );
        return _peb;
        #elif CMN_SYSTEM_ARCH_ARM64
        void* _teb;

        asm volatile
        (
            "mrs %0, tpidr_el0"
            : "=r"(_teb)
        );

        return (PEB*)7;
        // return (PEB*)(*(void**)((u08*)_teb + 0x60));
        #endif

    };

    void *resolve_library(const c08 *_libraryName)
    {
        s64 _libraryLength = 0;
        while (_libraryName[_libraryLength] != '\0') ++_libraryLength;

        const LIST_ENTRY *_head = &PROCESS_ENV_BLOCK->Ldr->InLoadOrderModuleList;

        for (const LIST_ENTRY* _entry = _head->Flink; _entry != _head; _entry = _entry->Flink)
        {
            const LDR_DATA_TABLE_ENTRY *_lib = reinterpret_cast<const LDR_DATA_TABLE_ENTRY*>(_entry);

            c08 _entryName[64];
            s64 _entryLength = _lib->BaseDllName.Length / 2;

            if (_entryLength != _libraryLength)
                continue;

            // TODO: probably completely useless.
            for (u32 _i = 0; _i < _entryLength; ++_i)
            {
                c08 _char = (c08)_lib->BaseDllName.Buffer[_i];
                if (_char >= 'A' && _char <= 'Z')
                    _char += 'a' - 'A';
                _entryName[_i] = _char;
            }
            _entryName[_entryLength] = '\0';

            if (!memcmp(_entryName, _libraryName, _entryLength))
                return _lib->DllBase;
        }

        // TODO: just exit here, if you can't even call a single Nt function then th program is fucking useless lmao.
        return (void*)nullptr; // TODO: add `nul` alias for nullptr.
    };

    void *resolve_proc_address(const char* _func, const s64 _funcLength)
    {
        if (!PROCESS_ENV_BLOCK)
        {
            PROCESS_ENV_BLOCK = resolve_peb();
            // if (!PROCESS_ENV_BLOCK      ) return (void*)1;
            NTDLL             = resolve_library("ntdll.dll");
            // if (!PROCESS_ENV_BLOCK      ) return (void*)2;
            EXPORT_DIRECTORY = (IMAGE_EXPORT_DIRECTORY*)((u08*)NTDLL + ((IMAGE_NT_HEADERS64*)((u08*)NTDLL + ((IMAGE_DOS_HEADER*)NTDLL)->e_lfanew))->OptionalHeader.DataDirectory[0].VirtualAddress);
            // if (!PROCESS_ENV_BLOCK      ) return (void*)3;
            EXPORT_NAMES     = (u32*)((u08*)NTDLL + EXPORT_DIRECTORY->AddressOfNames);
            // if (!PROCESS_ENV_BLOCK      ) return (void*)4;
            EXPORT_FUNCTIONS = (u32*)((u08*)NTDLL + EXPORT_DIRECTORY->AddressOfFunctions);
            // if (!PROCESS_ENV_BLOCK      ) return (void*)5;
            EXPORT_ORDINALS  = (u16*)((u08*)NTDLL + EXPORT_DIRECTORY->AddressOfNameOrdinals);
            // if (!PROCESS_ENV_BLOCK      ) return (void*)6;
            EXPORT_COUNT     =                      EXPORT_DIRECTORY->NumberOfNames;
            // if (!PROCESS_ENV_BLOCK      ) return (void*)7;
        }

        for (u32 _i = 0; _i < EXPORT_COUNT; ++_i)
        {
            c08* _name   = (c08*)NTDLL + EXPORT_NAMES[_i];
            s64  _length = 0;
            while (_name[_length] != '\0')
            {
                ++_length;
            }

            if (_funcLength != _length)
            {
                continue;
            }

            if (!memcmp(_name, _func, _funcLength))
            {
                return (u08*)NTDLL + EXPORT_FUNCTIONS[EXPORT_ORDINALS[_i]];
            }
        }

        return (void*)nullptr;
    }
}