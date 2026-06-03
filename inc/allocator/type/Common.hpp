#pragma once
#include "type/Alias.hpp"

namespace cmn::allocator::type
{
    template<typename ALLOCATOR_>
    struct Common
    {
public:
        s64   available__(             ) const {return static_cast<const ALLOCATOR_*>(this)->available__(       );}
        s64   used__     (             ) const {return static_cast<const ALLOCATOR_*>(this)->used__     (       );}
        bool  owns__     (void* _memory) const {return static_cast<const ALLOCATOR_*>(this)->owns__     (_memory);}

        void* allocate  (               s64 _size   , s64 _align  ) {return static_cast<ALLOCATOR_*>(this)->allocate__  (         _size   , _align  );}
        void* reallocate(void* _memory, s64 _oldSize, s64 _newSize) {return static_cast<ALLOCATOR_*>(this)->reallocate__(_memory, _oldSize, _newSize);}
        void  deallocate(void* _memory                            ) {       static_cast<ALLOCATOR_*>(this)->deallocate__(_memory                    );}
    };
}