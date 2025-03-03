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
file(GLOB_RECURSE TEST_CASES_SOURCES "${PROJECT_SOURCE_DIR}/src/cases/*.cpp")
file(GLOB_RECURSE TEST_FW_SOURCES "${PROJECT_SOURCE_DIR}/src/common/*.cpp")

# Add test main executable
add_executable(test_main
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# Add test cases lib library
add_library(test_cases_lib STATIC
    ${TEST_CASES_SOURCES}
)

# Add test common lib library
add_library(test_common_lib STATIC
    ${TEST_FW_SOURCES}
)

include_directories({CMAKE_SOURCE_DIR}/deps/cmocka/include)

# Link test libraries
target_link_libraries(test_main PRIVATE 
    gcov
    gtest gmock cmocka
    test_cases_lib
    test_common_lib
)

# Set output directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

if (CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
endif()

# Add compiler options
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(test_main PRIVATE -Wall -Wextra -pedantic -fprofile-arcs -ftest-coverage)
    target_link_options(test_main PRIVATE -Wl,--wrap=open -Wl,--wrap=write -Wl,--wrap=close)
    target_compile_options(test_cases_lib PRIVATE -Wall -Wextra -pedantic -fprofile-arcs -ftest-coverage)
    target_compile_options(test_common_lib PRIVATE -Wall -Wextra -pedantic -fprofile-arcs -ftest-coverage)
endif()
