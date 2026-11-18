#pragma once
#include "error/status.hh"
#include "sys/platform/os.hh"

#if CMN_SYS_OS_LIN
    #include "syscall/lin/errno.hh"
#elif CMN_SYS_OS_MAC
    #include "syscall/mac/errno.hh"
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

        /// For all os-specific errors below, the returned length is 0 and `_outputBuffer` is untouched, unless specified otherwise.

        #if CMN_SYS_OS_LIN

            /// Permission to read or search a component of the cwd path was denied.
            PERMISSION_DENIED           = EACCES,
            /// The cwd has been unlinked/removed from the filesystem.
            UNLINKED_CWD                = ENOENT,
            /// The OS does not have enough memory to obtain the cwd.
            OUT_OF_MEMORY               = ENOMEM,
            /// The cwd's absolute path length exceeded the OS' internal max path length.
            LONG_CWD                    = ENAMETOOLONG,

            /// Error does not occur on linux.
            INTERRUPTED                 = -1,
            /// Error does not occur on linux.
            SYMLINK_LIMIT               = -1,
            /// Error does not occur on linux.
            MAX_OPEN_PROCESS_HANDLES    = -1,
            /// Error does not occur on linux.
            MAX_OPEN_SYSTEM_HANDLES     = -1,
            /// Error does not occur on linux.
            NOT_A_DIRECTORY             = -1,
            /// Error does not occur on linux.
            INVALID_DEVICE              = -1,
            /// Error does not occur on linux.
            SEAL_BLOCKED                = -1,

            /// The internal capacity specified was zero, and the internal buffer was null.
            ZERO_INTERNAL_SIZE          = EINVAL,
            /// The internal buffer was invalid and likely null.
            INVALID_INTERNAL_ADDRESS    = EFAULT,
            /// The internal specified was not large enough to store the cwd path.
            SHORT_INTERNAL_CAPACITY     = ERANGE,

        #elif CMN_SYS_OS_MAC // AT_FDCWD + O_RDONLY | O_DIRECTORY | O_CLOEXEC

            /// Permission to read or search a component of the cwd path was denied.
            PERMISSION_DENIED           = EACCES,
            /// The cwd has been unlinked/removed from the filesystem.
            UNLINKED_CWD                = ENOENT,
            /// The OS does not have enough memory to open the cwd.
            OUT_OF_MEMORY               = ENOMEM,
            /// The cwd's absolute path length exceeded the OS' internal max path length.
            LONG_CWD                    = ENAMETOOLONG,

            /// A signal interrupt occurred while blocked, waiting to open the cwd.
            INTERRUPTED                 = EINTR,
            /// Too many symbolic links were encountered, likely a symlink-loop.
            SYMLINK_LIMIT               = ELOOP,
            /// The per-process limit on open file-descriptors was met.
            MAX_OPEN_PROCESS_HANDLES    = EMFILE,
            /// The system limit on open file-descriptors was met.
            MAX_OPEN_SYSTEM_HANDLES     = ENFILE,
            /// The cwd doesn't point to a directory.
            NOT_A_DIRECTORY             = ENOTDIR,
            /// The cwd points to an invalid device-special file.
            INVALID_DEVICE              = ENXIO,       // The file is a device special file and no corresponding device exists.
            /// A file-seal prevented opening the cwd.
            SEAL_BLOCKED                = EPERM,       // The operation was prevented by a file seal; see fcntl(2).


            /// One of the inputs or flags passed were invalid.
            INVALID_INTERNAL_INPUT      = EINVAL,
            /// The internal buffer passed was outside of process memory.
            INVALID_INTERNAL_ADDRESS    = EFAULT,
            /// The opened cwd was not valid.
            INVALID_INTERNAL_HANDLE     = EBADF,

        #elif CMN_SYS_OS_WIN

            /// ...

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