#include "allocator/Region.hpp"
#include "error/Abort.hpp"
#include "error/Syscall.hpp"
#include "system/Syscall.hpp"
#include "type/Alias.hpp"

namespace cmn::allocator
{
    Region::Region(const s64 _capacity):
        capacity_(_capacity),
        heap_    (nullptr)
    {
        heap_ = reinterpret_cast<u08*>(ASSERT_SYSCALL(system::mmap(NULL, capacity_, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)));
        reinterpret_cast<s64*>(heap_)[0] = _capacity - sizeof(s64);
    }

    Region::~Region()
    {
        ASSERT_SYSCALL(system::munmap(reinterpret_cast<u64>(heap_), capacity_));
    }

    bool Region::fits__ (const s64 _size, const s64 _align) const
    {
        s64 _i = 0;
        while (_i < capacity_)
        {
            const i64  _block = reinterpret_cast<i64*>(heap_)[_i];
            const bool _used  = _block < 0;

            const s64 _totalBegin  = _i;
            const s64 _totalStart  = _totalBegin + sizeof(s64);
            const s64 _totalLength = _used ? static_cast<s64>(-_block) : static_cast<s64>(_block);

            if (_used || _totalLength < _size)
            {
                _i += _totalLength + sizeof(s64);
                continue;
            }

            const s64 _alignedStart = (_totalStart + _align - 1) & ~(_align - 1);
            if (_alignedStart == _totalStart) return true;

            const s64 _startB = (_totalStart + sizeof(s64) + _align - 1) & ~(_align - 1);
            const s64 _lengthB = _totalLength - (_startB - _totalStart);

            if (_lengthB < _size)
            {
                _i += _totalLength;
                continue;
            }

            return true;
        }

        return false;
    }

    s64   Region::available__(                  ) const
    {
        s64 _available = 0;
        s64 _i         = 0;
        while (_i < capacity_)
        {
            const i64  _block = reinterpret_cast<i64*>(heap_)[_i];
            if (_block < 0)
            {
                _i += -_block;
                continue;
            }

            _available += _block;
        }

        return _available;
    }
    s64   Region::used__     (                  ) const
    {
        s64 _used = 0;
        s64 _i    = 0;
        while (_i < capacity_)
        {
            const i64  _block = reinterpret_cast<i64*>(heap_)[_i];
            if (_block >= 0)
            {
                _i += _block;
                continue;
            }

            _used += -_block;
        }

        return _used;
    }
    bool  Region::owns__     (const u08 *_memory) const
    {
        return _memory > heap_ && _memory < heap_ + capacity_;
    }

    u08 *Region::allocate__  (const s64 _size, const s64 _align)
    {
        s64 _i = 0;
        while (_i < capacity_)
        {
            const i64  _block = reinterpret_cast<i64*>(heap_)[_i];
            const bool _used  = _block < 0;

            const s64 _totalBegin  = _i;
            const s64 _totalStart  = _totalBegin + sizeof(s64);
            const s64 _totalLength = _used ? static_cast<s64>(-_block) : static_cast<s64>(_block);


            if (_used || _totalLength < _size)
            {
                _i += _totalLength + sizeof(s64);
                continue;
            }

            const s64 _alignedStart = (_totalStart + _align - 1) & ~(_align - 1);
            if (_alignedStart == _totalStart)
            {

                if (_totalLength - _size <= sizeof(s64))
                {
                    reinterpret_cast<i64*>(heap_)[_totalBegin] = -_block;
                    return heap_ + _totalStart;
                }

                reinterpret_cast<i64*>(heap_)[_totalBegin        ] = -static_cast<i64>(_size);
                reinterpret_cast<i64*>(heap_)[_totalStart + _size] =  static_cast<i64>(_totalLength - _size - sizeof(s64));
                return heap_ + _totalStart;
            }

            const s64 _startB = (_totalStart + sizeof(s64) + _align - 1) & ~(_align - 1);
            const s64 _lengthB = _totalLength - (_startB - _totalStart);

            const s64 _startA = _totalStart;
            const s64 _lengthA = _startB - _startA - sizeof(s64);

            const s64 _beginA = _startA - sizeof(s64);
            const s64 _beginB = _startB - sizeof(s64);

            if (_lengthB < _size)
            {
                _i += _totalLength;
                continue;
            }

            if (_lengthB - _size <= sizeof(s64))
            {
                reinterpret_cast<i64*>(heap_)[_beginA] =  _lengthA;
                reinterpret_cast<i64*>(heap_)[_beginB] = -_lengthB;
                return heap_ + _totalStart;
            }

            reinterpret_cast<i64*>(heap_)[_beginA        ] =  _lengthA;
            reinterpret_cast<i64*>(heap_)[_beginB        ] = -_size;
            reinterpret_cast<i64*>(heap_)[_startB + _size] =  _lengthB - _size - sizeof(s64);

            return heap_ + _startB;
        }

        ABORT("No available space to allocate.");
    }
    void Region::deallocate__(const u08 *_memory               )
    {
        s64 _block = reinterpret_cast<s64>(_memory) - sizeof(s64) - reinterpret_cast<s64>(heap_);

        s64 _i = 0;
        s64 _prev = 0;
        while (_i < capacity_)
        {
            if (_i != _block)
            {
                _prev = _i;
                _i += math::abs(reinterpret_cast<i64*>(heap_)[_i]) + sizeof(s64);
                continue;
            }

            i64 _lengthPrev = _prev                          == _i        ? 0 : reinterpret_cast<i64*>(heap_)[_prev                         ];
            i64 _lengthCurr =                                                  -reinterpret_cast<i64*>(heap_)[_i                            ];
            i64 _lengthNext = _i + sizeof(s64) + _lengthCurr == capacity_ ? 0 : reinterpret_cast<i64*>(heap_)[_i + sizeof(s64) + _lengthCurr];

            reinterpret_cast<i64*>(heap_)[_i] = _lengthCurr;

            if (_lengthNext > 0)
            {
                _lengthCurr = _lengthCurr + sizeof(s64) + _lengthNext;
                reinterpret_cast<i64*>(heap_)[_i   ] = _lengthCurr;
            }
            if (_lengthPrev > 0)
            {
                reinterpret_cast<i64*>(heap_)[_prev] = _lengthPrev + sizeof(s64) + _lengthCurr;
            }

            return;
        }
    }

          s64  Region::capacity() const {return capacity_;}
    const u08 *Region::heap    () const {return heap_;    }
          u08 *Region::heap    ()       {return heap_;    }
}