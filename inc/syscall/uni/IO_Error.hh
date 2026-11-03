#pragma once
#include "error/Status.hh"
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
        /// The length of the cwd is returned and `_outputBuffer` is set to the cwd.
        SUCCESS = 0,
        /// The specified `_capacity` was < the length of the cwd.
        /// The length of the cwd is returned and `_outputBuffer` is untouched.
        SHORT_CAPACITY = 1,

        #if CMN_SYS_OS_LIN

            /// Permission to read or search a component of the cwd path was denied.
            /// The returned length is 0 and `_outputBuffer` is untouched.
            PERMISSION_DENIED       = EACCES,
            /// The cwd has been unlinked/removed from the filesystem.
            /// The returned length is 0 and `_outputBuffer` is untouched.
            UNLINKED_CWD            = ENOENT,
            /// The OS does not have enough memory to obtain the cwd.
            /// The returned length is 0 and `_outputBuffer` is untouched.
            OUT_OF_MEMORY           = ENOMEM,

            /// The internal capacity specified was zero, and the internal buffer was null.
            /// The returned length is 0 and `_outputBuffer` is untouched.
            ZERO_INTERNAL_SIZE      = EINVAL,
            /// The internal buffer was invalid and likely null.
            /// The returned length is 0 and `_outputBuffer` is untouched.
            NULL_INTERNAL_ADDRESS   = EFAULT,
            /// The internal specified was not large enough to store the cwd path.
            /// The returned length is 0 and `_outputBuffer` is untouched.
            SHORT_INTERNAL_CAPACITY = ERANGE,

        #elif CMN_SYS_OS_MAC

        #elif CMN_SYS_OS_WIN

        #endif

    };
    enum class Exists : error::Code
    {
        /// The specified `_path` was valid, and the filesystem-object's type; and whether it exists, is returned.
        SUCCESS = 0,

        #if CMN_SYS_OS_LIN

        #elif CMN_SYS_OS_MAC

        #elif CMN_SYS_OS_WIN

        #endif
    };
    enum class Query : error::Code
    {
        SUCCESS = 0,

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