#include "syscall/uni/IO.hh"
#include "error/Result.hh"

#if CMN_SYS_OS_LIN
#include "syscall/lin/Call.hh"
#elif CMN_SYS_OS_MAC
#include "syscall/mac/Call.hh"
#elif CMN_SYS_OS_WIN
#include "syscall/win/Call.hh"
#include "syscall/win/Func.hh"
#endif

namespace cmn::syscall::uni::io
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

        _output[_count] = u'\0';
        return _count;
    }

    s64 posix_to_win_path()
    {
        s64 _count = 0;

        return _count;
    }

    #endif

    PathHandle cwd_handle()
    {
        #if CMN_SYS_OS_LIN
            return AT_FDCWD;
        #elif CMN_SYS_OS_MAC
            return AT_FDCWD;
        #elif CMN_SYS_OS_WIN
            return PathHandle(win_::resolve_peb()->ProcessParameters->CurrentDirectory.Handle);
        #endif
    }

    cmn::error::Result<PathHandle, CREATE> create(const PathHandle _root, const c08 *_path, const s64 _length)
    {
        PathHandle _pathHandle;
        CREATE     _error;

        #if CMN_SYS_OS_LIN

            _pathHandle = cmn::syscall::lin::openat(_root, _path, O_WRONLY | O_CREAT | O_TRUNC, (lin::mode_t)0644);
            _error  = (u64(_pathHandle) >= u64(-4095LL)) ? CREATE(-_pathHandle) : CREATE::NONE;

        #elif CMN_SYS_OS_MAC

            _pathHandle = cmn::syscall::mac::openat(_root, (user_addr_t)_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
                (void*)_root,
                &_name,
                OBJ_CASE_INSENSITIVE,
                nullptr,
                nullptr
            };

            IO_STATUS_BLOCK _ioStatus { };
            HANDLE _handle;

            #define FILE_OPEN_IF        3
            #define FILE_CREATE         2
            #define FILE_DIRECTORY_FILE 0x00000001
            #define FILE_LIST_DIRECTORY 0x00000001

            NTSTATUS _status = cmn::syscall::win::NtCreateFile
            (
                &_handle,
                FILE_LIST_DIRECTORY | SYNCHRONIZE, // FILE_WRITE_DATA
                &_attributes,
                &_ioStatus,
                nullptr,
                FILE_ATTRIBUTE_NORMAL,
                FILE_SHARE_READ | FILE_SHARE_WRITE,
                FILE_OPEN_IF, // FILE_OVERWRITE_IF
                FILE_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT, // FILE_NON_DIRECTORY_FILE
                nullptr,
                0
            );

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








    void get_name(cmn::syscall::uni::io::PathHandle _handle, c08 *_output)
    {
        _output[0] = 0;

    #if CMN_SYS_OS_LIN

        // Build "/proc/self/fd/<handle>".
        c08 _path[32] = "/proc/self/fd/";
        c08 _digits[20];

        s64 _count = 0;
        s64 _index = 14;
        u64 _fd = u64(_handle);

        do
        {
            _digits[_count++] = c08('0' + _fd % 10);
            _fd /= 10;
        }
        while (_fd);

        while (_count > 0)
            _path[_index++] = _digits[--_count];

        _path[_index] = 0;

        // Assumes output has at least 4097 bytes.
        s64 _length = cmn::syscall::lin::readlinkat(
            -100, _path, _output, 4096
        );

        if (_length < 0)
            return;

        _output[_length] = 0;

    #elif CMN_SYS_OS_MAC

        constexpr s64 F_GETPATH = 50;

        // Assumes output has at least MAXPATHLEN bytes (normally 1024).
        s64 _result = cmn::syscall::mac::fcntl(
            _handle, F_GETPATH, (user_addr_t)_output
        );

        if (_result < 0)
            _output[0] = 0;

    #elif CMN_SYS_OS_WIN

        constexpr u32 FileNameInformation = 9;

        // Thread-local: avoids a ~64 KiB stack allocation.
        static struct
        {
            u32 FileNameLength;
            c16 FileName[32768];
        } _info;

        IO_STATUS_BLOCK _ioStatus {};

        NTSTATUS _status = cmn::syscall::win::NtQueryInformationFile(
            HANDLE(_handle),
            &_ioStatus,
            &_info,
            u32(sizeof(_info)),
            _FILE_INFORMATION_CLASS(FileNameInformation)
        );

        if (_status < 0)
            return;

        // FileNameLength counts bytes, not UTF-16 code units.
        s64 _length = _info.FileNameLength / 2;
        s64 _outputIndex = 0;

        for (s64 _index = 0; _index < _length; ++_index)
        {
            u32 _code = u32(_info.FileName[_index]);

            // UTF-16 surrogate pair.
            if (_code >= 0xD800 && _code <= 0xDBFF)
            {
                if (_index + 1 >= _length)
                    return;

                u32 _low = u32(_info.FileName[++_index]);

                if (_low < 0xDC00 || _low > 0xDFFF)
                    return;

                _code = 0x10000
                      + ((_code - 0xD800) << 10)
                      + (_low - 0xDC00);
            }
            else if (_code >= 0xDC00 && _code <= 0xDFFF)
            {
                return;
            }

            // Encode UTF-8 without changing the code point.
            if (_code <= 0x7F)
            {
                _output[_outputIndex++] = c08(_code);
            }
            else if (_code <= 0x7FF)
            {
                _output[_outputIndex++] = c08(0xC0 | (_code >> 6));
                _output[_outputIndex++] = c08(0x80 | (_code & 0x3F));
            }
            else if (_code <= 0xFFFF)
            {
                _output[_outputIndex++] = c08(0xE0 | (_code >> 12));
                _output[_outputIndex++] = c08(0x80 | ((_code >> 6) & 0x3F));
                _output[_outputIndex++] = c08(0x80 | (_code & 0x3F));
            }
            else
            {
                _output[_outputIndex++] = c08(0xF0 | (_code >> 18));
                _output[_outputIndex++] = c08(0x80 | ((_code >> 12) & 0x3F));
                _output[_outputIndex++] = c08(0x80 | ((_code >> 6) & 0x3F));
                _output[_outputIndex++] = c08(0x80 | (_code & 0x3F));
            }
        }

        _output[_outputIndex] = 0;

    #endif
    }





    // Returns:
    //   0 = successfully enumerated all entries
    //  <0 = POSIX error, or signed NTSTATUS on Windows
    //
    // _visit receives:
    //   _name    = UTF-8 filename (null-terminated)
    //   _length  = filename length in bytes, excluding '\0'
    //   _context = caller-provided data

    s64 for_each_name(cmn::syscall::uni::io::PathHandle _handle, void (*_visit)(const c08 *_name, s64 _length, void *_context), void *_context)
    {
    #if CMN_SYS_OS_LIN

        struct Dirent
        {
            u64 d_ino;
            s64 d_off;
            u16 d_reclen;
            u08 d_type;
            c08 d_name[1];
        };

        alignas(8) u08 _buffer[8192];

        while (true)
        {
            s64 _size = cmn::syscall::lin::getdents64(
                _handle,
                _buffer,
                sizeof(_buffer)
            );

            if (_size < 0)
                return _size;

            if (_size == 0)
                return 0;

            s64 _offset = 0;

            while (_offset < _size)
            {
                Dirent *_entry = (Dirent*)(_buffer + _offset);

                if (_entry->d_reclen < 20 ||
                    _entry->d_reclen > _size - _offset)
                    return -1;

                const c08 *_name = _entry->d_name;

                _offset += _entry->d_reclen;

                // Ignore "." and "..".
                if (_name[0] == '.' &&
                    (_name[1] == 0 ||
                     (_name[1] == '.' && _name[2] == 0)))
                    continue;

                s64 _length = 0;

                while (_name[_length])
                    ++_length;

                _visit(_name, _length, _context);
            }
        }

    #elif CMN_SYS_OS_MAC

        struct Dirent
        {
            u64 d_ino;
            u64 d_seekoff;
            u16 d_reclen;
            u16 d_namlen;
            u08 d_type;
            c08 d_name[1024];
        };

        alignas(8) u08 _buffer[8192];
        s64 _position = 0;

        while (true)
        {
            s64 _size = cmn::syscall::mac::getdirentries64(
                _handle,
                _buffer,
                sizeof(_buffer),
                &_position
            );

            if (_size < 0)
                return _size;

            if (_size == 0)
                return 0;

            s64 _offset = 0;

            while (_offset < _size)
            {
                Dirent *_entry = (Dirent*)(_buffer + _offset);

                if (_entry->d_reclen < 22 ||
                    _entry->d_reclen > _size - _offset)
                    return -1;

                _offset += _entry->d_reclen;

                if (_entry->d_ino == 0)
                    continue;

                const c08 *_name = _entry->d_name;
                s64 _length = _entry->d_namlen;

                if (_length == 1 && _name[0] == '.')
                    continue;

                if (_length == 2 &&
                    _name[0] == '.' && _name[1] == '.')
                    continue;

                _visit(_name, _length, _context);
            }
        }

    #elif CMN_SYS_OS_WIN

        constexpr u32 FileNamesInformation = 12;

        constexpr u32 STATUS_NO_MORE_FILES = 0x80000006;
        constexpr u32 STATUS_NO_SUCH_FILE  = 0xC000000F;

        struct FILE_NAMES_INFORMATION
        {
            u32 NextEntryOffset;
            u32 FileIndex;
            u32 FileNameLength; // Bytes
            c16 FileName[1];
        };

        // No static/TLS storage. Separate buffers per invocation.
        alignas(8) u08 _buffer[2048];
        c08 _name[1024];

        bool _restart = true;

        while (true)
        {
            IO_STATUS_BLOCK _ioStatus {};

            NTSTATUS _status = cmn::syscall::win::NtQueryDirectoryFile(
                HANDLE(_handle),
                nullptr,
                nullptr,
                nullptr,
                &_ioStatus,
                _buffer,
                u32(sizeof(_buffer)),
                _FILE_INFORMATION_CLASS(FileNamesInformation),
                0,
                nullptr,
                u08(_restart)
            );

            _restart = false;

            if (u32(_status) == STATUS_NO_MORE_FILES ||
                u32(_status) == STATUS_NO_SUCH_FILE)
                return 0;

            if (_status != 0)
                return s64(_status);

            s64 _size = s64(_ioStatus.Information);

            if (_size == 0)
                return -1; // No complete record returned.

            s64 _offset = 0;

            while (_offset < _size)
            {
                FILE_NAMES_INFORMATION *_entry =
                    (FILE_NAMES_INFORMATION*)(_buffer + _offset);

                if (_size - _offset < 12 ||
                    _entry->FileNameLength > u64(_size - _offset - 12) ||
                    (_entry->FileNameLength & 1))
                    return -1;

                s64 _length = _entry->FileNameLength / 2;
                s64 _outputIndex = 0;

                // UTF-16 -> UTF-8.
                for (s64 _index = 0; _index < _length; ++_index)
                {
                    u32 _code = u32(_entry->FileName[_index]);

                    if (_code >= 0xD800 && _code <= 0xDBFF)
                    {
                        if (_index + 1 >= _length)
                            return -1;

                        u32 _low = u32(_entry->FileName[++_index]);

                        if (_low < 0xDC00 || _low > 0xDFFF)
                            return -1;

                        _code = 0x10000
                              + ((_code - 0xD800) << 10)
                              + (_low - 0xDC00);
                    }
                    else if (_code >= 0xDC00 && _code <= 0xDFFF)
                    {
                        return -1;
                    }

                    if (_code <= 0x7F)
                    {
                        _name[_outputIndex++] = c08(_code);
                    }
                    else if (_code <= 0x7FF)
                    {
                        _name[_outputIndex++] = c08(0xC0 | (_code >> 6));
                        _name[_outputIndex++] = c08(0x80 | (_code & 0x3F));
                    }
                    else if (_code <= 0xFFFF)
                    {
                        _name[_outputIndex++] = c08(0xE0 | (_code >> 12));
                        _name[_outputIndex++] = c08(0x80 | ((_code >> 6) & 0x3F));
                        _name[_outputIndex++] = c08(0x80 | (_code & 0x3F));
                    }
                    else
                    {
                        _name[_outputIndex++] = c08(0xF0 | (_code >> 18));
                        _name[_outputIndex++] = c08(0x80 | ((_code >> 12) & 0x3F));
                        _name[_outputIndex++] = c08(0x80 | ((_code >> 6) & 0x3F));
                        _name[_outputIndex++] = c08(0x80 | (_code & 0x3F));
                    }
                }

                _name[_outputIndex] = 0;

                if (!(_outputIndex == 1 && _name[0] == '.') &&
                    !(_outputIndex == 2 &&
                      _name[0] == '.' && _name[1] == '.'))
                {
                    _visit(_name, _outputIndex, _context);
                }

                if (_entry->NextEntryOffset == 0)
                    break;

                if (_entry->NextEntryOffset > u64(_size - _offset))
                    return -1;

                _offset += _entry->NextEntryOffset;
            }
        }

    #endif
    }
}