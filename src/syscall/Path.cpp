#include "sys/platform/OS.hpp"
#include "syscall/Path.hpp"
#include "syscall/lin/Type.hpp"
#include "type/Alias.hpp"

#if CMN_SYS_OS_LIN
#include "syscall/lin/Call.hpp"

namespace cmn::syscall
{
    constexpr i64 EPOCH = i64(1970) * 31556952;
    Timestamp convert_time(timespec _time)
    {
        return Timestamp
        {
            .seconds     =     _time.tv_sec + EPOCH,
            .nanoseconds = u32(_time.tv_nsec)
        };
    }

    FileInfo query(const c08* _path) // NtQueryAttributesFile        : stat                         : stat
    {
        stat _stat;

        newfstatat(-100, _path, &_stat, 0);

        return FileInfo
        {
            .accessTime = convert_time(_stat.st_atim),
            .modifyTime = convert_time(_stat.st_mtim),
            .changeTime = convert_time(_stat.st_ctim),

            .size       = _stat.st_size,
            .mode       = _stat.st_mode,
            .attributes = 0
        };
    }
    void move (const c08* _pathSrc, const c08* _pathDst) // NtSetInformationFile         : renameat                     : renameat
    {
        cmn::syscall::renameat(-100, _pathSrc, -100, _pathDst);
    }
}
#elif CMN_SYS_OS_MAC
#include "syscall/mac/Call.hpp"

namespace cmn::syscall
{
    constexpr i64 EPOCH_MAC = i64(719528) * 86400;
    Timestamp from_mac(timespec _time)
    {
        return Timestamp
        {
            .seconds     =     _time.tv_sec + EPOCH_MAC,
            .nanoseconds = u32(_time.tv_nsec)
        };
    }

    timespec to_mac(Timestamp _time)
    {
        return timespec
        {
            .tv_sec  =     _time.seconds - EPOCH_MAC,
            .tv_nsec = i64(_time.nanoseconds)
        };
    }

    void query(const c08* _path) // NtQueryAttributesFile        : stat                         : stat
    {
        sys::xnu::fstatat(-100, _path, user_addr_t ub, 0);
    }
    void move (const c08* _pathSrc, const c08* _pathDst) // NtSetInformationFile         : renameat                     : renameat
    {
        sys::xnu::renameat(-100, _pathSrc, -100, _pathDst);
    }
}
#elif CMN_SYS_OS_WIN
#include "syscall/win/Call.hpp"

s64 utf8_to_utf16(const c08* _src, c16* _dst)
{
    s64 _length = 0;

    while (*_src)
    {
        u32 cp;
        u08 c = (u08)*_src++;

        if (c < 0x80)
        {
            cp = c;
        }
        else if ((c & 0xE0) == 0xC0)
        {
            u08 c1 = (u08)*_src++;

            if ((c1 & 0xC0) != 0x80)
                return -1;

            cp =
                ((u32)(c & 0x1F) << 6) |
                ((u32)(c1 & 0x3F));

            if (cp < 0x80)
                return -1; // overlong
        }
        else if ((c & 0xF0) == 0xE0)
        {
            u08 c1 = (u08)*_src++;
            u08 c2 = (u08)*_src++;

            if ((c1 & 0xC0) != 0x80 ||
                (c2 & 0xC0) != 0x80)
                return -1;

            cp =
                ((u32)(c & 0x0F) << 12) |
                ((u32)(c1 & 0x3F) << 6) |
                ((u32)(c2 & 0x3F));

            if (cp < 0x800)
                return -1; // overlong
        }
        else if ((c & 0xF8) == 0xF0)
        {
            u08 c1 = (u08)*_src++;
            u08 c2 = (u08)*_src++;
            u08 c3 = (u08)*_src++;

            if ((c1 & 0xC0) != 0x80 ||
                (c2 & 0xC0) != 0x80 ||
                (c3 & 0xC0) != 0x80)
                return -1;

            cp =
                ((u32)(c & 0x07) << 18) |
                ((u32)(c1 & 0x3F) << 12) |
                ((u32)(c2 & 0x3F) << 6) |
                ((u32)(c3 & 0x3F));

            if (cp < 0x10000 || cp > 0x10FFFF)
                return -1; // overlong/out of range
        }
        else
        {
            return -1;
        }

        if (cp <= 0xFFFF)
        {
            _dst[_length++] = (c16)cp;
        }
        else
        {

            cp -= 0x10000;

            _dst[_length++] = 0xD800 | (c16)(cp >> 10);
            _dst[_length++] = 0xDC00 | (c16)(cp & 0x3FF);
        }
    }

    _dst[_length] = '\0';
    return _length;
}

namespace cmn::syscall
{
    constexpr i64 EPOCH_WIN = i64(584388) * 86400;
    Timestamp from_win(FILETIME _time)
    {
        u64 _ticks = (u64(_time.dwHighDateTime) << 32) | _time.dwLowDateTime;

        return Timestamp
        {
            .seconds     = i64( _ticks / 10000000       ) + EPOCH_WIN,
            .nanoseconds = u32((_ticks % 10000000) * 100)
        };
    }
    FILETIME to_win(Timestamp _time)
    {
        u64 _ticks = u64(_time.seconds - EPOCH_WIN) * 10000000 + (_time.nanoseconds / 100);

        return FILETIME
        {
            .dwLowDateTime  = u32(_ticks      ),
            .dwHighDateTime = u32(_ticks >> 32)
        };
    }

    void query(const c08* _path) // NtQueryAttributesFile        : stat                         : stat
    {
        c16 _buffer[512];
        s64 _length = utf8_to_utf16(_path, _buffer);
        if (_length == (s64)-1)
        {
            // return -1;
        }

        UNICODE_STRING _utf16Path
        {
            .Length        = (c16)(_length * sizeof(c16)),
            .MaximumLength = sizeof(_buffer),
            .Buffer        = _buffer,
        };

        OBJECT_ATTRIBUTES _attributes
        {
            .Length                   = sizeof(OBJECT_ATTRIBUTES),
            .RootDirectory             = nullptr,
            .ObjectName                = &_utf16Path,
            .Attributes                = 0x00000040, // OBJ_CASE_INSENSITIVE
            .SecurityDescriptor       = nullptr,
            .SecurityQualityOfService = nullptr,
        };

        FILE_BASIC_INFORMATION _info;

        NTSTATUS _status = win::nt_query_attributes_file(&_attributes, &_info);
    }
    void move (const c08* _pathSrc, const c08* _pathDst) // NtSetInformationFile         : renameat                     : renameat
    {

    }
}
#endif