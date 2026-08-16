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
        Timestamp accessTime;
        Timestamp modifyTime;
        Timestamp changeTime;

        s64       size;

        u32       mode;
        u32       attributes;
    };

    FileInfo query(const c08* _path);
    void     move (const c08* _pathSrc, const c08* _pathDst);
}