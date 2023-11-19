# Variables definition, declaration and initialization


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](basic_data_types/Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

Gain clarity on the process of introducing variables into your Cppfront code. Learn the difference between defining a variable, which allocates storage, and declaring a variable, which introduces a name into the program. Understand the importance of initialization and explore the various ways to initialize variables in Cppfront, including pointers, `nullptr`, and `const` qualifiers. Dive into the significance of compile-time initialization with `constexpr` and `consteval`.

	* pointer
	* nullpter
	* const
	* constexpr, consteval and constinit

How it is done in C and C++ 98 and modern C++

### Declare left-to-right:

I think this can be a controversial topic of the new syntax, specially to the ones used for a very long type with the r-to-l syntax. The new declaration syntax left-to-right has the form: `name: type = value`.

For many, reading from left to right is natural. 
In languages like C++, where you can have multiple modifiers to a type (like pointers or references), right-to-left reading can become confusing. Consider int* a, b; In this C++ declaration, a is a pointer to an integer, but b is just an integer. This can lead to misconceptions.

C++:
```C++
class shape { /* syntax 1 code since 1980, can’t update semantics
without backward compatibility breakage concerns */ };

auto f(int i) -> string { /* syntax 1 code since C++11, can’t update semantics
without backward compatibility breakage concerns */ }

i32 a = 0;
i32 *b = &a;

int main(){
	std:vector<std::string> vec{"hello", "2022"};
	...
}
```

Cppfront:
```c++
shape: type = { /* syntax 2 code doesn’t exist today, can update
semantics as desired without any breaking change */ }

f: (i: int) -> string = { /* syntax 2 code doesn’t exist today, can update
semantics as desired without any breaking change */ }

a: int = 0;
b: *int = a&;

main: () -> int = {
	vec: std:vector<std::string> = ("hello", "2022");
	...
}
```

### Order independence


No forward declarations inCpp2 because we forward-declare everything in the Cpp1 code. Functions and objects can be declared in any order because Cppfront warrants the declaration, e.g.:

Cppfront:
```c++
main: () = {
    myType := MyType();
	println(myType.myX);
}

MyType: type = {
	public myX: std::string = "myX\n";
}

println: (myvar:) = { std::cout << myvar;}
```

### wildcard `_`

There are two uses for wildcard `_`.
- deduced type wildcard
- “don’t care” wildcard


#### deduced type wildcard

Since C++11, the `auto` keyword has been introduced to deduce the type from the initializer. In Cppfront, you can use `_` in place of the C++ `auto` keyword. See the example for clarification.

Cppfront:
```c++
test: (d: _) = {
	a: int = 0;
	b: _ = a;
}
```

However, in Cppfront, you don't even need the `_` as the type can be inferred from the initialization. Refer to the example below for more details.

Cppfront:
```c++
test: (d:) = {
	a: = 0;
	b: = a;
}
```

However, deduced type is only allowed for local variables (e.g., inside functions) or within classes. It is not allowed for global variables or variables declared at the namespace scope.

See also [variables](../basic_data_types/Variables.md).

#### “don’t care” wildcard

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

See also [variables](../basic_data_types/Variables.md).

### All variables must be initialized:

All variables in Cppfront must be initialized; failing to do so will result in a compiler error.

`a: int = 0;` is ok.

`a: int;`, unless in a type definition, it will fail with comment:

```
variable must be initialized on every branch path
 ==> program violates initialization safety guarantee - see previous errors
```
It is not allowed to initialize a pointer with `nullptr`.
There are some discussion how shall be raw-pointers handled. See: [cppfront issues 192](https://github.com/hsutter/cppfront/issues/192) and  [cppfront discussions 646](https://github.com/hsutter/cppfront/discussions/646).

See also [variables](../basic_data_types/Variables.md).

See also [introduction](../pointers_and_references/Introduction.md) to pointers.

### Non-local objects are `const` by default

In Cpp2, a majority of objects adopt the `const` attribute by default. Specifically:

- Parameters inherently assume a `const` nature. The default setting for parameters is `in`, which not only signifies `const` but also restricts any modifications to its state. If mutability is required, then the alternative is `inout`, which isn't set by default.
- As a result, class member functions are inherently `const`. The reason lies in their implicit `this` parameter, which, like any other parameter, defaults to `in` and subsequently, `const`.
- (To be implemented) I'm planning for non-local entities, such as global and static objects, to be automatically recognized as `constexpr`.

Cppfront:
```c++
	T: type = {
		func1: (_a:, _b:) -> bool = {return _a == _b;}
	}

	myfunc: (_a:, _b:) -> int = {
		a = _a;
		b = _b;
	}
```

Results:

C++:
```c++
...
class T {
    private: int a {1}; 
    private: int b {2}; 
    public: [[nodiscard]] static auto func1(auto const& _a, auto const& _b) const& -> bool;
        
    public: T() = default;
    public: T(T const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(T const&) -> void = delete;
};
...
    [[nodiscard]] auto T::func1(auto const& _a, auto const& _b) const& -> bool{
        (*this).a = _a;
        (*this).b = _b;
        return a == b; 
    }
...
	[[nodiscard]] auto myfunc(auto const& _a, auto const& _b) -> int{
		a = _a;
		b = _b;
	}
...
```



## TODO

Declare left-to-right:

Order independence

deduced type wildcard

“don’t care” wildcard

All variables must be initialized

Non-local objects are `const` by default

pointer and nullpter

const, constexpr, consteval and constinit


## Next

To the [next Chapter](Operators.md).

To the [previous Chapter](Basic_types.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

