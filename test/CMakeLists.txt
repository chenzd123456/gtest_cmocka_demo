# Test configuration
include(GoogleTest)

# Include source headers
include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

# Add test executable
add_executable(unit_tests
    main.cpp
    print_to_file_test.cpp
    fib_test.cpp
    mock_functions.cpp
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_CPP_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# Set C++ as linker language
set_property(TARGET unit_tests PROPERTY LINKER_LANGUAGE CXX)

# Link test libraries
target_link_libraries(unit_tests
    PRIVATE
    gtest
    gmock
    gtest_main
    ${PROJECT_NAME}_lib
    mock_lib gcov
    gcov
)

# Add test
gtest_discover_tests(unit_tests)

# Set output directory
set_target_properties(unit_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
