# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(main)

# Include lib conan test
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Options
set(CMAKE_CXX_STANDARD 11)

# Compiler-specific options
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_compile_options(
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wcast-align
        -Wcast-qual
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-promo
        -Wno-deprecated-declarations
    )
endif()

# Source files
set(SOURCES
    source/main.cpp
    source/equal.cpp
    source/sum.cpp
    include/min.h
    include/less_than_zero.h
)

# Source tests files
set(TEST_SOURCES
    test/source/test_equal.cpp
    test/source/test_sum.cpp
    test/source/test_min.cpp
    test/source/test_less_than_zero.cpp
    source/equal.cpp
    source/sum.cpp
    include/min.h
    include/less_than_zero.h
)

# Include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})

# Compiling target for tests
add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})

# Link target with gtest
target_link_libraries(${PROJECT_NAME}_tests ${CONAN_LIBS})