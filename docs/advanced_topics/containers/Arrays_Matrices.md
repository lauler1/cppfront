# Arrays and Matrices


Back to Tutorial [home](../readme.md)

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


How it is done in C and C++ 98 and modern C++

## New syntax cppfront

Shows how is done now


## How is the code transpiled

## Advanced topics

Cover other advanced modern C++ topics (e.g. C++ 17, 20, 23) because the idea is to teach how to write code right.
If cppfront does not have a specific syntax, then use modern C++.

