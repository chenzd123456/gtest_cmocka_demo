#!/bin/bash

# 进入build目录
cd build

# 运行CMake构建
cmake ..
make

# 运行测试程序
./test/print_to_file_test
