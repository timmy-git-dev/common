#pragma once
#include "container/UnorderedWrite.hpp"
#include "container/UnorderedRead.hpp"

namespace cmn::container
{
    template<typename TYPE_, s64 LENGTH_>
    struct Span:
        public UnorderedRead <Span<TYPE_, LENGTH_>, TYPE_>,
        public UnorderedWrite<Span<TYPE_, LENGTH_>, TYPE_>
    {
        friend struct UnorderedRead <Span<TYPE_, LENGTH_>, TYPE_>;
        friend struct UnorderedWrite<Span<TYPE_, LENGTH_>, TYPE_>;
public:
        Span();
        Span(const TYPE_ &_element);
        template<typename... _TYPE>
        requires(sizeof...(_TYPE) == LENGTH_)
        Span(_TYPE&&... _elements);

        ~Span          () = default;
        Span           (const Span  &_copied) = delete;
        Span           (      Span &&_moved ) = delete;
        Span &operator=(const Span  &_copied) = delete;
        Span &operator=(      Span &&_moved ) = delete;

        const TYPE_ &operator[](s64 _index) const;
              TYPE_ &operator[](s64 _index);

        bool operator==(const Span &_other) const;
        bool operator!=(const Span &_other) const;
        bool operator< (const Span &_other) const;
        bool operator<=(const Span &_other) const;
        bool operator> (const Span &_other) const;
        bool operator>=(const Span &_other) const;

private:
        void fill__   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);
        void replace__(const TYPE_ &_before , const TYPE_ &_after, const s64 _startIndex, const s64 _stopIndex);

        s64  count__   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);
        bool contains__(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);
        s64  first_of__(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);
        s64  last_of__ (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);

        TYPE_ *begin__();
        TYPE_ *end__  ();
public:
                  s64    length();
        const     TYPE_ *data  () const;
                  TYPE_ *data  ();
private:
        TYPE_ data_[LENGTH_];

    };

    template<typename TYPE_, s64 LENGTH_> Span<TYPE_, LENGTH_>::Span()
    { }
    template<typename TYPE_, s64 LENGTH_> Span<TYPE_, LENGTH_>::Span(const TYPE_ &_element)
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

    template<typename TYPE_, s64 LENGTH_> const TYPE_ &Span<TYPE_, LENGTH_>::operator[](s64 _index) const {return data_[_index];}
    template<typename TYPE_, s64 LENGTH_>       TYPE_ &Span<TYPE_, LENGTH_>::operator[](s64 _index)       {return data_[_index];}

    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator==(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] != _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator!=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] == _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator< (const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) {return true; }
            if (data_[_i] > _other.data_[_i]) {return false;}
        }
        return false;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator<=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) {return true; }
            if (data_[_i] > _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator> (const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) {return true; }
            if (data_[_i] < _other.data_[_i]) {return false;}
        }
        return false;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator>=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) {return true; }
            if (data_[_i] < _other.data_[_i]) {return false;}
        }
        return true;
    }

    template<typename TYPE_, s64 LENGTH_> void Span<TYPE_, LENGTH_>::fill__   (const TYPE_ &_element                    , const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            data_[_i] = _element;
        }
    }
    template<typename TYPE_, s64 LENGTH_> void Span<TYPE_, LENGTH_>::replace__(const TYPE_ &_before, const TYPE_ &_after, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _before) {data_[_i] = _after;}
        }
    }

    template<typename TYPE_, s64 LENGTH_> s64  Span<TYPE_, LENGTH_>::count__   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        s64 _count = 0;
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) {_count++;}
        }
        return _count;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::contains__(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) {return true;}
        }
        return false;
    }
    template<typename TYPE_, s64 LENGTH_> s64  Span<TYPE_, LENGTH_>::first_of__(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) {return _i;}
        }
        return s64(-1);
    }
    template<typename TYPE_, s64 LENGTH_> s64  Span<TYPE_, LENGTH_>::last_of__ (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _stopIndex; _i-- > _startIndex;)
        {
            if (data_[_i] == _element) {return _i;}
        }
        return s64(-1);
    }

    template<typename TYPE_, s64 LENGTH_> TYPE_ *Span<TYPE_, LENGTH_>::begin__() {return data_;          }
    template<typename TYPE_, s64 LENGTH_> TYPE_ *Span<TYPE_, LENGTH_>::end__  () {return data_ + LENGTH_;}

    template<typename TYPE_, s64 LENGTH_>       s64    Span<TYPE_, LENGTH_>::length()       {return LENGTH_;}
    template<typename TYPE_, s64 LENGTH_> const TYPE_ *Span<TYPE_, LENGTH_>::data  () const {return data_;}
    template<typename TYPE_, s64 LENGTH_>       TYPE_ *Span<TYPE_, LENGTH_>::data  ()       {return data_;}
}