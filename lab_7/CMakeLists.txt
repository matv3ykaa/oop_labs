cmake_minimum_required(VERSION 3.10)

project(Lab7Project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(SOURCES
    src/bear.cpp
    src/elf.cpp
    src/npc.cpp
    src/rogue.cpp
)

set(HEADERS
    include/bear.hpp
    include/elf.hpp
    include/npc.hpp
    include/rogue.hpp
    include/factory.hpp
    include/observer.hpp
    include/visitor.hpp
)

add_executable(main src/main.cpp ${SOURCES})
target_include_directories(main PRIVATE include)
target_link_libraries(main pthread)

add_executable(tests tests/tests.cpp ${SOURCES})
target_include_directories(tests PRIVATE include)
target_link_libraries(tests gtest_main pthread)

include(GoogleTest)
gtest_discover_tests(tests)
