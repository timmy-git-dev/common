#pragma once
#include "type/Alias.hpp"

namespace cmn::syscall
{
    struct Timestamp
    {
        i64 seconds;
        u32 nanoseconds;
    };
    struct FileInfo
    {
        Timestamp accessTime; // st_atime / LastAccessTime
        Timestamp modifyTime; // st_mtime / LastWriteTime
        Timestamp changeTime; // st_ctime / ChangeTime

        i64       size;             // st_size

        u32       mode;             // Linux/macOS st_mode
        u32       attributes;       // Windows FILE_ATTRIBUTE_*
    };

    FileInfo query(const c08* _path);
    void     move (const c08* _pathSrc, const c08* _pathDst);
}