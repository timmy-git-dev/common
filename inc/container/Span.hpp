#pragma once
#include "container/type/Common.hpp"
#include "container/type/Unordered.hpp"

namespace cmn::container
{
    template<typename TYPE_, s64 CAPACITY_>
    struct Span:
        public type::Common   <Span<TYPE_, CAPACITY_>, TYPE_>,
        public type::Unordered<Span<TYPE_, CAPACITY_>, TYPE_>
    {
        friend struct type::Common   <Span<TYPE_, CAPACITY_>, TYPE_>;
        friend struct type::Unordered<Span<TYPE_, CAPACITY_>, TYPE_>;
public:
        Span();
        Span(TYPE_ _element);
        template<typename... _TYPE>
        requires(sizeof...(_TYPE) == CAPACITY_)
        Span(_TYPE&&... _elements);

        const TYPE_ &operator[](const s64 _index) const;
              TYPE_ &operator[](const s64 _index);

        bool operator==(const Span &_other) const;
        bool operator!=(const Span &_other) const;
        bool operator< (const Span &_other) const;
        bool operator<=(const Span &_other) const;
        bool operator> (const Span &_other) const;
        bool operator>=(const Span &_other) const;
private:
        const TYPE_ *begin__() const;
              TYPE_ *begin__();
        const TYPE_ *end__  () const;
              TYPE_ *end__  ();

        s64  count__      (const TYPE_ &_element, const s64 _start, const s64 _stop) const;
        bool contains__   (const TYPE_ &_element, const s64 _start, const s64 _stop) const;
        s64  index_first__(const TYPE_ &_element, const s64 _start, const s64 _stop) const;
        s64  index_last__ (const TYPE_ &_element, const s64 _start, const s64 _stop) const;

        void fill__   (const TYPE_ &_element                     , const s64 _start, const s64 _stop);
        void replace__(const TYPE_ &_before , const TYPE_ &_after, const s64 _start, const s64 _stop);
public:
                  s64    capacity() const;
        const     TYPE_ *data    () const;
                  TYPE_ *data    ();
private:
        TYPE_ data_[CAPACITY_];
    };

    template<typename TYPE_, s64 LENGTH_>
    Span<TYPE_, LENGTH_>::Span()
    { }
    template<typename TYPE_, s64 LENGTH_>
    Span<TYPE_, LENGTH_>::Span(TYPE_ _element)
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            data_[_i] = _element;
        }
    }
    template<typename TYPE_, s64 LENGTH_>
    template<typename... _TYPE>
    requires(sizeof...(_TYPE) == LENGTH_)
    Span<TYPE_, LENGTH_>::Span(_TYPE&&... _elements):
        data_{static_cast<_TYPE&&>(_elements)...}
    { }

    template<typename TYPE_, s64 LENGTH_>
    const TYPE_ &Span<TYPE_, LENGTH_>::operator[](const s64 _index) const {return data_[_index];}
    template<typename TYPE_, s64 LENGTH_>
          TYPE_ &Span<TYPE_, LENGTH_>::operator[](const s64 _index)       {return data_[_index];}

    template<typename TYPE_, s64 LENGTH_>
    bool Span<TYPE_, LENGTH_>::operator==(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] != _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<typename TYPE_, s64 LENGTH_>
    bool Span<TYPE_, LENGTH_>::operator!=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] == _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<typename TYPE_, s64 LENGTH_>
    bool Span<TYPE_, LENGTH_>::operator< (const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) {return true; }
            if (data_[_i] > _other.data_[_i]) {return false;}
        }
        return false;
    }
    template<typename TYPE_, s64 LENGTH_>
    bool Span<TYPE_, LENGTH_>::operator<=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) {return true; }
            if (data_[_i] > _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<typename TYPE_, s64 LENGTH_>
    bool Span<TYPE_, LENGTH_>::operator>
    (const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) {return true; }
            if (data_[_i] < _other.data_[_i]) {return false;}
        }
        return false;
    }
    template<typename TYPE_, s64 LENGTH_>
    bool Span<TYPE_, LENGTH_>::operator>=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) {return true; }
            if (data_[_i] < _other.data_[_i]) {return false;}
        }
        return true;
    }

    template<typename TYPE_, s64 LENGTH_>
    const TYPE_ *Span<TYPE_, LENGTH_>::begin__() const {return data_;          }
    template<typename TYPE_, s64 LENGTH_>
          TYPE_ *Span<TYPE_, LENGTH_>::begin__()       {return data_;          }
    template<typename TYPE_, s64 LENGTH_>
    const TYPE_ *Span<TYPE_, LENGTH_>::end__  () const {return data_ + LENGTH_;}
    template<typename TYPE_, s64 LENGTH_>
          TYPE_ *Span<TYPE_, LENGTH_>::end__  ()       {return data_ + LENGTH_;}

    template<typename TYPE_, s64 LENGTH_>
    bool Span<TYPE_, LENGTH_>::contains__   (const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _element) {return true;}
        }
        return false;
    }
    template<typename TYPE_, s64 LENGTH_>
    s64  Span<TYPE_, LENGTH_>::count__      (const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        s64 _count = 0;
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _element) {_count++;}
        }
        return _count;
    }
    template<typename TYPE_, s64 LENGTH_>
    s64  Span<TYPE_, LENGTH_>::index_first__(const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _element) {return _i;}
        }
        return s64(-1);
    }
    template<typename TYPE_, s64 LENGTH_>
    s64  Span<TYPE_, LENGTH_>::index_last__ (const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        for (s64 _i = _stop; _i-- > _start;)
        {
            if (data_[_i] == _element) {return _i;}
        }
        return s64(-1);
    }

    template<typename TYPE_, s64 LENGTH_>
    void Span<TYPE_, LENGTH_>::fill__   (const TYPE_ &_element                    , const s64 _start, const s64 _stop)
    {
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            data_[_i] = _element;
        }
    }
    template<typename TYPE_, s64 LENGTH_>
    void Span<TYPE_, LENGTH_>::replace__(const TYPE_ &_before, const TYPE_ &_after, const s64 _start, const s64 _stop)
    {
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _before) {data_[_i] = _after;}
        }
    }

    template<typename TYPE_, s64 LENGTH_>
          s64    Span<TYPE_, LENGTH_>::capacity() const {return LENGTH_;}
    template<typename TYPE_, s64 LENGTH_>
    const TYPE_ *Span<TYPE_, LENGTH_>::data  () const {return data_;}
    template<typename TYPE_, s64 LENGTH_>
          TYPE_ *Span<TYPE_, LENGTH_>::data  ()       {return data_;}
}