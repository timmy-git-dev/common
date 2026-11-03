#pragma once
#include "type/alias.hh"

namespace cmn::error
{
    using Code = i32;

    template<typename Code_>
    requires(__is_same(__underlying_type(Code_), Code))
    struct Status
    {
        Code_ code;
    };
}