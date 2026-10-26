#include "syscall/util/UTF.hh"
#include "syscall/win/Type.hh"

namespace cmn::syscall::util::path
{
    enum class PATH : error::ERROR
    {
        NONE = 0,

        INVALID_INPUT = 1,
    };

    /// "/C:/dir_a/dir_b/../file.c" -> "\??\C:\dir_a\file.c"
    UNICODE_STRING to_native               (const c08 *_exposedPath, const s64 _exposedPathLength                                                );
    /// "/C:/dir_a/dir_b" + "\dir_c\file.d" -> "/C:/dir_c/file.d"
    s64            from_native_rooted_drive(const c08 *_exposedPath, const s64 _exposedPathLength, const UNICODE_STRING _nativePath, c08 *_output);
    /// "/C:/dir_a/dir_b" + "dir_c\file.d" -> "/C:/dir_a/dir_b/dir_c/file.d"
    s64            from_native_relative    (const c08 *_exposedPath, const s64 _exposedPathLength, const UNICODE_STRING _nativePath, c08 *_output);
    /// N/A + "C:/dir_c/file.d" -> "/C:/dir_c/file.d"
    s64            from_native_absolute    (                                                       const UNICODE_STRING _nativePath, c08 *_output);
}