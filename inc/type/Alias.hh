#pragma once

/// A 32-bit signed float.
using f32 = float;
/// A 64-bit signed float.
using f64 = double;

/// An 8-bit signed integer.
using i08 = signed char;
/// A 16-bit signed integer.
using i16 = signed short;
/// A 32-bit signed integer.
using i32 = signed int;
/// A 64-bit signed integer.
using i64 = signed long long;

/// An 8-bit unsigned integer.
using u08 = unsigned char;
/// A 16-bit unsigned integer.
using u16 = unsigned short;
/// A 32-bit unsigned integer.
using u32 = unsigned int;
/// A 64-bit unsigned integer.
using u64 = unsigned long long;

/// An 8-bit character used to represent ASCII or UTF-8.
using c08 = char;
/// An 8-bit character used to represent UTF-16.
using c64 = wchar_t;

/// An 8-bit boolean used to represent a true/false condition.
using b08 = bool;

/// Typically a 64-bit unsigned integer to represent a memory location.
using s64 = __SIZE_TYPE__;

static_assert(sizeof(f32) == 4, "'f32' 32-bit float alias not 32-bit.");
static_assert(sizeof(f64) == 8, "'f64' 64-bit double alias not 64-bit.");

static_assert(sizeof(i08) == 1, "'i08' 8-bit signed-integer alias not 8-bit.");
static_assert(sizeof(i16) == 2, "'i16' 16-bit signed-integer alias not 16-bit.");
static_assert(sizeof(i32) == 4, "'i32' 32-bit signed-integer alias not 32-bit.");
static_assert(sizeof(i64) == 8, "'i64' 64-bit signed-integer alias not 64-bit.");

static_assert(sizeof(u08) == 1, "'u08' 8-bit unsigned-integer alias not 8-bit.");
static_assert(sizeof(u16) == 2, "'u16' 16-bit unsigned-integer alias not 16-bit.");
static_assert(sizeof(u32) == 4, "'u32' 32-bit unsigned-integer alias not 32-bit.");
static_assert(sizeof(u64) == 8, "'u64' 64-bit unsigned-integer alias not 64-bit.");

static_assert(sizeof(c08) == 1, "'c08' 8-bit character alias not 8-bit.");
static_assert(sizeof(c64) == 4, "'c64' 64-bit wide-character alias not 64-bit.");

static_assert(sizeof(c08) == 1, "'b08' 8-bit boolean alias not 8-bit.");

static_assert(sizeof(s64) == 8, "'s64' 64-bit size-type alias not 64-bit.");