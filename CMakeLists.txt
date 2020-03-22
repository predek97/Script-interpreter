cmake_minimum_required(VERSION 3.6)
project(2_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Var.cpp Var.h defines.h Stack.cpp Stack.h Variable.cpp Variable.h HashEntry.cpp HashEntry.h Element.cpp Element.h HashTable.cpp HashTable.h)
add_executable(2_1 ${SOURCE_FILES})