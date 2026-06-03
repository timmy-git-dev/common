#pragma once
#include "type/Alias.hpp"

namespace cmn::container
{
    template<typename CONTAINER_, typename TYPE_>
    struct Unordered
    {
public:
        const TYPE_ *begin() const { return static_cast<const CONTAINER_*>(this)->begin__();}
              TYPE_ *begin()       { return static_cast<      CONTAINER_*>(this)->begin__();}
        const TYPE_ *end  () const { return static_cast<const CONTAINER_*>(this)->end__  ();}
              TYPE_ *end  ()       { return static_cast<      CONTAINER_*>(this)->end__  ();}

        bool contains(const TYPE_ &_element, const s64 _start, const s64 _stop) const {return static_cast<const CONTAINER_*>(this)->contains__(_element, _start, _stop);}
        s64  count   (const TYPE_ &_element, const s64 _start, const s64 _stop) const {return static_cast<const CONTAINER_*>(this)->count__   (_element, _start, _stop);}
        s64  first_of(const TYPE_ &_element, const s64 _start, const s64 _stop) const {return static_cast<const CONTAINER_*>(this)->first_of__(_element, _start, _stop);}
        s64  last_of (const TYPE_ &_element, const s64 _start, const s64 _stop) const {return static_cast<const CONTAINER_*>(this)->last_of__ (_element, _start, _stop);}

        void fill    (const TYPE_ &_element                     , const s64 _start, const s64 _stop) {static_cast<CONTAINER_*>(this)->fill__   (_element       , _start, _stop);}
        void replace (const TYPE_ &_before , const TYPE_ &_after, const s64 _start, const s64 _stop) {static_cast<CONTAINER_*>(this)->replace__(_before, _after, _start, _stop);}
    };
}