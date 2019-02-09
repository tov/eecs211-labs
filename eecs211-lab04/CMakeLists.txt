cmake_minimum_required(VERSION 3.3)
project(project-base CXX)
include(.eecs211/cmake/CMakeLists.txt)

# Builds program client from the two listed source files:
add_program(game src/game.cpp src/model.cpp)
target_link_libraries(game ge211)
