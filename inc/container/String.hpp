#pragma once
#include "allocator/type/Common.hpp"
#include "container/Array.hpp"

namespace cmn::container
{
    template<allocator::type::COMMON ALLOCATOR_>
    struct String:
        public Array<ALLOCATOR_, c08>
    {
public:
        String(ALLOCATOR_ &_allocator, const s64 _capacity);
        String(ALLOCATOR_ &_allocator, const s64 _capacity, const s64 _length, c08 _char);
        String(ALLOCATOR_ &_allocator, const c08 *_cString);

        void c_string       (      c08 *_buffer );
        s64  c_string_length(const c08 *_cString) const; // TODO: Move to separate util script outside string class.

        void lower();
        void upper();
    };

    template <allocator::type::COMMON ALLOCATOR_>
    String<ALLOCATOR_>::String(ALLOCATOR_ &_allocator, const s64 _capacity):
        Array<ALLOCATOR_, c08>(_allocator, _capacity)
    { }
    template <allocator::type::COMMON ALLOCATOR_>
    String<ALLOCATOR_>::String(ALLOCATOR_ &_allocator, const s64 _capacity, const s64 _length, c08 _char):
        Array<ALLOCATOR_, c08>(_allocator, _capacity, _length, _char)
    { }
    template <allocator::type::COMMON ALLOCATOR_>
    String<ALLOCATOR_>::String(ALLOCATOR_ &_allocator, const c08 *_cString):
        Array<ALLOCATOR_, c08>(_allocator, c_string_length(_cString))
    {
        for (s64 _i = 0; _i < this->capacity(); ++_i)
        {
            this->append_copy(_cString[_i]);
        }
    }

    template <allocator::type::COMMON ALLOCATOR_>
    void String<ALLOCATOR_>::c_string(c08 *_buffer)
    {
        s64 _i = 0;
        for (; _i < this->length(); ++_i)
        {
            _buffer[_i] = this->data()[_i];
        }
        _buffer[_i] = '\0';
    }
    template <allocator::type::COMMON ALLOCATOR_>
    s64 String<ALLOCATOR_>::c_string_length(const c08 *_cString) const
    {
        s64 _length = 0;
        while(_cString[_length] != '\0') _length++;
        return _length;
    }

    template <allocator::type::COMMON ALLOCATOR_>
    void String<ALLOCATOR_>::lower()
    {
        for (s64 _i = 0; _i < this->length(); ++_i)
        {
            if (static_cast<s64>(this->data()[_i]) - static_cast<s64>('A') <= static_cast<s64>('Z' - 'A'))
            {
                this->data()[_i] += 'a' - 'A';
            }
        }
    }
    template <allocator::type::COMMON ALLOCATOR_>
    void String<ALLOCATOR_>::upper()
    {
        for (s64 _i = 0; _i < this->length(); ++_i)
        {
            if (static_cast<s64>(this->data()[_i]) - static_cast<s64>('a') <= static_cast<s64>('z' - 'a'))
            {
                this->data()[_i] += 'A' - 'a';
            }
        }
    }
}