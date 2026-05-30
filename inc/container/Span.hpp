#pragma once
#include "generic/Assert.hpp"
#include "type/Alias.hpp"

namespace cmn::container
{
    template<typename TYPE_, s64 LENGTH_>
    struct Span
    {
        COMPILER_ASSERT(LENGTH_ > 0, "A span cannot have a length of 0.\n");
public:
        static consteval s64 LENGTH() {return LENGTH_;}

        Span();
        Span(const TYPE_ &_copiedElement);
        template<typename... _TYPE>
        requires(sizeof...(_TYPE) == LENGTH_)
        Span(     _TYPE&&... _elements);
        Span(const TYPE_ ( &_copiedArray)[LENGTH_]);
        Span(      TYPE_ (&&_movedArray )[LENGTH_]);

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

        void fill    (const TYPE_ &_copiedElement, const s64 _startIndex, const s64 _stopIndex);

        s64  count   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);
        bool contains(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);
        s64  first_of(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);
        s64  last_of (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);

        const TYPE_ *begin() const;
              TYPE_ *begin();
        const TYPE_ *end  () const;
              TYPE_ *end  ();

        const TYPE_ *data() const;
              TYPE_ *data();
private:
        TYPE_ data_[LENGTH_];
    };

    template<typename TYPE_, s64 LENGTH_> Span<TYPE_, LENGTH_>::Span()
    { }
    template<typename TYPE_, s64 LENGTH_> Span<TYPE_, LENGTH_>::Span(const TYPE_ &_copiedElement)
    {
        fill(_copiedElement, 0, LENGTH_);
    }
    template<typename TYPE_, s64 LENGTH_>
    template<typename... _TYPE>
    requires(sizeof...(_TYPE) == LENGTH_)
    Span<TYPE_, LENGTH_>::Span(_TYPE&&... _elements):
        data_{static_cast<_TYPE&&>(_elements)...}
    { }
    template<typename TYPE_, s64 LENGTH_> Span<TYPE_, LENGTH_>::Span(const TYPE_ (&_copiedArray)[LENGTH_])
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            data_[_i] = _copiedArray[_i];
        }
    }
    template<typename TYPE_, s64 LENGTH_> Span<TYPE_, LENGTH_>::Span(TYPE_ (&&_movedArray )[LENGTH_])
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            data_[_i] = static_cast<TYPE_&&>(_movedArray[_i]);
        }
    }

    template<typename TYPE_, s64 LENGTH_> const TYPE_ &Span<TYPE_, LENGTH_>::operator[](s64 _index) const {return data_[_index];}
    template<typename TYPE_, s64 LENGTH_>       TYPE_ &Span<TYPE_, LENGTH_>::operator[](s64 _index)       {return data_[_index];}

    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator==(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] != _other.data_[_i]) return false;
        }
        return true;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator!=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] == _other.data_[_i]) return false;
        }
        return true;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator< (const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) return true;
            if (data_[_i] > _other.data_[_i]) return false;
        }
        return false;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator<=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) return true;
            if (data_[_i] > _other.data_[_i]) return false;
        }
        return true;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator> (const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) return true;
            if (data_[_i] < _other.data_[_i]) return false;
        }
        return false;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::operator>=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) return true;
            if (data_[_i] < _other.data_[_i]) return false;
        }
        return true;
    }

    template<typename TYPE_, s64 LENGTH_> void Span<TYPE_, LENGTH_>::fill    (const TYPE_ &_copiedElement, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            data_[_i] = _copiedElement;
        }
    }

    template<typename TYPE_, s64 LENGTH_> s64  Span<TYPE_, LENGTH_>::count   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        s64 _count = 0;
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) _count++;
        }
        return _count;
    }
    template<typename TYPE_, s64 LENGTH_> bool Span<TYPE_, LENGTH_>::contains(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) return true;
        }
        return false;
    }
    template<typename TYPE_, s64 LENGTH_> s64  Span<TYPE_, LENGTH_>::first_of(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) return _i;
        }
        return s64(-1);
    }
    template<typename TYPE_, s64 LENGTH_> s64  Span<TYPE_, LENGTH_>::last_of (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _stopIndex; _i-- > _startIndex;)
        {
            --_i;
            if (data_[_i] == _element) return _i;
        }
        return s64(-1);
    }

    template<typename TYPE_, s64 LENGTH_> const TYPE_ *Span<TYPE_, LENGTH_>::begin() const {return data_;}
    template<typename TYPE_, s64 LENGTH_>       TYPE_ *Span<TYPE_, LENGTH_>::begin()       {return data_;}
    template<typename TYPE_, s64 LENGTH_> const TYPE_ *Span<TYPE_, LENGTH_>::end  () const {return data_ + LENGTH_;}
    template<typename TYPE_, s64 LENGTH_>       TYPE_ *Span<TYPE_, LENGTH_>::end  ()       {return data_ + LENGTH_;}

    template<typename TYPE_, s64 LENGTH_> const TYPE_ *Span<TYPE_, LENGTH_>::data() const {return data_;}
    template<typename TYPE_, s64 LENGTH_>       TYPE_ *Span<TYPE_, LENGTH_>::data()       {return data_;}
}