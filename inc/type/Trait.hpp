#pragma once

namespace cmn::type
{
    /// Provides a compile-time alias to a specified type with a removed reference.
    template<typename TYPE> struct remove_reference
    {
        /// An alias to the specified type without it's reference.
        using type = TYPE;
    };
    /// Provides a compile-time alias to a specified type with a removed reference.
    template<typename TYPE> struct remove_reference<TYPE&>
    {
        /// An alias to the specified type without it's reference.
        using type = TYPE;
    };
    /// Provides a compile-time alias to a specified type with a removed reference.
    template<typename TYPE> struct remove_reference<TYPE&&>
    {
        /// An alias to the specified type without it's reference.
        using type = TYPE;
    };

    /// Provides a compile-time boolean as to whether or not a type is an lvalue.
    template<typename TYPE> struct is_lvalue_reference
    {
        /// Whether or not the type is an lvalue.
        static constexpr bool value = false;
    };
    /// Provides a compile-time boolean as to whether or not a type is an lvalue.
    template<typename TYPE> struct is_lvalue_reference<TYPE&>
    {
        /// Whether or not the type is an lvalue.
        static constexpr bool value = true;
    };

    /// Preserves the value category of a type when passing it as a parameter to avoid copies.
    template<typename _TYPE> constexpr _TYPE &&forward(typename remove_reference<_TYPE>::type &_type) noexcept
    {
        return static_cast<_TYPE&&>(_type);
    }
    ///@desc Preserves the value category of a type when passing it as a parameter to avoid copies.
    template<typename _TYPE> constexpr _TYPE &&forward(typename remove_reference<_TYPE>::type &&_type) noexcept
    {
        static_assert(!is_lvalue_reference<_TYPE>::value, "Bad forward of an lvalue.");

        return static_cast<_TYPE&&>(_type);
    }
}