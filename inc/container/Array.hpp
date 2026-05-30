#pragma once
#include "generic/Assert.hpp"
#include "system/Syscall.hpp"
#include "type/Alias.hpp"
#include <asm-generic/mman-common.h>

inline void* operator new(s64, void* _memory) noexcept
{
    return _memory;
}
inline void operator delete(void*, void*) noexcept
{ }

namespace cmn::container
{
    template<typename TYPE_>
    struct Array
    {
public:
        Array();
        Array(const s64 _capacity, const s64 _length, const TYPE_ &_copiedElement);

        ~Array          ();
        Array           (const Array  &_copied) = delete;
        Array           (      Array &&_moved ) = delete;
        Array &operator=(const Array  &_copied) = delete;
        Array &operator=(      Array &&_moved ) = delete;

        const TYPE_ &operator[](s64 _index) const;
              TYPE_ &operator[](s64 _index);

        bool operator==(const Array &_other) const;
        bool operator!=(const Array &_other) const;
        bool operator< (const Array &_other) const;
        bool operator<=(const Array &_other) const;
        bool operator> (const Array &_other) const;
        bool operator>=(const Array &_other) const;

        void append_copy(const TYPE_  &_copiedElement);
        void append_move(      TYPE_ &&_movedElement );
        void insert_copy(const TYPE_  &_copiedElement, const s64 _index);
        void insert_move(      TYPE_ &&_movedElement , const s64 _index);
        void fill_copy  (const TYPE_ & _copiedElement, const s64 _startIndex, const s64 _stopIndex);
        void fill_move  (      TYPE_ &&_movedElement , const s64 _startIndex, const s64 _stopIndex);
        void remove     (                );
        void remove     (const s64 _index);

        void reserve(const s64 _capacity);

        s64  count   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);
        bool contains(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);
        s64  first_of(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);
        s64  last_of (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex);

        const TYPE_ *begin() const;
              TYPE_ *begin();
        const TYPE_ *end  () const;
              TYPE_ *end  ();

              s64    capacity() const;
              s64    length  () const;
        const TYPE_ *data    () const;
              TYPE_ *data    ();
private:
        s64    capacity_;
        s64    length_;
        TYPE_ *data_;
    };

    template<typename TYPE_> Array<TYPE_>::Array():
        capacity_(0),
        length_  (0),
        data_    (nullptr)
    { }
    template<typename TYPE_> Array<TYPE_>::Array(const s64 _capacity, const s64 _length, const TYPE_ &_copiedElement):
        capacity_(_capacity),
        length_  (_length),
        data_    (nullptr)
    {
        RUNTIME_ASSERT(capacity_ >= length_, "The capacity of an array must exceed or equal it's length.");

        data_ = (TYPE_*)cmn::system::mmap((u64)nullptr, sizeof(TYPE_) * capacity_, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        RUNTIME_ASSERT((u64)data_ < (u64)-4095, "Failed syscall: mmap.");

        for(s64 _i = 0; _i < length_; ++_i)
        {
            new(&data_[_i]) TYPE_(_copiedElement);
        }
    }

    template<typename TYPE_> Array<TYPE_>::~Array          ()
    {
        for(s64 _i = 0; _i < length_; ++_i)
        {
            data_[_i].~TYPE_();
        }
        system::munmap((u64)data_, sizeof(TYPE_) * capacity_);
    }

    template<typename TYPE_> const TYPE_ &Array<TYPE_>::operator[](s64 _index) const {return data_[_index];}
    template<typename TYPE_>       TYPE_ &Array<TYPE_>::operator[](s64 _index)       {return data_[_index];}

    template<typename TYPE_> bool Array<TYPE_>::operator==(const Array &_other) const
    {
        if (length_ != _other.length_) {return false;}

        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] != _other.data_[_i]) return false;
        }
        return true;
    }
    template<typename TYPE_> bool Array<TYPE_>::operator!=(const Array &_other) const
    {
        if (length_ != _other.length_) {return true;}

        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] != _other.data_[_i]) return true;
        }
        return false;
    }
    template<typename TYPE_> bool Array<TYPE_>::operator< (const Array &_other) const
    {
        s64 _length = length_ < _other.length_ ? length_ : _other.length_;

        for (s64 _i = 0; _i < _length; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) return true;
            if (data_[_i] > _other.data_[_i]) return false;
        }
        return length_ < _other.length_;
    }
    template<typename TYPE_> bool Array<TYPE_>::operator<=(const Array &_other) const
    {
        s64 _length = length_ < _other.length_ ? length_ : _other.length_;

        for (s64 _i = 0; _i < _length; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) return true;
            if (data_[_i] > _other.data_[_i]) return false;
        }
        return length_ <= _other.length_;
    }
    template<typename TYPE_> bool Array<TYPE_>::operator> (const Array &_other) const
    {
        s64 _length = length_ < _other.length_ ? length_ : _other.length_;

        for (s64 _i = 0; _i < _length; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) return true;
            if (data_[_i] < _other.data_[_i]) return false;
        }
        return length_ > _other.length_;
    }
    template<typename TYPE_> bool Array<TYPE_>::operator>=(const Array &_other) const
    {
        s64 _length = length_ < _other.length_ ? length_ : _other.length_;

        for (s64 _i = 0; _i < _length; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) return true;
            if (data_[_i] < _other.data_[_i]) return false;
        }
        return length_ >= _other.length_;
    }

    template<typename TYPE_> void Array<TYPE_>::append_copy(const TYPE_  &_copiedElement)
    {
        RUNTIME_ASSERT(length_ < capacity_, "No memory to append extra element.");

        new(&data_[length_]) TYPE_(_copiedElement);
        length_++;
    }
    template<typename TYPE_> void Array<TYPE_>::append_move(      TYPE_ &&_movedElement )
    {
        RUNTIME_ASSERT(length_ < capacity_, "No memory to append extra element.");

        new(&data_[length_]) TYPE_(static_cast<TYPE_&&>(_movedElement));
        length_++;
    }
    template<typename TYPE_> void Array<TYPE_>::insert_copy(const TYPE_  &_copiedElement, const s64 _index)
    {
        RUNTIME_ASSERT(length_ < capacity_, "No memory to insert extra element.");

        new(&data_[length_]) TYPE_(static_cast<TYPE_&&>(data_[length_ - 1]));

        for(s64 _i = length_ - 1; _i > _index; --_i)
        {
            data_[_i] = static_cast<TYPE_&&>(data_[_i - 1]);
        }

        data_[_index] = _copiedElement;
        ++length_;
    }
    template<typename TYPE_> void Array<TYPE_>::insert_move(      TYPE_ &&_movedElement , const s64 _index)
    {
        RUNTIME_ASSERT(length_ < capacity_, "No memory to insert extra element.");

        new(&data_[length_]) TYPE_(static_cast<TYPE_&&>(data_[length_ - 1]));

        for(s64 _i = length_ - 1; _i > _index; --_i)
        {
            data_[_i] = static_cast<TYPE_&&>(data_[_i - 1]);
        }

        data_[_index] = static_cast<TYPE_&&>(_movedElement); // move
        ++length_;
    }
    template<typename TYPE_> void Array<TYPE_>::fill_copy  (const TYPE_ & _copiedElement, const s64 _startIndex, const s64 _stopIndex)
    {
        for(s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            data_[_i] = TYPE_(_copiedElement);
        }
    }
    template<typename TYPE_> void Array<TYPE_>::fill_move  (      TYPE_ &&_movedElement, const s64 _startIndex, const s64 _stopIndex)
    {
        for(s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            data_[_i] = static_cast<TYPE_&&>(_movedElement);
        }
    }
    template<typename TYPE_> void Array<TYPE_>::remove     (                )
    {
        RUNTIME_ASSERT(length_ > 0, "No element to remove.");

        data_[--length_].~TYPE_();
    }
    template<typename TYPE_> void Array<TYPE_>::remove     (const s64 _index)
    {
        data_[_index].~TYPE_();
        --length_;
        for(s64 _i = _index; _i < length_; ++_i)
        {
            data_[_i] = static_cast<TYPE_&&>(data_[_i + 1]);
        }
    }

    template<typename TYPE_> void Array<TYPE_>::reserve(const s64 _capacity)
    {
        RUNTIME_ASSERT(_capacity != capacity_, "Specified array capacity unchanged, function will unecessarily reserve new array.");
        RUNTIME_ASSERT(_capacity >=  length_ , "Specified array capacity must be able to contain the previous data.");

        TYPE_ *_data = system::mmap((u64)nullptr, sizeof(TYPE_) * _capacity, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        RUNTIME_ASSERT((u64)_data < (u64)-4095, "Failed syscall: mmap.");

        for(s64 _i = 0; _i < length_; ++_i)
        {
            new(&_data[_i]) TYPE_(static_cast<TYPE_&&>(data_[_i]));
        }

        for(s64 _i = 0; _i < length_; ++_i)
        {
            data_[_i].~TYPE_();
        }
        system::munmap((u64)data_, sizeof(TYPE_) * capacity_);

        data_ = _data;
        capacity_ = _capacity;
    }

    template<typename TYPE_> s64  Array<TYPE_>::count   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        s64 _count = 0;
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) {_count++;}
        }

        return _count;
    }
    template<typename TYPE_> bool Array<TYPE_>::contains(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) {return true;}
        }

        return false;
    }
    template<typename TYPE_> s64  Array<TYPE_>::first_of(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _startIndex; _i < _stopIndex; ++_i)
        {
            if (data_[_i] == _element) {return _i;}
        }

        return s64(-1);
    }
    template<typename TYPE_> s64  Array<TYPE_>::last_of (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {
        for (s64 _i = _stopIndex; _i-- > _startIndex;)
        {
            if (data_[_i] == _element) {return _i;}
        }

        return s64(-1);
    }

    template<typename TYPE_> const TYPE_ *Array<TYPE_>::begin() const {return data_;          }
    template<typename TYPE_>       TYPE_ *Array<TYPE_>::begin()       {return data_;          }
    template<typename TYPE_> const TYPE_ *Array<TYPE_>::end  () const {return data_ + length_;}
    template<typename TYPE_>       TYPE_ *Array<TYPE_>::end  ()       {return data_ + length_;}

    template<typename TYPE_>       s64    Array<TYPE_>::capacity() const {return capacity_;}
    template<typename TYPE_>       s64    Array<TYPE_>::length  () const {return length_;  }
    template<typename TYPE_> const TYPE_ *Array<TYPE_>::data    () const {return data_;    }
    template<typename TYPE_>       TYPE_ *Array<TYPE_>::data    ()       {return data_;    }
}