cmake_minimum_required(VERSION 3.3)
project(ex1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/magomed/ClionProjects/ex1")
set(SOURCE_FILES main.cpp)
add_executable(ex1 ${SOURCE_FILES})