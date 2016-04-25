cmake_minimum_required(VERSION 3.5)
project(Array_line)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/magomed/ClionProjects/PrepareKurs/ex7")
set(SOURCE_FILES main.cpp ArrLine.cpp ArrLine.h Array.cpp Array.h)
add_executable(Array_line ${SOURCE_FILES})