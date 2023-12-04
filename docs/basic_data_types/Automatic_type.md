# Type Inference


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](basic_data_types/Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

Embrace the convenience of type inference in Cppfront with `auto`, allowing the compiler to deduce the type of a variable from its initializer. Explore `decltype` for obtaining the type of an expression, streamlining template code, and making your programs more adaptable to changes.

	* auto
	* decltype
	

## New syntax cppfront

Shows how is done now


## How is the code transpiled

## Advanced topics

Cover other advanced modern C++ topics (e.g. C++ 17, 20, 23) because the idea is to teach how to write code right.
If cppfront does not have a specific syntax, then use modern C++.




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



## Next

To the [next Chapter](Strings.md).

To the [previous Chapter](Operators.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

