#include "error/Error.hh"
#include "error/Result.hh"
#include "type/Alias.hh"

namespace cmn::syscall::util::path
{
    enum class PATH : error::ERROR
    {
        NONE = 0,

        INVALID_INPUT = 1,
    };

    error::Result<s64, PATH> to_win(const c08 *_inputUTF8, const s64 _length, c16 *_outputUTF16);
    s64 to_lin(const c08 *_inputUTF16, const s64 _length, c16 *_outputUTF8 );
}