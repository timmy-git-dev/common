#pragma once
#include "allocator/type/Common.hpp"
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
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    struct Array:
        public type::Common   <Array<ALLOCATOR_, TYPE_>, TYPE_>,
        public type::Resizable<Array<ALLOCATOR_, TYPE_>, TYPE_>,
        public type::Unordered<Array<ALLOCATOR_, TYPE_>, TYPE_>
    {
        friend struct type::Common   <Array<ALLOCATOR_, TYPE_>, TYPE_>;
        friend struct type::Resizable<Array<ALLOCATOR_, TYPE_>, TYPE_>;
        friend struct type::Unordered<Array<ALLOCATOR_, TYPE_>, TYPE_>;
public:
        Array(ALLOCATOR_ &_allocator, const s64 _capacity);
        Array(ALLOCATOR_ &_allocator, const s64 _capacity, const s64 _length, TYPE_ _element);

        ~Array();
        Array(const Array  &_copied);
        Array(      Array &&_moved );
        Array &operator=(const Array  &_copied);
        Array &operator=(      Array &&_moved );

        const TYPE_ &operator[](const s64 _index) const;
              TYPE_ &operator[](const s64 _index);

        bool operator==(const Array &_other) const;
        bool operator!=(const Array &_other) const;
        bool operator< (const Array &_other) const;
        bool operator<=(const Array &_other) const;
        bool operator> (const Array &_other) const;
        bool operator>=(const Array &_other) const;
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
                  s64        capacity () const;
                  s64        length   () const;
        const     ALLOCATOR_ allocator() const;
        const     TYPE_     *data     () const;
                  TYPE_     *data     ();
private:
        s64         capacity_;
        s64         length_;
        ALLOCATOR_ &allocator_;
        TYPE_      *data_;
    };

    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    Array<ALLOCATOR_, TYPE_>::Array(ALLOCATOR_ &_allocator, const s64 _capacity):
        capacity_ (_capacity ),
        length_   (0         ),
        allocator_(_allocator),
        data_     (reinterpret_cast<TYPE_*>(allocator_.allocate(sizeof(TYPE_) * capacity_, alignof(TYPE_))))
    { }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    Array<ALLOCATOR_, TYPE_>::Array(ALLOCATOR_ &_allocator, const s64 _capacity, const s64 _length, TYPE_ _element):
        capacity_ (_capacity ),
        length_   (_length   ),
        allocator_(_allocator),
        data_     (reinterpret_cast<TYPE_*>(allocator_.allocate(sizeof(TYPE_) * capacity_, alignof(TYPE_))))
    {
        for(s64 _i = 0; _i < length_; ++_i)
        {
            new(&data_[_i]) TYPE_(_element);
        }
    }

    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    Array<ALLOCATOR_, TYPE_>::~Array()
    {
        for(s64 _i = 0; _i < length_; ++_i)
        {
            data_[_i].~TYPE_();
        }
        allocator_.deallocate(reinterpret_cast<u08*>(data_));
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    Array<ALLOCATOR_, TYPE_>::Array(const Array  &_copied):
        capacity_ (_copied.capacity_ ),
        length_   (_copied.length_   ),
        allocator_(_copied.allocator_),
        data_     (reinterpret_cast<TYPE_*>(allocator_.allocate(sizeof(TYPE_) * capacity_, alignof(TYPE_))))
    {
        for(s64 _i = 0; _i < length_; ++_i)
        {
            new(&data_[_i]) TYPE_(_copied.data_[_i]);
        }
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    Array<ALLOCATOR_, TYPE_>::Array(      Array &&_moved):
        capacity_ (_moved.capacity_ ),
        length_   (_moved.length_   ),
        allocator_(_moved.allocator_),
        data_     (_moved.data_     )
    {
        _moved.capacity_ = 1;
        _moved.length_   = 0;
        _moved.data_     = reinterpret_cast<TYPE_*>(_moved.allocator_.allocate(sizeof(TYPE_) * _moved.capacity_, alignof(TYPE_)));
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    Array<ALLOCATOR_, TYPE_>& Array<ALLOCATOR_, TYPE_>::operator=(const Array  &_copied)
    {
        if(this == &_copied) return *this;

        this->~Array();

        capacity_ = _copied.capacity_;
        length_   = _copied.length_;
        data_     = reinterpret_cast<TYPE_*>(allocator_.allocate(sizeof(TYPE_) * capacity_, alignof(TYPE_)));

        for(s64 i = 0; i < length_; ++i)
        {
            new(&data_[i]) TYPE_(_copied.data_[i]);
        }

        return *this;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    Array<ALLOCATOR_, TYPE_>& Array<ALLOCATOR_, TYPE_>::operator=(      Array &&_moved)
    {
        if(this == &_moved) return *this;

        this->~Array();

        capacity_ = _moved.capacity_;
        length_   = _moved.length_;
        data_     = _moved.data_;

        _moved.capacity_ = 1;
        _moved.length_   = 0;
        _moved.data_     = reinterpret_cast<TYPE_*>(_moved.allocator_.allocate(sizeof(TYPE_) * _moved.capacity_, alignof(TYPE_)));

        return *this;
    }

    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    const TYPE_ &Array<ALLOCATOR_, TYPE_>::operator[](const s64 _index) const {return data_[_index];}
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
          TYPE_ &Array<ALLOCATOR_, TYPE_>::operator[](const s64 _index)       {return data_[_index];}

    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    bool Array<ALLOCATOR_, TYPE_>::operator==(const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] != _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    bool Array<ALLOCATOR_, TYPE_>::operator!=(const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] != _other.data_[_i]) {return true;}
        }
        return false;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    bool Array<ALLOCATOR_, TYPE_>::operator< (const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) {return true; }
            if (data_[_i] > _other.data_[_i]) {return false;}
        }
        return false;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    bool Array<ALLOCATOR_, TYPE_>::operator<=(const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] < _other.data_[_i]) {return true; }
            if (data_[_i] > _other.data_[_i]) {return false;}
        }
        return true;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    bool Array<ALLOCATOR_, TYPE_>::operator> (const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) {return true; }
            if (data_[_i] < _other.data_[_i]) {return false;}
        }
        return false;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    bool Array<ALLOCATOR_, TYPE_>::operator>=(const Array &_other) const
    {
        for (s64 _i = 0; _i < length_; ++_i)
        {
            if (data_[_i] > _other.data_[_i]) {return true; }
            if (data_[_i] < _other.data_[_i]) {return false;}
        }
        return true;
    }

    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    const TYPE_ *Array<ALLOCATOR_, TYPE_>::begin__() const {return data_;          }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
          TYPE_ *Array<ALLOCATOR_, TYPE_>::begin__()       {return data_;          }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    const TYPE_ *Array<ALLOCATOR_, TYPE_>::end__  () const {return data_ + length_;}
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
          TYPE_ *Array<ALLOCATOR_, TYPE_>::end__  ()       {return data_ + length_;}

    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    bool Array<ALLOCATOR_, TYPE_>::contains__   (const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _element) {return true;}
        }

        return false;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    s64  Array<ALLOCATOR_, TYPE_>::count__      (const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        s64 _count = 0;
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _element) {_count++;}
        }

        return _count;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    s64  Array<ALLOCATOR_, TYPE_>::index_first__(const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        for (s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _element) {return _i;}
        }

        return s64(-1);
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    s64  Array<ALLOCATOR_, TYPE_>::index_last__ (const TYPE_ &_element, const s64 _start, const s64 _stop) const
    {
        for (s64 _i = _stop; _i-- > _start;)
        {
            if (data_[_i] == _element) {return _i;}
        }

        return s64(-1);
    }

    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    void Array<ALLOCATOR_, TYPE_>::fill__   (const TYPE_ & _element                   , const s64 _start, const s64 _stop)
    {
        for(s64 _i = _start; _i < _stop; ++_i)
        {
            data_[_i] = TYPE_(_element);
        }
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    void Array<ALLOCATOR_, TYPE_>::replace__(const TYPE_ &_before, const TYPE_ &_after, const s64 _start, const s64 _stop)
    {
        for(s64 _i = _start; _i < _stop; ++_i)
        {
            if (data_[_i] == _before)
            {
                data_[_i] = TYPE_(_after);
            }
        }
    }

    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    void Array<ALLOCATOR_, TYPE_>::append_copy__(TYPE_   _element                  )
    {
        new(&data_[length_]) TYPE_(_element);
        length_++;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    void Array<ALLOCATOR_, TYPE_>::append_move__(TYPE_ &&_element                  )
    {
        new(&data_[length_]) TYPE_(static_cast<TYPE_&&>(_element));
        length_++;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    void Array<ALLOCATOR_, TYPE_>::insert_copy__(TYPE_   _element, const s64 _index)
    {
        new(&data_[length_]) TYPE_(static_cast<TYPE_&&>(data_[length_ - 1]));

        for(s64 _i = length_ - 1; _i > _index; --_i)
        {
            data_[_i] = static_cast<TYPE_&&>(data_[_i - 1]);
        }

        data_[_index] = _element;
        ++length_;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    void Array<ALLOCATOR_, TYPE_>::insert_move__(TYPE_ &&_element, const s64 _index)
    {
        new(&data_[length_]) TYPE_(static_cast<TYPE_&&>(data_[length_ - 1]));

        for(s64 _i = length_ - 1; _i > _index; --_i)
        {
            data_[_i] = static_cast<TYPE_&&>(data_[_i - 1]);
        }

        data_[_index] = static_cast<TYPE_&&>(_element); // move
        ++length_;
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    void Array<ALLOCATOR_, TYPE_>::remove__     (                                  )
    {
        data_[--length_].~TYPE_();
    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    void Array<ALLOCATOR_, TYPE_>::remove__     (                  const s64 _index)
    {
        data_[_index].~TYPE_();
        --length_;
        for(s64 _i = _index; _i < length_; ++_i)
        {
            data_[_i] = static_cast<TYPE_&&>(data_[_i + 1]);
        }
    }

    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    void Array<ALLOCATOR_, TYPE_>::reserve__(const s64 _capacity)
    {
        TYPE_* _data = reinterpret_cast<TYPE_*>(allocator_.allocate(sizeof(TYPE_) * _capacity, alignof(TYPE_)));
        for(s64 _i = 0; _i < length_; ++_i)
        {
            _data[_i] = static_cast<TYPE_&&>(data_[_i]);
        }

        data_     = _data;
        capacity_ = _capacity;
    }

    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
          s64    Array<ALLOCATOR_, TYPE_>::capacity() const {return capacity_;}
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
          s64    Array<ALLOCATOR_, TYPE_>::length  () const {return length_;  }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
    const TYPE_ *Array<ALLOCATOR_, TYPE_>::data    () const {return data_;    }
    template<allocator::type::COMMON ALLOCATOR_, typename TYPE_>
          TYPE_ *Array<ALLOCATOR_, TYPE_>::data    ()       {return data_;    }
}