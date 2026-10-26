#include "syscall/util/Path.hh"
#include "syscall/util/UTF.hh"
#include "sys/platform/OS.hh"

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









    // TODO: Change "size" to "length" for naming.

    /// takes exposed path and returns the expected size when converted to a native path.
    // s64 native_size(const c08 *_exposedPath, const s64 _exposedPathLength)
    // {










    //     // lin:
    //     /// - /root/example/.. -> /root (removes "/file/..")
    //     /// - /root/example/. -> /root/example (removes "/.")
    //     // mac:
    //     /// - /root/example/.. -> /root (removes "/file/..")
    //     /// - /root/example/. -> /root/example (removes "/.")
    //     // win:
    //     /// - /root/example/.. -> /root (removes "/file/..")
    //     /// - /root/example/. -> /root/example (removes "/.")
    //     /// - /root/example -> \root\example (swaps "/" with "\", but won't change size, so don't check here.)
    //     /// - /root/example -> \??/root/example (prepends "\??" to the path)

    //     // lin: /root/example/../test/./file.txt -> /root/test/file.txt
    //     // mac: /root/example/../test/./file.txt -> /root/test/file.txt
    //     // win: /C:/example/../test/./file.txt -> \??\C:\test\file.txt


    //     // Remember, must iterate through code-points, not characters.
    //     s64 _bufferIndex = BUFFER_SIZE - 1;

    //     s64 _nativePathLength = 0;

    //     s64 _index = _exposedPathLength;
    //     s64 _utfCount = 0;
    //     s64 _skip = 0;
    //     s64 _componentUtfSize = 0;
    //     s64 _componentCount = 0;
    //     while (_index-- > 0)
    //     {
    //         _utfCount++;
    //         if (((u08(_exposedPath[_index]) & 0b11000000)) == 0b10000000)
    //         {
    //             continue;
    //         }

    //         switch (_utfCount)
    //         {
    //             case 1: buffer[_bufferIndex] = u32(_exposedPath[_index]);                                                                                                                                                                      break;
    //             case 2: buffer[_bufferIndex] = u32(_exposedPath[_index] & 0b00011111) <<  6 | u32(_exposedPath[_index + 1] & 0b00111111);                                                                                                      break;
    //             case 3: buffer[_bufferIndex] = u32(_exposedPath[_index] & 0b00001111) << 12 | u32(_exposedPath[_index + 1] & 0b00111111) <<  6 | u32(_exposedPath[_index + 2] & 0b00111111);                                                   break;
    //             case 4: buffer[_bufferIndex] = u32(_exposedPath[_index] & 0b00000111) << 18 | u32(_exposedPath[_index + 1] & 0b00111111) << 12 | u32(_exposedPath[_index + 2] & 0b00111111) << 6 | u32(_exposedPath[_index + 3] & 0b00111111); break;

    //             default: return -1; // TODO: Use result output with error.
    //         }
    //         #if CMN_SYS_OS_LIN
    //             _componentUtfSize += _utfCount;
    //         #elif CMN_SYS_OS_MAC
    //             _componentUtfSize += _utfCount;
    //         #elif CMN_SYS_OS_WIN
    //             _componentUtfSize += buffer[_bufferIndex] > 0xFFFF ? 4 : 2;
    //         #endif
    //         _utfCount = 0;

    //         if (buffer[_bufferIndex] != '/')
    //         {
    //             _bufferIndex--;
    //             continue;
    //         }

    //         s64 _componentLength = BUFFER_SIZE - 1 - _bufferIndex;
    //         _bufferIndex = BUFFER_SIZE - 1;

    //         if (_componentLength == 0 || (_componentLength == 1 && buffer[BUFFER_SIZE - 1] == '.'))
    //         {
    //             _componentUtfSize = 0;
    //             continue;
    //         }

    //         if (_componentLength == 2 && buffer[BUFFER_SIZE - 2] == '.' && buffer[BUFFER_SIZE - 1] == '.')
    //         {
    //             _skip++;
    //             _componentUtfSize = 0;
    //             continue;
    //         }

    //         #if CMN_SYS_OS_LIN
    //             if (_skip > 0)
    //         #elif CMN_SYS_OS_MAC
    //             if (_skip > 0)
    //         #elif CMN_SYS_OS_WIN
    //             if (_skip > 0 && _index != 0)
    //         #endif
    //         {
    //             _skip--;
    //             _componentUtfSize = 0;
    //             continue;
    //         }

    //         // TODO: Consider utf conversion, add the amount of utf-8/16 characters that will be in the native path.
    //         _nativePathLength += _componentUtfSize;
    //         _componentCount++;
    //         _componentUtfSize = 0;

    //         // buffer[_bufferIndex] -> buffer[BUFFER_SIZE - 1] = "/component_name"
    //     }

    //     // TODO: Windows likely needs edge case handling for root because likely fails when "\??\C:" does not contain appended '\' separator.

    //     #if CMN_SYS_OS_LIN
    //         return _componentCount == 0 ? 2 : _nativePathLength + 1; // Ensure that for "empty" paths with just root (i.e: "/", "/a/..") will be a single valid '/' and '\0' null-terminator.
    //     #elif CMN_SYS_OS_MAC
    //         return _componentCount == 0 ? 2 : _nativePathLength + 1; // Ensure that for "empty" paths with just root (i.e: "/", "/a/..") will be a single valid '/' and '\0' null-terminator.
    //     #elif CMN_SYS_OS_WIN
    //         return _nativePathLength + (_componentCount == 1 ? 8 : 6);     // If the path is just the drive ("\??\A-Z:"), append an additional '\' because windows is shit.
    //     #endif
    // }
    // /// takes native path and returns the expected size when converted to an exposed path.
    // s64 exposed_size(const u32 *_nativePath, const s64 _nativePathLength)
    // {
    //     // lin:
    //     /// - returned path is identical.
    //     // mac:
    //     /// - /root/example/.. -> /root (removes "/file/..")
    //     /// - /root/example/. -> /root/example (removes "/.")
    //     // win:
    //     /// - /root/example/.. -> /root (removes "/file/..")
    //     /// - /root/example/. -> /root/example (removes "/.")
    //     /// - /root/example -> \root\example (swaps "/" with "\", but won't change size, so don't check here.)
    //     /// - /root/example -> \??/root/example (prepends "\??" to the path)

    //     // lin:
    //     /// - /a/b + /a/b/..//c/./d.efg -> /a/c/d.efg
    //     /// - /a/b + a/b/..//c/./d.efg -> /a/c/d.efg
    //     // mac: /root/example/../test/./file.txt -> /root/test/file.txt
    //     // win: /C:/example/../test/./file.txt -> \??\C:\test\file.txt
    // }

    // /// takes exposed path and outputs native path to buffer, should be >= native_path_size().
    // void to_native(const c08 *_exposedPath, const s64 _length, u08 *_bufferNativePath)
    // {

    // }
    // /// takes native path and outputs exposed path to buffer, should be >= exposed_path_size().
    // void to_exposed(const c08 *_nativePath, const s64 _length , c08 *_bufferExposedPath)
    // {

    // }



    // error::Result<s64, PATH> component_count(const c08 *_inputUTF8, const s64 _length, c16 *_outputUTF16);
    // error::Result<s64, PATH> resolve_components(const c08 *_inputUTF8, const s64 _length, c16 *_outputUTF16);
    // s64 to_lin(const c08 *_inputUTF16, const s64 _length, c16 *_outputUTF8 );
}