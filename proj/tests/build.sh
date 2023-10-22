
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

cppfront $1 tests.cpp2

if [ $? -eq 0 ]; then
	g++ -I$CPPFRONTDIR/include/ -std=c++20 tests.cpp -o tests.out

	if [ $? -eq 0 ]; then
		echo -e "\nCompilation Ok."
		echo      "==============="
	    ./tests.out
	else
	    echo -e "\nCompilation error."
	    echo      "=================="
	fi

else
    echo -e "\nCppfront error."
    echo      "==============="
fi
