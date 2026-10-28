#include "error/Result.hh"
#include "syscall/uni/IO.hh"
#include "syscall/uni/IO_Error.hh"
#include "sys/platform/OS.hh"

#if CMN_SYS_OS_LIN
    #include "syscall/lin/Call.hh"
#elif CMN_SYS_OS_MAC
    #include "syscall/mac/Call.hh"
    #include "syscall/mac/Type.hh"
#elif CMN_SYS_OS_WIN
    #include "syscall/util/Path.hh"
    #include "syscall/win/Func.hh"
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

#elif CMN_SYS_OS_MAC

    #define AT_FDCWD -2

    #define F_GETPATH 50

    #define O_RDONLY    0x00000000
    #define O_DIRECTORY 0x00100000
    #define O_CLOEXEC   0x01000000

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
    static cmn::syscall::uni::io::Path pathBuffer;

    /// Returns the specified
    /// If _capacity is < the length of the current working directory, the output buffer is only set up to _capacity.
    /// Upon error, _outputBuffer is untouched and the returned length is 0.
    cmn::error::Result<s64, Cwd> cwd(c08* _outputBuffer, const s64 _capacity)
    {
        s64 _length;
        Cwd _error;

        #if CMN_SYS_OS_LIN

            i64 _status  = lin::getcwd(_outputBuffer, _capacity);
            b08 _success = u64(_status) < -4095ul;

            _length = _success ? _status   : 0;
            _error  = _success ? Cwd::NONE : Cwd(-_status);

        #elif CMN_SYS_OS_MAC

            c08 _cwd[]   = ".";
            i64 _status  = mac::openat(AT_FDCWD, user_addr_t(_cwd), O_RDONLY | O_DIRECTORY | O_CLOEXEC, 0);
            b08 _success = _status >= 0;

            _length = 0;

            if (_success)
            {
                i32 _fileDescriptor = i32(_status);

                _status  = mac::sys_fcntl(_fileDescriptor, F_GETPATH, long(pathBuffer.string));
                _success = _status >= 0;

                if (_success)
                {
                    while (_length < _capacity && pathBuffer.string[_length] != '\0')
                    {
                        _outputBuffer[_length] = pathBuffer.string[_length];
                        ++_length;
                    }
                    while (pathBuffer.string[_length] != '\0')
                    {
                        ++_length;
                    }
                }

                // No need to check close, regardless of whether this fails or not, the cwd output is valid, and if this does fail it likely means it was already closed by another thread in-between.
                mac::sys_close(_fileDescriptor);
            }

            _error = _success ? Cwd::NONE : Cwd(-_status);

        #elif CMN_SYS_OS_WIN

            UNICODE_STRING _cwd = cmn::syscall::win_::resolve_peb()->ProcessParameters->CurrentDirectory.DosPath;

            // Maybe implement capacities for path conversions.
            _length = cmn::syscall::util::path::from_native_absolute(_cwd, _outputBuffer);
            _error = Cwd::NONE;

        #endif

        return error::Result<s64, Cwd>(_length, _error);
    }
    /// Determines if and what type of filesystem-object exists at a given path.
    /// Upon error, TYPE::NONE is returned.
    cmn::error::Result<Type, Exists> exists(const c08 *_path, const s64 _length);
    /// Obtains information on a given filesystem-object.
    cmn::error::Result<s64 , Query > query (const Handle _object); // TODO: Add info for query.
}