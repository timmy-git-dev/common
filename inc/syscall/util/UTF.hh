#pragma once
#include "error/Error.hh"
#include "error/Result.hh"
#include "type/Alias.hh"

namespace cmn::syscall::util::utf
{
    enum class Utf : error::CODE
    {
        NONE = 0,

        INVALID_FORMAT = 1,
    };

    // TODO: Perhaps make struct or something better to specify how many c08s/c16s were used when parsing utf -> code.
    error::Result<u32, Utf>  str8_to_code (const c08 *_utf8 , s64 &_index);
    error::Result<u32, Utf>  str16_to_code(const c16 *_utf16, s64 &_index);

    void code_to_str8 (const u32 _code, c08 *_utf8 , s64 &_index);
    void code_to_str16(const u32 _code, c16 *_utf16, s64 &_index);
}