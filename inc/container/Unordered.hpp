#pragma once
#include "type/Alias.hpp"

namespace cmn::container
{
    template<typename CONTAINER_, typename TYPE_>
    struct Unordered
    {
public:
        void fill    (const TYPE_ &_element                     , const s64 _startIndex, const s64 _stopIndex) {static_cast<CONTAINER_*>(this)->fill__   (_element       , _startIndex, _stopIndex);}
        void replace (const TYPE_ &_before , const TYPE_ &_after, const s64 _startIndex, const s64 _stopIndex) {static_cast<CONTAINER_*>(this)->replace__(_before, _after, _startIndex, _stopIndex);}

        s64  count   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex) {return static_cast<CONTAINER_*>(this)->count__   (_element, _startIndex, _stopIndex);}
        bool contains(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex) {return static_cast<CONTAINER_*>(this)->contains__(_element, _startIndex, _stopIndex);}
        s64  first_of(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex) {return static_cast<CONTAINER_*>(this)->first_of__(_element, _startIndex, _stopIndex);}
        s64  last_of (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex) {return static_cast<CONTAINER_*>(this)->last_of__ (_element, _startIndex, _stopIndex);}

        const TYPE_ *begin() const { return static_cast<CONTAINER_>(this)->begin__();}
              TYPE_ *begin()       { return static_cast<CONTAINER_>(this)->begin__();}
        const TYPE_ *end  () const { return static_cast<CONTAINER_>(this)->end__  ();}
              TYPE_ *end  ()       { return static_cast<CONTAINER_>(this)->end__  ();}
    };
}