cmake_minimum_required(VERSION 3.5)
project(ex5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/magomed/ClionProjects/PrepareKurs/ex5")
set(SOURCE_FILES main.cpp array.cpp array.h set.cpp set.h)
add_executable(ex5 ${SOURCE_FILES})