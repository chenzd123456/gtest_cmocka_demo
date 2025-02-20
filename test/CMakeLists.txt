project(unit_tests VERSION 1.0 LANGUAGES C CXX)

# Set C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
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
# include_directories(${PROJECT_SOURCE_DIR}/deps/gtest/googletest/include)
# include_directories(${PROJECT_SOURCE_DIR}/deps/gtest/googlemock/include)
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
    # print_to_file_test.cpp
    # fib_test.cpp
    # mock_functions.cpp
    ${SOURCES} ${TEST_SOURCES}
)



set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_CPP_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# Set C++ as linker language
set_property(TARGET ${PROJECT_NAME} PROPERTY LINKER_LANGUAGE CXX)

# Link test libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
# mock_lib
 gtest gmock gcov
)

# Add test
# gtest_discover_tests(unit_tests)

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
