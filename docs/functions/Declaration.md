# Declaration and definition


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

How it is done in C and C++ 98 and modern C++

### [[nodiscard]] by default

C++17 introduced the [[nodiscard]] attribute. Applying this attribute to a function signals that its return value shouldn't be overlooked, prompting the compiler to issue a warning. This can aid in averting security, memory leak, and performance-related bugs. While using this attribute consistently can be inconvenient, Cppfront makes [[nodiscard]] the default behavior, eliminating the need for explicit annotations.

### Function, Lambda, and Block Statements

In Cppfront, lambdas are functions without names. It is possible to pass parameters to a block. If a function, lambda, or block statement has a single line, it can omit the `{` and `}`.

Cppfront:
```c++
f:(x: int = init) = { ... }     // x is a parameter to the function
f:(x: int = init) = statement;  // same, { } is implicit
 
 :(x: int = init) = { ... }     // x is a parameter to the lambda
 :(x: int = init) = statement;  // same, { } is implicit
 
  (x: int = init)   { ... }     // x is a parameter to the block
  (x: int = init)   statement;  // same, { } is implicit
 
                    { ... }     // x is a parameter to the block
                    statement;  // same, { } is implicit
```

### Handling Multiple Return Values

Cppfront allows functions to return multiple values. Each return parameter must be explicitly named, and they need to be initialized within the function body, or else the Cppfront transpiler will generate an error. The following example demonstrates returning multiple values including 'valid', 'error', and 'val':

Cppfront:
```c++
myfunc: (opt: int) -> (valid: bool, error: int, val: std::string) = {
    if(opt) {
        valid = true;
        error = 0;
        val = "This is the value";
    } else {
        valid = false;
        error = 1;
        val = "Error";
    }
}

main: () = {
    answer := myfunc(0);
    std::cout << "valid = (answer.valid)$, error = (answer.error)$, val = (answer.val)$\n";
    answer = myfunc(1);
    std::cout << "valid = (answer.valid)$, error = (answer.error)$, val = (answer.val)$\n";
}
```


## TODO

[[nodiscard]] by default

Common format Function, Lambda, and Block Statements

Handling Multiple Return Values

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
