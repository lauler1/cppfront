# Declaration and definition


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

How it is done in C and C++ 98 and modern C++

## New syntax cppfront

Shows how is done now


## How is the code transpiled

## Advanced topics

Cover other advanced modern C++ topics (e.g. C++ 17, 20, 23) because the idea is to teach how to write code right.
If cppfront does not have a specific syntax, then use modern C++.

## TODO

Also Variadic Template Functions --> this is C++ standard, nothing special in Cppfront so far.

"Variadic" refers to a concept in programming where a function, template, or data structure can accept a variable number of arguments. This term is commonly associated with variadic functions and variadic templates in C++.

1. **Variadic Functions:** These are functions that can take a variable number of arguments. The most famous example in C and C++ is the `printf` function. In C++, you can create variadic functions using the ellipsis (`...`) syntax or, more safely and commonly, with variadic templates.

2. **Variadic Templates:** In C++, variadic templates allow the creation of classes and functions that can take any number of template arguments of any type. This is done using a parameter pack. A parameter pack is a template parameter that accepts zero or more template arguments (non-types, types, or templates). 

Here's a simple example of a variadic template function in C++:

```cpp
#include <iostream>

template<typename T>
void print(T value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Args>
void print(T value, Args... args) {
    std::cout << value << ", ";
    print(args...); // recursive call using pack expansion
}

int main() {
    print(1, 2.5, "hello", 'c');
    return 0;
}
```

In the above example, `print` is a variadic template function that can take any number of arguments of any type. The recursion in combination with template argument deduction and pack expansion allows for each argument to be processed.



## Next

To the [next Chapter](Parameters.md).

To the [previous Chapter](../pointers_and_references/Conversions.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)
