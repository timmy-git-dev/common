#pragma once
#include "error/Error.hh"
#include "type/Alias.hh"

namespace cmn::error
{
    template<typename Type_, typename Error_>
    requires(__is_same(__underlying_type(Error_), u32))
    struct Result
    {
        Type_         value;
        Error<Error_> error;

        Result(Type_ _value, Error_ _error) :
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