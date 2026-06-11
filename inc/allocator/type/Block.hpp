#pragma once
#include "type/Alias.hpp"

namespace cmn::allocator::type
{
    template<typename ALLOCATOR_>
    struct Block
    {
public:
        bool fits (const s64 _size, const s64 _align) const {return static_cast<const ALLOCATOR_*>(this)->fits__ (_size, _align);}

        // s64 blocks_total    () const {return static_cast<const ALLOCATOR_*>(this)->blocks_total__    ();}
        // s64 blocks_available() const {return static_cast<const ALLOCATOR_*>(this)->blocks_available__();}
        // s64 blocks_used     () const {return static_cast<const ALLOCATOR_*>(this)->blocks_used__     ();}
    };

    template<typename TYPE_>
    concept BLOCK = __is_base_of(Block<TYPE_>, TYPE_);
}