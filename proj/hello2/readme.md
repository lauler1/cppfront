# Introduction

This is the same project from `proj/hello1` folder but using CMake


# Build

> Do not forget to initialize the environment running `. init.sh` from the base directory before.

```bash
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug ../
$ make
$ ./hello

```
The `-DCMAKE_BUILD_TYPE=Debug` is optional if you want to generate the debug version with the debug symbols.
You can also use CMake option `--debug-output`
