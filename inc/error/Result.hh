#pragma once
#include <error/Error.hh>
#include <type/Alias.hh>
namespace cmn::error
{
    template<typename TYPE, typename ERROR>
    struct Result
    {
        TYPE  value;
        ERROR error;

        Result(TYPE _value, ERROR _error) :
            value(_value),
            error(_error)
        { }
    };

    template<typename ERROR>
    struct Result<void, ERROR>
    {
        ERROR error;
        Result(ERROR _error) :
            error(_error)
        { }
    };
}