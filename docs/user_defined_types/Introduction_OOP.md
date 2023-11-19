# Introduction to OOP


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

How it is done in C and C++ 98 and modern C++

## New syntax cppfront

#### Static Members

Methods that don't include `this` are treated as static members and consequently, they cannot access the instance variables of the class. To define static const members in a class, the alias syntax can be employed.

In Cppfront:
```c++
MyType: type = {
    x :== 0;
}
```

This translates to:

In C++:
```c++
class MyType {
    public: static const auto x;
	...
}
```

> Note: As of the time this tutorial was written, Cppfront did not support the creation of [static variables](https://github.com/hsutter/cppfront/issues/522).

### Inheritance

Inheritance is done byt defining `this:` of the derived class. See example of a derived class Cyborg which inherits from interface Human:

Cppfront:
```c++
Human: @interface type = {
    speak: (this);
}

Cyborg: type = {
    name:    std::string;
    this:    Human = ();

    operator=: (out this, n: std::string) = {
        name = n;
    }

    speak: (override this) =
        std::cout << "I am a Cyborg with name: (name)$\n";
}

main: ()={
paul: Cyborg = ("Paul");
paul.speak();
}
```



## TODO

Static Members

Inheritance


## Open Points

- [Static variables](https://github.com/hsutter/cppfront/issues/522).


## Next

To the [next Chapter](Constructors_destructors.md).

To the [previous Chapter](Overvie_new_syntax_type.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)
