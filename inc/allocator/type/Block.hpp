#pragma once
#include "type/Alias.hpp"

namespace cmn::allocator::type
{
    template<typename ALLOCATOR_>
    struct Block
    {
public:
        s64 fits (s64 _size) const {return static_cast<const ALLOCATOR_*>(this)->fits__ (_size);}

        s64 blocks_total    () const {return static_cast<const ALLOCATOR_*>(this)->blocks_total__    (     );}
        s64 blocks_available() const {return static_cast<const ALLOCATOR_*>(this)->blocks_available__(     );}
        s64 blocks_used     () const {return static_cast<const ALLOCATOR_*>(this)->blocks_used__     (     );}

        void deallocate(void* _memory) {return static_cast<ALLOCATOR_*>(this)->deallocate__(_memory);}
    };
}