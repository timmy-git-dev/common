#pragma once
#include <cstdint>
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
        size_t test;
    };
}


// Span<TYPE, LENGTH>:
    // ctor:
        constexpr Span() noexcept; // Value-initialize all elements.
        constexpr explicit Span(const TYPE& value) noexcept; // Fill with value.
        template<typename... Args> requires(sizeof...(Args) == LENGTH)
        constexpr explicit Span(Args&&... elems) noexcept; // Direct-init.
        constexpr explicit Span(std::initializer_list<TYPE> il) noexcept; // il.size()==LENGTH.
        constexpr explicit Span(const TYPE* ptr) noexcept; // Copy from buffer.
        constexpr explicit Span(TYPE* ptr) noexcept; // Copy from mutable buffer.
        template<size_t N> requires(N == LENGTH)
        constexpr explicit Span(const TYPE (&arr)[N]) noexcept; // From C-array.
        template<typename It>
        constexpr Span(It first, It last); // distance == LENGTH.
        constexpr Span(const Span&) noexcept = default; // Copy-ctor.
        constexpr Span(Span&&) noexcept = default; // Move-ctor.
        template<typename U>
        constexpr explicit Span(const Span<U, LENGTH>& other) noexcept; // Convertible copy.
        template<typename U>
        constexpr explicit Span(Span<U, LENGTH>&& other) noexcept; // Convertible move.
    // dtor:
        constexpr ~Span() noexcept = default; // Trivial if TYPE is trivial.
    // operators:
        constexpr Span& operator=(const Span&) noexcept = default; // Copy-assign.
        constexpr Span& operator=(Span&&) noexcept = default; // Move-assign.
        constexpr Span& operator=(std::initializer_list<TYPE> il) noexcept; // Assign il.
        [[nodiscard]] constexpr auto operator<=>(const Span&) const noexcept; // Lexicographic.
        [[nodiscard]] constexpr bool operator==(const Span&) const noexcept; // Equality.
        [[nodiscard]] constexpr bool operator!=(const Span&) const noexcept; // Inequality.
        [[nodiscard]] constexpr bool operator<(const Span&) const noexcept;
        [[nodiscard]] constexpr bool operator<=(const Span&) const noexcept;
        [[nodiscard]] constexpr bool operator>(const Span&) const noexcept;
        [[nodiscard]] constexpr bool operator>=(const Span&) const noexcept;
        [[nodiscard]] constexpr TYPE& operator[](size_t i) noexcept; // Unchecked.
        [[nodiscard]] constexpr const TYPE& operator[](size_t i) const noexcept;
        [[nodiscard]] constexpr TYPE& at(size_t i); // Checked (may throw/assert).
        [[nodiscard]] constexpr const TYPE& at(size_t i) const;
        [[nodiscard]] constexpr TYPE& operator()(size_t i) noexcept; // Alt index.
        [[nodiscard]] constexpr const TYPE& operator()(size_t i) const noexcept;
        [[nodiscard]] constexpr Span operator+(size_t off) const noexcept; // Sub-span.
        [[nodiscard]] constexpr Span operator-(size_t off) const noexcept;
        constexpr Span& operator+=(const TYPE& v) noexcept; // Custom shift-in.
        constexpr Span& operator-=(const TYPE& v) noexcept; // Custom shift-out.
    // helper/util:
        constexpr void fill(const TYPE& v) noexcept; // Fill all.
        constexpr void clear() noexcept; // Reset elements.
        constexpr void swap(Span& other) noexcept; // Element-wise swap.
        [[nodiscard]] constexpr bool empty() const noexcept; // LENGTH==0.
        [[nodiscard]] static consteval size_t size_static() noexcept; // CT size.
        [[nodiscard]] constexpr TYPE* begin() noexcept;
        [[nodiscard]] constexpr const TYPE* begin() const noexcept;
        [[nodiscard]] constexpr TYPE* end() noexcept;
        [[nodiscard]] constexpr const TYPE* end() const noexcept;
        [[nodiscard]] constexpr TYPE* rbegin() noexcept;
        [[nodiscard]] constexpr const TYPE* rbegin() const noexcept;
        [[nodiscard]] constexpr TYPE* rend() noexcept;
        [[nodiscard]] constexpr const TYPE* rend() const noexcept;
        [[nodiscard]] constexpr TYPE& front() noexcept;
        [[nodiscard]] constexpr const TYPE& front() const noexcept;
        [[nodiscard]] constexpr TYPE& back() noexcept;
        [[nodiscard]] constexpr const TYPE& back() const noexcept;
        [[nodiscard]] constexpr Span clone() const noexcept; // Deep copy.
        template<size_t N>
        [[nodiscard]] constexpr Span<TYPE, N> sub_span(size_t idx) const noexcept; // CT slice.
        [[nodiscard]] constexpr Span sub_span(size_t idx, size_t count) const; // RT slice.
        constexpr void copy_to(TYPE* dst) const noexcept; // Copy out.
        constexpr void copy_from(const TYPE* src) noexcept; // Copy in.
        [[nodiscard]] constexpr size_t find(const TYPE& v) const noexcept;
        [[nodiscard]] constexpr size_t rfind(const TYPE& v) const noexcept;
        [[nodiscard]] constexpr bool contains(const TYPE& v) const noexcept;
        [[nodiscard]] constexpr size_t count(const TYPE& v) const noexcept;
        template<typename F>
        constexpr void for_each(F&& f) noexcept; // Apply f.
        template<typename F>
        [[nodiscard]] constexpr bool all_of(F&& f) const noexcept;
        template<typename F>
        [[nodiscard]] constexpr bool any_of(F&& f) const noexcept;
        template<typename F>
        [[nodiscard]] constexpr bool none_of(F&& f) const noexcept;
        template<typename F>
        constexpr void transform(F&& f) noexcept; // In-place.
        constexpr void reverse() noexcept;
        constexpr void rotate_left(size_t n) noexcept;
        constexpr void rotate_right(size_t n) noexcept;
    // accessors:
        [[nodiscard]] static consteval size_t length() noexcept; // LENGTH.
        [[nodiscard]] static consteval size_t size() noexcept; // Same.
        [[nodiscard]] static consteval size_t bytes() noexcept; // LENGTH*sizeof(TYPE).
        [[nodiscard]] constexpr TYPE* data() noexcept;
        [[nodiscard]] constexpr const TYPE* data() const noexcept;
        [[nodiscard]] constexpr const TYPE* cdata() const noexcept;
        [[nodiscard]] constexpr bool is_aligned(size_t alignment) const noexcept;
        [[nodiscard]] constexpr uintptr_t address() const noexcept;