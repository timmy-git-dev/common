#include "allocator/Arena.hpp"
#include "error/Syscall.hpp"

namespace cmn::allocator
{
    Arena::Arena(const s64 _capacity):
        capacity_(_capacity),
        length_  (0),
        heap_    (nullptr)
    {
        heap_ = reinterpret_cast<u08*>(ASSERT_SYSCALL(system::mmap(NULL, capacity_, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)));
    }

    Arena::~Arena()
    {
        ASSERT_SYSCALL(system::munmap(reinterpret_cast<u64>(heap_), capacity_));
    }

    void Arena::rollback(const s64 _length  ) {length_ = _length;}

    s64  Arena::available__(                  ) const {return capacity_ - length_;                          }
    s64  Arena::used__     (                  ) const {return             length_;                          }
    bool Arena::owns__     (const u08 *_memory) const {return _memory >= heap_ && _memory < heap_ + length_;}

    u08 *Arena::allocate__  (                       const s64 _size,                        const s64 _align)
    {
        length_ = (length_ + _align - 1) & ~(_align - 1);
        u08* _memory = heap_ + length_;
        length_ += _size;
        return _memory;
    }
    u08 *Arena::reallocate__(const u08 *_oldMemory, const s64 _oldSize, const s64 _newSize, const s64 _align)
    {
        length_ = (length_ + _align - 1) & ~(_align - 1);
        u08* _newMemory = heap_ + length_;
        for (s64 _i = 0; _i < _oldSize; _i++)
        {
            _newMemory[_i] = _oldMemory[_i];
        }

        length_ += _newSize;
        return _newMemory;
    }
    void Arena::deallocate__(const u08 *                                                                    )
    { }

          s64  Arena::capacity() const {return capacity_;}
          s64  Arena::length  () const {return length_  ;}
    const u08 *Arena::heap    () const {return heap_    ;}
          u08 *Arena::heap    ()       {return heap_    ;}
}