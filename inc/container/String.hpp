#pragma once
#include "allocator/type/Common.hpp"
#include "container/Array.hpp"

namespace cmn::container
{
    template<allocator::type::COMMON ALLOCATOR_>
    struct String:
        public Array<c08, ALLOCATOR_>
    {
public:
        String(ALLOCATOR_ &_allocator, const s64 _capacity);
        String(ALLOCATOR_ &_allocator, const s64 _capacity, const s64 _length, c08 _char);
        template<s64 LENGTH_>
        String(ALLOCATOR_ &_allocator, const c08 (&_cString)[LENGTH_]);

        ~String          ();
        String           (const String  &_copied) = delete;
        String           (      String &&_moved ) = delete;
        String &operator=(const String  &_copied) = delete;
        String &operator=(      String &&_moved ) = delete;

        void c_string(c08 *_buffer);

        void lower();
        void upper();
    };

    template <allocator::type::COMMON ALLOCATOR_> String<ALLOCATOR_>::String(ALLOCATOR_ &_allocator, const s64 _capacity):
        Array<c08, ALLOCATOR_>(_allocator, _capacity)
    { }
    template <allocator::type::COMMON ALLOCATOR_> String<ALLOCATOR_>::String(ALLOCATOR_ &_allocator, const s64 _capacity, const s64 _length, c08 _char):
        Array<c08, ALLOCATOR_>(_allocator, _capacity, _length, _char)
    { }
    template <allocator::type::COMMON ALLOCATOR_> template <s64 LENGTH_> String<ALLOCATOR_>::String(ALLOCATOR_ &_allocator, const c08 (&_cString)[LENGTH_]):
        Array<c08, ALLOCATOR_>(_allocator, LENGTH_)
    {
        for (s64 _i = 0; _i < LENGTH_ - 1; ++_i)
        {
            this->append_copy(_cString[_i]);
        }
    }

    template <allocator::type::COMMON ALLOCATOR_> String<ALLOCATOR_>::~String()
    { }

    template <allocator::type::COMMON ALLOCATOR_> void String<ALLOCATOR_>::c_string(c08 *_buffer)
    {
        s64 _i = 0;
        for (; _i < this->length_; ++_i)
        {
            _buffer[_i] = this->data_[_i];
        }
        _buffer[_i] = '\0';
    }

    template <allocator::type::COMMON ALLOCATOR_> void String<ALLOCATOR_>::lower()
    {
        for (s64 _i = 0; _i < this->length_; ++_i)
        {
            if (static_cast<s64>(this->data_[_i]) - static_cast<s64>('A') <= static_cast<s64>('Z' - 'A'))
            {
                this->data_[_i] += 'a' - 'A';
            }
        }
    }
    template <allocator::type::COMMON ALLOCATOR_> void String<ALLOCATOR_>::upper()
    {
        for (s64 _i = 0; _i < this->length_; ++_i)
        {
            if (static_cast<s64>(this->data_[_i]) - static_cast<s64>('a') <= static_cast<s64>('z' - 'a'))
            {
                this->data_[_i] += 'A' - 'a';
            }
        }
    }
}