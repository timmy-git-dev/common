#pragma once
#include "container/Span.hpp"

namespace cmn::container
{
    template<s64 LENGTH_>
    struct Text:
        public Span<c08, LENGTH_ + 1>
    {
public:
        Text();
        Text(c08 _char);
        Text(const c08 *_cText);

        void lower();
        void upper();

        s64 length() const;
    };

    template <s64 LENGTH_>
    Text<LENGTH_>::Text():
        Span<c08, LENGTH_ + 1>()
    {

    }
    template <s64 LENGTH_>
    Text<LENGTH_>::Text(c08 _char):
        Span<c08, LENGTH_ + 1>()
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            this->data()[_i] = _char;
        }

        this->data()[LENGTH_] = '\0';
    }
    template <s64 LENGTH_>
    Text<LENGTH_>::Text(const c08 *_cText):
        Span<c08, LENGTH_ + 1>()
    {
        for (s64 _i = 0; _i < LENGTH_; ++_i)
        {
            this->append_copy(_cText[_i]);
        }

        this->data()[LENGTH_] = '\0';
    }

    template <s64 LENGTH_>
    void Text<LENGTH_>::lower()
    {
        for (s64 _i = 0; _i < length(); ++_i)
        {
            if (static_cast<s64>(this->data()[_i]) - static_cast<s64>('A') <= static_cast<s64>('Z' - 'A'))
            {
                this->data()[_i] += 'a' - 'A';
            }
        }
    }
    template <s64 LENGTH_>
    void Text<LENGTH_>::upper()
    {
        for (s64 _i = 0; _i < length(); ++_i)
        {
            if (static_cast<s64>(this->data()[_i]) - static_cast<s64>('a') <= static_cast<s64>('z' - 'a'))
            {
                this->data()[_i] += 'A' - 'a';
            }
        }
    }

    template<s64 LENGTH_>
    s64 Text<LENGTH_>::length() const {return LENGTH_;}
}