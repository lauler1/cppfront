cmake_minimum_required(VERSION 3.27)
project(sampleCmake)

include_directories("$ENV{CPPFRONTDIR}/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

# List of original source files
set(SOURCE_FILES
    hello
)

# Preprocess each source file
foreach(SOURCE_FILE ${SOURCE_FILES})
    # Get the file name without the directory
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME)

    # Define the output file path
    set(OUTPUT_FILE "${FILE_NAME}.cpp")

    # Add a custom command to preprocess each file
    add_custom_command(
        OUTPUT ${OUTPUT_FILE}
        #COMMAND cppfront "${SOURCE_FILE}.cpp2"
		COMMAND ../../../cppfront/cppfront "../hello.cpp2"
        #DEPENDS "${SOURCE_FILE}.cpp2"
		DEPENDS "../hello.cpp2"
        COMMENT "Preprocessing ${FILE_NAME}: From ${SOURCE_FILE}.cpp2 to ${OUTPUT_FILE}"
    )

    # Add the output file to a list to be compiled
    list(APPEND COMPILED_SOURCE_FILES "../${OUTPUT_FILE}")

    # Add the output file to a list to be compiled
    list(APPEND INPUT_SOURCE_FILES "../${SOURCE_FILE}.cpp2")
endforeach()

# Add an executable target
add_executable(MyExecutable ${COMPILED_SOURCE_FILES})

# Ensure the preprocessed files are built before the executable
#add_dependencies(MyExecutable ${INPUT_SOURCE_FILES})
