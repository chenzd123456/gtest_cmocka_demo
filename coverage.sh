#!/bin/bash

# 清理之前的覆盖率数据
lcov --directory . --zerocounters

# 运行测试
./bin/c_unit_test_demo

# 生成覆盖率数据
lcov -capture --directory . --output-file coverage.info --test-name test

# 生成HTML报告
genhtml coverage.info --output-directory coverage_report

# 生成JSON报告
gcovr --json --json-pretty -o coverage.json

# 打开报告
if command -v xdg-open &> /dev/null
then
    xdg-open coverage_report/index.html
elif command -v open &> /dev/null
then
    open coverage_report/index.html
else
    echo "Please install xdg-open or open command to view the report"
fi