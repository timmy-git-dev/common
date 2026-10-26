#include "syscall/util/Path.hh"
#include "sys/platform/OS.hh"
#include "syscall/win/Type.hh"

namespace cmn::syscall::util::path
{
    // TODO: This is dumb af, make some proper copy, compare, etc. funcs somewhere else.
    inline s64 memcmp(const void* _a, const void* _b, s64 _length)
    {
        const u08* _x = (const u08*)_a;
        const u08* _y = (const u08*)_b;

        for (s64 _i = 0; _i < _length; ++_i)
        {
            if (_x[_i] != _y[_i])
            {
                return _x[_i] - _y[_i];
            }
        }

        return 0;
    }


    // TODO: thread_local broken due to _tls_index, should fix cuz actually useful.
    #if CMN_SYS_OS_LIN
        constexpr s64 MAX_PATH_SIZE = 256;
        static c08 PATH_BUFFER[MAX_PATH_SIZE];
    #elif CMN_SYS_OS_MAC
        constexpr s64 MAX_PATH_SIZE = 256;
        static c08 PATH_BUFFER[MAX_PATH_SIZE];
    #elif CMN_SYS_OS_WIN
        constexpr s64 MAX_PATH_SIZE = 260;
        static c16 nativePathBuffer[MAX_PATH_SIZE];
        static u32 componentBuffer [MAX_PATH_SIZE];

        /// "/C:/dir_a/dir_b/../file.c" -> "\??\C:\dir_a\file.c"
        UNICODE_STRING to_native(const c08 *_exposedPath, const s64 _exposedPathLength)
        {
            s64 _utfCharacterCount = 0;
            s64 _skip = 0;
            s64 _componentCount = 0;

            s64 _exposedPathIndex     = _exposedPathLength;
            s64 _componentBufferIndex = MAX_PATH_SIZE;
            s64 _nativeBufferIndex    = MAX_PATH_SIZE - 1; // Reserve an extra trailing separator for when the path just points to a drive "\??\C:\".

            // Iterate backwards through the exposed path.
            while (_exposedPathIndex-- > 0)
            {
                // Count utf-8 chars until found one that is a valid start sequence.
                _utfCharacterCount++;
                if (((u08(_exposedPath[_exposedPathIndex]) & 0b11000000)) == 0b10000000)
                {
                    continue;
                }

                // Obtain the unicode-point for the utf-8 sequence.
                u32 _code;
                switch (_utfCharacterCount)
                {
                    case 1:
                    {
                        _code =
                            u32(_exposedPath[_exposedPathIndex]);
                        break;
                    }
                    case 2:
                    {
                        _code =
                            u32(_exposedPath[_exposedPathIndex    ] & 0b00011111) <<  6 |
                            u32(_exposedPath[_exposedPathIndex + 1] & 0b00111111);
                        break;
                    }
                    case 3:
                    {
                        _code =
                            u32(_exposedPath[_exposedPathIndex    ] & 0b00001111) << 12 |
                            u32(_exposedPath[_exposedPathIndex + 1] & 0b00111111) <<  6 |
                            u32(_exposedPath[_exposedPathIndex + 2] & 0b00111111);
                        break;
                    }
                    case 4:
                    {
                        _code =
                            u32(_exposedPath[_exposedPathIndex    ] & 0b00000111) << 18 |
                            u32(_exposedPath[_exposedPathIndex + 1] & 0b00111111) << 12 |
                            u32(_exposedPath[_exposedPathIndex + 2] & 0b00111111) <<  6 |
                            u32(_exposedPath[_exposedPathIndex + 3] & 0b00111111);
                        break;
                    }
                }
                _utfCharacterCount = 0;

                //  If a separator is not found, continue writing the component to the buffer.
                if (_code != '/')
                {
                    componentBuffer[--_componentBufferIndex] = _code;
                    continue;
                }

                // Get the length and reset the buffer.
                s64 _componentLength = MAX_PATH_SIZE - _componentBufferIndex;
                _componentBufferIndex = MAX_PATH_SIZE;

                // Skip trailing separators, consecutive separators/empty components, and single-period/current directory components.
                if (_componentLength == 0 || (_componentLength == 1 && componentBuffer[MAX_PATH_SIZE - 1] == '.'))
                {
                    continue;
                }

                // Skip the next valid, non-root component if the current component is two-periods.
                if (_componentLength == 1 && componentBuffer[MAX_PATH_SIZE - 2] == '.' && componentBuffer[MAX_PATH_SIZE - 1] == '.')
                {
                    _skip++;
                    continue;
                }

                // If valid, and a non-root component, skip the component if a ".." was encountered.
                if (_skip > 0 && _exposedPathIndex == 0)
                {
                    _skip--;
                    continue;
                }

                for (s64 _i = 0; _i < _componentLength; ++_i)
                {
                    _code = componentBuffer[MAX_PATH_SIZE - 1 - _i];

                    if (_code > 0b1111111111111111)
                    {
                        nativePathBuffer[--_nativeBufferIndex] = c16(0b1101100000000000 | ((_code - 0x10000) >> 10));
                        nativePathBuffer[--_nativeBufferIndex] = c16(0b1101110000000000 | ((_code - 0x10000) & 0b1111111111));
                    }
                    else
                    {
                        nativePathBuffer[--_nativeBufferIndex] = _code;
                    }
                }
                nativePathBuffer[--_nativeBufferIndex] = u'\\';
                _componentCount++;
            }

            // Prepend "\??".
            nativePathBuffer[--_nativeBufferIndex] = u'\\';
            nativePathBuffer[--_nativeBufferIndex] = u'?';
            nativePathBuffer[--_nativeBufferIndex] = u'?';

            s64 _nativePathLength = u16(MAX_PATH_SIZE - 1 - _nativeBufferIndex);

            // Append a trailing '\' separator if the path is just a drive.
            if (_componentCount == 1)
            {
                nativePathBuffer[MAX_PATH_SIZE - 1] = u'\\';
                _nativePathLength++;
            }

            // Return the native path buffer.
            return UNICODE_STRING
            {
                .Length        = u16(_nativePathLength * 2),
                .MaximumLength = u16(_nativePathLength * 2),
                .Buffer        = nativePathBuffer + _nativeBufferIndex,
            };
        }
        /// "/C:/dir_a/dir_b" + "\dir_c\file.d" -> "/C:/dir_c/file.d"
        s64 from_native_rooted_drive(const c08 *_exposedPath, const s64 _exposedPathLength, const UNICODE_STRING _nativePath, c08 *_output)
        {
            // Add the first component from _exposedPath (typically drive 'A-Z + ':') to _output, excluding the first leading '/' separator.
            // Note that if the exposed path is empty, a single '/' separator, or just a drive without an
            // extra '/' separator, the output will still be valid after appending the converted native path.
            s64 _outputIndex = 0;
            s64 _exposedPathIndex = 1;
            while (_exposedPathIndex < _exposedPathLength)
            {
                c08 _char = _exposedPath[_exposedPathIndex];

                // Break and ignore the separator if found.
                if (((u08(_char) & 0b10000000)) == 0b00000000 && _exposedPath[_exposedPathIndex] != '/')
                {
                    break;
                }

                _output[_outputIndex++] = _char;
            }

            // Convert the entire string from _nativePath to utf-8 and add to _output, ensure all '\'s are replaced with '/'.
            s64 _nativePathIndex = 0;
            const s64 _nativePathLength = _nativePath.Length / 2;
            while (_nativePathIndex < _nativePathLength)
            {
                u32 _char = _nativePath.Buffer[_nativePathIndex++];

                u32 _code = _char >= 0xD800 && _char <= 0xDBFF ?
                    0x10000 | ((_char & 0x3FF) << 10) | (_nativePath.Buffer[_nativePathIndex++] & 0x3FF) :
                    _char;

                _code = _code == '\\' ? '/' : _code;

                if (_code <= 0x7F)
                {
                    _output[_outputIndex++] = c08(_code);
                }
                else if (_code <= 0x7FF)
                {
                    _output[_outputIndex++] = c08(0b11000000 |  (_code >> 6));
                    _output[_outputIndex++] = c08(0b10000000 |  (_code & 0x3F));
                }
                else if (_code <= 0xFFFF)
                {
                    _output[_outputIndex++] = c08(0b11100000 |  (_code >> 12));
                    _output[_outputIndex++] = c08(0b10000000 | ((_code >> 6) & 0x3F));
                    _output[_outputIndex++] = c08(0b10000000 |  (_code & 0x3F));
                }
                else
                {
                    _output[_outputIndex++] = c08(0b11110000 |  (_code >> 18));
                    _output[_outputIndex++] = c08(0b10000000 | ((_code >> 12) & 0x3F));
                    _output[_outputIndex++] = c08(0b10000000 | ((_code >> 6) & 0x3F));
                    _output[_outputIndex++] = c08(0b10000000 |  (_code & 0x3F));
                }
            }

            // Return the concatenated exposed output size.
            return _outputIndex;
        }
        /// "/C:/dir_a/dir_b" + "dir_c\file.d" -> "/C:/dir_a/dir_b/dir_c/file.d"
        s64 from_native_relative(const c08 *_exposedPath, const s64 _exposedPathLength, const UNICODE_STRING _nativePath, c08 *_output)
        {
            s64 _outputIndex = 0;
            s64 _exposedPathIndex = 0;
            while (_exposedPathIndex < _exposedPathLength)
            {
                _output[_outputIndex++] = _exposedPath[_exposedPathIndex];
            }

            // Convert the entire string from _nativePath to utf-8 and add to _output, ensure all '\'s are replaced with '/'.
            s64 _nativePathIndex = 0;
            const s64 _nativePathLength = _nativePath.Length / 2;
            while (_nativePathIndex < _nativePathLength)
            {
                u32 _char = _nativePath.Buffer[_nativePathIndex++];

                u32 _code = _char >= 0xD800 && _char <= 0xDBFF ?
                    0x10000 | ((_char & 0x3FF) << 10) | (_nativePath.Buffer[_nativePathIndex++] & 0x3FF) :
                    _char;

                _code = _code == '\\' ? '/' : _code;

                if (_code <= 0x7F)
                {
                    _output[_outputIndex++] = c08(_code);
                }
                else if (_code <= 0x7FF)
                {
                    _output[_outputIndex++] = c08(0b11000000 |  (_code >> 6));
                    _output[_outputIndex++] = c08(0b10000000 |  (_code & 0x3F));
                }
                else if (_code <= 0xFFFF)
                {
                    _output[_outputIndex++] = c08(0b11100000 |  (_code >> 12));
                    _output[_outputIndex++] = c08(0b10000000 | ((_code >> 6) & 0x3F));
                    _output[_outputIndex++] = c08(0b10000000 |  (_code & 0x3F));
                }
                else
                {
                    _output[_outputIndex++] = c08(0b11110000 |  (_code >> 18));
                    _output[_outputIndex++] = c08(0b10000000 | ((_code >> 12) & 0x3F));
                    _output[_outputIndex++] = c08(0b10000000 | ((_code >> 6) & 0x3F));
                    _output[_outputIndex++] = c08(0b10000000 |  (_code & 0x3F));
                }
            }

            // Return the concatenated exposed output size.
            return _outputIndex;
        }
        /// N/A + "C:/dir_c/file.d" -> "/C:/dir_c/file.d"
        s64 from_native_absolute(const UNICODE_STRING _nativePath, c08 *_output)
        {
            s64 _outputIndex = 0;
             // Insert a '/' separator at the beginning.
            _output[_outputIndex++] = '/';

            // Convert the entire string from _nativePath to utf-8 and add to _output, ensure all '\'s are replaced with '/'.
            s64 _nativePathIndex = 0;
            const s64 _nativePathLength = _nativePath.Length / 2;
            while (_nativePathIndex < _nativePathLength)
            {
                u32 _char = _nativePath.Buffer[_nativePathIndex++];

                u32 _code = _char >= 0xD800 && _char <= 0xDBFF ?
                    0x10000 | ((_char & 0x3FF) << 10) | (_nativePath.Buffer[_nativePathIndex++] & 0x3FF) :
                    _char;

                _code = _code == '\\' ? '/' : _code;

                if (_code <= 0x7F)
                {
                    _output[_outputIndex++] = c08(_code);
                }
                else if (_code <= 0x7FF)
                {
                    _output[_outputIndex++] = c08(0b11000000 |  (_code >> 6));
                    _output[_outputIndex++] = c08(0b10000000 |  (_code & 0x3F));
                }
                else if (_code <= 0xFFFF)
                {
                    _output[_outputIndex++] = c08(0b11100000 |  (_code >> 12));
                    _output[_outputIndex++] = c08(0b10000000 | ((_code >> 6) & 0x3F));
                    _output[_outputIndex++] = c08(0b10000000 |  (_code & 0x3F));
                }
                else
                {
                    _output[_outputIndex++] = c08(0b11110000 |  (_code >> 18));
                    _output[_outputIndex++] = c08(0b10000000 | ((_code >> 12) & 0x3F));
                    _output[_outputIndex++] = c08(0b10000000 | ((_code >> 6) & 0x3F));
                    _output[_outputIndex++] = c08(0b10000000 |  (_code & 0x3F));
                }
            }

            // Return the exposed output size.
            return _outputIndex;
        }

    #endif
}