# Cppfront guide

This folder is intended to have a tutorial of Cppfront public in the internet.
The main reference for this tutorial is the [**GitHub repository of Cppfront**](https://github.com/hsutter/cppfront)

> **Note1:** Cppfront is a work in progress proposal. It is not ready for production, use it at your own risk.

> **Note2:** This is a work in progress tutorial. Use it at your own risk.

## Content

This is the preliminary content table, it may change.

* [**Basics**](basics/Overview.md)
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

# Preface

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


# Old list of topics

The concern about the need for a C++ sucessor has rised recently. The overarching software community across the private sector, academia, and the U.S. Government have begun initiatives to drive the culture of software development towards utilizing memory safe languages.
NSA advises organizations to consider making a strategic shift from programming languages that provide little or no inherent memory protection, such as C/C++, to a memory safe language when possible. Some examples of memory safe languages are C#, Go, Java, Ruby™, and Swift

There is a real, serious problem for many uses and users
• Bugs and security violations from bad code in various language (incl. C++) and other causes
• Diversion of resources from C++ to other languages
• Discouraging people from learning C++
• Massive improvements are possible in many areas
• C++ has a massive image problem (“C/C++”)
• And it is getting worse
• Governments and large corporations can coerce developers
• Ignoring the safety issues now would hurt large sections of the C++ community and undermine much of the other work we are doing to improve C++.
• So would focusing exclusively on safety
• Offering guaranteed safety will be in the best tradition of C++

Constraints on a solution
• C++ must serve wide variety of users/areas
• One size doesn’t fit all
• C++ is (also) a systems programming language – we can’t “outsource” dangerous operations to some other language
• We can’t just break billions of lines of existing code
• Even if we wanted to – major users would insist on compatibility (probably compatibility by default)
• We can change the use of C++
• We can’t just “upgrade” millions of developers
• And teaching material, courses, videos, books, articles
• If you want a shiny new language, please go ahead
• But it won’t be C++ or the job of WG2

Challenges
• Describe a type-safe C++ use
• No violations of the static type system
• No resource leaks
• Convince developers to use that safe (or just safer) styles of use
• Except where it is not appropriate
• Direct use of system and hardware resources
• Need for ultimate efficiency
• Implementation of code that cannot be proven safe (e.g., some linked structures)
• Get this to work at scale
• Not just “academic” examples
• Note: there is lots of great C++ “out there”
• For any definition of “great” including “reliable over decades”

Safety is not just type safety
• Logic errors: perfectly legal constructs that don’t reflect the programmer’s intent, such as using < where a <= or a > was intended.
• Resource leaks: failing to delete resources (e.g., memory, file handles, and locks) potentially leading to the program grinding to a halt because of lack of available resources.
• Concurrency errors: failing to correctly take current activities into account leading to (typically) obscure problems (such as data races and deadlocks).
• Memory corruption: for example, through the result of a range error or by accessing and memory through a pointer to an object that no longer exists thereby changing a different object.
• Type errors: for example, using the result of an inappropriate cast or accessing a union through a member different from the one through which it was written.
• Overflows and unanticipated conversions: For example, an unanticipated wraparound of an unsigned integer loop variable or a narrowing conversion.
• Timing errors: for example, delivering a result in 1.2ms to a device supposedly responding to an external event in 1ms.
• Allocation unpredictability: for example, ban on free store allocation “after the engine starts.”
• Termination errors: a library that terminates in case of “unanticipated conditions” being part of a 
program that is not allowed to unconditionally terminate.

Thhere are basically 3 deiiferent approaches to evolve a language:
 Incremental evolution (Default aproach for most languages): This is how C++ evolves today.
 Incompatible new language (complete new language): This is the “Dart plan”.
 Compatible by design: This is the “TypeScript plan”, The source is transpiled from the new language to the existing one.

Some proposal as C++ sucessor are:
 - Carbon Project from Google (which is new language and toolos)
 - Verona project from Microsoft (which isnew language and tools)
 - CppFront from Herb Sutter (which is a new syntax to C++, transpiled in a similar way as TypeScript is for Javascript)
 - Also Circle compiler (by changing the c++ compiler as a new proposal)

The Incremental aproach is the default and usually the one with best compatibility. But after decades of evolution, it may become difficult to keep compatibility or the language may become to complex with to many flavors/options of code. The syntax may become to ugly.

Usualy, creating a new incompatible language with a complete new set of tools and libraries take some time till it get momentum by developers, I mean, regular developers not only the entusiasts. Usualy it takes a decade.
The main advantage of having a complete new language is the complete freedom to do everything without being blocked by the compatibility with the past. One disadvantage is that it is more dificult to keep compatibility, specially in companies that have a long history of code already written in other languages.  Interoperability can be done via wrapping And the developers need to learn everything from zero. Example of time dalais that happened in other projects:
MSVC 6 ~12 years
	Shipped in 1998
	“10 is the new 6” fanfare in 2010
C99 _Complex and VLAs ~12 years
	Added in 1999
	Walked them back to “optional” in 2011
C++11 std::string ~11 years
	Banned RC for std::string in 2008/2010
	Major Linux distro enabled it in 2019
Python 3 ~12 years
	Shipped 3.0 in 2008
	10% still using 2.x as of early 2020

The best examples of Compatible by design is the Typescript and Swift. It can cooperate and participate with 
Lang continued evolution. It can contribute evolution proposals to Lang evolution.

Cppfront is an experimental compiler from a potential C++ 'syntax 2' (Cpp2) to today's 'syntax 1' (Cpp1). It proposes to follow the compatible by design approach.
Cppfront has being developed by Herb Sutter for a while.
It has received support of peaple in the community (entusiasts).
This tutorial intends to teach Cppfront.
It is public in the internet.
It is not yet ready for production.
The main reference for this tutorial is the GitHub repository of Cppfront.
Cppfront aims total compatibility with modern C++ (e.g. C++20) allowing the reuse of all the existing tools, libraries and acosystems.



