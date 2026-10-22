#include "syscall/util/Path.hh"
#include "syscall/util/UTF.hh"

namespace cmn::syscall::util::path
{
    s64 to_win(const c08 *_inputUTF8 , const s64 _length, c16 *_outputUTF16)
    {
        for (s64 _i = 0; _i < _length; ++_i)
        {
            c08 _char = _inputUTF8[_i];
            if (_char == '/')
            {
                _inputUTF8[_i] = '\\';
            }
        }
    }
    s64 to_lin(const c08 *_inputUTF16, const s64 _length, c16 _outputUTF8 );
}