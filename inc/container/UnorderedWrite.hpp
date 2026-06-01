#pragma once
#include "type/Alias.hpp"

namespace cmn::container
{
    template<typename CONTAINER_, typename TYPE_>
    struct UnorderedWrite
    {
public:
        void fill    (const TYPE_ &_element                     , const s64 _startIndex, const s64 _stopIndex) {static_cast<CONTAINER_*>(this)->fill__   (_element       , _startIndex, _stopIndex);}
        void replace (const TYPE_ &_before , const TYPE_ &_after, const s64 _startIndex, const s64 _stopIndex) {static_cast<CONTAINER_*>(this)->replace__(_before, _after, _startIndex, _stopIndex);}

        TYPE_ *begin() { return static_cast<CONTAINER_>(this)->begin__();}
        TYPE_ *end  () { return static_cast<CONTAINER_>(this)->end__  ();}
    };
}