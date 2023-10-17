# Cppfront guide

This folder is intended to have a tutorial of Cppfront public in the internet.
The main reference for this tutorial is the [GitHub repository of Cppfront](https://github.com/hsutter/cppfront)

> **Note1:** Cppfront is a work in progress proposal. It is not ready for production, use it at your own risk.

> **Note2:** This is a work in progress tutorial. Use it at your own risk.

## Content

This is the preliminary content table, it may change.

> I used also Carbon tutorial as an initial ref to content structure.
> * https://tipseason.com/carbon-language-tutorial-syntax/
> * https://www.udemy.com/course/the-complete-carbon-programming-course/?utm_source=adwords&utm_medium=udemyads&utm_campaign=LongTail_la.EN_cc.BR&utm_content=deal4584&utm_term=_._ag_112130202440_._ad_467215026440_._kw__._de_c_._dm__._pl__._ti_dsa-1007766171312_._li_1001773_._pd__._&matchtype=&gclid=Cj0KCQjw4bipBhCyARIsAFsieCy-rlkhfCF8fJfpnaARG_oB5nYFcJjOaqac_wGya7a6-bCdv38mMb0aAqfUEALw_wcB


* [Basics](basics/Overview.md)
	* Introduction to Cppfront Language
		* Work in progress, instable
		* Safety
	* Installation and how to compile
	* Key features of Cppfront language
		* Interoperability:
			* tools: compilers, debuggers
			* preprocessors '#'
			* C++ syntax inside cppfront
			* everything else from C++. Everything not covered in this tutorial can be used from C++
	* Cppfront language VS Rust comparison
	* First Programm: "main:"
		* args
		* std::cout with format
		* std complete included
		* Analyze the cpp code, enforce the need to learn by checking c++ generated
* [Basic Data Types](basic_data_types/Overview.md)
	* The basic types
		* boolean	
		* char
		* int, long
		* float double
		* void
	* Variables definition, declaration and initialization
	* Operators
		* Assign
		* Arithmetic
		* Compound OperatorsI
		* Increment Decrement
	* Automatic type (auto)
	* Strings in Cppfront
* [Containers (collections)](containers/Overview.md)
	* Arrays Matrixes
	* Vectors
	* Tuples
* [Control Statements](control_statements/Overview.md)
	* Introduction to Control Statements
		* Conditional control flow with Cppfront
		* Loops in Cppfront language
			* for each loop
			* old c/c++
		* Match multiple conditions similar to Switch
	* Selection Control Statements
	* Repetition Control Statements
* [Pointers and references](pointers_and_references/Overview.md)
	* memory safety
		* new as unique_ptr
	* (RAII “Resource Acquisition Is Initialization”) using a class to force automatic destruction of FILE*
		* file, locks, sockets, shaders
	* Pointer to strings
	* Conversions (implicit explicit)
* [Functions](functions/Overview.md)
	* Declaration and definition
	* in, out, inout: parameters
	* lambdas
	* Scope and Lifetime
* [User defined types](user_defined_types/Overview.md)
	* Overvie of new syntax for "@xxxx type" 
		* @interface
		* @polymorphic_base
		* @ordered
		* @copyable
		* @basic_value
		* @value
		* @struct
		* @enum
		* @union
			* Maybe each  topic can be addressed in more details in separated chapters or subchapters
	* Introduction to OOP
		* Classes and Structs
		* Inheritance and Polymorphism
		* Abstract Classes
	* Constructors and destructors
	* Copy (constructor and assignment)
	* Move (constructor and assignment)
* [Generics](generics/Overview.md)
	* templates
		* simple example
		* ref to guihub exaple pointed by sutter
* [Advanced topics](advanced_topics/Overview.md)
	* Modules (replacement for #include)
	* Recursion
	* Threads (atomic)
	* Network
* [Appendix](appendix/Overview.md)
	* Debug
	* CMake
	* #include "cpp2util.h"


## Chapter template

Basic template for each chapter.

	## Background C and C++
	
	How it is done in C and C++ 98 and modern C++
	
	## New syntax cppfront
	
	Shows how is done now
	
	
	## How is the code transpiled
	
	## Advanced topics
	
	Cover other advanced modern C++ topics (e.g. C++ 17, 20, 23) because the idea is to teach how to write code right.
	If cppfront does not have a specific syntax, then use modern C++.
	
