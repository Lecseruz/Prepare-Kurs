cmake_minimum_required(VERSION 3.5)
project(ex6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/magomed/ClionProjects/PrepareKurs/ex6")
set(SOURCE_FILES main.cpp shape.cpp shape.h Cylinder.cpp Cylinder.h ball.cpp ball.h)
add_executable(ex6 ${SOURCE_FILES})