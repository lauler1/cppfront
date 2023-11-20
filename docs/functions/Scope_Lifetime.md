# Scope and Lifetime


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

How it is done in C and C++ 98 and modern C++

## New syntax cppfront

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

## TODO

Common format Function, Lambda, and Block Statements

Also `std::function` ??? `std::forward` for injection of funtions as dependence for test mock


## Next

To the [next Chapter](Functional_prog.md).

To the [previous Chapter](Lambdas.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)
