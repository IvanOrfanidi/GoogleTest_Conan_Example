#!/bin/bash
mkdir -p build
cd build

# Build Test
conan install ../ -s build_type=Debug
