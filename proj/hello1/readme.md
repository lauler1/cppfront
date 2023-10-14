# Compilation


## Clang

```bash
cppfront hello.cpp2

clang++ hello.cpp -I../../cppfront/include/ -std=c++20 -o hello
or
clang++ -fuse-line-directives -O0 -g -I../../cppfront/include/ -std=c++20 hello.cpp -o hello

```

For debugging it is necessary to use `-fuse-line-directives` and `-g`. Option `-fuse-line-directives` makes llvm point to cpp2 file instead of cpp whie debugging.

## g++

```bash
g++ -I../../cppfront/include/ -std=c++20 hello.cpp -o hello
or
g++ -O0 -g -I../../cppfront/include/ -std=c++20 hello.cpp -o hello
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


