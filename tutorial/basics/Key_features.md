# Interoperability and Key Features of Cppfront


Back to Tutorial [home](../readme.md)

Back to the Chapter [Overview](Overview.md)

## Interoperability

One of Cppfront's main goals is full interoperability with C++. This makes it easier to integrate Cppfront into existing C++ projects and leverage existing libraries.
Stemming from the C++ lineage, Cppfront aims to refresh and rejuvenate the C++ language. It attempts to reduce complexity and maintain full interoperability with C++, making the transition easier for existing C++ developers.
The silver lining is the seamless interoperability Cppfront boasts with C++. This makes it approachable for enthusiasts keen on experimenting, although it's worth noting that it's still in its nascent stage for production use.

In Cppfront, you're presented with two choices:
- You can blend Cpp1/Cpp2 within a single source file, ensuring seamless backward compatibility through `#include` or `import`.
- You can opt to use exclusively Cpp2 syntax in a specific source file.

For those transitioning a multi-file C++ project to Cppfront, it's advisable to take a gradual approach. Consider converting one C++ file to Cppfront at a time. After each conversion, ensure it compiles and runs smoothly before moving on to the next file.

You can combine Cpp1 and Cpp2 in a single file. However, once you start using Cpp2 syntax for a function or type definition, you must stick to Cpp2 inside it. For instance, in the example below, only Cpp2 syntax is allowed within the `main` function and the `Y` union.

Cppfront:
```c++
union X{           // union declared with syntax 1
    a: i32;        // mixed syntax allowed inside
    int b;
}

Y: @union type = { // union declared with syntax 2
    a: int;        // only sintax 2 allowed inside
    b: int;
}

int func(){        // function declared with syntax 1
    a: int = 0;    // mixed syntax allowed inside
    int b;
    return 0;
}

main: (args) = {   // function declared with syntax 1
    a: int = 0;    // only sintax 2 allowed inside
    b: *int = a&;
    b: = a;

    std::cout << "This program's name is (args[0])$";
}

a: long = 0;   // mixed syntax at namespace scope
int b;
long *x = &a;
```

Lastly, when it comes to debugging, projects that combine both Cpp1 and Cpp2 syntaxes pose no unique challenges. Modern debugging tools and environments are designed to seamlessly handle this mix, allowing developers to inspect and troubleshoot their code efficiently. Whether you're stepping through a Cpp1 function or analyzing variables in a Cpp2 segment, the experience remains consistent and intuitive. It's a testament to the adaptability and forward-thinking design of today's development tools.


## Key features:

This section provides a summary of Cppfront's primary features. Each topic will be elaborated upon in subsequent chapters. For those familiar with C++, this section offers a comprehensive introduction to the language and a broad view of its capabilities.

### goals: safety, simplicity, toolability

stay measurable: Each change must address a known C++ weakness in a measurable way (e.g., remove X% of rules we teach, remove X% of reported vulnerabilities)

stay C++: never violate zero-overhead, opt-in to “open the hood”

### Syntax & grammar

declare l-to-r: Declarations are written left to right

optional `{` `}` for single-expression functions, e.g. `println: (x: _) = std::cout << x << "\n";`.

lambda is declared the same way as a function, but omits the name, e.g. `:(x: int = init) = { ... }`.

context-free: Esp. parsing never requires sema (e.g., lookup)

order-independent: No forward declarations or ordering gotchas


declare ≡ use: Declaration syntax mirrors use syntax
	
### Automatic inclusion of the std libraries:
	
The "std" library is inherently included in Cppfront

“include std;” is implicit  under -pure-cpp2

### Cpp2util:	

self-contained support library header (e.g., in<T>):
"#include "cpp2util.h"

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

Order of declaration of functions:
Functions can be declared in any order because Cppfront warants the declaration

order independence (no forward declarations inCpp2 because we forward-declare everything in the Cpp1 code)

### wildcard `_`

There are two uses for wildcard `_`.
- deduced typewildcard
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

This topic is also shown in the **Move on Last Use** section below. In this example, that call to `g: (inout myvar:)`; is a definite last use of `myvar`, and so Cpp2 will automatically pass `myvar` as an rvalue and make it a move candidate… and presto! the call won’t compile because you can’t pass an rvalue to a Cpp2 `inout` parameter. That’s a feature, not a bug, because if that’s the last use of `myvar` that means the function is not looking at `myvar` again, so it’s ignoring the “out” value of the `g: (inout myvar:)` function call, which is exactly like ignoring a return value. And the guidance is the same: If you really meant to do that, just explicitly discard `myvar`‘s final value:

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

### All variables must be initialized:

All variables in Cppfront must be initialized; failing to do so will result in a compiler error.

`a: int = 0;` is ok.

`a: int;`, unless in a type definition, it will fail with comment:

```
variable must be initialized on every branch path
 ==> program violates initialization safety guarantee - see previous errors
```


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

### Basic types

Cppfront has introduced a set of primitive types derived from the C++ language's basic types and its standard library. These can be utilized without importing any additional libraries.

- New signed types (from std): i8, i16, i32, i64
- New unsigned types (from std): u8, u16, u32, u64
- Also (from primitive): ushort, ulong, longlong, ulonglong, longdouble

### The `new` Syntax in Cppfront

In Cppfront, the `new` syntax defaults to returning a `std::unique_ptr`. Interestingly, if you specify the type of a variable as either `std::shared_ptr` or `std::unique_ptr<int>`, the `new<T>` syntax will adjust its return type accordingly.

Here's an illustrative example in Cppfront:

```c++
main: () = {
    p1:= new<int>(0);                     // Defaults to std::unique_ptr<int>
    q1: std::shared_ptr<int> = new<int>(0);  // Explicitly std::shared_ptr<int>
    r1: std::unique_ptr<int> = new<int>(0);  // Explicitly std::unique_ptr<int>

    std::cout << "p1's type = (typeid(p1).name())$\n";
    std::cout << "q1's type = (typeid(q1).name())$\n";
    std::cout << "r1's type = (typeid(r1).name())$\n";
}
```

When executed, the program produces:

```bash
p1's type = St10unique_ptrIiSt14default_deleteIiEE
q1's type = St10shared_ptrIiE
r1's type = St10unique_ptrIiSt14default_deleteIiEE
```

Cppfront does not allow pointer arithmetic.

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

However, there's a snag with the above rendition. The function signature `g: (inout myvar:)` does not accept an rvalue of the type ‘std::remove_reference<int&>::type’. This results in the error:
```bash
error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘std::remove_reference<int&>::type’ {aka ‘int’}
```

To navigate around this issue, there are two alternatives:
1. Introduce a fresh function that accommodates the move operation, i.e., `g: (move myvar:)`.
2. Invoke `myvar` post its last call to `g:()`. This can be achieved by appending a line like `_ = myvar;`.

Both strategies are viable. However, in the given example, employing the first solution makes the second one untenable. This is because, after `myvar` is moved, it resides in an unspecified state and its continued use within `main:()` is not guaranteed to be valid.

### [[nodiscard]] by default

C++17 introduced the [[nodiscard]] attribute. Applying this attribute to a function signals that its return value shouldn't be overlooked, prompting the compiler to issue a warning. This can aid in averting security, memory leak, and performance-related bugs. While using this attribute consistently can be inconvenient, Cppfront makes [[nodiscard]] the default behavior, eliminating the need for explicit annotations.


### `this` is explicit and not a pointer

See: https://github.com/hsutter/cppfront/wiki/Cpp2:-operator=,-this-&-that

In Cppfront, the `this` parameter is visible and not a not magic. This is famiuliar to Python programmers.
For normal fuctions, `this` is optional, however for constructors, destructors and operators it is mandatory.
The following example:

Cppfront:
```c++
Point2: @struct type = {
	x: int = 2;
    y: int = 3;

    myfunc: (this, in myparam:) -> int = {
        return this.x * this.y + myparam;
    }
}

main: () ={
	mypoint:= Point2();
	std::cout << mypoint.myfunc(1);
}
```

Will transpile to:

C++:
```c++
class Point2 {
	private: int x {1}; 
    private: int y {1}; 

    public: [[nodiscard]] auto myfunc(auto const& myparam) const& -> int;
}

 ...
 
[[nodiscard]] auto Point2::myfunc(auto const& myparam) const& -> int{
	return (*this).x * (*this).y; 
}
```

And will result to:

```
7
```

### Constructors and destructors

In Cppfront, constructors, assignment, conversion, and destructors are defined with the `operator=`. For constructors, the parameter `out this` is mandatory. For destructors, the parameter `move this` is mandatory.

Cppfront:
```c++
Point: type = {
	x: int = 2;y: int = 3;

    operator=: (out this, in _x, in _y) = {
        x=_x; y=_y;
        std::cout << "Point: my contructor (x)$ (y)$\n";
    }
    operator=: (out this) = {
        std::cout << "Point: my def contructor\n";
    }
    operator=: (move this) = {
        std::cout << "Point: destructor (x)$ (y)$\n";
    }
}

main: () ={
	pt1:= Point();
	pt2:= Point(1,2);
}
```

### `that` parameter

> TODO

The `that` parameter can be used to move and copy members from a class, it is a synonym for the object to be copied/moved from.

Cppfront:
```c++
myclass : type = {
    operator=: (out this) = {
		std::cout << "Default constructor\n";
	}
    operator=: (out this, that) = {
        name = that.name;
        addr = that.addr;
		std::cout << "Copy constructor\n";
    }
    operator=: (out this, move that) = {
        name = that.name;
        addr = that.addr;
		std::cout << "Move constructor\n";
    }
    operator=: (move this) = {
		std::cout << "Destructor\n";
    }
    print: (this) = {
        std::cout << "name '(name)$', addr '(addr)$'\n";
    }
    name: std::string = "Henry";
    addr: std::string = "123 Ford Dr.";
}

main: () = {
    x: myclass = (); //Create
    x.print();
    std::cout << "-----\n";
    y := x; //Copy
    x.print();
    y.print();
    std::cout << "-----\n";
    z := (move x); //Move
    x.print();
    z.print();
}
```

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

#### Captured Variables

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

This is also valid for post-conditions and string interpolation.

Cppfront:
```c++
[[post: v.size() == v.size()$ + 1]] // capture a copy of v.size() on function entry for use later when the whole postcondition is evaluated on function exit.

"My name is (name)$" // capture a copy of name on string construction for use later when the string value is referred to
```

> Note: At the moment of writing this tutorial, there was some discussion about how should be the syntax of Captures (e.g., prefix or suffix `$`).


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

### `<=>` three-way comparison ("spaceship")

> TODO


Directly express comparison intent, eliminate boilerplate & errors See P0515. This operator was introduced to c++20 standard. It is not used directly to compare but to generate the comparison object for all `==, !=, <, >, <=, >=` cases.

The primary motivation behind this operator is to simplify the process of writing comparison functions. Instead of writing separate ==, <, <=, >, and >= operators, you can just write a single <=> operator, and the compiler can derive the others (assuming you also declare them as defaulted).

Cppfront:
```c++
struct Point {
	int x, y;
	bool operator<=>(const Point&) const = default;
};

main: () ={
    [[assert: !(pt1 == pt2)]]
    [[assert:   pt1 != pt2 ]]
    [[assert:   pt1 <  pt2 ]]
    [[assert:   pt1 <= pt2 ]]
    [[assert: !(pt1 >  pt2)]]
    [[assert: !(pt1 >= pt2)]]
}
```

### Named break and continue

Cppfront:
```c++
while_continue_outer: () =
{
    i := 0;
    outer: while i<3 next i++ {
        j := 0;
        while j<3 next j++ {
            std::cout << i << j << " ";
            if j == 1 {
                continue outer;
            }
            std::cout << "inner ";
        }
        std::cout << "outer ";
    }
}

while_break_outer: () =
{
    i := 0;
    outer: while i<3 next i++ {
        j := 0;
        while j<3 next j++ {
            std::cout << i << j << " ";
            if j == 1 {
                break outer;
            }
            std::cout << "inner ";
        }
        std::cout << "outer ";
    }
}
```

### New unified type system

Unified format has `name: <@metafunction> type = {...}` syntax, where metafunction can be:

- **@interface** An abstract class having only pure virtual functions.
- **@polymorphic_base** A pure polymorphic base type that is not copyable or movable, and whose destructor is either public+virtual or protected+nonvirtual.
- **@ordered** A totally ordered type with `operator<=>` that implements `std::strong_ordering`
	- Also: @weakly_ordered, @partially_ordered.
- **@copyable** A type that has copy/move construction/assignment.
- **@basic_value** A `copyable` type that has public default construction and destruction (generated if not user-written) and no protected or virtual functions.
- **@value** An ordered `basic_value`.
	- Also: @weakly_ordered_value, @partially_ordered_value.
- **@struct** A `basic_value` with all public members, no virtual functions, and no user written `operator=`.
- **@enum** Same safeties as `enum class` + only valid values.
- **@flag_enum** Same as `@enum` but as flags (bit fields), add up them into a variable using the `|` operator.
- **@union** Same usability as `union`, same safety as `variant`.


### Corollary: Simplified `for` each

Removed `:` and `=` from `for` each.

Cppfront
```c++
for items do (item) {
    x := local + item;
    // ...
}
```

C++
```c++
for items do: (item) = {
    x := local + item;
    // ...
}
```

to this, which is the same except that it removes : and =


### Keywords `is` and `as`, and pattern matching

all type casts done via as

- **x is C** can be used uniformly for all constraints. C can be a type predicate, specific type, value predicate,
or specific value.
- **x as T** can be used uniformly to invoke all casting (conversions and coercions). T is a type predicate or
specific type.

[P2392: Pattern matching using is and as](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2392r2.pdf) is the ISO C++ committee paper.

Cppfront
```c++
main:()={
    vec:= std::vector(1, 2);
    std::cout << fun(vec) << "\n";
    arr: std::array = (1, 2);
    std::cout << fun(arr) << "\n";
    i:= 1;
    std::cout << fun(i) << "\n";
    f:= 1.0;
    std::cout << fun(f) << "\n";
}
fun: (v : _) -> std::string = {
	if v is std::vector { return "std::vector"; }
	if v is std::array { return "std::array"; }
	if v is std::variant { return "std::variant"; }
	if v is int { return "int"; }
	else { return "unknown"; }
}
```

## Advanced topics

Cover other advanced modern C++ topics (e.g. C++ 17, 20, 23) because the idea is to teach how to write code right.
If Cppfront does not have a specific syntax, then use modern C++.

---

Discover the essence of Cppfront through its salient features. This section emphasizes:
   - Integrating tools: Unravel the workings of compilers and debuggers within the Cppfront ecosystem.
   - Bridging with C++ Syntax: Learn how to seamlessly use C++ syntax within Cppfront, ensuring a smoother transition and enhanced compatibility.
   - Preprocessors in Action: Understand the significance of '#' for macros and delve into the intricacies of "include" functionalities.
   - Beyond the Basics: While this tutorial focuses on the fundamentals, it's imperative to note that anything from C++ not explicitly covered here can be integrated into Cppfront. This feature accentuates the language's versatility.
  

## Next

To the [next Chapter](../basic_data_types/Overview.md). {style=text-align:center}

To the [previous Chapter](First_Program.md).

Back to Tutorial [home](../readme.md)

Back to the Chapter [Overview](Overview.md)

