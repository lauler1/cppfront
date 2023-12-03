# Operators


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](basic_data_types/Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

Operators are the verbs of the programming language, enabling you to perform actions on your data. We will cover the assignment operator for setting values, arithmetic operators for mathematical operations, compound operators for combined assignment and arithmetic, and increment/decrement operators for adjusting values succinctly.

	* Assign
	* Arithmetic
	* Compound OperatorsI
	* Increment Decrement



## New syntax cppfront

Shows how is done now

### Unary Operators are Suffixes

In Cppfront, unary [operators are Suffixes](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Postfix-operators).

Cppfront:
```c++
	a: int = 0;

	a++;            // a is incremented
    b: *int = a&;   // b gets address of a
	//b++;          // Error, pointer arithmetic is not allowed
	b*++;           // Content pointed by b is incremented
    c : int = b*;   // c gets the value pointed by b
    std::cout << c<< "\n"; // result = 2
```

### Alias

Aliases are defined using the ':==' symbol and are immutable, meaning their values cannot be altered.

In Cppfront:
```c++
var_alias :== 10;                // Alias for a variable
func_alias :== main;             // Alias for a function
type_alias: type == std::string; // Alias for a type
nspace_alias: namespace == std;  // Alias for a namespace
```

### `<=>` three-way comparison ("spaceship")

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

### Keywords `is` and `as`, and pattern matching

all type casts done via as

- **x is C** can be used uniformly to test for all constraints. C can be a type predicate, specific type, value predicate,
or specific value.
- **x as T** can be used uniformly to invoke all casting (conversions and coercions). T is a type predicate or
specific type.

[P2392: Pattern matching using is and as](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2392r2.pdf) is the ISO C++ committee paper.

See also [operators](../basic_data_types/Operators.md).

#### `is`

Static queries

| Cppfront   | C++                 |
| :--------: | :-----------------: |
| `X is Y`   | `is_same_v<X,Y>`    |
| `D is B`   | `is_base_of_v<B,D>` |

Dynamic queries

| Cppfront   | C++                                                     |
| :--------: | :-----------------------------------------------------: |
| `pb is D*` | `dynamic_cast<D*>(pb)`                                  |
| `v is T`   | `std::holds_alternative<T>(v)`                          |
| `a is T`   | `a.type() == typeid(T)`                                 |
| `o is T`   | `o.has_value()`                                         |
| `f is T`   | `.wait_for(chrono::seconds(0)) == future_status::ready` | 


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

#### `as`

Static casts

| Cppfront   | C++                   |
| :--------: | :-------------------: |
| `x as Y `  | `Y(x), Y{x}`          | 
| `pd as B*` | `static_cast<B*>(pd)` |

Dynamic casts

| Cppfront  | C++                      |
| :-------: | :----------------------: |
| `pb as D `| `dynamic_cast<D*>(pb)`   |
| `v as T`  | `std::get<T>(v)`         |
| `v as T&` | `std::get<T&>(v)`        |
| `a as T`  | `std::any_cast<T>(a)`    |
| `a as T&` | `*std::any_cast<T*>(&a)` |
| `o as T`  | `o.value()`              |
| `f as T`  | `f.get()`                |


C++ non-safe casts are not allowed:

- `(Y)x`
- `reinterpret_cast<Y>(x)`
- `const_cast<X&>(cx)`

### `inspect`

`inspect` is used for pattern matching.

Cppfront
```c++
main: () -> int = {
    test_generic(0);
    test_generic(0.1);
    test_generic(true);
    test_generic("");

    up: std::unique_ptr<int> = ();
    it: std::vector<int>::iterator = ();
 
    test_generic(up);
    test_generic(it);
}
 
test_generic: ( x: _ ) = {
std::cout 
	<< typeid(x).name() << ": "
	<< inspect x -> std::string {
		is void   = " EMPTY";
		is int    = " int";
		is double = " double";
		is bool   = " bool";
		is _      = " no match";
	   }
	<< "\n";
}
```
There is a very basic support for inspect expressions, see  [`is`, `as`, and pattern matching](https://github.com/hsutter/cppfront#2021-is-as-and-pattern-matching).



## TODO

Alias: defined using the ':==' symbol

Unary Operators are Suffixes

Keywords `is` and `as`, and pattern matching

Overloading of operators will be addressed in ../user_defined_types/Overvie_new_syntax_type.md

`<=>` three-way comparison ("spaceship")

## Open Points

-  Full support for [`is`, `as`, and pattern matching](https://github.com/hsutter/cppfront#2021-is-as-and-pattern-matching).



## Next

To the [next Chapter](Automatic_type.md).

To the [previous Chapter](Variables.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

