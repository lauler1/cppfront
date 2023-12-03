# Strings


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

Strings are a fundamental aspect of any programming language, and Cppfront offers robust support for them. Learn about the different string types available and how to perform common operations such as concatenation and comparison. Discover Cppfront's string formatting capabilities, enabling you to integrate variables into strings seamlessly for output and logging.

	* String types
	* String format
	



Yes, you can construct a `std::string_view` from a `std::string` and vice versa, but there are some nuances to be aware of.

**Constructing a `std::string_view` from a `std::string`:**

```cpp
#include <string>
#include <string_view>

int main() {
    std::string str = "Hello, World!";
    std::string_view sv(str); // Construct string_view from string
    // You can also directly construct it like this:
    // std::string_view sv = str;
}
```

This is a non-owning view into the string, meaning that `std::string_view` does not take ownership of the memory and simply points to the same memory that the `std::string` manages. It is essential to ensure that the `std::string` outlives the `std::string_view` to avoid dangling references.

**Constructing a `std::string` from a `std::string_view`:**

```cpp
#include <string>
#include <string_view>

int main() {
    std::string_view sv = "Hello, World!";
    std::string str(sv); // Construct string from string_view
    // You can also construct it explicitly like this:
    // std::string str(sv.begin(), sv.end());
}
```

This creates a new `std::string` object that owns its own copy of the data. The data from the `std::string_view` is copied into the new `std::string`, so there are no issues with lifetimes or dangling references in this direction of conversion.

Keep in mind that `std::string_view` was designed to be a lightweight, non-owning reference to a string and is particularly useful for functions that want to accept any kind of string-like object without causing unnecessary copies. However, because it doesn't own the data it points to, you have to manage the lifetime of the underlying string data yourself.

## New syntax cppfront

### Captured Variables

In Cppfront, variables used inside lambdas are captured using a '$' suffix. For example, `:() = {std::cout << y$;};`. See some examples of lambdas:

Cppfront:
```c++
MyType: type = {
	y4: std::string = "y4\n";

	myfunc: (this) = {
		myLambda4 := :() = { std::cout << this.y4$; };	// Capture example inside a class
		myLambda4();
	}
}

main: () -> int = {
    y1: std::string = "y1\n";
    y2: std::string = "y2\n";
    y3: std::string = "y3\n";

    myLambda1 := :() = { std::cout << y1$; };	// Capture example by copy value
	myLambda1();

    myLambda2 := :() = { std::cout << y2&$*; };	// Capture example by reference
	myLambda2();
	
    myLambda3 := :() = { std::cout << "(y3$)$"; };	// Capture example by string interpolation.
	myLambda3();
	
	mytype := MyType();
	mytype.myfunc();  // Use an object
}
```

String Interpolation has the format `(...)$` inside strings and allows also the evaluation of expressions.

Cppfront:
```c++
x := 5;
str: std::string = "res = (x * 2)$\n";
std::cout << str; // res = 10
```
This is also valid for post-conditions and string interpolation.

Cppfront:
```c++
[[post: v.size() == v.size()$ + 1]] // capture a copy of v.size() on function entry for use later when the whole postcondition is evaluated on function exit.

"My name is (name)$" // capture a copy of name on string construction for use later when the string value is referred to
```

> Note: At the moment of writing this tutorial, there was some discussion about how should be the [syntax of Captures](https://github.com/hsutter/cppfront/discussions/771) (e.g., prefix or suffix `$`).

### Bounds check

Cppfront automatically performs runtime checks for bounds violations when accessing elements of arrays, vectors, lists, and similar data structures. In the event of an out-of-bounds access, the application is terminated.

Cppfront
```c++
main: () -> int
= {
	a: std::array<char, 6> = ("hallo");
    std::cout << a[-1] << "\n"; // aborts
	
    sv: std::string_view = ("Hallo");
    std::cout << sv[5] << "\n"; // aborts

    v: std::vector = ("str1", "str2");
    std::cout << v[2] << "\n"; // aborts
}
```


## TODO

Bounds check. Cppfront automatically performs runtime checks for bounds violations when accessing elements of Strings.

String Interpolation: Captured Variables in strings

String format

string_view vs string


## Open Points

- [Syntax of Captures](https://github.com/hsutter/cppfront/discussions/771)



## Next

To the [next Chapter](../containers/Overview.md).

To the [previous Chapter](Automatic_type.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

