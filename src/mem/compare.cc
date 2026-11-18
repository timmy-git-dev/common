#include "type/alias.hh"
#include "type/cast.hh"

extern "C"
{
    s64 memcmp(void *_a, const void *_b, s64 _length) noexcept
    {
        u08 *_x = cast_bits<u08*>(_a);
        u08 *_y = cast_bits<u08*>(_b);

        for (s64 _index = 0; _index < _length; ++_index)
        {
            if (_x[_index] != _y[_index])
            {
                return _x[_index] - _y[_index];
            }
        }

        return 0;
    }
}