#include "type/alias.hh"
#include "type/cast.hh"

extern "C"
{
    void *memcpy(void *_to, const void *_from, s64 _length) noexcept
    {
              u08 *_a = cast_bits<      u08*>(_to  );
        const u08 *_b = cast_bits<const u08*>(_from);

        for (__SIZE_TYPE__ _index = 0; _index < _length; ++_index)
        {
            _a[_index] = _b[_index];
        }

        return _to;
    }
}