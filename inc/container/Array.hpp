#pragma once
#include "generic/Assert.hpp"
#include "system/Syscall.hpp"
#include "type/Alias.hpp"
#include <asm-generic/mman-common.h>

namespace cmn::container
{
    template<typename TYPE_>
    struct Array
    {
public:
        Array();
        Array(const s64 _capacity, const s64 _length, const TYPE_ &_copiedElement);
        // template<typename... _TYPE>
        // Array(const s64 _capacity, _TYPE&&... _elements);

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

        void add_copy   (const TYPE_  &_copiedElement);
        void add_move   (      TYPE_ &&_movedElement );
        void insert_copy(const TYPE_  &_copiedElement, const s64 _index);
        void insert_move(      TYPE_ &&_movedElement , const s64 _index);
        void remove     (                );
        void remove     (const s64 _index);

        void reserve(const s64 _capacity);
        void resize (const s64 _length, const TYPE_ &_copiedElement);
        void fill   (const TYPE_ &_copiedElement, const s64 _startIndex, const s64 _stopIndex);

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

#define TEMPLATE template<typename TYPE_>
#define ARRAY Array<TYPE_>

    TEMPLATE ARRAY::Array():
        capacity_(0),
        length_  (0),
        data_    (nullptr)
    { }
    TEMPLATE ARRAY::Array(const s64 _capacity, const s64 _length, const TYPE_ &_copiedElement):
        capacity_(_capacity),
        length_  (_length),
        data_    (nullptr)
    {
        RUNTIME_ASSERT(_capacity >= _length, "The capacity of an array must exceed or equal it's length.");

        data_ = (s64)cmn::system::mmap((u64)nullptr, sizeof(TYPE_) * capacity_, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        // c08 _buffer[2];
        // _buffer[0] = '0' + (c08)data_;
        // _buffer[1] = '\n';
        // cmn::system::write(1, _buffer, 2);
        RUNTIME_ASSERT((u64)data_ < (u64)-4095, "Failed syscall: mmap.");

        for(s64 _i = 0; _i < length_; ++_i)
        {
            new(&data_[_i]) TYPE_(_copiedElement);
        }
    }
    // TEMPLATE template<typename... _TYPE>
    // ARRAY::Array(const s64 _capacity, _TYPE&&... _elements)
    // {

    // }

    TEMPLATE ARRAY::~Array          ()
    {
        for(s64 _i = 0; _i < length_; ++_i)
        {
            data_[_i].~TYPE_();
        }

        const s64 Bytes = sizeof(TYPE_) * capacity_;

        system::munmap((u64)data_, Bytes);
    }

    TEMPLATE const TYPE_ &ARRAY::operator[](s64 _index) const { return data_[_index]; }
    TEMPLATE       TYPE_ &ARRAY::operator[](s64 _index)       { return data_[_index]; }

    TEMPLATE bool ARRAY::operator==(const Array &_other) const
    {

    }
    TEMPLATE bool ARRAY::operator!=(const Array &_other) const
    {

    }
    TEMPLATE bool ARRAY::operator< (const Array &_other) const
    {

    }
    TEMPLATE bool ARRAY::operator<=(const Array &_other) const
    {

    }
    TEMPLATE bool ARRAY::operator> (const Array &_other) const
    {

    }
    TEMPLATE bool ARRAY::operator>=(const Array &_other) const
    {

    }

    TEMPLATE void ARRAY::add_copy   (const TYPE_  &_copiedElement)
    {

    }
    TEMPLATE void ARRAY::add_move   (      TYPE_ &&_movedElement )
    {

    }
    TEMPLATE void ARRAY::insert_copy(const TYPE_  &_copiedElement, const s64 _index)
    {

    }
    TEMPLATE void ARRAY::insert_move(      TYPE_ &&_movedElement , const s64 _index)
    {

    }
    TEMPLATE void ARRAY::remove     (                )
    {

    }
    TEMPLATE void ARRAY::remove     (const s64 _index)
    {

    }

    TEMPLATE void ARRAY::reserve(const s64 _capacity)
    {

    }
    TEMPLATE void ARRAY::resize (const s64 _length, const TYPE_ &_copiedElement)
    {

    }
    TEMPLATE void ARRAY::fill   (const TYPE_ &_copiedElement, const s64 _startIndex, const s64 _stopIndex)
    {

    }

    TEMPLATE s64  ARRAY::count   (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {

    }
    TEMPLATE bool ARRAY::contains(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {

    }
    TEMPLATE s64  ARRAY::first_of(const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {

    }
    TEMPLATE s64  ARRAY::last_of (const TYPE_ &_element, const s64 _startIndex, const s64 _stopIndex)
    {

    }

    TEMPLATE const TYPE_ *ARRAY::begin() const {return data_;}
    TEMPLATE       TYPE_ *ARRAY::begin()       {return data_;}
    TEMPLATE const TYPE_ *ARRAY::end  () const {return data_;}
    TEMPLATE       TYPE_ *ARRAY::end  ()       {return data_;}

    TEMPLATE       s64    ARRAY::capacity() const {}
    TEMPLATE       s64    ARRAY::length  () const {}
    TEMPLATE const TYPE_ *ARRAY::data    () const {}
    TEMPLATE       TYPE_ *ARRAY::data    ()       {}
}