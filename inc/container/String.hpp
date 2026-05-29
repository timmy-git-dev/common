#pragma once
#include "type/Alias.hpp"

namespace cmn::container
{
    struct String
    {
public:
        String();
        String(const s64 _capacity, const s64 _length, const char &_copiedChar);
        String(const s64 _capacity, const s64 _length, const char *_cString);

        ~String          ();
        String           (const String  &_copied) = delete;
        String           (      String &&_moved ) = delete;
        String &operator=(const String  &_copied) = delete;
        String &operator=(      String &&_moved ) = delete;

        const c08 &operator[](s64 _index) const;
              c08 &operator[](s64 _index);

        bool operator==(const String &_other) const;
        bool operator!=(const String &_other) const;
        bool operator< (const String &_other) const;
        bool operator<=(const String &_other) const;
        bool operator> (const String &_other) const;
        bool operator>=(const String &_other) const;

        void add_copy(const c08  &_copiedChar);
        void add_move(      c08 &&_movedChar );
        void insert_copy(const c08  &_copiedChar, const s64 _index);
        void insert_move(      c08 &&_movedChar , const s64 _index);
        void remove(                );
        void remove(const s64 _index);

        void reserve(const s64 _capacity);
        void resize (const s64 _length, const c08 &_copiedChar);
        void fill   (const c08 &_copiedChar);

        s64  count   (const c08 &_char, const s64 _startIndex, const s64 _stopIndex);
        bool contains(const c08 &_char, const s64 _startIndex, const s64 _stopIndex);
        s64  first_of(const c08 &_char, const s64 _startIndex, const s64 _stopIndex);
        s64  last_of (const c08 &_char, const s64 _startIndex, const s64 _stopIndex);

        const c08 *begin() const;
              c08 *begin();
        const c08 *end  () const;
              c08 *end  ();

              s64  capacity() const;
              s64  length  () const;
        const c08 *data    () const;
              c08 *data    ();
private:
        s64  capacity_;
        s64  length_;
        c08 *data_;
    };
}