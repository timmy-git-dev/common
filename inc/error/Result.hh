#pragma once
#include "error/Error.hh"
#include "type/Alias.hh"

namespace cmn::error
{
    template<typename TYPE, typename ERROR>
    requires(__is_same(__underlying_type(ERROR), u32))
    struct Result
    {
        TYPE         value;
        Error<ERROR> error;

        Result(TYPE _value, ERROR _error) :
            value(_value),
            error(_error)
        { }
    };

    template<typename ERROR>
    struct Result<void, ERROR>
    {
        Error<ERROR> error;

        Result(ERROR _error) :
            error(_error)
        { }
    };
}