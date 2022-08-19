cmake_minimum_required(VERSION 3.22)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithm main.cpp)
# test for sort_algorithm data_structure and base_function
add_executable(base_test test/base_test.cpp src/base_function/base.h)
add_executable(random_test test/random_test.cpp src/base_function/random.h)
add_executable(chrono_test test/chrono_test.cpp src/base_function/chrono.h)
add_executable(vector_test test/vector_test.cpp src/data_structure/vector.h)
add_executable(list_test test/list_test.cpp src/data_structure/list.h)
add_executable(sort_test test/sort_test.cpp src/sort_algorithm/sort_algorithm.h)

include_directories(src/data_structure)
include_directories(src/sort_algorithm)
include_directories(src/base_function)
include_directories(test)