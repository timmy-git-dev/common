#include "memory/Memory.hh"
#include "error/Result.hh"
#include "syscall/lin/Call.hh"
#include "syscall/lin/Errno.hh"
namespace cmn::syscall
{
    enum PROTECTION
    {
        NONE          = 0x0         ,
        READ          = 0x1         ,
        WRITE         = 0x2         ,
        EXEC          = 0x4         ,
    };

    enum MAP
    {
        PRIVATE         = 0x02    ,
        ANONYMOUS       = 0x20    ,
    };

    cmn::error::Result<void*, MEMORY> allocate  (s64 _size)
    {
        cmn::error::Result<i64, ERRNO> _output = mmap(0, _size, PROTECTION::READ | PROTECTION::WRITE, MAP::PRIVATE | MAP::ANONYMOUS, -1, 0);
        return cmn::error::Result<void*, MEMORY>(reinterpret_cast<void*>(_output.value), static_cast<MEMORY>(_output.error));
    }
    // cmn::error::Result<void , MEMORY> deallocate(s64 _size, void *_address)
    // {
    //     return __builtin_bit_cast(cmn::error::Result<void, ERRNO>, mmap(0, _size, PROTECTION::READ | PROTECTION::WRITE, MAP::PRIVATE | MAP::ANONYMOUS, -1, 0));
    //     return munmap(reinterpret_cast<u64>(_address), _size);
    // }
}