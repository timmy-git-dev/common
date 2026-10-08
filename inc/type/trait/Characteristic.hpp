#pragma once
#include "type/Alias.hpp"

namespace cmn::type::trait_
{
    template<typename TYPE_> struct is_lvalue          {static constexpr b08 value = false;};
    template<typename TYPE_> struct is_lvalue<TYPE_& > {static constexpr b08 value = true; };

    template<typename TYPE_> struct is_rvalue          {static constexpr b08 value = false;};
    template<typename TYPE_> struct is_rvalue<TYPE_&&> {static constexpr b08 value = true; };
}

namespace cmn::type::trait
{
    template<typename TYPE_                > inline constexpr b08 IS_LVALUE          = trait_::is_lvalue   <TYPE_ >::value;
    template<typename TYPE_                > inline constexpr b08 IS_RVALUE          = trait_::is_rvalue   <TYPE_ >::value;

    template<typename TYPE_                > inline constexpr b08 IS_CONST           = __is_const                  (TYPE_     );
    template<typename TYPE_                > inline constexpr b08 IS_VOLATILE        = __is_volatile               (TYPE_     );
    template<typename TYPE_                > inline constexpr b08 IS_POINTER         = __is_pointer                (TYPE_     );
    template<typename TYPE_                > inline constexpr b08 IS_REFERENCE       = __is_reference              (TYPE_     );
    template<typename TYPE_                > inline constexpr b08 IS_ARRAY           = __is_array                  (TYPE_     );

    template<typename A_   , typename B_   > inline constexpr b08 IS_SAME            = __is_same                   (A_, B_    );

    template<typename TYPE_                > inline constexpr b08 IS_TRIVIAL_CTOR    = __is_trivially_constructible(TYPE_     );
    template<typename TYPE_                > inline constexpr b08 IS_TRIVIAL_DTOR    = __is_trivially_destructible (TYPE_     );
    template<typename TO_  , typename FROM_> inline constexpr b08 IS_TRIVIAL_ASGN    = __is_trivially_assignable   (TO_, FROM_);

    template<typename TYPE_                > inline constexpr b08 IS_STANDARD_LAYOUT = __is_standard_layout        (TYPE_     );
    template<typename TYPE_                > inline constexpr b08 IS_EMPTY           = __is_empty                  (TYPE_     );
    template<typename TYPE_                > inline constexpr b08 IS_POD             = __is_pod                    (TYPE_     );

    template<typename BASE_, typename TYPE_> inline constexpr b08 IS_BASE_OF         = __is_base_of                (BASE_, TYPE_);
    template<typename TO_  , typename FROM_> inline constexpr b08 IS_CONVERTIBLE     = __is_convertible            (TO_, FROM_);

    template<typename TYPE_                > inline constexpr b08 IS_POLYMORPHIC     = __is_polymorphic            (TYPE_     );
    template<typename TYPE_                > inline constexpr b08 IS_ABSTRACT        = __is_abstract               (TYPE_     );
    template<typename TYPE_                > inline constexpr b08 IS_FINAL           = __is_final                  (TYPE_     );
}