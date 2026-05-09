#pragma once
#include "generic/Assert.hpp"
#include "type/Alias.hpp"

namespace cmn::container
{
    template<typename TYPE, s64 LENGTH>
    class Span
    {
        CASSERT(LENGTH > 0, "A span cannot have a length of 0.\n");
public:
        Span();
        Span(const TYPE& _copiedElement);
        template<typename... _TYPE>
        requires(sizeof...(_TYPE) == LENGTH)
        Span(     _TYPE&&... _elements);
        Span(const TYPE (& _copiedArray)[LENGTH]);
        Span(      TYPE (&&_movedArray )[LENGTH]);

        ~Span          (                   ) = default;
        Span           (const Span& _copied) = delete;
        Span           (      Span&& _moved) = delete;
        Span& operator=(const Span& _copied) = delete;
        Span& operator=(      Span&& _moved) = delete;

        const TYPE& operator[](s64 _index) const;
              TYPE& operator[](s64 _index);

        bool operator== (const Span&) const;
        bool operator!= (const Span&) const;
        bool operator<  (const Span&) const;
        bool operator<= (const Span&) const;
        bool operator>  (const Span&) const;
        bool operator>= (const Span&) const;

        template<s64 _OFFSET, s64 _LENGTH>
        Span<TYPE, _LENGTH> sub_span();
        void                fill    (const TYPE& _copiedElement);
        s64                 count   (const TYPE& _element, s64 _startIndex = 0);
        bool                contains(const TYPE& _element, s64 _startIndex = 0);
        s64                 first_of(const TYPE& _element, s64 _startIndex = 0);
        s64                 last_of (const TYPE& _element, s64 _startIndex = 0);

        const TYPE* begin() const;
              TYPE* begin();
        const TYPE* end  () const;
              TYPE* end  ();

        static s64   length();
        const  TYPE* data  () const;
               TYPE* data  ();
private:
        TYPE data_[LENGTH];
    };
}