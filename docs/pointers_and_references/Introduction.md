# Introduction


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

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
In Cppfront, the delete operator is not present, and raw pointers do not have the capability to own memory. Additionally, pointer arithmetic is not permitted in Cppfront.




## TODO

pointer and nullpter: It is not allowed to initialize a pointer with `nullptr` in cppfront.

In Cppfront, the delete operator is not present, and raw pointers do not have the capability to own memory. Additionally, pointer arithmetic is not permitted in Cppfront.


## Next

To the [next Chapter](Memory_safety.md).

To the [previous Chapter](../control_statements/Repetition.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)
