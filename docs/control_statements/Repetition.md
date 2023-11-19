# Repetition Control Statements


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

How it is done in C and C++ 98 and modern C++

## New syntax cppfront

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

### Corollary: Simplified `for` each

Removed `:` and `=` from `for` each.

Cppfront
```c++
for items do (item) {
    x := local + item;
    // ...
}
```

to this:

C++
```c++
for items do: (item) = {
    x := local + item;
    // ...
}
```

which is the same except that it removes `:` and `=`.

## TODO

Corollary: Simplified `for` each. Removed `:` and `=` from `for` each.

Named break and continue


## Next

To the [next Chapter](../pointers_and_references/Introduction.md).

To the [previous Chapter](Selection.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)
