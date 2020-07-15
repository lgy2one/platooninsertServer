#版本和项目名
cmake_minimum_required(VERSION 2.8.4)
project(platooninsertServer)

#C++版本
set(CMAKE_CXX_STANDARD 11)

#追加pthread参数
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

#支持gdb
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

set(SOURCE_FILES main.cpp)

add_definitions(-g -pthread -std=c++11)

#添加所有头文件和源文件
FILE(GLOB SRC *.cpp *.h)
add_executable(platooninsertServer ${SOURCE_FILES} ${SRC})