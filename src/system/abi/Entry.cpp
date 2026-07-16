#include "system/platform/OS.hpp"
#include "system/abi/Entry.hpp"

namespace cmn::system::abi_
{
    #if CMN_SYSTEM_OS_LIN
    #include "system/syscall/Call.hpp"

    using ctor_t = void(*)();
    using dtor_t = void(*)();

    extern "C"
    {
        extern ctor_t __init_array_start[];
        extern ctor_t __init_array_end  [];

        extern dtor_t __fini_array_start[];
        extern dtor_t __fini_array_end  [];
    }

    static void init_ctors()
    {
        for (ctor_t* _ctor = __init_array_start; _ctor != __init_array_end; ++_ctor)
        {
            (*_ctor)();
        }
    }

    static void fini_dtors()
    {
        for (dtor_t* _dtor = __fini_array_start; _dtor != __fini_array_end; ++_dtor)
        {
            (*_dtor)();
        }
    }

    extern "C"
    void start__()
    {
        init_ctors();
        i32 _result = main(0, nullptr);
        fini_dtors();

        cmn::system::syscall::exit(_result);
        while (true) { }
    }
    #elif CMN_SYSTEM_OS_WIN
    extern "C" void __main() { }



    // Minimal x64 Windows.
    // No includes.

    // ---------- Types ----------
    using i32 = signed int;
    using u16 = unsigned short;
    using u32 = unsigned int;
    using u64 = unsigned long;
    using s64 = __SIZE_TYPE__;
    using c08 = char;

    #define NULL s64(0)

    // ---------- PE ----------
    struct LIST_ENTRY
    {
        LIST_ENTRY* Flink;
        LIST_ENTRY* Blink;
    };

    struct UNICODE_STRING
    {
        u16 Length;
        u16 MaximumLength;
        u16* Buffer;
    };

    struct LDR_DATA_TABLE_ENTRY
    {
        LIST_ENTRY     InLoadOrderLinks;
        LIST_ENTRY     InMemoryOrderLinks;
        LIST_ENTRY     InInitializationOrderLinks;
        void*          DllBase;
        void*          EntryPoint;
        u32            SizeOfImage;
        UNICODE_STRING FullDllName;
        UNICODE_STRING BaseDllName;
    };

    struct PEB_LDR_DATA
    {
        u32 Length;
        u32 Initialized;
        void* SsHandle;
        LIST_ENTRY InLoadOrderModuleList;
    };

    struct PEB
    {
        u08 Reserved1[24];
        PEB_LDR_DATA* Ldr;
    };

    struct IMAGE_DOS_HEADER
    {
        u16 e_magic;
        u16 pad1[29];
        i32 e_lfanew;
    };

    struct IMAGE_DATA_DIRECTORY
    {
        u32 VirtualAddress;
        u32 Size;
    };

    struct IMAGE_OPTIONAL_HEADER64
    {
        u16 pad0;
        u08 pad1[110];
        IMAGE_DATA_DIRECTORY DataDirectory[16];
    };

    struct IMAGE_FILE_HEADER
    {
        u16 pad0;
        u16 pad1;
        u32 pad2;
        u32 pad3;
        u32 pad4;
        u16 pad5;
        u16 pad6;
    };

    struct IMAGE_NT_HEADERS64
    {
        u32 Signature;
        IMAGE_FILE_HEADER FileHeader;
        IMAGE_OPTIONAL_HEADER64 OptionalHeader;
    };

    struct IMAGE_EXPORT_DIRECTORY
    {
        u32 Characteristics;
        u32 TimeDateStamp;
        u16 MajorVersion;
        u16 MinorVersion;
        u32 Name;
        u32 Base;
        u32 NumberOfFunctions;
        u32 NumberOfNames;
        u32 AddressOfFunctions;
        u32 AddressOfNames;
        u32 AddressOfNameOrdinals;
    };

    // ---------- Helpers ----------
    static inline PEB* Peb()
    {
        PEB* p;
        asm("mov %%gs:0x60,%0" : "=r"(p));
        return p;
    }

    static i32 StrCmp(const c08* a, const c08* b)
    {
        while (*a && *b)
        {
            if (*a != *b)
                return *a - *b;
            ++a;
            ++b;
        }
        return *a - *b;
    }

    static void* GetModule(const c08* name)
    {
        LIST_ENTRY* head = &Peb()->Ldr->InLoadOrderModuleList;

        for (LIST_ENTRY* e = head->Flink; e != head; e = e->Flink)
        {
            auto* mod = (LDR_DATA_TABLE_ENTRY*)e;

            c08 buf[64];
            u32 len = mod->BaseDllName.Length / 2;

            if (len >= sizeof(buf))
                continue;

            for (u32 i = 0; i < len; ++i)
            {
                c08 c = (c08)mod->BaseDllName.Buffer[i];
                if (c >= 'A' && c <= 'Z')
                    c += 32;
                buf[i] = c;
            }
            buf[len] = 0;

            if (!StrCmp(buf, name))
                return mod->DllBase;
        }

        return 0;
    }

    static void* GetProc(void* module, const c08* name)
    {
        auto* dos = (IMAGE_DOS_HEADER*)module;
        auto* nt = (IMAGE_NT_HEADERS64*)((u08*)module + dos->e_lfanew);

        auto* exp = (IMAGE_EXPORT_DIRECTORY*)
            ((u08*)module +
            nt->OptionalHeader.DataDirectory[0].VirtualAddress);

        auto* names = (u32*)((u08*)module + exp->AddressOfNames);
        auto* funcs = (u32*)((u08*)module + exp->AddressOfFunctions);
        auto* ords  = (u16*)((u08*)module + exp->AddressOfNameOrdinals);

        for (u32 i = 0; i < exp->NumberOfNames; ++i)
        {
            c08* n = (c08*)module + names[i];

            if (!StrCmp(n, name))
                return (u08*)module + funcs[ords[i]];
        }

        return 0;
    }

    // ---------- Nt ----------
    using NtTerminateProcess_t = i32(*)(void*, i32);

    NtTerminateProcess_t NtTerminateProcess;

    // ---------- Entry ----------
    extern "C" void start__()
    {
        void* ntdll = GetModule("ntdll.dll");

        NtTerminateProcess =
            (NtTerminateProcess_t)GetProc(
                ntdll,
                "NtTerminateProcess"
            );

        NtTerminateProcess((void*)-1, 3);
        while (true) { }
    }




    #elif CMN_SYSTEM_OS_MAC
    #include "system/xnu/Call.hpp"

    extern "C" void start__()
    {
        i32 _result = main(0, nullptr);

        cmn::system::xnu::exit(_result);
        while (true) { }
    }
    #endif
}