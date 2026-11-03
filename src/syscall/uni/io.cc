#include "error/result.hh"
#include "syscall/uni/io.hh"
#include "syscall/uni/io-error.hh"
#include "sys/platform/os.hh"

#include "dbg/print.hh"

#if CMN_SYS_OS_LIN
    #include "syscall/lin/call.hh"
    #include "syscall/lin/type.hh"
#elif CMN_SYS_OS_MAC
    #include "syscall/mac/call.hh"
    #include "syscall/mac/type.hh"
#elif CMN_SYS_OS_WIN
    #include "syscall/util/path.hh"
    #include "syscall/win/call.hh"
    #include "syscall/win/func.hh"
    #include "syscall/win/type.hh"
#endif

// TODO: Cleanup and make non-defines or something? And put into separate "flags" files for each OS.
#if CMN_SYS_OS_LIN

    #define AT_FDCWD -100

    #define O_RDONLY 0
    #define O_WRONLY 1
    #define O_RDWR   2

    #define O_CREAT  0100
    #define O_EXCL   0200
    #define O_TRUNC  01000
    #define O_APPEND 02000

    #define AT_SYMLINK_NOFOLLOW 0x100

    #define STATX_TYPE   0x0001
    #define STATX_SIZE   0x0200
    #define STATX_BLOCKS 0x0400
    #define STATX_NLINK  0x0004
    #define STATX_INO    0x0100
    #define STATX_BTIME  0x0800
    #define STATX_ATIME  0x0020
    #define STATX_MTIME  0x0040
    #define STATX_CTIME  0x0080

    #define S_IFMT     0170000  // type of file

    #define S_IFSOCK   0140000  // socket
    #define S_IFLNK    0120000  // symbolic link
    #define S_IFREG    0100000  // regular file
    #define S_IFBLK    0060000  // block device
    #define S_IFDIR    0040000  // directory
    #define S_IFCHR    0020000  // character device
    #define S_IFIFO    0010000  // FIFO

#elif CMN_SYS_OS_MAC

    #define AT_FDCWD -2

    #define F_GETPATH 50

    #define O_RDONLY    0x00000000
    #define O_DIRECTORY 0x00100000
    #define O_CLOEXEC   0x01000000

    #define AT_SYMLINK_NOFOLLOW 0x0020

    #define S_IFMT   0170000  /* type of file */

#elif CMN_SYS_OS_WIN

    #define FILE_WRITE_DATA              0x0002
    #define SYNCHRONIZE                  0x00100000

    #define OBJ_CASE_INSENSITIVE         0x40
    #define FILE_ATTRIBUTE_NORMAL        0x80
    #define FILE_SHARE_READ              0x01
    #define FILE_SHARE_WRITE             0x02
    #define FILE_OVERWRITE_IF            0x05
    #define FILE_NON_DIRECTORY_FILE      0x40
    #define FILE_SYNCHRONOUS_IO_NONALERT 0x20

#endif


namespace cmn::syscall::uni::io
{
    // Reusable buffer for internal path copying, mainly for windows UTF-8 <-> UTF-16 and POSIX <-> NT path resolution.
    static c08 pathBuffer[4096];

    cmn::error::Result<s64, Cwd> cwd(c08* _outputBuffer, const s64 _capacity)
    {
        s64 _length = 0;
        Cwd _error  = Cwd::SUCCESS;

        #if CMN_SYS_OS_LIN

            // Obtain the cwd length or errno.
            i64 _status = lin::getcwd(pathBuffer, 1024);

            b08 _success = u64(_status) < -4095ul;
            if (!_success)
            {
                _error = Cwd(-_status);
                return { _length, _error };
            }

            // Exclude the null-terminator.
            _length = _status - 1;
            if (_capacity < _length)
            {
                _error = Cwd::SHORT_CAPACITY;
                return { _length, _error };
            }

            // Copy over the cwd path.
            for (s64 _i = 0; _i < _length; ++_i)
            {
                _outputBuffer[_i] = pathBuffer[_i];
            }

        #elif CMN_SYS_OS_MAC

            // Attempt to open the cwd path.
            c08 _cwd[]  = ".";
            i64 _status = mac::openat(AT_FDCWD, user_addr_t(_cwd), O_RDONLY | O_DIRECTORY | O_CLOEXEC, 0);

            b08 _success = _status >= 0;
            if (!_success)
            {
                _error = Cwd(-_status);
                return { _length, _error };
            }

            // Attempt to get the string path of the cwd.
            i32 _fileDescriptor = i32(_status);
                _status         = mac::sys_fcntl(_fileDescriptor, F_GETPATH, long(pathBuffer));

            // Close the fd regardless of fcntl.
            mac::sys_close(_fileDescriptor);

            _success = _status >= 0;
            if (!_success)
            {
                _error = Cwd(-_status);
                return { _length, _error };
            }

            // Find the length of the path.
            while (pathBuffer[_length] != '\0')
            {
                ++_length;
            }

            if (_capacity < _length)
            {
                _error = Cwd::SHORT_CAPACITY;
                return { _length, _error };
            }

            // Copy the buffer.
            for (s64 _i = 0; _i < _length; ++_i)
            {
                _outputBuffer[_i] = pathBuffer[_i];
            }

        #elif CMN_SYS_OS_WIN

            // Obtain the DOS-path from the peb.
            UNICODE_STRING _cwd = cmn::syscall::win_::resolve_peb()->ProcessParameters->CurrentDirectory.DosPath;
            _length = cmn::syscall::util::path::from_native_absolute(_cwd, pathBuffer); // Maybe implement capacities for path conversions.

            if (_capacity < _length)
            {
                _error = Cwd::SHORT_CAPACITY;
                return { _length, _error };
            }

            // Copy the buffer.
            for (s64 _i = 0; _i < _length; ++_i)
            {
                _outputBuffer[_i] = pathBuffer[_i];
            }

        #endif

        return { _length, _error };
    }
    cmn::error::Result<Info, Query> query(const c08 *_path, const s64 _length)
    {
        Info  _info;
        Query _error = Query::SUCCESS;

        #if CMN_SYS_OS_LIN

            // TODO: Proper conversion funcs for posix, and probably polish up windows version too.
            // Convert the path to a posix-based path with a null-terminator.
            for (s64 _i = 0; _i < _length; ++_i)
            {
                pathBuffer[_i] = _path[_i];
            }
            pathBuffer[_length] = '\0';

            // Obtain the path's statx info struct.
            struct lin::statx _stat;
            const i64 _status = lin::statx
            (
                AT_FDCWD,
                _path,
                AT_SYMLINK_NOFOLLOW,
                STATX_TYPE   |
                STATX_SIZE   |
                STATX_BLOCKS |
                STATX_NLINK  |
                STATX_INO    |
                STATX_BTIME  |
                STATX_ATIME  |
                STATX_MTIME  |
                STATX_CTIME,
                &_stat
            );

            b08 _success = u64(_status) < -4095ul;
            if (!_success)
            {
                _error = Query(-_status);
                return { _info, _error };
            }

            // Set the parsed/shared info among each OS.
            _info = Info
            {
                .type         = Type(_stat.stx_mode & 0xF000),

                .length       = s64 (_stat.stx_size         ),
                .allocated    = s64 (_stat.stx_blksize * 512),

                .linkCount    = s64 (_stat.stx_nlink        ),

                .id           = u64 (_stat.stx_ino          ),
                .filesystemID = u64 (_stat.stx_dev_major    ) << 32 |
                                u64 (_stat.stx_dev_minor    ),

                .created      = Time
                {
                    .seconds     = i64(_stat.stx_btime.tv_sec + 62167219200),
                    .nanoseconds = u64(_stat.stx_btime.tv_nsec             ),
                },
                .accessed     = Time
                {
                    .seconds     = i64(_stat.stx_atime.tv_sec + 62167219200),
                    .nanoseconds = u64(_stat.stx_atime.tv_nsec             ),
                },
                .edited       = Time
                {
                    .seconds     = i64(_stat.stx_mtime.tv_sec + 62167219200),
                    .nanoseconds = u64(_stat.stx_mtime.tv_nsec             ),
                },
                .updated      = Time
                {
                    .seconds     = i64(_stat.stx_ctime.tv_sec + 62167219200),
                    .nanoseconds = u64(_stat.stx_ctime.tv_nsec             ),
                },
            };

        #elif CMN_SYS_OS_MAC

            // TODO: Proper conversion funcs for posix, and probably polish up windows version too.
            // Convert the path to a posix-based path with a null-terminator.
            for (s64 _i = 0; _i < _length; ++_i)
            {
                pathBuffer[_i] = _path[_i];
            }
            pathBuffer[_length] = '\0';

            // Obtain the path's info struct.
            struct stat _stat;
            i64 _status = mac::fstatat(-1, user_addr_t(pathBuffer), user_addr_t(&_stat), AT_SYMLINK_NOFOLLOW);

            bool _success = _status >= 0;
            if (!_success)
            {
                _error = Query(-_status);
                return { _info, _error };
            }

            // Set the parsed/shared info among each OS.
            _info = Info
            {
                .type         = Type(_stat.st_mode   ),

                .length       = s64 (_stat.st_size   ),
                .allocated    = s64 (_stat.st_blksize),

                .linkCount    = s64 (_stat.st_nlink  ),

                .id           = u64 (_stat.st_ino    ),
                .filesystemID = u64 (_stat.st_dev    ),

                .created      = Time
                {
                    .seconds     = i64(_stat.st_birthtimespec.tv_sec ),
                    .nanoseconds = u64(_stat.st_birthtimespec.tv_nsec),
                },
                .accessed     = Time
                {
                    .seconds     = i64(_stat.st_atimespec    .tv_sec ),
                    .nanoseconds = u64(_stat.st_atimespec    .tv_nsec),
                },
                .edited       = Time
                {
                    .seconds     = i64(_stat.st_mtimespec    .tv_sec ),
                    .nanoseconds = u64(_stat.st_mtimespec    .tv_nsec),
                },
                .updated      = Time
                {
                    .seconds     = i64(_stat.st_ctimespec    .tv_sec ),
                    .nanoseconds = u64(_stat.st_ctimespec    .tv_nsec),
                },
            };

        #elif CMN_SYS_OS_WIN

            UNICODE_STRING _name = cmn::syscall::util::path::to_native(_path, _length);

            OBJECT_ATTRIBUTES _attributes =
            {
                .Length                   = sizeof(OBJECT_ATTRIBUTES),
                .RootDirectory            = nullptr,
                .ObjectName               = &_name,
                .Attributes               = OBJ_CASE_INSENSITIVE,
                .SecurityDescriptor       = nullptr,
                .SecurityQualityOfService = nullptr
            };
            FILE_STAT_BASIC_INFORMATION _stat;
            IO_STATUS_BLOCK _ioStatus;

            NTSTATUS _status = win::NtQueryInformationByName(&_attributes, &_ioStatus, &_stat, sizeof(_stat), FILE_INFORMATION_CLASS::FileStatBasicInformation);

            bool _success = _status >= 0;
            if (!_success)
            {
                _error = Query(_status);
                return { _info, _error };
            }

            // Set the parsed/shared info among each OS.
            _info = Info
            {
                .type         = _stat.FileAttributes & 0x0400u ? Type(_stat.ReparseTag) : Type(_stat.FileAttributes & 0x0010u),

                .length       = s64(_stat.EndOfFile         .QuadPart),
                .allocated    = s64(_stat.AllocationSize    .QuadPart),

                .linkCount    = s64(_stat.NumberOfLinks              ),

                .id           = u64(_stat.FileId            .QuadPart),
                .filesystemID = u64(_stat.VolumeSerialNumber.QuadPart),

                .created      = Time
                {
                    .seconds     = i64(_stat.CreationTime   .QuadPart / 10000000 + 50522745600),
                    .nanoseconds = u64(_stat.CreationTime   .QuadPart % 10000000 * 100        ),
                },
                .accessed     = Time
                {
                    .seconds     = i64(_stat.LastAccessTime .QuadPart / 10000000 + 50522745600),
                    .nanoseconds = u64(_stat.LastAccessTime .QuadPart % 10000000 * 100        ),
                },
                .edited       = Time
                {
                    .seconds     = i64(_stat.LastWriteTime  .QuadPart / 10000000 + 50522745600),
                    .nanoseconds = u64(_stat.LastWriteTime  .QuadPart % 10000000 * 100        ),
                },
                .updated      = Time
                {
                    .seconds     = i64(_stat.ChangeTime     .QuadPart / 10000000 + 50522745600),
                    .nanoseconds = u64(_stat.ChangeTime     .QuadPart % 10000000 * 100        ),
                },
            };

        #endif

        return { _info, _error };
    }
    /// Obtains information on a given filesystem-object.
    cmn::error::Result<Info, Query> query(const Handle _object); // TODO: Add info for query.
}