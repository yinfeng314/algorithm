cmake_minimum_required(VERSION 3.22)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/data_structure)
include_directories(src/sort_algorithm)
include_directories(src/base_function)

add_executable(algorithm main.cpp)
add_executable(test tmp.cpp)
# test for data_structure
add_executable(vector_test src/test/ src/test/vector_test.cpp src/data_structure/vector.h)
add_executable(list_test src/test/list_test.cpp src/data_structure/list.h)
add_executable(sort_test src/test/sort_test.cpp src/sort_algorithm/sort_algorithm.h)