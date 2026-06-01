#pragma once
#include "type/Alias.hpp"

namespace cmn::container
{
    template<typename CONTAINER_, typename TYPE_>
    struct UnorderedRead
    {
public:
        s64  count   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex) {return static_cast<CONTAINER_*>(this)->count__   (_element, _startIndex, _stopIndex);}
        bool contains(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex) {return static_cast<CONTAINER_*>(this)->contains__(_element, _startIndex, _stopIndex);}
        s64  first_of(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex) {return static_cast<CONTAINER_*>(this)->first_of__(_element, _startIndex, _stopIndex);}
        s64  last_of (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex) {return static_cast<CONTAINER_*>(this)->last_of__ (_element, _startIndex, _stopIndex);}

        const TYPE_ *begin() const { return static_cast<CONTAINER_>(this)->begin__();}
        const TYPE_ *end  () const { return static_cast<CONTAINER_>(this)->end__  ();}
    };
}