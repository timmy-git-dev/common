#pragma once
#include "container/type/Common.hpp"
#include "container/type/Resizable.hpp"
#include "container/type/Unordered.hpp"
#include "error/Syscall.hpp"

inline void* operator new(s64, void* _memory) noexcept
{
    return _memory;
}
inline void operator delete(void*, void*) noexcept
{ }

namespace cmn::container
{
    template<typename TYPE_>
    struct Array:
        public type::Common   <Array<TYPE_>, TYPE_>,
        public type::Resizable<Array<TYPE_>, TYPE_>,
        public type::Unordered<Array<TYPE_>, TYPE_>
    {
        friend struct type::Common   <Array<TYPE_>, TYPE_>;
        friend struct type::Resizable<Array<TYPE_>, TYPE_>;
        friend struct type::Unordered<Array<TYPE_>, TYPE_>;
public:
        Array(const s64 _capacity);
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

private:
        TYPE_ *begin__();
        TYPE_ *end__  ();

        bool contains__   (const TYPE_ &_element, const s64 _start, const s64 _stop) const;
        s64  count__      (const TYPE_ &_element, const s64 _start, const s64 _stop) const;
        s64  index_first__(const TYPE_ &_element, const s64 _start, const s64 _stop) const;
        s64  index_last__ (const TYPE_ &_element, const s64 _start, const s64 _stop) const;

        void fill__   (const TYPE_ &_element                     , const s64 _start, const s64 _stop);
        void replace__(const TYPE_ &_before , const TYPE_ &_after, const s64 _start, const s64 _stop);

        void append_copy__(const TYPE_  &_element                  );
        void append_move__(      TYPE_ &&_element                  );
        void insert_copy__(const TYPE_  &_element, const s64 _index);
        void insert_move__(      TYPE_ &&_element, const s64 _index);
        void remove__     (                                        );
        void remove__     (                        const s64 _index);

        void reserve__(const s64 _capacity);
public:
                  s64    capacity() const;
                  s64    length  () const;
        const     TYPE_ *data    () const;
                  TYPE_ *data    ();
private:
        s64    capacity_;
        s64    length_;
        TYPE_ *data_;
    };

    template<typename TYPE_> Array<TYPE_>::Array(const s64 _capacity):
        capacity_(_capacity),
        length_  (0),
        data_    (nullptr)
    {
        data_ = reinterpret_cast<TYPE_*>(ASSERT_SYSCALL(cmn::system::mmap(reinterpret_cast<u64>(nullptr), sizeof(TYPE_) * capacity_, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)));
    }
    template<typename TYPE_> Array<TYPE_>::Array(const s64 _capacity, const s64 _length, const TYPE_ &_element):
        capacity_(_capacity),
        length_  (_length),
        data_    (nullptr)
    {
        data_ = reinterpret_cast<TYPE_*>(ASSERT_SYSCALL(cmn::system::mmap(NULL, sizeof(TYPE_) * capacity_, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, static_cast<u64>(-1), 0ul)));

        for(s64 _i = 0; _i < length_; ++_i)
        {
            new(&data_[_i]) TYPE_(_element);
        }
    }

    template<typename TYPE_> Array<TYPE_>::~Array()
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
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] != _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<typename TYPE_> bool Array<TYPE_>::operator!=(const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] == _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<typename TYPE_> bool Array<TYPE_>::operator< (const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) {return true; }
            if (data_[_i] > _other.data_[_i]) {return false;}
        }
        return false;
    }
    template<typename TYPE_> bool Array<TYPE_>::operator<=(const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) {return true; }
            if (data_[_i] > _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<typename TYPE_> bool Array<TYPE_>::operator> (const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) {return true; }
            if (data_[_i] < _other.data_[_i]) {return false;}
        }
        return false;
    }
    template<typename TYPE_> bool Array<TYPE_>::operator>=(const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) {return true; }
            if (data_[_i] < _other.data_[_i]) {return false;}
        }
        return true;
    }

    template<typename TYPE_> TYPE_ *Array<TYPE_>::begin__() {return data_;          }
    template<typename TYPE_> TYPE_ *Array<TYPE_>::end__  () {return data_ + length_;}

    template<typename TYPE_> bool Array<TYPE_>::contains__(const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _element) {return true;}
        }

        return false;
    }
    template<typename TYPE_> s64  Array<TYPE_>::count__   (const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        s64 _count = 0;
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _element) {_count++;}
        }

        return _count;
    }
    template<typename TYPE_> s64  Array<TYPE_>::index_first__(const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _element) {return _i;}
        }

        return s64(-1);
    }
    template<typename TYPE_> s64  Array<TYPE_>::index_last__ (const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        for (s64 _i = _stop; _i-- > _start;)
        {
            if (data_[_i] == _element) {return _i;}
        }

        return s64(-1);
    }

    template<typename TYPE_> void Array<TYPE_>::fill__   (const TYPE_ & _element, const s64 _start, const s64 _stop)
    {
        for(s64 _i = _start; _i < _stop; ++_i)
        {
            data_[_i] = TYPE_(_element);
        }
    }
    template<typename TYPE_> void Array<TYPE_>::replace__(const TYPE_ &_before , const TYPE_ &_after, const s64 _start, const s64 _stop)
    {
        for(s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _before)
            {
                data_[_i] = TYPE_(_after);
            }
        }
    }

    template<typename TYPE_> void Array<TYPE_>::append_copy__(const TYPE_  &_element)
    {
        new(&data_[length_]) TYPE_(_element);
        length_++;
    }
    template<typename TYPE_> void Array<TYPE_>::append_move__(      TYPE_ &&_element)
    {
        new(&data_[length_]) TYPE_(static_cast<TYPE_&&>(_element));
        length_++;
    }
    template<typename TYPE_> void Array<TYPE_>::insert_copy__(const TYPE_  &_element, const s64 _index)
    {
        new(&data_[length_]) TYPE_(static_cast<TYPE_&&>(data_[length_ - 1]));

        for(s64 _i = length_ - 1; _i > _index; --_i)
        {
            data_[_i] = static_cast<TYPE_&&>(data_[_i - 1]);
        }

        data_[_index] = _element;
        ++length_;
    }
    template<typename TYPE_> void Array<TYPE_>::insert_move__(      TYPE_ &&_element, const s64 _index)
    {
        new(&data_[length_]) TYPE_(static_cast<TYPE_&&>(data_[length_ - 1]));

        for(s64 _i = length_ - 1; _i > _index; --_i)
        {
            data_[_i] = static_cast<TYPE_&&>(data_[_i - 1]);
        }

        data_[_index] = static_cast<TYPE_&&>(_element); // move
        ++length_;
    }
    template<typename TYPE_> void Array<TYPE_>::remove__     (                )
    {
        data_[--length_].~TYPE_();
    }
    template<typename TYPE_> void Array<TYPE_>::remove__     (const s64 _index)
    {
        data_[_index].~TYPE_();
        --length_;
        for(s64 _i = _index; _i < length_; ++_i)
        {
            data_[_i] = static_cast<TYPE_&&>(data_[_i + 1]);
        }
    }

    template<typename TYPE_>       s64    Array<TYPE_>::capacity() const {return capacity_;}
    template<typename TYPE_>       s64    Array<TYPE_>::length  () const {return length_;  }
    template<typename TYPE_> const TYPE_ *Array<TYPE_>::data    () const {return data_;    }
    template<typename TYPE_>       TYPE_ *Array<TYPE_>::data    ()       {return data_;    }
}