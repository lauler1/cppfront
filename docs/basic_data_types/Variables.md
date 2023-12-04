# Variables definition, declaration and initialization


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](basic_data_types/Overview.md)

## Background C and C++

Variables are named storage locations in the computer's memory, used to store data that can be modified during program execution. Each variable is associated with a specific type, which determines the size and layout of the variable's memory, the range of values that can be stored within that memory, and the set of operations that can be applied to the variable (See the [previous Chapter](Basic_types.md)).

The new declaration syntax of Cppfront is left-to-right and it has the form: `name: type = value`. For many, reading from left to right is natural. In languages like C++, where you can have multiple modifiers to a type (like pointers or references), right-to-left reading can become confusing. Consider `int* a, b;`. In this C++ declaration, a is a pointer to an integer, but b is just an integer. This can lead to misconceptions.

Declaring variables for all the fundamental types involves specifying the type followed by the variable name. Here's how you can declare variables for each of the fundamental types:

1. **Integer Types:**

| Type                       | Example in C++                               | New syntax in Cppfront                |
|----------------------------|----------------------------------------------|---------------------------------------|
| Signed integer[^1]         | `int myInt = 0;`                             | `myInt: int = 0;`                     |
| Short integer              | `short myShort = 0;`                         | `myShort: short = 0;`                 |
| Unsigned short integer     | `unsigned short myUnsignedShort = 0;`        | `myUnsignedShort: ushort = 0;`        |
| Long integer               | `long myLong = 0;`                           | `myLong: long = 0;`                   |
| Unsigned long integer      | `unsigned long myUnsignedLong = 0;`          | `myUnsignedLong: ulong = 0;`          |
| Long long integer          | `long long myLongLong = 0;`                  | `myLongLong: longlong = 0;`           |
| Unsigned long long integer | `unsigned long long myUnsignedLongLong = 0;` | `myUnsignedLongLong: ulonglong = 0;`  |

[^1]: For unsigned int, Cppfron does not define any new alias.

As already stated in the previous chapter, the use of primitive types is discouraged and you should prefere these options:

| Type              | Example in C++                | New syntax in Cppfront         |
|-------------------|-------------------------------|--------------------------------|
| Signed 8 bits     | `std::int8_t myint8 = 0;`     | `myint8:  std::int8_t = 0;`    |
| Signed 16 bits    | `std::int16_t myint16 = 0;`   | `myint16: std::int16_t = 0;`   |
| Signed 32 bits    | `std::int32_t myint32 = 0;`   | `myint32: std::int32_t = 0;`   |
| Signed 64 bits    | `std::int64_t myint64 = 0;`   | `myint64: std::int64_t = 0;`   |
| Unsigned 8 bits   | `std::uint8_t myuint8 = 0;`   | `myuint8: std::uint8_t = 0;`   |
| Unsigned 16 bits  | `std::uint16_t myuint16 = 0;` | `myuint16: std::uint16_t = 0;` |
| Unsigned 32 bits  | `std::uint32_t myuint32 = 0;` | `myuint32: std::uint32_t = 0;` |
| Unsigned 64 bits  | `std::uint64_t myuint64 = 0;` | `myuint64: std::uint64_t = 0;` |

2. **Character Types:**

| Type                  | Example in C++                      | New syntax in Cppfront        |
|-----------------------|-------------------------------------|-------------------------------|
| Character             | `char myChar = 'a';`                | `myChar: _schar = 'a';` or `myChar: char = 'a';` |
| Signed character      | `signed char mySignedChar = 'a';`   | `mySignedChar: _schar = 'a';` |
| Unsigned character    | `unsigned char myUnsignedChar = 0;` | `myUnsignedChar: _uchar = 0;` |
| Wide character        | `wchar_t myWideChar = L'a';`        | `myWideChar: wchar_t = L'a';` |
| Char16_t (for UTF-16) | `char16_t myChar16 = u'a';`         | `myChar16: char16_t = u'a';`  |
| Char32_t (for UTF-32) | `char32_t myChar32 = U'a';`         | `myChar32: char32_t = U'a';`  |

3. **Floating-Point Types:**

| Type        | Example in C++                     | New syntax in Cppfront              |
|-------------|------------------------------------|-------------------------------------|
| Float       | `float myFloat = 0.0f;`            | `myFloat: float = 0.0;`             |
| Double      | `double myDouble = 0.0;`           | `myDouble: double = 0.0;`           |
| Long double | `long double myLongDouble = 0.0l;` | `myLongDouble: longdouble = 0.0l;` |

4. **Boolean Type:**

| Type    | Example in C++        | New syntax in Cppfront |
|---------|-----------------------|------------------------|
| Boolean | `bool myBool = true;` | `myBool: bool = true;` |

You can see these declarations in the Compiler Explorer: https://godbolt.org/z/aeqc4hcTx

In order to read or change the value of a variable is the same as in C++.

Cppfront:
```c++
main: () -> int = {
	myVar: int = 10;
	otherVar: int = myVar;

    // Use myconst before declaration
    std::cout << "1) myVar = " << myVar << "\n";        // 10
    std::cout << "1) otherVar = " << otherVar << "\n";  // 10

	myVar = 30;
	otherVar = otherVar + 100;
	
    std::cout << "2) myVar = " << myVar << "\n";        // 30
    std::cout << "2) otherVar = " << otherVar << "\n";  // 110

    return 0;
}
```

## Attributes


In C++, attributes are qualifiers that can be applied to variables (as well as to functions and types) to modify their behavior or enforce certain properties. The attributes `const`, `constexpr`, `consteval`, and `constinit` are particularly important in modern C++ programming. Cppfront implements some of the C++ attributes. Here's a brief overview of each:

1. **`const`:**
   - The `const` attribute indicates that the value of the variable cannot be modified after initialization. It's a promise that the variable remains constant through its lifetime, which can help in optimization and ensuring program correctness.
   - Example C++: `const int myConst = 10;` means that `myConst` cannot be changed after initialization.
   - Example Cppfront: `myConst: const int = 0;` means that `myConst` cannot be changed after initialization.

2. **`constexpr`:**
   - A `constexpr` variable indicates that its value can be computed at compile time. This is useful for optimization, as it can eliminate runtime computation for values that can be determined when the program is compiled. In Cppfront, you achieve this result by defineing a variable with `==` operator.
   - Example C++: `constexpr int myConstExpr = 2 + 3;` allows the compiler to compute the value of `myConstExpr` during compilation.
   - Example Cppfront: `myConstExpr: int == 2 + 3;` allows the compiler to compute the value of `myConstExpr` during compilation.

3. **`consteval`:**
   - The `consteval` specifier, introduced in C++20, ensures that a function is an immediate function, meaning it must produce a compile-time constant when called with constant expressions. This is stricter than `constexpr`, as `consteval` functions cannot be called at runtime.
   - Example C++: `consteval int square(int n) { return n * n; }` ensures that `square` can only be used in constant expressions.
   - Example Cppfront: **Not yet available.**

4. **`constinit`:**
   - Introduced in C++20, `constinit` ensures that the variable is initialized with a constant expression before any dynamic initialization takes place. It's a middle ground between `constexpr` and non-constant initialization, ensuring that the variable gets constant initialization but can be changed later.
   - Example C++: `constinit int myConstInit = someConstexprFunction();` ensures `myConstInit` is initialized during the static initialization phase.
   - Example Cppfront: **Not yet available.**

These attributes play crucial roles in modern C++ and Cppfront by providing more control over how and when variables are initialized and modified, and by enforcing compile-time computation which can lead to more efficient and reliable code.


## Pointers

A pointer is a variable that stores the memory address of another variable. Pointers are used for various purposes, such as dynamic memory allocation, arrays, and implementing data structures like linked lists and trees. A pointer in C++ is declared by specifying the type of data it points to, followed by an asterisk (`*`). In Cppfront a pointer is declared by an asterisk (`*`) followed byt the specification of the type of data it points to,

- **C++**
 - **Declaration:** For example, `int* myPointer;` declares a pointer that can hold the address of an `int` variable.
 - **Usage:** After declaring a pointer, you can assign it the address of a variable using the address-of operator (`&`). For example, `int myVar = 10; myPointer = &myVar;`.
 - **Dereferencing:** You can access the value at the memory address the pointer points to using the dereference operator (`*`). For example, `int value = *myPointer;` retrieves the value of `myVar` through the pointer.

- **Cppfront**
 - **Declaration:** For example, `myPointer: *int;` declares a pointer that can hold the address of an `int` variable. Note that the asterisk (`*`) comes before the type.
 - **Usage:** The assignment of the address of a variable is also with address-of operator (`&`), but after the variable where the address is to be taken. For example, `myVar: int = 10; myPointer = myVar&;`. By default Cppfront use right side operators.
 - **Dereferencing:** You can also access the value at the memory address the pointer points to using the dereference operator (`*`), but at the right side of the variable as well. For example, `value: int  = myPointer*;` retrieves the value of `myVar` through the pointer. By default Cppfront use right side operators.

See an example in Compiler Explorer: https://godbolt.org/z/fKr4Y5bo4

### `nullptr`

`nullptr` is a keyword introduced in C++11 as a more type-safe replacement for the old `NULL` macro used in C and older C++ code. It represents a null pointer, which is a pointer that points to nothing. Using `nullptr` in C++ helps prevent some errors and misunderstandings that can arise from the older `NULL` macro, which is simply defined as `0`. However `nullptr` is not considered safe (lifetime safety guarantee) and Cppfront does not allow to initialize a variable to it. You can leave it uninitialized and then set it to a non-null value when you have one (See also section: All variables must be initialized).

## Order independence

No forward declarations in Cppfront because we forward-declare everything in the C++ code. Functions and objects can be declared in any order because Cppfront warrants the declaration, e.g.:

Cppfront:
```c++
main: () -> int = {
    // Use myconst before declaration
    std::cout << "print " << myconst << "\n";
    return 0;
}

myconst: const int = 123;
```

This will be transpiled to C++ as:

```c++
...

[[nodiscard]] auto main() -> int;

extern int const myconst;

[[nodiscard]] auto main() -> int{
    // Use myconst before declaration
    std::cout << "print " << myconst << "\n";
    return 0; 
}

int const myconst {123}; 
```

Note the automatic inclusion of `extern int const myconst;` by Cppfront in the generated C++ code.

## All variables must be initialized:

All variables in Cppfront must be initialized; failing to do so will result in a compiler error.

`a: int = 0;` is ok.

`a: int;`, unless in a type definition, it will fail with comment:

```
variable must be initialized on every branch path
 ==> program violates initialization safety guarantee - see previous errors
```

As explained in section `nullptr`, it is not allowed to initialize a pointer with `nullptr` in Cppfront.
There are some discussion how shall be raw-pointers handled. See: [cppfront issues 192](https://github.com/hsutter/cppfront/issues/192) and  [cppfront discussions 646](https://github.com/hsutter/cppfront/discussions/646).

See also [introduction](../pointers_and_references/Introduction.md) to pointers.

## “don’t care” wildcard

When there's a need to consciously overlook a result, one can use the "intentional disregard" wildcard. It's understated yet unmistakably deliberate:

Cppfront:
```c++
_ = vec.emplace_back(1,2,3);
```
When is it apt to employ this?

Cppfront:
```c++
g: (inout myvar:) = {myvar++;}

main: () = {
    myvar := 0;
    g(myvar);
}
```

This topic is also shown in the **Move on Last Use** section below. In this example, that call to `g: (inout myvar:)`; is a definite last use of `myvar`, and so Cpp2 will automatically pass `myvar` as a rvalue and make it a move candidate… and presto! the call won’t compile because you can’t pass a rvalue to a Cpp2 `inout` parameter. That’s a feature, not a bug, because if that’s the last use of `myvar` that means the function is not looking at `myvar` again, so it’s ignoring the “out” value of the `g: (inout myvar:)` function call, which is exactly like ignoring a return value. And the guidance is the same: If you really meant to do that, just explicitly discard `myvar`‘s final value:

Cppfront:
```c++
g: (inout myvar:) = {myvar++;}

main: () = {
    myvar := 0;
    g(myvar);
    _ = myvar; // all right, you said you meant it, carry on then...
}
```

Adding `_ = myvar`; afterward naturally makes that the last use of `myvar` instead. Problem solved, and it self-documents that the code really meant to ignore a function’s output value.

## Next

To the [next Chapter](Operators.md).

To the [previous Chapter](Basic_types.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)
