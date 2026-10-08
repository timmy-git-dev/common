#pragma once
#include "type/Alias.hpp"

namespace cmn::type::trait
{
    template<typename T> inline constexpr b08 IS_INTEGRAL       = __is_integral(T);
    template<typename T> inline constexpr b08 IS_FLOATING_POINT = __is_floating_point(T);
    template<typename T> inline constexpr b08 IS_VOID           = __is_void(T);

    template<typename T> inline constexpr b08 IS_ENUM           = __is_enum(T);
    template<typename T> inline constexpr b08 IS_UNION          = __is_union(T);
    template<typename T> inline constexpr b08 IS_CLASS          = __is_class(T);

    template<typename T> inline constexpr b08 IS_SIGNED         = __is_signed(T);
    template<typename T> inline constexpr b08 IS_UNSIGNED       = __is_unsigned(T);

    template<typename T> inline constexpr b08 IS_FUNCTION       = __is_function(T);
}