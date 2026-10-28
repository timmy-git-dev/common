#include "error/Result.hh"
#include "sys/platform/OS.hh"
#include "syscall/uni/Mem.hh"
#include "type/Cast.hh"

#if CMN_SYS_OS_LIN

    #include "syscall/lin/Call.hh"

    constexpr i64 PROT_READ     = 0x1;
    constexpr i64 PROT_WRITE    = 0x2;
    constexpr i64 MAP_PRIVATE   = 0x02;
    constexpr i64 MAP_ANONYMOUS = 0x20;

#elif CMN_SYS_OS_MAC

    #include "syscall/mac/Call.hh"

    constexpr i64 PROT_READ   = 0x1;
    constexpr i64 PROT_WRITE  = 0x2;
    constexpr i64 MAP_PRIVATE = 0x02;
    constexpr i64 MAP_ANON    = 0x1000;

#elif CMN_SYS_OS_WIN

    #include "syscall/win/Call.hh"
    #include "syscall/win/Type.hh"

    constexpr u32 MEM_COMMIT     = 0x1000;
    constexpr u32 MEM_RESERVE    = 0x2000;
    constexpr u32 MEM_RELEASE    = 0x8000;
    constexpr u32 PAGE_READWRITE = 0x04;

#endif

namespace cmn::syscall::uni::mem
{
    error::Result<void *, Memory> allocate(const s64 _length)
    {
        void *_address = nullptr;
        Memory _error;

        #if CMN_SYS_OS_LIN

            u64 _status = lin::mmap(0, _length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
            _address = cast_bits<void *>(_status);
            _error   = _status >= -4095ULL ? cast<Memory>(_status) : Memory::NONE;

        #elif CMN_SYS_OS_MAC

            u64 _status = mac::mmap(0, _length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
            _address = cast_bits<void *>(_status);
            _error   = _status >= -4095ULL ? cast<Memory>(_status) : Memory::NONE;

        #elif CMN_SYS_OS_WIN

            SIZE_T _size = _length;
            NTSTATUS _status = win::NtAllocateVirtualMemory(cast_bits<HANDLE>(-1ULL), &_address, 0, &_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
            _error = _status < 0 ? cast<Memory>(_status) : Memory::NONE;

        #endif

        return error::Result<void *, Memory>(_address, _error);
    }
    error::Result<void, Memory> free(void *_memory, s64 _length)
    {
        Memory _error;

        #if CMN_SYS_OS_LIN
            _error = cast<Memory>(lin::munmap(cast_bits<u64>(_memory), _length));
        #elif CMN_SYS_OS_MAC
            _error = cast<Memory>(mac::munmap(cast_bits<caddr_t>(_memory), _length));
        #elif CMN_SYS_OS_WIN

            SIZE_T _size = _length;
            NTSTATUS _status = win::NtFreeVirtualMemory(cast_bits<HANDLE>(-1ULL), &_memory, &_size, MEM_RELEASE);
            _error = _status < 0 ? cast<Memory>(_status) : Memory::NONE;

        #endif

        return error::Result<void, Memory>(_error);
    }
}