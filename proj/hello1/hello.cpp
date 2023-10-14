

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#include <stdio.h>

#line 3 "hello.cpp2"
auto main(int const argc_, char** argv_) -> int;
 

//=== Cpp2 function definitions =================================================


#line 3 "hello.cpp2"
auto main(int const argc_, char** argv_) -> int{
 auto args = cpp2::make_args(argc_, argv_); 
#line 4 "hello.cpp2"
 std::string mytext {"my text."}; 
 std::cout <<  "This exe is " + cpp2::to_string(cpp2::assert_in_bounds(args, 0)) + ", " + cpp2::to_string(std::move(mytext));
}

