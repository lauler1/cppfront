# Vectors


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

```cpp
main:()={
    vec:= std::vector(1, 2);
    std::cout << fun(vec) << "\n";
    arr: std::array = (1, 2);
    std::cout << fun(arr) << "\n";
    //var:= std::variant=(1, 2);
    //fun(var) << "\n";
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
	//if v is my_type { return "my_type"; }
	else { return "unknown"; }
}
```

## New syntax cppfront

### Bounds check

Cppfront automatically performs runtime checks for bounds violations when accessing elements of arrays, vectors, lists, and similar data structures. In the event of an out-of-bounds access, the application is terminated.

Cppfront
```c++
main: () -> int
= {
	a: std::array<char, 6> = ("hallo");
    std::cout << a[-1] << "\n"; // aborts
	
    sv: std::string_view = ("Hallo");
    std::cout << sv[5] << "\n"; // aborts

    v: std::vector = ("str1", "str2");
    std::cout << v[2] << "\n"; // aborts
}
```

## TODO

Bounds check. Cppfront automatically performs runtime checks for bounds violations when accessing elements of arrays, vectors, lists, and similar data structures.


## Next

To the [next Chapter](Tuples.md).

To the [previous Chapter](Arrays_Matrices.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)
