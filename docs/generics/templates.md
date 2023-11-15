# templates


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++
In C++, "generics" are more commonly referred to as "templates." They allow you to write a single class or function definition that works on a variety of data types rather than a specific one. Templates enable type-safe and flexible code, and they are a foundational feature for generic programming in C++.

### Overview:

1. **Function Templates**: These are used to create functions that can be adapted to more than one type or class without resorting to overloading.

   ```cpp
   template <typename T>
   T add(T a, T b) {
       return a + b;
   }
   ```

   You can then call this function with `int`, `float`, or any type that supports the `+` operation.

2. **Class Templates**: Like function templates, class templates allow you to define a blueprint for a class, and then create instances of the class specifically tailored to different types.

   ```cpp
   template <typename T>
   class Box {
   private:
       T item;
   public:
       Box(T i) : item(i) {}
       T getItem() { return item; }
   };
   ```

   You can create instances like: `Box<int> intBox(5);` or `Box<std::string> strBox("hello");`

### How Templates Work:

When you use a template in your code (i.e., instantiate a class template or call a function template with a specific type), the compiler generates a version of that code specifically for the given type(s). This process is known as "instantiation." It's important to note that the template code is only a blueprint; actual code gets generated only for the types with which templates are instantiated.

### Key Points:

- **Type Safety**: Templates provide a way to write functions and classes that work with many data types, while still retaining type safety.
  
- **Compile Time**: Templates are a compile-time feature. The code for each instantiation is generated during compilation.

- **Flexible & Reusable**: Instead of writing multiple versions of a function or class for different types, you can write a single, generic version.

- **Variadic Templates**: Introduced in C++11, these allow functions and classes to accept a variable number of template arguments.

- **Specialization**: You can provide specialized behavior for a specific type of a template.

- **Concepts** (C++20): Introduced in C++20, concepts define a set of requirements for template arguments, enhancing type safety and readability.

Templates (or generics in other languages like C# or Java) are a powerful feature in C++ and form the basis for many Standard Library components, such as containers (like `std::vector`, `std::list`) and algorithms (`std::sort`, `std::find`).

### Overview of Concepts:

Concepts, introduced in C++20, are an extension of C++'s template system that allow for more fine-grained constraints on template parameters. They're a significant advancement in C++'s type system and are sometimes informally referred to as a form of "type-level programming."

Concepts provide a way to express more refined and readable constraints on templates, moving beyond the simple type-based constraints provided by traditional templates.

#### Basic Usage:

Instead of writing a template like this, where constraints are either implicit or manually checked:

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;  // Assumes T supports the + operation, but this isn't enforced by the compiler until instantiation.
}
```

You can use a concept to explicitly state your assumptions:

```cpp
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>; 
};

template <Addable T>
T add(T a, T b) {
    return a + b;
}
```

With the concept in place, if you tried to instantiate the `add` function with a type that doesn't support the `+` operation, the compiler would give a clear error message at the point of the function's use, rather than a potentially cryptic error inside the function's implementation.

#### Standard Library Concepts:

C++20 added a lot of predefined concepts in the standard library, many of which are designed to work with the existing algorithms and containers. Some examples include:

- `std::integral`: Matches integral types like `int`, `char`, etc.
- `std::floating_point`: Matches floating-point types like `float`, `double`, etc.
- `std::predicate`: Matches any callable type that can be invoked with a given set of arguments and returns something convertible to `bool`.

### Benefits of Concepts:

1. **Readability**: Concepts can make template code more understandable by clearly stating the assumptions on types.
  
2. **Better Error Messages**: If a type does not meet the requirements of a concept, the compiler can provide a clearer and more direct error message.

3. **Overloading Based on Constraints**: You can overload functions based on concepts, which allows for different implementations based on type properties.

4. **Design and Documentation**: By defining concepts, library authors can more precisely document and express the interface and expectations of their components.

To sum up, while traditional templates can be seen as "unchecked" generics, where constraints are implicit and errors can be cryptic, concepts turn them into "checked" generics, where constraints are explicit, readable, and enforced by the compiler.

## New syntax cppfront

Shows how is done now


## How is the code transpiled

## Advanced topics

Cover other advanced modern C++ topics (e.g. C++ 17, 20, 23) because the idea is to teach how to write code right.
If cppfront does not have a specific syntax, then use modern C++.

