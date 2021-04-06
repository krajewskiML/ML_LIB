cmake_minimum_required(VERSION 3.17)
project(ML_LIB)

set(CMAKE_CXX_STANDARD 14)

#include_directories(ML_LIB Matrix.h Matrix.cpp)

add_executable(ML_LIB main.cpp Matrix.h Matrix.cpp)