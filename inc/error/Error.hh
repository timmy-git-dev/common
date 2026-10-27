#pragma once
#include "type/Alias.hh"

namespace cmn::error
{
    using Code = u32;

    template<typename Code_>
    requires(__is_same(__underlying_type(Code_), Code))
    struct Error
    {
        Code_ code;
    };
}