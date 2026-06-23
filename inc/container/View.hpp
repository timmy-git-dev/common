#pragma once
#include "container/type/Common.hpp"
#include "container/type/Resizable.hpp"
#include "container/type/Unordered.hpp"

inline void* operator new(s64, void* _memory) noexcept
{
    return _memory;
}
inline void operator delete(void*, void*) noexcept
{ }

namespace cmn::container
{
    template<typename TYPE_>
    struct View:
        public type::Common   <View<TYPE_>, TYPE_>,
        public type::Resizable<View<TYPE_>, TYPE_>,
        public type::Unordered<View<TYPE_>, TYPE_>
    {
        friend struct type::Common   <View<TYPE_>, TYPE_>;
        friend struct type::Resizable<View<TYPE_>, TYPE_>;
        friend struct type::Unordered<View<TYPE_>, TYPE_>;
public:
        View(const TYPE_* _data, const s64 _length);

        ~View();
        View(const View  &_copied);
        View(      View &&_moved );
        View &operator=(const View  &_copied);
        View &operator=(      View &&_moved );

        const TYPE_ &operator[](const s64 _index) const;
              TYPE_ &operator[](const s64 _index);

        bool operator==(const View &_other) const;
        bool operator!=(const View &_other) const;
        bool operator< (const View &_other) const;
        bool operator<=(const View &_other) const;
        bool operator> (const View &_other) const;
        bool operator>=(const View &_other) const;
private:
        const TYPE_ *begin__() const;
              TYPE_ *begin__();
        const TYPE_ *end__  () const;
              TYPE_ *end__  ();

        bool contains__   (const TYPE_ &_element, const s64 _start, const s64 _stop) const;
        s64  count__      (const TYPE_ &_element, const s64 _start, const s64 _stop) const;
        s64  index_first__(const TYPE_ &_element, const s64 _start, const s64 _stop) const;
        s64  index_last__ (const TYPE_ &_element, const s64 _start, const s64 _stop) const;

        void fill__   (const TYPE_ &_element                     , const s64 _start, const s64 _stop);
        void replace__(const TYPE_ &_before , const TYPE_ &_after, const s64 _start, const s64 _stop);

        void append_copy__(TYPE_   _element                  );
        void append_move__(TYPE_ &&_element                  );
        void insert_copy__(TYPE_   _element, const s64 _index);
        void insert_move__(TYPE_ &&_element, const s64 _index);
        void remove__     (                                  );
        void remove__     (                  const s64 _index);

        void reserve__(const s64 _capacity);
public:
                  s64        length   () const;
        const     TYPE_     *data     () const;
                  TYPE_     *data     ();
private:
        s64    length_;
        TYPE_ *data_;
    };
}