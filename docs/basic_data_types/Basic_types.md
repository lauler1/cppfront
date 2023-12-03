# Basic Types


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](basic_data_types/Overview.md)

## Background from C++

This chapter is more conceptual. The practical examples will be explored more in the [next chapter](Variables.md), where variable declarations will be explored. In programming, a "type" refers to a classification that specifies the kind of value a variable can hold and what operations can be performed on it. Types are fundamental to a programming language and are used to ensure the correct usage of data, improve performance, and prevent bugs.

In C++, the **basic types** can be categorized into several groups:

1. **Fundamental Types:**
   - **Integer Types:** Represent whole numbers. Examples include `int`, `short`, `long`, and `long long`, available in both signed and unsigned variants.
   - **Character Types:** Used for storing characters. The primary type is `char`, with `char16_t`, `char32_t`, and `wchar_t` available for wider character representations.
   - **Floating Point Types:** Represent real numbers (numbers with fractions). Examples include `float`, `double`, and `long double`.
   - **Boolean Type:** The `bool` type is used for true/false values.

2. **Special Case - Void Type:**
   - **void:** Represents the absence of a type and is used in specific contexts like function return types.

3. **Derived Types:**
   - **Pointers:** Hold memory addresses of other variables.
   - **Arrays:** Collections of elements of the same type.
   - **References:** Serve as an alternative name for an existing variable.
   - **Functions:** Sequences of instructions packaged as a unit.

4. **Compound Types:**
   - **Classes:** User-defined types in C++.
   - **Structures:** Similar to classes, primarily used for data grouping.
   - **Unions:** Structures where all members share the same memory location.
   - **Enumerations:** User-defined types consisting of sets of named integral constants.

Understanding these basic types is crucial for effective programming in C++, as they form the building blocks for more complex data structures and algorithms.

## Fundamental Types in Cppfront

In many programming languages, "fundamental types" often equate to "primitive types." These are basic, built-in types that aren't composed of other types, serving as the essential building blocks for data manipulation.

These types are directly supported by the language syntax, offering high efficiency as they closely map to the underlying hardware. They're termed "primitive" because they fundamentally represent data in a program, forming the basis for more complex types.

Cppfront introduces a set of primitive types derived from C++'s basic types and standard library, accessible without additional imports.

### Fundamental Types in Cppfront

Cppfront offers a blend of traditional C++ primitive types and new, fixed-precision types based on the C++ Standard Library. The traditional types include:

| Cppfront       | C++ Primitive         | Description                                                         |
|----------------|-----------------------|---------------------------------------------------------------------|
| _schar or char | char                  | At least 8 bits signed.                                             |
| _uchar         | unsigned char         | At least 8 bits unsigned.                                           |
| short          | short                 | At least 16 bits signed, at least as large as `char`.               |
| ushort         | unsigned short        | At least 16 bits unsigned, at least as large as `unsigned char`.    |
| int            | int                   | At least 16 bits signed, at least as large as `short`.              |
| long           | long                  | At least 32 bits signed, at least as large as `int`.                |
| ulong          | unsigned long         | At least 32 bits unsigned, at least as large as `unsigned int`.     |
| longlong       | long long             | At least 64 bits signed, at least as large as `long`.               |
| ulonglong      | unsigned long long    | At least 64 bits unsigned, at least as large as `unsigned long`.    |
| longdouble     | long double           | 64 bits or 80 bits floating point.                                  |

Note: The use of these primitive types, especially `_schar` and `_uchar`, is discouraged due to their non-fixed precision. They exist primarily for compatibility and interoperability. Instead, Cppfront encourages the use of fixed-precision types:

| Cppfront | C++ Standard Lib   | Description                  |
|----------|--------------------|------------------------------|
| i8       | std::int8_t        | Always 8 bits signed.        |
| i16      | std::int16_t       | Always 16 bits signed.       |
| i32      | std::int32_t       | Always 32 bits signed.       |
| i64      | std::int64_t       | Always 64 bits signed.       |
| u8       | std::uint8_t       | Always 8 bits unsigned.      |
| u16      | std::uint16_t      | Always 16 bits unsigned.     |
| u32      | std::uint32_t      | Always 32 bits unsigned.     |
| u64      | std::uint64_t      | Always 64 bits unsigned.     |

## The Type of Literals in Cppfront

Like in modern C++, Cppfront allows literals to be suffixed to specify their type directly in the code. These suffixes determine the type of the literal at compile time, ensuring that the literal has the intended type. Below are common suffixes used in C++ (since C++11) and adopted in Cppfront:

1. **Integer Literals:**
   - `u` or `U` for `unsigned int`. Example: `100U`.
   - `l` or `L` for `long`. Example: `100L`.
   - Variants for `unsigned long`: `ul`, `uL`, `Ul`, `UL`, `lu`, `Lu`, `lU`, `LU`. Example: `100UL`.
   - `ll` or `LL` for `long long`. Example: `100LL`.
   - Variants for `unsigned long long`: `ull`, `uLL`, `Ull`, `ULL`, `llu`, `LLu`, `llU`, `LLU`. Example: `100ULL`.

2. **Floating-Point Literals:**
   - `f` or `F` for `float`. Example: `3.14F`.
   - `l` or `L` for `long double`. Example: `3.14L`.

3. **Character Literals:**
   - Prefix `L` for `wchar_t` (wide character). Example: `L'a'`.
   - Prefix `u` for `char16_t` (UTF-16). Example: `u'a'`.
   - Prefix `U` for `char32_t` (UTF-32). Example: `U'a'`.
   - Prefix `u8` for UTF-8 (since C++20). Example: `u8"hello"`.

4. **Binary Literals:**
   - Specified with `0b` or `0B`. Example: `0b1010`.

5. **User-Defined Literals:**
   - Custom suffixes, available since C++11. Example: `123_km`.

New in C++23:

   - `uz` or `UZ` for `std::size_t`. Example: `100uz`.
   - `z` or `Z` for the signed version of `std::size_t`. Example: `100z`.

For more details, refer to the C++ reference for [integer literals](https://en.cppreference.com/w/cpp/language/integer_literal), [floating literals](https://en.cppreference.com/w/cpp/language/floating_literal), and [user-defined literals](https://en.cppreference.com/w/cpp/language/user_literal).

Using the correct suffix ensures that the literal is treated as the intended type, crucial for operations where type matters, such as arithmetic operations, function overloading, and template instantiation.

Single quotes (`'`) may be inserted as separators between digits in literals; they are ignored in determining the literal's value. For example, the following represent the same unsigned long long value:

```
18446744073709550592ull       // C++11
18'446'744'073'709'550'592llu // C++14
1844'6744'0737'0955'0592uLL   // C++14
184467'440737'0'95505'92LLU   // C++14
```

This separator can also be used with floating-point numbers:

```
3.14'15'92 // The same as 3.141592
```

## Next

To the [next Chapter](Variables.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

