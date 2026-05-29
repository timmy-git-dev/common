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

#define TEMPLATE template<typename TYPE_, s64 LENGTH_>
#define SPAN Span<TYPE_, LENGTH_>

    TEMPLATE SPAN::Span()
    { }
    TEMPLATE SPAN::Span(const TYPE_ &_copiedElement)
    {
        fill(_copiedElement, 0, LENGTH_);
    }
    TEMPLATE
    template<typename... _TYPE>
    requires(sizeof...(_TYPE) == LENGTH_)
    SPAN::Span(_TYPE&&... _elements):
        data_{static_cast<_TYPE&&>(_elements)...}
    { }
    TEMPLATE SPAN::Span(const TYPE_ (&_copiedArray)[LENGTH_])
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            data_[_i] = _copiedArray[_i];
        }
    }
    TEMPLATE SPAN::Span(TYPE_ (&&_movedArray )[LENGTH_])
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            data_[_i] = static_cast<TYPE_&&>(_movedArray[_i]);
        }
    }

    TEMPLATE const TYPE_ &SPAN::operator[](s64 _index) const { return data_[_index]; }
    TEMPLATE       TYPE_ &SPAN::operator[](s64 _index)       { return data_[_index]; }

    TEMPLATE bool SPAN::operator==(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] != _other.data_[_i]) return false;
        }
        return true;
    }
    TEMPLATE bool SPAN::operator!=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] == _other.data_[_i]) return false;
        }
        return true;
    }
    TEMPLATE bool SPAN::operator< (const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) return true;
            if (data_[_i] > _other.data_[_i]) return false;
        }
        return false;
    }
    TEMPLATE bool SPAN::operator<=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) return true;
            if (data_[_i] > _other.data_[_i]) return false;
        }
        return true;
    }
    TEMPLATE bool SPAN::operator> (const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) return true;
            if (data_[_i] < _other.data_[_i]) return false;
        }
        return false;
    }
    TEMPLATE bool SPAN::operator>=(const Span &_other) const
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) return true;
            if (data_[_i] < _other.data_[_i]) return false;
        }
        return true;
    }

    TEMPLATE void SPAN::fill    (const TYPE_ &_copiedElement, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            data_[_i] = _copiedElement;
        }
    }

    TEMPLATE s64  SPAN::count   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        s64 _count = 0;
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) ++_count;
        }
        return _count;
    }
    TEMPLATE bool SPAN::contains(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) return true;
        }
        return false;
    }
    TEMPLATE s64  SPAN::first_of(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) return _i;
        }
        return s64(-1);
    }
    TEMPLATE s64  SPAN::last_of (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _stopIndex; _i-- > _startIndex;)
        {
            --_i;
            if (data_[_i] == _element) return _i;
        }
        return s64(-1);
    }

    TEMPLATE const TYPE_ *SPAN::begin() const {return data_;}
    TEMPLATE       TYPE_ *SPAN::begin()       {return data_;}
    TEMPLATE const TYPE_ *SPAN::end  () const {return data_ + LENGTH_;}
    TEMPLATE       TYPE_ *SPAN::end  ()       {return data_ + LENGTH_;}

    TEMPLATE const TYPE_ *SPAN::data() const {return data_;}
    TEMPLATE       TYPE_ *SPAN::data()       {return data_;}
}