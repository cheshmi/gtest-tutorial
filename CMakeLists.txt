
cmake_minimum_required(VERSION 3.14)
project(gtest-tutorial)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# make a main driver project for manual testing
add_executable(
        main
        main.cpp
        test/test_utils.cpp
)
target_link_libraries(
        main
        swift_dsp
)

add_subdirectory(src)
add_subdirectory(test)
