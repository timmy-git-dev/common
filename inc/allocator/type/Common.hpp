#pragma once
#include "type/Alias.hpp"

namespace cmn::allocator::type
{
    template<typename ALLOCATOR_>
    struct Common
    {
public:
        s64  available(                  ) const {return static_cast<const ALLOCATOR_*>(this)->available__(       );}
        s64  used     (                  ) const {return static_cast<const ALLOCATOR_*>(this)->used__     (       );}
        bool owns     (const u08* _memory) const {return static_cast<const ALLOCATOR_*>(this)->owns__     (_memory);}

        u08* allocate  (s64 _size, s64 _align) {return static_cast<ALLOCATOR_*>(this)->allocate__  (_size, _align);}
        void deallocate(u08* _memory         ) {       static_cast<ALLOCATOR_*>(this)->deallocate__(_memory      );}
    };

    template<typename TYPE_>
    concept COMMON = __is_base_of(type::Common<TYPE_>, TYPE_);
}