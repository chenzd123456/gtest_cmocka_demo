# C 单元测试示例项目

这是一个演示如何在 C++ 项目中使用 GTest 和 CMocka 进行单元测试的示例项目。项目包含一个简单的 Fibonacci 数列生成器和文件打印功能，并配有相应的单元测试。

## 项目结构

```tree
.
├── bin/                # 可执行文件
├── build/              # 构建目录
├── include/            # 头文件
├── src/                # 源代码
│   ├── fib.cpp         # Fibonacci 实现
│   ├── fib.h           # Fibonacci 头文件
│   ├── main.cpp        # 主程序
│   ├── print_to_file.cpp # 文件打印实现
│   └── print_to_file.h # 文件打印头文件
├── test/               # 测试代码
│   ├── bin/            # 测试可执行文件
│   ├── build/          # 测试构建目录
│   ├── coverage_report/ # 测试覆盖率报告
│   ├── src/            # 测试源代码
│   │   ├── caces/      # 测试用例
│   │   └── common/     # 测试公共代码
│   ├── CMakeLists.txt  # 测试构建配置
│   ├── coverage.sh     # 覆盖率脚本
│   └── test.sh         # 测试脚本
├── .gitignore          # Git 忽略文件
├── .gitmodules         # Git 子模块
├── CMakeLists.txt      # 主构建配置
└── README.md           # 项目说明
```

## 构建说明

1. 创建构建目录：

   ```bash
   mkdir -p build
   cd build
   ```

2. 配置项目：

   ```bash
   cmake ..
   ```

3. 构建项目：

   ```bash
   make
   ```

## 测试说明

1. 运行所有测试：

   ```bash
   ./test/test.sh
   ```

2. 生成测试覆盖率报告：

   ```bash
   ./test/coverage.sh
   ```

## 贡献指南

欢迎提交 Pull Request 来改进本项目。请确保：

1. 代码风格与现有代码一致
2. 添加相应的单元测试
3. 更新相关文档
