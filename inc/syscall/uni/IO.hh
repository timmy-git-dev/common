#pragma once
#include "error/Error.hh"
#include "error/Result.hh"
#include "sys/platform/OS.hh"

#if CMN_SYS_OS_LIN
#include "syscall/lin/Errno.hh"
#endif

namespace cmn::syscall::uni::io
{
    using PathHandle = s64;

    enum class CWD : error::ERROR
    {
        NONE = 0,
    };

    enum class CREATE : error::ERROR
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

        #endif
    };

    PathHandle cwd_handle();

    // Return universal file-descriptor
    cmn::error::Result<PathHandle, CREATE> create(const c08 *_path, const s64 _length);
    // cmn::error::Result<void, OPEN  > open  ();
    // void close     (); // NtClose                      : close                        : close
    // void remove    (); // NtSetInformationFile         : unlinkat                     : unlinkat

    // void read      (); // NtReadFile                   : read                         : read
    // void write     (); // NtWriteFile                  : write                        : write
    // void seek      (); // NtSetInformationFile         : lseek                        : lseek

    // void resize    (); // NtSetInformationFile         : ftruncate                    : ftruncate
    // void allocate  (); // NtSetInformationFile*        : fallocate                    : fcntl(F_PREALLOCATE)
    // void deallocate(); // NtSetInformationFile*        : fallocate                    : fcntl(F_PUNCHHOLE*) / ftruncate

    // void query     (); // NtQueryInformationFile       : fstat                        : fstat

    // void flush     (); // NtFlushBuffersFile           : fsync                        : fsync



    void get_name(cmn::syscall::uni::io::PathHandle _handle, c08 *_output);
    s64 for_each_name(cmn::syscall::uni::io::PathHandle _handle, void (*_visit)(const c08 *_name, s64 _length, void *_context), void *_context = nullptr);
}