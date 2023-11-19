# in, out, inout: parameters


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

### `in`, `out` and `inout`

Cppfront has no references `&`.

Declare intent directly:

|                         |                            |
| ----------------------- | -------------------------- |
| f: ( in x: **X** )      | an x I can read from.      |
| f: ( inout x: **X** )   | an x I can read and write. |
| f: ( out x: **X** )     | an x I will assign to.     |
| f: ( move x: **X** )    | an x I will move from.     |
| f: ( forward x: **X** ) | an x I will pass along.    |

Where **X** is the type or `_`. See examples below:

Cppfront:
```c++
f1: ( in x: )      = {}
f2: ( inout x: )   = {}
f3: ( out x: )     = {x=1;}  //Must be initialized
f4: ( move x: )    = {}
f5: ( forward x: ) = {}
```

See also [parameters](../functions/Parameters.md) of functions.

### Move on Last Use

One of the pivotal concepts ushered in with C++11 was move semantics. This feature allows for circumventing costly deep copy operations by substituting them with more economical move operations. In essence, move semantics enable the transformation of a **deep copy** into a **shallow copy**. In Cppfront, local variables are automatically subjected to a move on their final utilization.

Cppfront:
```c++
g: (inout myvar:) = {myvar++;}

main: () = {
    myvar := 0;
    g(myvar);
    g(myvar);
    g(myvar);
}
```

This gets translated to:

C++:
```c++
...
auto g(auto const& myvar) -> void {++myvar;  }

auto main() -> int {
    auto myvar {0}; 
    g(myvar);
    g(myvar);
    g(std::move(myvar));
}
```

However, there's a snag with the above rendition. The function signature `g: (inout myvar:)` does not accept a rvalue of the type ‘std::remove_reference<int&>::type’. This results in the error:
```bash
error: cannot bind non-const lvalue reference of type ‘int&’ to a rvalue of type ‘std::remove_reference<int&>::type’ {aka ‘int’}
```

To navigate around this issue, there are two alternatives:
1. Introduce a fresh function that accommodates the move operation, i.e., `g: (move myvar:)`.
2. Invoke `myvar` post its last call to `g:()`. This can be achieved by appending a line like `_ = myvar;`.

Both strategies are viable. However, in the given example, employing the first solution makes the second one untenable. This is because, after `myvar` is moved, it resides in an unspecified state and its continued use within `main:()` is not guaranteed to be valid.

### Specifying Parameter Types Explicitly

In Cppfront, you have the ability to specify the type of function parameter you wish to use when calling overloaded functions.

Cppfront Example:
```c++
myfunc: (x: u8)   = { std::cout << "u8:  (x)$\n"; }
myfunc: (x: u16)  = { std::cout << "u16: (x)$\n"; }
myfunc: (x: u32)  = { std::cout << "u32: (x)$\n"; }

main: () = {
    myfunc(:u8 =  1);  // Calls version with u8
    myfunc(:u16 = 1);  // Calls version with u16
    myfunc(:u32 = 1);  // Calls version with u32
}
```

### Universal Function Call Syntax (UFCS)

The implementation of UFCS is now force-inlined on all compilers, i.e. when calling a nonmember function `f(x,y)` use `x.f(y)`. This is a Zero-cost implementation of UFCS.

Cppfront:
```c++
main: ()={
x: double = 9.0;
result: double = x.sqrt();     // Instead of std::sqrt(x);

v: std::vector<int> = (3, 1, 4);
_ = v.size();                  // Instead of std::size(v);

fd := fopen("test.txt", "w");
_ = fd.fprintf("Hello World"); // Instead of fprintf(fd, "Hello %d!", 2);
_ = fd.fclose();               // Instead of fclose(fd)
// Note the '_' to force discards the results due to ‘nodiscard’ [-Wunused-result].
}
```

See also: https://github.com/hsutter/cppfront/discussions/811

### Pre-, Postconditions and Assert

Syntax:
- `[[pre: <condition>]]` = Precondition.
- `[[post: <condition>]]` = Postcondition.
- `[[assert: <condition>]]` = Assert.

As their names suggest, preconditions and postconditions are used to test the conditions before and after a function is called. If a condition fails, a contract error is written to stderr, and the program is aborted.

Cppfront:
```c++
i:int=0;
main: () -> int = {
    myincrement();
    myincrement();
}
myincrement: () 
    [[pre:  i >= 0 ]]
    [[post: i > 0 && i == (i$+1)]]
= {
    i++;
}
```

In order to improve the quality of information sent to stderr, use the option `-a` of the Cppfront transpiler.

Asserts can be used everywhere, e.g. `[[assert: !(pt1 == pt2)]]`.



## TODO

Pre-, Postconditions and Assert

Universal Function Call Syntax (UFCS)

Specifying Parameter Types Explicitly, when calling overloaded functions.

Concept of Move. But remember that Move is also addressed in class Constructors

`in`, `out`, `inout` and `move`

Move on Last Use 


## Next

To the [next Chapter](Lambdas.md).

To the [previous Chapter](Declaration.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)
