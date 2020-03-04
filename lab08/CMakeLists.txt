cmake_minimum_required(VERSION 3.3)
project(lab06 CXX)
include(.eecs211/cmake/CMakeLists.txt)

# Builds program `game` from the six listed source files:
add_program(game
        src/game.cpp
        src/model.cpp
        src/view.cpp
        src/space_object.cpp
        src/controller.cpp)
target_link_libraries(game ge211)


