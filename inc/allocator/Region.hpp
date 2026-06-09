#pragma once
#include "allocator/type/Block.hpp"
#include "allocator/type/Common.hpp"

namespace cmn::allocator
{
    struct Region:
        public type::Block <Region>,
        public type::Common<Region>
    {
        friend struct type::Block <Region>;
        friend struct type::Common<Region>;
public:
        Region(const s64 _capacity);

        ~Region          ();
        Region           (const Region  &_copied) = delete;
        Region           (      Region &&_moved ) = delete;
        Region &operator=(const Region  &_copied) = delete;
        Region &operator=(      Region &&_moved ) = delete;
private:
        bool fits__ (const s64 _size, const s64 _align) const;

        s64   available__(                  ) const;
        s64   used__     (                  ) const;
        bool  owns__     (const u08 *_memory) const;

        u08 *allocate__  (const s64 _size, const s64 _align);
        void deallocate__(const u08 *                      );
public:
              s64  capacity() const;
        const u08 *heap    () const;
              u08 *heap    ();
private:
        s64  capacity_;
        u08 *heap_;
    };
}