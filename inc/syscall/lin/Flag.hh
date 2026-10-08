#pragma once
#include "type/Alias.hh"
namespace cmn::syscall
{
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