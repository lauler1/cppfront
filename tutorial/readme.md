# Cppfront guide

This folder is intended to have a tutorial of Cppfront public in the internet.
The main reference for this tutorial is the [**GitHub repository of Cppfront**](https://github.com/hsutter/cppfront)

> **Note1:** Cppfront is a work in progress proposal. It is not ready for production, use it at your own risk.

> **Note2:** This is a work in progress tutorial. Use it at your own risk.

## Content

This is the preliminary content table, it may change.

* [**Crafting Your First Cppfront Program**](basics/Overview.md)
	* Introduction to Cppfront Language
	* Installation and how to compile
	* Key features of Cppfront language
	* Cppfront language VS Rust comparison
	* First Programm: "main:"
* [**Basic Data Types**](basic_data_types/Overview.md)
	* The basic types
	* Variables definition, declaration and initialization
	* Operators
	* Automatic type (auto)
	* Strings
* [**Containers (collections)**](containers/Overview.md)
	* Arrays Matrixes
	* Vectors
	* Tuples
* [**Control Statements**](control_statements/Overview.md)
	* Introduction to Control Statements
	* Selection Control Statements
	* Repetition Control Statements
* [**Pointers and references**](pointers_and_references/Overview.md)
	* memory safety
	* (RAII “Resource Acquisition Is Initialization”) using a class to force automatic destruction of FILE*
	* Pointer to strings
	* Conversions (implicit explicit)
* [**Functions**](functions/Overview.md)
	* Declaration and definition
	* in, out, inout: parameters
	* lambdas
	* Scope and Lifetime
* [**User defined types**](user_defined_types/Overview.md)
	* Overvie of new syntax for "@xxxx type" 
	* Introduction to OOP
	* Constructors and destructors
	* Copy (constructor and assignment)
	* Move (constructor and assignment)
* [**Generics**](generics/Overview.md)
	* templates
* [**Advanced topics**](advanced_topics/Overview.md)
	* Modules (replacement for #include)
	* Recursion
	* Threads (atomic)
	* Network
* [**Appendix**](appendix/Overview.md)
	* Debug
	* CMake
	* #include "cpp2util.h"

## Preface

**Preface: The Future of C++ - An Introduction to Cppfront**

In the recent past, murmurs of the need for a successor to C++ have grown louder. These aren't mere whispers but have evolved into a concerted discussion spearheaded by the larger software community, inclusive of the private sector, academia, and prominent governmental institutions like the U.S. Government. The driving force behind this? The relentless pursuit of software development that prioritizes memory safety. 

The National Security Agency (NSA) has been vocal in its advice for organizations, pushing them to pivot away from languages like C/C++, which offer limited memory protection, and embrace memory-safe languages such as C#, Go, Java, Ruby™, and Swift. 

But what makes this call for change so urgent? 

- The pervasive bugs and security threats from faulty code in languages, including C++, divert vital resources away from C++ to alternative languages. 
- There's a perceptible deterrent for newcomers to learn C++.
- The constant image battle C++ fights, often bracketed with C as “C/C++,” further deteriorates its image. 
- Ignoring the safety issues now stands to harm vast portions of the C++ community and can counteract the ongoing efforts to enhance the language. 

However, addressing these concerns is not straightforward. C++ serves a broad spectrum of users and purposes. It's not just a language; it's a systems programming tool. We cannot forsake its legacy nor its billions of lines of existing code. Changing its use is feasible, but what isn't practical is the colossal task of "upgrading" millions of developers and the vast educational resources that support them.

Safety, a pivotal issue, extends beyond type safety. It encapsulates logic errors, resource leaks, concurrency issues, memory corruption, type errors, overflows, timing discrepancies, and more.

So, how can a language evolve?

Three prominent strategies are in consideration:

1. **Incremental Evolution:** The path C++ has traditionally followed.
2. **Incompatible New Language:** A complete overhaul, akin to the “Dart plan.”
3. **Compatible by Design:** A strategy reminiscent of the “TypeScript plan,” where the source transpiles from the new language to the existing one.

Several successors to C++ have been proposed, with the likes of Google's Carbon Project and Microsoft's Verona Project, both offering new languages and tools. There's also the Circle compiler. And then, there's **Cppfront** by Herb Sutter, which introduces a new syntax to C++ and transpiles it similarly to how TypeScript operates for Javascript.

Incremental evolution, though reliable, may render the language cumbersome and overcomplicated with time. A brand new, incompatible language, while liberating in design, could suffer from a slow adoption rate among developers, with interoperability achieved only through wrappers. History provides evidence of such time lags, whether it's the MSVC 6, C99 Complex and VLAs, C++11 std::string, or Python 3.

Yet, the "Compatible by Design" strategy, evidenced by successes like TypeScript and Swift, offers a blend of cooperation with the original language and the scope for evolutionary contributions. 

Enter **Cppfront**.

This experimental compiler, birthed as a potential 'syntax 2' for C++, aims to translate the language's contemporary syntax to its traditional form. Designed with compatibility in mind, Cppfront, under Herb Sutter's guidance, has piqued the interest of the enthusiast community. And while it is yet to be deemed production-ready, its goal of ensuring complete compatibility with modern C++ versions (like C++20) means that the existing tools, libraries, and ecosystems can be seamlessly integrated.

This tutorial seeks to usher you into the world of Cppfront, using the language's GitHub repository as a primary reference. The objective? To empower you with the knowledge of this potentially revolutionary iteration of C++.

Welcome to the future of C++. Welcome to Cppfront.


## Chapter Descriptions of the Cppfront Tutorial


**1. [Crafting Your First Cppfront Program](basics/Overview.md)**
   Begin your Cppfront journey by understanding its foundational aspects, setting up the environment, and crafting your initial program. Also, dive deep into a comparative study of Cppfront vs. Rust.

---

**2. [Basic Data Types](basic_data_types/Overview.md)**
   Navigate through the core data types in Cppfront. Understand variables, their definitions, declarations, and initialization. Learn about the power of operators, the convenience of the 'auto' type, and explore the dynamic world of strings.

---

**3. [Containers (collections)](containers/Overview.md)**
   Delve into Cppfront’s robust collection mechanisms. Explore arrays and matrices, the flexibility of vectors, and the structured world of tuples.

---

**4. [Control Statements](control_statements/Overview.md)**
   Understand the backbone of programmatic logic. This chapter introduces you to control statements, guiding you through selection mechanisms and repetitive constructs.

---

**5. [Pointers and references](pointers_and_references/Overview.md)**
   Dive into the nuances of memory in Cppfront. Understand memory safety, leverage the RAII principle for resource management, and explore pointers, references, and their conversions.

---

**6. [Functions](functions/Overview.md)**
   Unravel the world of functions in Cppfront. Learn how to declare and define functions, understand parameter passing mechanisms like in, out, and inout, and explore the elegance of lambdas. Additionally, grasp the intricacies of scope and lifetime.

---

**7. [User defined types](user_defined_types/Overview.md)**
   Customize Cppfront to your needs. Explore the innovative "@xxxx type" syntax, dive into Object-Oriented Programming, and understand the mechanics of constructors, destructors, copy, and move operations.

---

**8. [Generics](generics/Overview.md)**
   Leverage the power of templating in Cppfront. This chapter delves into the world of generics, offering a structured way to create flexible and reusable code constructs.

---

**9. [Advanced topics](advanced_topics/Overview.md)**
   Push the boundaries of your Cppfront knowledge. Dive into advanced features like modules, which replace traditional includes, explore recursion, understand threading with atomic operations, and tap into networking.

---

**10. [Appendix](appendix/Overview.md)**
   A treasure trove of additional resources. Whether you're looking to debug effectively, integrate with CMake, or leverage utilities like "cpp2util.h", this section has you covered.

---

Embark on this comprehensive journey with Cppfront, and by the end of this tutorial, you'll be proficiently navigating its diverse and powerful features. Happy coding!

