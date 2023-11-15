#!/bin/bash

# Define a function with three parameters
my_function() {
    local param1="$1"
    local param2="$2"
    local param3="$3"

echo -e "\n\n\n## Next" >> $param1
echo -e "\nTo the [next Chapter]($param2)." >> $param1
echo -e "\nTo the [previous Chapter]($param3)." >> $param1
echo -e "\nBack to Tutorial [home](../README.md)" >> $param1
echo -e "\nBack to the Chapter [Overview](Overview.md)" >> $param1
}

	# cd containers
	# 
	# #Overview.md" 
	# my_function "Arrays_Matrices.md" "Vectors.md" "../basic_data_types/Strings.md"
	# my_function "Vectors.md" "Tuples.md" "Arrays_Matrices.md" 
	# my_function "Tuples.md" "Ranges_Views.md" "Vectors.md" 
	# my_function "Ranges_Views.md" "../control_statements/Introduction_Controls.md" "Tuples.md" 
	# 
	# cd ..
	# 
cd control_statements

#Overview.md" 
my_function "Introduction_Controls.md" "Selection.md" "../containers/Ranges_Views.md"
my_function "Selection.md" "Repetition.md" "Introduction_Controls.md"
my_function "Repetition.md" "../pointers_and_references/Introduction.md" "Selection.md"

cd ..

cd pointers_and_references

#Overview.md" 
my_function "Introduction.md" "Memory_safety.md" "../control_statements/Repetition.md"
my_function "Memory_safety.md" "RAII.md" "Introduction.md"
my_function "RAII.md" "Pointe_strings.md" "Memory_safety.md" 
my_function "Pointe_strings.md" "Conversions.md" "RAII.md" 
my_function "Conversions.md" "../functions/Declaration.md" "Pointe_strings.md"

cd ..

cd functions

#Overview.md" 
my_function "Declaration.md" "Parameters.md" "../pointers_and_references/Conversions.md"
my_function "Parameters.md" "Lambdas.md" "Declaration.md"
my_function "Lambdas.md" "Scope_Lifetime.md" "Parameters.md"
my_function "Scope_Lifetime.md" "Functional_prog.md" "Lambdas.md" 
my_function "Functional_prog.md" "../user_defined_types/Overvie_new_syntax_type.md" "Scope_Lifetime.md" 

cd ..

cd user_defined_types

#Overview.md" 
my_function "Overvie_new_syntax_type.md" "Introduction_OOP.md" "../functions/Functional_prog.md"
my_function "Introduction_OOP.md" "Constructors_destructors.md" "Overvie_new_syntax_type.md"
my_function "Constructors_destructors.md" "Copy.md" "Introduction_OOP.md"
my_function "Copy.md" "Move.md" "Constructors_destructors.md" 
my_function "Move.md" "../generics/Templates.md" "Copy.md" 

cd ..

cd generics

#Overview.md" 
my_function "Templates.md" "Templates_concepts.md" "../user_defined_types/Move.md"
my_function "Templates_concepts.md" "../advanced_topics/Packages.md" "Templates.md"

cd ..

cd advanced_topics

#Overview.md" 
my_function "Packages.md" "Modules.md" "../generics/Templates_concepts.md"
my_function "Modules.md" "Recursion.md" "Packages.md"
my_function "Recursion.md" "Threads.md" "Modules.md"
my_function "Threads.md" "Network.md" "Recursion.md"
my_function "Network.md" "../appendix/Debug.md" "Threads.md" 

cd ..

cd appendix

#Overview.md" 
my_function "Debug.md" "CMake.md" "../advanced_topics/Network.md"
my_function "CMake.md" "Include_cpp2util.md" "Debug.md"
my_function "Include_cpp2util.md" "Overview.md"

cd ..
