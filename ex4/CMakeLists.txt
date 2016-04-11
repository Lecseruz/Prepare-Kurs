cmake_minimum_required(VERSION 3.3)
project(ex4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp array.cpp array.h Worker.cpp Worker.h)
add_executable(ex4 ${SOURCE_FILES})