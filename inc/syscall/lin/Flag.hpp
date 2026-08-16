#pragma once
#include "type/Alias.hpp"

namespace cmn::syscall
{
    // TODO: maybe automate if possible/get all defines + maybe separate files.
    enum class PROT : u32
    {
        NONE          = 0x0         ,
        READ          = 0x1         ,
        WRITE         = 0x2         ,
        EXEC          = 0x4         ,
        SEM           = 0x8         ,
        GROWSDOWN     = 0x01000000  ,
        GROWSUP       = 0x02000000  ,
    };

    enum class MAP : u32
    {
        SHARED          = 0x01    ,
        PRIVATE         = 0x02    ,
        SHARED_VALIDATE = 0x03    ,
        FIXED           = 0x10    ,
        ANONYMOUS       = 0x20    ,
        GROWSDOWN       = 0x0100  ,
        DENYWRITE       = 0x0800  ,
        EXECUTABLE      = 0x1000  ,
        LOCKED          = 0x2000  ,
        NORESERVE       = 0x4000  ,
        POPULATE        = 0x8000  ,
        NONBLOCK        = 0x10000 ,
        STACK           = 0x20000 ,
        HUGETLB         = 0x40000 ,
        SYNC            = 0x80000 ,
        FIXED_NOREPLACE = 0x100000,
    };

    enum class S : u32
    {
        IFMT   = 0xF000,
        IFSOCK = 0xC000,
        IFLNK  = 0xA000,
        IFREG  = 0x8000,
        IFBLK  = 0x6000,
        IFDIR  = 0x4000,
        IFCHR  = 0x2000,
        IFIFO  = 0x1000,
        ISUID  = 0x0800,
        ISGID  = 0x0400,
        ISVTX  = 0x0200,
        IRUSR  = 0x0100,
        IWUSR  = 0x0080,
        IXUSR  = 0x0040,
        IRGRP  = 0x0020,
        IWGRP  = 0x0010,
        IXGRP  = 0x0008,
        IROTH  = 0x0004,
        IWOTH  = 0x0002,
        IXOTH  = 0x0001,
    };
}