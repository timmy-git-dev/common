#pragma once
#include "type/Alias.hpp"

namespace cmn::allocator::type
{
    template<typename ALLOCATOR_>
    struct Block
    {
public:
        s64 fits__ (s64 _size) const {return static_cast<const ALLOCATOR_*>(this)->fits__ (_size);}

        s64 blocks_total__    (         ) const {return static_cast<const ALLOCATOR_*>(this)->blocks_total__    (     );}
        s64 blocks_available__(         ) const {return static_cast<const ALLOCATOR_*>(this)->blocks_available__(     );}
        s64 blocks_used__     (         ) const {return static_cast<const ALLOCATOR_*>(this)->blocks_used__     (     );}
    };
}