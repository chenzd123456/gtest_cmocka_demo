#!/bin/bash

# 清理之前的覆盖率数据
lcov --directory .. --zerocounters

# 运行测试
./bin/unit_tests

# 生成覆盖率数据
geninfo src --output-filename coverage.info --test-name test --memory 0 --ignore-errors mismatch

# 生成HTML报告
genhtml coverage.info --output-directory coverage_report

# 生成JSON报告
gcovr --json --json-pretty -o coverage.json --exclude ./test/src --exclude ./test/deps --exclude ./deps