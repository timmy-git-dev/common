#pragma once
#include <generic/Debug.hpp>
#include <type/Int.hpp>
#include <type/Trait.hpp>

namespace cmn::container
{
    template<typename TYPE, s64 CAPACITY> class Span
    {
        static_assert(CAPACITY > 0, "A span must have a capacity > 0.");
public:
        constexpr Span();
        template<typename... _TYPE> requires(sizeof...(_TYPE) == CAPACITY) constexpr explicit Span(_TYPE&&... _elements);

        ~Span          (                   ) noexcept = default;
        Span           (const Span& _copied) noexcept = default;
        Span           (      Span&& _moved) noexcept = default;
        Span& operator=(const Span& _copied)          = default;
        Span& operator=(      Span&& _moved) noexcept = default;

        constexpr const TYPE& operator[](s64 _index) const noexcept;
        constexpr       TYPE& operator[](s64 _index)       noexcept;

        [[nodiscard]] constexpr const TYPE* begin() const noexcept;
        [[nodiscard]] constexpr       TYPE* begin()       noexcept;
        [[nodiscard]] constexpr const TYPE* end  () const noexcept;
        [[nodiscard]] constexpr       TYPE* end  ()       noexcept;

        [[nodiscard]] constexpr       s64   capacity() const noexcept;
        [[nodiscard]] constexpr const TYPE* data    () const noexcept;
        [[nodiscard]] constexpr       TYPE* data    ()       noexcept;
private:
        TYPE data_[CAPACITY];
    };
}