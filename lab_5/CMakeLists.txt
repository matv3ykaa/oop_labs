cmake_minimum_required(VERSION 3.10)

project("gtest")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(googletest)

add_library(CustomAllocator src/Allocator.cpp)

add_executable(main main.cpp)
target_link_libraries(main_app CustomAllocator)

add_executable(test tests/tests.cpp)
target_link_libraries(test_app gtest_main CustomAllocator)
