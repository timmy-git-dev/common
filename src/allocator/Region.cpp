#pragma once
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

    bool Region::fits__ (const s64 _size) const
    {

    }

    s64   Region::available__(                  ) const
    {

    }
    s64   Region::used__     (                  ) const
    {

    }
    bool  Region::owns__     (const u08 *_memory) const
    {

    }


    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wmultichar"
    static constexpr u16 CHARS2_10_[100] =
    {
        '00', '10', '20', '30', '40', '50', '60', '70', '80', '90',
        '01', '11', '21', '31', '41', '51', '61', '71', '81', '91',
        '02', '12', '22', '32', '42', '52', '62', '72', '82', '92',
        '03', '13', '23', '33', '43', '53', '63', '73', '83', '93',
        '04', '14', '24', '34', '44', '54', '64', '74', '84', '94',
        '05', '15', '25', '35', '45', '55', '65', '75', '85', '95',
        '06', '16', '26', '36', '46', '56', '66', '76', '86', '96',
        '07', '17', '27', '37', '47', '57', '67', '77', '87', '97',
        '08', '18', '28', '38', '48', '58', '68', '78', '88', '98',
        '09', '19', '29', '39', '49', '59', '69', '79', '89', '99',
    };
    #pragma GCC diagnostic pop
    c08* to_string(u32 _value, c08* _buffer)
    {
        u32 _length =
            (_value >= 1000000000) ? 10 :
            (_value >= 100000000)  ? 9  :
            (_value >= 10000000)   ? 8  :
            (_value >= 1000000)    ? 7  :
            (_value >= 100000)     ? 6  :
            (_value >= 10000)      ? 5  :
            (_value >= 1000)       ? 4  :
            (_value >= 100)        ? 3  :
            (_value >= 10)         ? 2  : 1;

        u16* _buff = reinterpret_cast<u16*>(_buffer + (_length & 1));

        u32 _i = _length >> 1;
        while (_i > 0)
        {
            u32 _quo = _value / 100;
            u32 _rem = _value - _quo * 100;
            _value = _quo;

            _buff[--_i] = CHARS2_10_[_rem];
        }

        if (_length & 1) _buffer[0] = '0' + _value;
        _buffer[_length] = '\0';

        return _buffer;
    }

    u08 *Region::allocate__  (                       const s64 _size,                        const s64 _align)
    {
        c08 _buffer[32];


        // Possibilites:
        // 1. Not enough space to fit into aligned space.

        s64 _i = 0;
        while (_i < capacity_)
        {
            const i64  _block = reinterpret_cast<i64*>(heap_)[_i];
            const bool _used  = _block < 0;

            const s64 _totalBegin  = _i;
            const s64 _totalStart  = _totalBegin + sizeof(s64);
            const s64 _totalLength = _used ? static_cast<s64>(-_block) : static_cast<s64>(_block);


            if (_totalLength == 0) return 0;

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
    u08 *Region::reallocate__(const u08 *_oldMemory, const s64 _oldSize, const s64 _newSize, const s64 _align)
    {

    }
    void Region::deallocate__(const u08 *_memory                                                             )
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