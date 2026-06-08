#pragma once

namespace cmn::math
{
    constexpr double PI = 3.1415926535897932384626433;

    template<typename _TYPE>
    _TYPE min  (const _TYPE &_valueA, const _TYPE &_valueB                ) {return _valueA < _valueB ? _valueA : _valueB;                 }
    template<typename _TYPE>
    _TYPE max  (const _TYPE &_valueA, const _TYPE &_valueB                ) {return _valueA > _valueB ? _valueA : _valueB;                 }
    template<typename _TYPE>
    _TYPE clamp(const _TYPE &_value , const _TYPE &_min, const _TYPE &_max) {return _value < _min ? _min : (_value > _max ? _max : _value);}

    template<typename _TYPE>
    _TYPE lerp(const _TYPE &_valueA, const _TYPE &_valueB, const _TYPE &_delta);

    template<typename _TYPE>
    _TYPE abs (const _TYPE &_value) {return _value < 0 ? -_value : _value;}
    template<typename _TYPE>
    _TYPE sign(const _TYPE &_value);

    template<typename _TYPE>
    _TYPE mod(const _TYPE &_value);
    template<typename _TYPE>
    _TYPE pow(const _TYPE &_value, const _TYPE &_exponent);

    template<typename _TYPE>
    void swap(_TYPE &_valueA, _TYPE &_valueB);
}