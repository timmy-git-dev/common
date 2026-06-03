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
using i64 = signed long;

/// An 8-bit unsigned integer.
using u08 = unsigned char;
/// A 16-bit unsigned integer.
using u16 = unsigned short;
/// A 32-bit unsigned integer.
using u32 = unsigned int;
/// A 64-bit unsigned integer.
using u64 = unsigned long;

/// An 8-bit character used to represent the 0-255 ASCII set.
using c08 = char;

/// An 8-bit boolean used to represent a true/false condition.
using b08 = bool;

/// Typically a 64-bit unsigned integer to represent a memory location.
using s64 = __SIZE_TYPE__;

/// Typically a 64-bit unsigned integer to represent a memory location for kernel/c addresses.
#define NULL s64(0)