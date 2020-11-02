#!/bin/bash
mkdir -p build
cd build

# Build Test
if [[ "$OSTYPE" == "msys" ]]; then
    # For Windows
    conan install ../ -s build_type=Debug --build=gtest
else
    # For Linux or other OS
    conan install ../ -s build_type=Debug
fi
