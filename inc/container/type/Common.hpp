#pragma once

namespace cmn::container::type
{
    template<typename CONTAINER_, typename TYPE_>
    struct Common
    {
public:
        const TYPE_ *begin() const { return static_cast<const CONTAINER_*>(this)->begin__();}
              TYPE_ *begin()       { return static_cast<      CONTAINER_*>(this)->begin__();}
        const TYPE_ *end  () const { return static_cast<const CONTAINER_*>(this)->end__  ();}
              TYPE_ *end  ()       { return static_cast<      CONTAINER_*>(this)->end__  ();}
    };
}