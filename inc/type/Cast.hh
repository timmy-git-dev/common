#pragma once

/// Explicitly casts from a type to another, equivalent to static_cast.
template<typename TO_, typename FROM_> constexpr
TO_ cast(FROM_ &&_value) noexcept
{
    return static_cast<TO_>(static_cast<FROM_ &&>(_value));
}
/// Adds or removes const and/or volatile qualifiers to/from a type, equivalent to const_cast.
template<typename TO_, typename FROM_> constexpr
TO_ cast_cv(FROM_ &&_value) noexcept
{
    return const_cast<TO_>(static_cast<FROM_ &&>(_value));
}
/// Reinterprets the bits from a type of the same size to another, equivalent to bit_cast, similar to reinterpret cast.
template<typename TO_, typename FROM_>
constexpr TO_ cast_bits(const FROM_& _value) noexcept
{
    assert(sizeof(TO_) == sizeof(FROM_)  , "Casted types must be the same size."          );
    assert(__is_trivially_copyable(FROM_), "From casting type must be trivially copyable.");
    assert(__is_trivially_copyable(TO_  ), "To casting type must be trivially copyable."  );

    return __builtin_bit_cast(TO_, _value);
}