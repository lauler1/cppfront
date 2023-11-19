# Overvie of new syntax for "@xxxx type"


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

Main source file:///C:/Users/auler/Downloads/cpp2/Cooperative_cpp_evolution_CppCon_2023_-_Sutter.pdf which is downloaded.


See [Cppfront-spring-update](https://herbsutter.com/2023/04/30/Cppfront-spring-update/) page.

including unifying all special member functions as `operator=`.

@interface An abstract class having only pure virtual functions.

@polymorphic_base A pure polymorphic base type that is not copyable or movable, and whose destructor is either public+virtual or protected+nonvirtual.

@ordered A totally ordered type with `operator<=>` that implements `std::strong_ordering`
	Also: @weakly_ordered, @partially_ordered.
	
@copyable A type that has copy/move construction/assignment.

@basic_value A `copyable` type that has public default construction and destruction (generated if not user-written) and no protected or virtual functions.

@value An ordered `basic_value`.
	Also: @weakly_ordered_value, @partially_ordered_value.
	
@struct A `basic_value` with all public members, no virtual functions, and no user written `operator=`.

@enum Same safeties as `enum class` + only valid values.

@flag_enum Same as `@enum` but as flags (bit fields), add up them into a variable using the `|` operator.

@union Same usability as `union`, same safety as `variant`.

	TO DO All types translates to classes to bring safety.
	
	TO DO: @union is safe union translated to a classe. See thes to declarations:
Cppfron
```c++
Y: @union type = {
    a: int;
    b: int;
}

int b;
int func(){
    a: int = 0;
    int b;
    return 0;
}
```
They are translated to C++ as:
```c++
union X{
    a: i32;
    int b;
}

class Y {
private: std::aligned_storage_t<cpp2::max(sizeof(int), sizeof(int))> _storage {}; private: cpp2::i8 _discriminator {-1}; public: [[nodiscard]] auto is_a() const& -> bool;
public: [[nodiscard]] auto a() const& -> int const&;
public: [[nodiscard]] auto a() & -> int&;
public: auto set_a(cpp2::in<int> _value) & -> void;
public: auto set_a(auto&& ..._args) & -> void;
public: [[nodiscard]] auto is_b() const& -> bool;
public: [[nodiscard]] auto b() const& -> int const&;
public: [[nodiscard]] auto b() & -> int&;
public: auto set_b(cpp2::in<int> _value) & -> void;
public: auto set_b(auto&& ..._args) & -> void;
private: auto _destroy() & -> void;
public: ~Y() noexcept;

    public: Y() = default;
    public: Y(Y const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(Y const&) -> void = delete;
};
```


How it is done in C and C++ 98 and modern C++

## New syntax cppfront

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
- **@union** Same usability as `union`, same safety as `variant`. C/C++ unions are not supported in pure mode (using `-p` option).



# TODO

- Overloading of operator

## Open Points

- Complete cover of operators overload


## Next

To the [next Chapter](Introduction_OOP.md).

To the [previous Chapter](../functions/Functional_prog.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)
