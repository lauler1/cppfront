# templates


Back to Tutorial [home](../readme.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

### Concepts as an Interface:

In C++, you can use templates concepts to behave like an interface (pure abstract class) which is used only has a specification for other classes.


```c++
#include <concepts>
#include <iostream>

// Define a concept that requires two member functions 'required_function' with different signatures
template<typename T, typename R1, typename R2, typename T1, typename T2>
concept HasRequiredFunctions = requires(T a, T1 t1, T2 t2) {
    { a.required_function(t1) } -> std::convertible_to<R1>;
    { a.required_function(t2) } -> std::convertible_to<R2>;
};

// Example class that satisfies the concept
class SatisfyingClass {
public:
    // First required function
    int required_function(double value) {
        std::cout << "required_function with double called, returning int" << std::endl;
        return static_cast<int>(value);
    }

    // Second required function
    std::string required_function(std::string value) {
        std::cout << "required_function with int called, returning double" << std::endl;
        return value;
    }
};

// Define a template class that uses the concept
template<typename T>
requires HasRequiredFunctions<T, double, std::string, double, std::string> // Concept is applied here with T and expected return types
class TemplatedClass {
public:
    // Call the first required function
    int call_required_function1(double value) {
        T instance;
        return instance.required_function(value);
    }

    // Call the second required function
    std::string call_required_function2(std::string value) {
        T instance;
        return instance.required_function(value);
    }
};

int main() {
    // This will compile because SatisfyingClass satisfies the HasRequiredFunctions concept
    TemplatedClass<SatisfyingClass> obj;
    int result1 = obj.call_required_function1(10.5);
    std::string result2 = obj.call_required_function2("10.1");

    std::cout << "Result1: " << result1 << std::endl;
    std::cout << "Result2: " << result2 << std::endl;

    return 0;
}

}
```



## New syntax cppfront

Shows how is done now


## How is the code transpiled

## Advanced topics

Cover other advanced modern C++ topics (e.g. C++ 17, 20, 23) because the idea is to teach how to write code right.
If cppfront does not have a specific syntax, then use modern C++.

