#pragma once
#include "type/Alias.hpp"

namespace cmn::type::trait_
{
    template<typename TYPE_>              struct remove_const                            {using type = TYPE_;};
    template<typename TYPE_>              struct remove_const    <TYPE_  const         > {using type = TYPE_;};

    template<typename TYPE_>              struct remove_volatile                         {using type = TYPE_;};
    template<typename TYPE_>              struct remove_volatile <TYPE_        volatile> {using type = TYPE_;};

    template<typename TYPE_>              struct remove_pointer                          {using type = TYPE_;};
    template<typename TYPE_>              struct remove_pointer  <TYPE_*               > {using type = TYPE_;};
    template<typename TYPE_>              struct remove_pointer  <TYPE_* const         > {using type = TYPE_;};
    template<typename TYPE_>              struct remove_pointer  <TYPE_*       volatile> {using type = TYPE_;};
    template<typename TYPE_>              struct remove_pointer  <TYPE_* const volatile> {using type = TYPE_;};

    template<typename TYPE_>              struct remove_reference                        {using type = TYPE_;};
    template<typename TYPE_>              struct remove_reference<TYPE_& >               {using type = TYPE_;};
    template<typename TYPE_>              struct remove_reference<TYPE_&&>               {using type = TYPE_;};

    template<typename TYPE_>              struct remove_extent                           {using type = TYPE_;};
    template<typename TYPE_>              struct remove_extent   <TYPE_[ ]             > {using type = TYPE_;};
    template<typename TYPE_, s64 LENGTH_> struct remove_extent   <TYPE_[LENGTH_]       > {using type = TYPE_;};

    template<typename TYPE_>              struct remove_extents                          {using type = TYPE_;};
    template<typename TYPE_>              struct remove_extents  <TYPE_[ ]             > {using type = typename remove_extents<TYPE_>::type;};
    template<typename TYPE_, s64 LENGTH_> struct remove_extents  <TYPE_[LENGTH_]       > {using type = typename remove_extents<TYPE_>::type;};
}

namespace cmn::type::trait
{
    template<typename T> using REMOVE_CONST     = typename trait_::remove_const    <T>::type;
    template<typename T> using REMOVE_VOLATILE  = typename trait_::remove_volatile <T>::type;
    template<typename T> using REMOVE_POINTER   = typename trait_::remove_pointer  <T>::type;
    template<typename T> using REMOVE_REFERENCE = typename trait_::remove_reference<T>::type;
    template<typename T> using REMOVE_EXTENT    = typename trait_::remove_extent   <T>::type;
    template<typename T> using REMOVE_EXTENTS   = typename trait_::remove_extents  <T>::type;
}