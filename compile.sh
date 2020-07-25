#!/bin/bash
mkdir -p build
cd build

# Build Project
cmake -G "Unix Makefiles" ..
cmake --build . -- -j4
