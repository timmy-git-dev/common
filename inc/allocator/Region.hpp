// #pragma once
// #include "allocator/type/Common.hpp"

// namespace cmn::allocator
// {
//     struct Arena:
//         public type::Common<Arena>
//     {
//         friend struct Common<Arena>;
// public:
//         Arena(const s64 _capacity);

//         ~Arena          ();
//         Arena           (const Arena  &_copied) = delete;
//         Arena           (      Arena &&_moved ) = delete;
//         Arena &operator=(const Arena  &_copied) = delete;
//         Arena &operator=(      Arena &&_moved ) = delete;

//         void rollback(s64 _length  );
//         void resize  (s64 _capacity);
// private:
//         s64   available__(            ) const;
//         s64   used__     (            ) const;
//         bool  owns__     (u08 *_memory) const;

//         u08 *allocate__  (                 s64 _size,                  s64 _align);
//         u08 *reallocate__(u08 *_oldMemory, s64 _oldSize, s64 _newSize, s64 _align);
// public:
//               s64  capacity() const;
//               s64  length  () const;
//         const u08 *heap    () const;
//               u08 *heap    ();
// private:
//         s64  capacity_;
//         s64  length_;
//         u08 *heap_;
//     };
// }