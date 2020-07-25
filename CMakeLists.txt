# Version CMake
cmake_minimum_required(VERSION 3.3)

# Project name
project(tests CXX)

# Include lib conan test
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Option
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# Source files
set(TEST_SOURCES
    test/test_equal.cpp
    test/test_sum.cpp
    test/test_min.cpp
    test/test_counting_zeros.cpp
    src/equal.cpp
    inc/equal.h
    src/sum.cpp
    inc/sum.h
    inc/min.h
    inc/counting_zeros.h
)

# include up
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

# Compiling target
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

# Link target
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
