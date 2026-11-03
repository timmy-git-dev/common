#include "type/alias.hh"

extern "C"
{
    void *memcpy(c08 *_to, const c08 *_from, s64 _length) noexcept
    {
        for (__SIZE_TYPE__ _index = 0; _index < _length; ++_index)
        {
            _to[_index] = _from[_index];
        }

        return _to;
    }
} // Not sure what to do about this /: