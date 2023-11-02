
# Test if CPPFRONT is initialized
cppfront -vers > /dev/null


if [ $? -eq 0 ]; then
	echo -e "\nCppfront is already initialized."
	echo      "================================"
else
    echo -e "\nInitializing Cppfront..."
	echo      "========================"
	export CPPFRONTDIR="../../cppfront"
	export PATH="../../cppfront:$PATH"
    cppfront -vers
fi

cppfront -a -in $1 tests.cpp2 -o out.cpp

if [ $? -eq 0 ]; then
	clang++ -I$CPPFRONTDIR/include/ -g -std=c++20 out.cpp -o out.out

	if [ $? -eq 0 ]; then
		echo -e "\nCompilation Ok."
		echo      "==============="
	    ./out.out
	else
	    echo -e "\nCompilation error."
	    echo      "=================="
	fi

else
    echo -e "\nCppfront error."
    echo      "==============="
fi


#  -no-c[omparison-checks] Disable mixed-sign comparison safety checks
#  -no-n[ull-checks]       Disable null safety checks
#  -no-s[ubscript-checks]  Disable subscript safety checks

#  -fno-e[xceptions]       Disable C++ EH - failed 'as' for 'variant' will assert
#  -fno-r[tti]             Disable C++ RTTI - using 'as' for '*'/'std::any' will assert
