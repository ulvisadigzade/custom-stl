cmake_minimum_required(VERSION 4.2)
project(custom_stl)

set(CMAKE_CXX_STANDARD 20)

add_executable(custom_stl main.cpp
        vector/Vector.hpp
        vector/Vector.tpp)
