#pragma once
#include "error/status.hh"
#include "type/alias.hh"

namespace cmn::error
{
    template<typename Type_, typename Status_>
    requires(__is_same(__underlying_type(Status_), i32))
    struct Result
    {
        Type_         value;
        Status<Status_> status;

        Result(Type_ _value, Status_ _status) :
            value(_value),
            status(_status)
        { }
    };

    template<typename Status_>
    struct Result<void, Status_>
    {
        Status<Status_> status;

        Result(Status_ _status) :
            status(_status)
        { }
    };
}