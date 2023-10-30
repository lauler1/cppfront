
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

cppfront $1 -a tests.cpp2 -o out.cpp

if [ $? -eq 0 ]; then
	g++ -I$CPPFRONTDIR/include/ -std=c++20 out.cpp -o out.out

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
