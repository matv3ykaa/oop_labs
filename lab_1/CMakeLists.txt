cmake_minimum_required(VERSION 3.10)

project("gtest")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(googletest)

add_library(src src/count_vowels.cpp)

add_executable(main_app main.cpp)
target_link_libraries(main_app include)

add_executable(test tests/tests.cpp)
target_link_libraries(test gtest_main src)