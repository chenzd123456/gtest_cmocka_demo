set(SOURCES
    main.cpp
    print_to_file.cpp
)

add_library(c_unit_test_demo_lib ${SOURCES})
target_include_directories(c_unit_test_demo_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(c_unit_test_demo_lib PUBLIC gmock gtest)
