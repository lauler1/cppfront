# basic_types


Back to Tutorial [home](../readme.md)

Back to the Chapter [Overview](Overview.md)

![](../TutorialUnderConstruction.png)

## Background C and C++

	> TO DO

	To cover not only the all basic types but all numbers sufix with specific size. Also std numbers.

	does cppfront redefine some primitive types? yes, in cpp2util.h, see:
```C++
//  Encouraged by default: Fixed-precision names
using i8        = std::int8_t        ;
using i16       = std::int16_t       ;
using i32       = std::int32_t       ;
using i64       = std::int64_t       ;
using u8        = std::uint8_t       ;
using u16       = std::uint16_t      ;
using u32       = std::uint32_t      ;
using u64       = std::uint64_t      ;

//  Discouraged: Variable precision names
//                 short
using ushort     = unsigned short;
//                 int
using ulong      = unsigned long;
//                 long
using longlong   = long long;
using ulonglong  = unsigned long long;
using longdouble = long double;

//  Strongly discouraged, for compatibility/interop only
using _schar     = signed char;      // normally use i8 instead
using _uchar     = unsigned char;    // normally use u8 instead
```


The type of the literal
The type of the integer literal is the first type in which the value can fit, from the list of types which depends on which numeric base and which integer-suffix was used:

| Suffix                | Decimal bases                                                              |
| :-------------------- | :------------------------------------------------------------------------- |
| (no suffix)           | int<br>long int<br>long long int (since C++11)                             |
| u or U                | unsigned int<br>unsigned long int<br>unsigned long long int (since C++11)  |
| l or L                | long int<br>unsigned long int (until C++11)<br>long long int (since C++11) |
| both l/L<br>and u/U   | unsigned long int<br>unsigned long long int (since C++11)                  |
| ll or LL              | long long int (since C++11)                                                |
| both ll/LL<br>and u/U | unsigned long long int (since C++11)                                       |
| z or Z                | the signed version of std::size_t (since C++23)                            |
| both z/Z<br>and u/U   | std::size_t (since C++23)                                                  |


How it is done in C and C++ 98 and modern C++

## New syntax cppfront

Shows how is done now


## How is the code transpiled

## Advanced topics

Cover other advanced modern C++ topics (e.g. C++ 17, 20, 23) because the idea is to teach how to write code right.
If cppfront does not have a specific syntax, then use modern C++.

