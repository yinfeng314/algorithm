cmake_minimum_required(VERSION 3.22)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/data_structure)
include_directories(src/sort_algorithm)
include_directories(src/base_function)

add_executable(algorithm main.cpp src/sort_algorithm/sort_algorithm.h)
add_executable(test tmp.cpp)