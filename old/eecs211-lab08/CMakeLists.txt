cmake_minimum_required(VERSION 3.3)
project(lab8 CXX)
include(.eecs211/CMakeLists.txt)

add_program(lab8 lab8_main.cpp lab8_functions.cpp Boat.cpp Car.cpp Plane.cpp)
add_test_program(lab8_test lab8_test.cpp lab8_functions.cpp Boat.cpp Car.cpp Plane.cpp)
