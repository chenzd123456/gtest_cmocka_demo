cmake_minimum_required(VERSION 3.14)
project(c_unit_test_demo VERSION 1.0 LANGUAGES C CXX)

# Set C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include GTest
# add_subdirectory(deps/gtest)

# Enable testing
# enable_testing()

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
# include_directories(${PROJECT_SOURCE_DIR}/deps/gtest/googletest/include)
# include_directories(${PROJECT_SOURCE_DIR}/deps/gtest/googlemock/include)

# Recursively find all source files
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.c" "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Add main library
# add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})

# Add mock library
# file(GLOB_RECURSE MOCK_SOURCES "${PROJECT_SOURCE_DIR}/test/mock_functions.cpp")
# add_library(mock_lib STATIC ${MOCK_SOURCES})
# target_include_directories(mock_lib PRIVATE ${CMAKE_SOURCE_DIR}/deps/cmocka/include)
# target_link_libraries(mock_lib PRIVATE ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES})
# target_link_libraries(mock_lib PRIVATE gtest gmock)

# Add main executable
add_executable(${PROJECT_NAME} ${SOURCES})
# target_link_libraries(${PROJECT_NAME} PRIVATE mock_lib gcov)

# Set output directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Add compiler options
# if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#     target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -fprofile-arcs -ftest-coverage)
# endif()

# Include test directory
# add_subdirectory(test)
