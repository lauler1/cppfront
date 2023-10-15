cmake_minimum_required(VERSION 3.27)
project(sampleCmake)

include_directories("$ENV{CPPFRONTDIR}/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_executable(hello hello.cpp)

