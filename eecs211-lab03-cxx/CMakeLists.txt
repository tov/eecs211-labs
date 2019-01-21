cmake_minimum_required(VERSION 3.3)
project(lab3 CXX)
include(.eecs211/CMakeLists.txt)

add_program(lab3
        lab3.cpp
        Dog.cpp)

add_test_program(dog_test
        dog_test.cpp
        Dog.cpp)
