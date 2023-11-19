# Constructors and destructors


Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)

![Tutorial Under Construction](../TutorialUnderConstruction.png)

## Background C and C++

How it is done in C and C++ 98 and modern C++

### Operators

Overload of operator in Cppfront has the syntax `operator@: (params) -> <return type> = {/*implementation*/}`, where @ is the operator to be overloaded.

Cppfront:
```c++
MyType: type = {
    x: int = 0;
    operator=: (inout this, _x:int) = {
        x=_x;
    }
    operator++: (inout this) -> int = {
        x++;
        return x;
    }
    operator+=: (inout this, _x:int) -> int = {
        x+=_x;
        return x;
    }
    operator+: (move this, move that) -> int = {
        x+=that.x;
        return x;
    }
}
main: () = {
    myvar: MyType = ();
    std::cout << myvar++ << "\n";
    std::cout << (myvar+=2) << "\n";

    myvar2: MyType = ();
	myvar2=2;
    std::cout << (myvar+myvar2) << "\n";
}
```

Note the explicit use of the param `this`.

See also [C++ operator overloading](https://en.cppreference.com/w/cpp/language/operators) for more details on this topic.
> Note: As of the time this tutorial was written, Cppfront did not support full creation of operators.

### Explicit `this` Reference

Refer to: [Cpp2: operator=, this & that](https://github.com/hsutter/cppfront/wiki/Cpp2:-operator=,-this-&-that)

In Cppfront, the `this` parameter is explicit and not hidden, similar to how it is used in Python. While it is optional for regular member functions, it is required for constructors, destructors, and overloaded operators. If `this` is not specified in the member function's parameter list, then the function behaves like a static method, meaning it does not have access to the instance members of the class.

Here is an example:

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


## TODO

Constructors

The `new` Syntax in Cppfront

Destructors

Operator overload

`this` and `that`

Also mention: Overload operator<< for std::ostream as the Java .toString() equivalent

Compatibility: Old style structs from ANSI C language, initialization of members of old C structs

## Next

To the [next Chapter](Copy_Move.md).

To the [previous Chapter](Introduction_OOP.md).

Back to Tutorial [home](../README.md)

Back to the Chapter [Overview](Overview.md)
