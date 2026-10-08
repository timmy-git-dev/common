#pragma once
#include <type/Alias.hh>
namespace cmn::error
{
    using ERROR = u32;
    template<typename CODE>
    requires(__is_same(__underlying_type(CODE), ERROR))
    struct Error
    {
        CODE code;
    };
}