#pragma once
#include "type/Alias.hpp"

namespace cmn::container::type
{
    template<typename CONTAINER_, typename TYPE_>
    struct Unordered
    {
public:
        bool contains   (const TYPE_ &_element, const s64 _start, const s64 _stop) const {return static_cast<const CONTAINER_*>(this)->contains__   (_element, _start, _stop);}
        s64  count      (const TYPE_ &_element, const s64 _start, const s64 _stop) const {return static_cast<const CONTAINER_*>(this)->count__      (_element, _start, _stop);}
        s64  index_first(const TYPE_ &_element, const s64 _start, const s64 _stop) const {return static_cast<const CONTAINER_*>(this)->index_first__(_element, _start, _stop);}
        s64  index_last (const TYPE_ &_element, const s64 _start, const s64 _stop) const {return static_cast<const CONTAINER_*>(this)->index_last__ (_element, _start, _stop);}

        void fill    (const TYPE_ &_element                     , const s64 _start, const s64 _stop) {static_cast<CONTAINER_*>(this)->fill__   (_element       , _start, _stop);}
        void replace (const TYPE_ &_before , const TYPE_ &_after, const s64 _start, const s64 _stop) {static_cast<CONTAINER_*>(this)->replace__(_before, _after, _start, _stop);}
    };
}