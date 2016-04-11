cmake_minimum_required(VERSION 3.3)
project(Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/magomed/ClionProjects/PrepareKurs/Test")
set(SOURCE_FILES main.cpp)
add_executable(Test ${SOURCE_FILES})