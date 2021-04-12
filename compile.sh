#!/bin/bash

rm -rf build
mkdir build
cd build

# Build Test
conan install ../ -s build_type=Debug

# Build Project
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DTEST=true ..
cmake --build .
