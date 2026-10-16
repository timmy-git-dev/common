#include "syscall/uni/IO.hh"
#include "error/Result.hh"
#include "syscall/win/Func.hh"

#if CMN_SYS_OS_LIN
#include "syscall/lin/Call.hh"
#elif CMN_SYS_OS_MAC
#include "syscall/mac/Call.hh"
#elif CMN_SYS_OS_WIN
#include "syscall/win/Call.hh"
#endif

namespace cmn::syscall::uni::file
{
    #if CMN_SYS_OS_WIN
        PRTL_USER_PROCESS_PARAMETERS processParameters;
    #endif

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

        #define O_WRONLY 0x0001

        #define O_CREAT  0x0200
        #define O_TRUNC  0x0400

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

    s64 utf_8_to_utf_16(const c08 *_input, const s64 _length, c16 *_output)
    {
        s64 _count = 0;

        for (s64 _i = 0; _i < _length;)
        {
            u32 _code        = 0;
            u32 _char        = _input[_i++];
            i32 _leadingOnes = __builtin_clz((~_char & 0xFF) << 24);

            switch (_leadingOnes)
            {
                case 0: _code =  _char;                                                                                                                                         break;

                case 2: _code = (_char & 0b00011111 <<  6) |  (_input[_i] & 0b00111111);                                                                               _i += 1; break;
                case 3: _code = (_char & 0b00001111 << 12) | ((_input[_i] & 0b00111111) <<  6) |  (_input[_i + 1] & 0b00111111);                                       _i += 2; break;
                case 4: _code = (_char & 0b00000111 << 18) | ((_input[_i] & 0b00111111) << 12) | ((_input[_i + 1] & 0b00111111) << 6) | (_input[_i + 2] & 0b00111111); _i += 3; break;

                default:                                                                                                                                                        break;
            }

            if (_code > 0xFFFF)
            {
                _code -= 0x10000;

                _output[_count++] = c16(0xD800 | (_code >> 10));
                _output[_count++] = c16(0xDC00 | (_code & 0x3FF));
                continue;
            }

            _output[_count++] = _code;
        }

        return _count;
    }

    #endif

    cmn::error::Result<PathHandle, CREATE> create(const c08 *_path, const s64 _length) // NtCreateFile(FILE_CREATE)    : openat(O_CREAT|O_EXCL)       : openat(O_CREAT|O_EXCL)
    {
        PathHandle _pathHandle;
        CREATE     _error;

        #if CMN_SYS_OS_LIN

            _pathHandle = cmn::syscall::lin::openat(AT_FDCWD, _path, O_WRONLY | O_CREAT | O_TRUNC, (lin::mode_t)0644);
            _error  = (u64(_pathHandle) >= u64(-4095LL)) ? CREATE(-_pathHandle) : CREATE::NONE;

        #elif CMN_SYS_OS_MAC

            _pathHandle = cmn::syscall::mac::openat(AT_FDCWD, (user_addr_t)_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            _error  = _pathHandle < 0 ? CREATE(-_pathHandle) : CREATE::NONE;

        #elif CMN_SYS_OS_WIN

            c16 _widePath[512];
            s64 _wideLength = utf_8_to_utf_16(_path, _length, _widePath);

            UNICODE_STRING _name
            {
                u16(_wideLength * 2),
                u16(_wideLength * 2 + 2),
                _widePath
            };

            OBJECT_ATTRIBUTES _attributes
            {
                sizeof(OBJECT_ATTRIBUTES),
                win_::resolve_peb()->ProcessParameters->CurrentDirectory.Handle,
                &_name,
                OBJ_CASE_INSENSITIVE,
                nullptr,
                nullptr
            };

            IO_STATUS_BLOCK _ioStatus { };
            HANDLE _handle;

            NTSTATUS _status = CREATE(cmn::syscall::win::NtCreateFile
            (
                &_handle,
                FILE_WRITE_DATA | SYNCHRONIZE,
                &_attributes,
                &_ioStatus,
                nullptr,
                FILE_ATTRIBUTE_NORMAL,
                FILE_SHARE_READ | FILE_SHARE_WRITE,
                FILE_OVERWRITE_IF,
                FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT,
                nullptr,
                0
            ));

            _pathHandle = PathHandle(_handle);
            _error = _status < 0 ? CREATE(_status) : CREATE::NONE;

        #endif

        return error::Result<PathHandle, CREATE>(_pathHandle, _error);
    }
    // cmn::error::Result<void, OPEN  > open  ();
    void close     (); // NtClose                      : close                        : close
    void remove    (); // NtSetInformationFile         : unlinkat                     : unlinkat

    void read      (); // NtReadFile                   : read                         : read
    void write     (); // NtWriteFile                  : write                        : write
    void seek      (); // NtSetInformationFile         : lseek                        : lseek

    void resize    (); // NtSetInformationFile         : ftruncate                    : ftruncate
    void allocate  (); // NtSetInformationFile*        : fallocate                    : fcntl(F_PREALLOCATE)
    void deallocate(); // NtSetInformationFile*        : fallocate                    : fcntl(F_PUNCHHOLE*) / ftruncate

    void query     (); // NtQueryInformationFile       : fstat                        : fstat

    void flush     (); // NtFlushBuffersFile           : fsync                        : fsync
}