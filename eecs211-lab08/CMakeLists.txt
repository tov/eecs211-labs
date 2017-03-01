cmake_minimum_required(VERSION 3.3)
project(lab8 CXX)
include(.eecs211/CMakeLists.txt)

add_program(lab8 lab8.cpp Boat.cpp Car.cpp Plane.cpp)
