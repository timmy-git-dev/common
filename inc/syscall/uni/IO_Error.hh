#pragma once
#include "error/Error.hh"
#include "sys/platform/OS.hh"

#if CMN_SYS_OS_LIN
    #include "syscall/lin/Errno.hh"
#elif CMN_SYS_OS_MAC

#elif CMN_SYS_OS_WIN

#endif

namespace cmn::syscall::uni::io
{
    enum class Cwd : error::Code
    {
        NONE = 0,

        #if CMN_SYS_OS_LIN

        #elif CMN_SYS_OS_MAC

        #elif CMN_SYS_OS_WIN

        #endif
    };
    enum class Exists : error::Code
    {
        NONE = 0,

        #if CMN_SYS_OS_LIN

        #elif CMN_SYS_OS_MAC

        #elif CMN_SYS_OS_WIN

        #endif
    };
    enum class Query : error::Code
    {
        NONE = 0,

        #if CMN_SYS_OS_LIN

        #elif CMN_SYS_OS_MAC

        #elif CMN_SYS_OS_WIN

        #endif
    };

    namespace file
    {
        enum class Create : error::Code
        {
            NONE = 0,
            #if CMN_SYS_OS_LIN
                PERMISSION_DENIED       = EACCES,
                QUOTA_EXHAUSTED         = EDQUOT,
                FILE_EXISTS             = EEXIST,
                PATH_INACCESSIBLE       = EFAULT,
                INTERRUPTED             = EINTR,
                IS_DIRECTORY            = EISDIR,
                TOO_MANY_SYMLINKS       = ELOOP,
                TOO_MANY_OPEN_FILES     = EMFILE,
                NAME_TOO_LONG           = ENAMETOOLONG,
                SYSTEM_FILE_LIMIT       = ENFILE,
                DEVICE_NOT_FOUND        = ENODEV,
                FILE_NOT_FOUND          = ENOENT,
                OUT_OF_MEMORY           = ENOMEM,
                NO_SPACE                = ENOSPC,
                NOT_DIRECTORY           = ENOTDIR,
                DEVICE_UNAVAILABLE      = ENXIO,
                OVERFLOW                = EOVERFLOW,
                OPERATION_NOT_PERMITTED = EPERM,
                READ_ONLY_FILESYSTEM    = EROFS,
                FILE_BUSY               = ETXTBSY,
                WOULD_BLOCK             = EAGAIN,
                INVALID_DESCRIPTOR      = EBADF,
            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
        enum class Remove : error::Code
        {
            NONE = 0,

            #if CMN_SYS_OS_LIN

            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
        enum class Open : error::Code
        {
            NONE = 0,

            #if CMN_SYS_OS_LIN

            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
        enum class Close : error::Code
        {
            NONE = 0,

            #if CMN_SYS_OS_LIN

            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
        enum class Read : error::Code
        {
            NONE = 0,

            #if CMN_SYS_OS_LIN

            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
        enum class Write : error::Code
        {
            NONE = 0,

            #if CMN_SYS_OS_LIN

            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
    }

    namespace dir
    {
        enum class Create : error::Code
        {
            NONE = 0,

            #if CMN_SYS_OS_LIN

            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
        enum class Remove : error::Code
        {
            NONE = 0,

            #if CMN_SYS_OS_LIN

            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
        enum class Open : error::Code
        {
            NONE = 0,

            #if CMN_SYS_OS_LIN

            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
        enum class Close : error::Code
        {
            NONE = 0,

            #if CMN_SYS_OS_LIN

            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
        enum class Entries : error::Code
        {
            NONE = 0,

            #if CMN_SYS_OS_LIN

            #elif CMN_SYS_OS_MAC

            #elif CMN_SYS_OS_WIN

            #endif
        };
    }
}