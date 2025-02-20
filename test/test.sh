#!/bin/bash

# 进入build目录
mkdir build
cd build

# 运行CMake构建
cmake ..
make
cd ..

# 运行测试程序
./bin/unit_tests
