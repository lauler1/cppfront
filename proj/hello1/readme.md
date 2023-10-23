# Installation

The first thing needed before you can start experiencing Cppfront is to download and build it. Cppfront builds with any major C++20 compiler.

From the [cppfront]/source, run:

- MSVC build instructions [^1]
```bash
cl cppfront.cpp -std:c++20 -EHsc
```

- GCC build instructions (GCC >= 10)
```bash
g++ cppfront.cpp -std=c++20 -o cppfront
```

- Clang build instructions (Clang >= 12)
```bash
clang++ cppfront.cpp -std=c++20 -o cppfront
```

This procedure will build the tool inside the source folder, we recomend to move it to the Cppfront base dir
```bash
mv cppfront ../
```

# Compilation

Before any code can be compiled by gcc, clang or Visual Studio [^1], the Cppfront code must be transpiled to C++. In order to transpile the Cppfront code to C++, run:

```bash
$ cppfront hello.cpp2
```

You can see all the options running `cppfront -h`. By default the command will generate a C++ file with the same name (`*.cpp`) in the same folder. The output file can be change using the option `-o [newname].cpp2`. The tool also use the mixed mode by default (i.e. mixing C++ and Cppfront syntax), in order to change this use the option `-p` (pure cpp2).

[^1]: This tutorial will focus on Linux, all examples were tested in WSL. For Visual Studio setup take a look: [Cpp2-setup:-Visual-Studio](https://github.com/hsutter/cppfront/wiki/Cpp2-setup:-Visual-Studio).

## Clang

```bash
$ clang++ hello.cpp -I../../cppfront/include/ -std=c++20 -o hello
or
$ clang++ -fuse-line-directives -O0 -g -I../../cppfront/include/ -std=c++20 hello.cpp -o hello

```

For debugging it is necessary to use `-fuse-line-directives` and `-g`. Option `-fuse-line-directives` makes llvm point to cpp2 file instead of cpp whie debugging.

## g++

```bash
$ g++ -I$CPPFRONTDIR/include/ -std=c++20 hello.cpp -o hello
or
$ g++ -O0 -g -I$CPPFRONTDIR/include/ -std=c++20 hello.cpp -o hello
```

gdb will point to cpp2 file automatically, no special diretive is needed, except the `-g`.


# Debugging

I tested with gdb and lldb, no speciall issue.
lldb needs the `-fuse-line-directives`.

Example

In the following example, I show how to start the gdb debugger (the exact same steps are used in lldb) with a brakpoint in the function `main`. In the example the debuger shows the first code line of the function `main`.

> Note: In the example, lines with just a `.` represents that the extra information of the terminal were omitted to make it simpler to visualize what matters.

```bash
$ gdb hello
.
.
.
(gdb) b main
.
(gdb) run
.
.
.
Breakpoint 1, main (argc_=1, argv_=0x7fffffffde38) at /home/leandro/projects/cppfront/proj/hello1/hello.cpp2:4
4               mytext: std::string = "my text.";
(gdb) quit
```
