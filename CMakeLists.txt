project(FactoryPattern)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++14)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(sources src/main.cpp src/operation.cpp)
add_executable(image_process ${sources})
