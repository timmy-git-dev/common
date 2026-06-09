#pragma once
#include "allocator/type/Common.hpp"

namespace cmn::allocator
{
    struct Arena:
        public type::Common<Arena>
    {
        friend struct type::Common<Arena>;
public:
        Arena(const s64 _capacity);

        ~Arena          ();
        Arena           (const Arena  &_copied) = delete;
        Arena           (      Arena &&_moved ) = delete;
        Arena &operator=(const Arena  &_copied) = delete;
        Arena &operator=(      Arena &&_moved ) = delete;

        void rollback(const s64 _length  );
private:
        s64   available__(                  ) const;
        s64   used__     (                  ) const;
        bool  owns__     (const u08 *_memory) const;

        u08 *allocate__  (const s64 _size, const s64 _align);
        void deallocate__(const u08 *                      );
public:
              s64  capacity() const;
              s64  length  () const;
        const u08 *heap    () const;
              u08 *heap    ();
private:
        s64  capacity_;
        s64  length_;
        u08 *heap_;
    };
}