cmake_minimum_required(VERSION 3.14)

project(unit_tests VERSION 1.0 LANGUAGES C CXX)

# Set C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/../include)
include_directories(${PROJECT_SOURCE_DIR}/../src)

add_definitions(-DUT_TEST)

# Enable testing
# Include GTest
add_subdirectory(deps/gtest)
add_subdirectory(deps/cmocka)
# Test configuration
include(GoogleTest)
include_directories(${PROJECT_SOURCE_DIR}/deps/gtest/googletest/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/gtest/googlemock/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/cmocka/include)

# Include source headers
include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/../src/*.c" "${PROJECT_SOURCE_DIR}/../src/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Add test executable
add_executable(${PROJECT_NAME}
    # main.cpp
    #print_to_file_test.cpp
    # fib_test.cpp
    src/mock_functions.cpp
    ${SOURCES} ${TEST_SOURCES}
)

# Add mock library
file(GLOB_RECURSE MOCK_SOURCES "${PROJECT_SOURCE_DIR}/src/mock_functions.cpp")
add_library(mock_lib STATIC ${MOCK_SOURCES})
target_include_directories(mock_lib PRIVATE ${CMAKE_SOURCE_DIR}/deps/cmocka/include)

# Set C++ as linker language
set_property(TARGET ${PROJECT_NAME} PROPERTY LINKER_LANGUAGE CXX)

# Link test libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    gcov
    mock_lib
    gtest gmock 
)

# Add test
# gtest_discover_tests(unit_tests)

# Set output directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Add compiler options
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -fprofile-arcs -ftest-coverage)
    target_link_options(${PROJECT_NAME} PRIVATE -Wl,--wrap=open -Wl,--wrap=write -Wl,--wrap=close)
endif()
