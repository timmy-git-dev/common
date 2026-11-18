#include "type/alias.hh"
#include "type/cast.hh"

extern "C"
{
    void *memset(void *_to, const u08 _from, s64 _length) noexcept
    {
              u08 *_a = cast_bits<u08*>(_to);
        const u08  _b = _from;

        for (__SIZE_TYPE__ _index = 0; _index < _length; ++_index)
        {
            _a[_index] = _b;
        }

        return _to;
    }
}