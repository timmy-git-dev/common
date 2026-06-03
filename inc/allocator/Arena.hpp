#pragma once
#include "allocator/type/Common.hpp"

namespace cmn::allocator
{
    struct Arena:
        public type::Common<Arena>
    {
        friend struct Common<Arena>;
public:
        Arena(const s64 _capacity);

        ~Arena          ();
        Arena           (const Arena  &_copied) = delete;
        Arena           (      Arena &&_moved ) = delete;
        Arena &operator=(const Arena  &_copied) = delete;
        Arena &operator=(      Arena &&_moved ) = delete;

        void reset();
private:
        s64   available__(             ) const;
        s64   used__     (             ) const;
        bool  owns__     (void* _memory) const;

        void* allocate__  (               s64 _size   , s64 _align  );
        void  reallocate__(void* _memory, s64 _oldSize, s64 _newSize);
        void  deallocate__(void* _memory                            );
public:
                  s64   capacity() const;
                  s64   marker  () const;
        const     void *heap    () const;
                  void *heap    ();
private:
        s64   capacity_;
        s64   marker_;
        void *heap_;
    };
}