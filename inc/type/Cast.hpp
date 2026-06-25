#pragma once
#include "type/trait/Transform.hpp"
// TODO: Might need more work?
namespace cmn::type
{
    #define cast_sttc static_cast
    #define cast_cnst const_cast
    #define cast_rntp reinterpret_cast
    #define cast_dync dynamic_cast

    template<typename TYPE_> constexpr                         TYPE_ *  address_of(                        TYPE_ &  _value) {return __builtin_addressof                          (_value);}
    template<typename TYPE_> constexpr trait::REMOVE_REFERENCE<TYPE_>&& move      (                        TYPE_ && _value) {return static_cast<trait::REMOVE_REFERENCE<TYPE_>&&>(_value);}
    template<typename TYPE_> constexpr                         TYPE_ && forward   (trait::REMOVE_REFERENCE<TYPE_>&  _value) {return static_cast<                        TYPE_ &&>(_value);}
    template<typename TYPE_> constexpr                         TYPE_ && forward   (trait::REMOVE_REFERENCE<TYPE_>&& _value) {return static_cast<                        TYPE_ &&>(_value);}
    template<typename TYPE_> constexpr                         void     swap      (TYPE_& _a, TYPE_& _b                   ) {TYPE_ _c = move(_a); _a = move(_b); _b = move(_c);          }
    template<typename TYPE_> constexpr                         void     swap      (TYPE_* _a, TYPE_* _b                   ) {TYPE_ _c =     *_a; *_a =     *_b; *_b =     *_c;           }
}