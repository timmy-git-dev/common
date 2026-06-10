#pragma once
#include "type/Alias.hpp"

namespace cmn::container::type
{
    template<typename CONTAINER_, typename TYPE_>
    struct Resizable
    {
public:
        void append_copy(TYPE_   _element                  ) {static_cast<CONTAINER_*>(this)->append_copy__(_element        );}
        void append_move(TYPE_ &&_element                  ) {static_cast<CONTAINER_*>(this)->append_move__(_element        );}
        void insert_copy(TYPE_   _element, const s64 _index) {static_cast<CONTAINER_*>(this)->insert_copy__(_element, _index);}
        void insert_move(TYPE_ &&_element, const s64 _index) {static_cast<CONTAINER_*>(this)->insert_move__(_element, _index);}
        void remove     (                                  ) {static_cast<CONTAINER_*>(this)->remove__     (                );}
        void remove     (                  const s64 _index) {static_cast<CONTAINER_*>(this)->remove__     (          _index);}

        void reserve(const s64 _capacity) {static_cast<CONTAINER_*>(this)->reserve__(_capacity);}
    };
}