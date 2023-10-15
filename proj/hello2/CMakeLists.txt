cmake_minimum_required(VERSION 3.27)
project(sampleCmake)

include_directories("$ENV{CPPFRONTDIR}/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

# List of original source files without sufix
set(SOURCE_FILES
    hello
)

# Preprocess each source file with cppfront command (cppfront must be in PATH)
foreach(SOURCE_FILE ${SOURCE_FILES})
    # Get the file name without the directory
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME)

    # Define the output file path
    set(OUTPUT_FILE "${FILE_NAME}.cpp")

    # Add a custom command to preprocess each file
    add_custom_command(
        OUTPUT ${OUTPUT_FILE}
		# cppfront "-o" option is needed otherwise the output will be in CMAKE_SOURCE_DIR
		COMMAND cppfront ${CMAKE_SOURCE_DIR}/"${FILE_NAME}.cpp2" -o  ${OUTPUT_FILE}
		DEPENDS "${FILE_NAME}.cpp2"
        COMMENT "Preprocessing ${FILE_NAME}: From ${SOURCE_FILE}.cpp2 to ${OUTPUT_FILE}"
    )

    # Add the output file to a list to be compiled
    list(APPEND COMPILED_SOURCE_FILES ${OUTPUT_FILE})
endforeach()

# Add an executable target
add_executable(hello ${COMPILED_SOURCE_FILES})
