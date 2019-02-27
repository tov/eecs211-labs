cmake_minimum_required(VERSION 3.3)
project(lab05 CXX)
include(.eecs211/cmake/CMakeLists.txt)

# Builds program `game` from the six listed source files:
add_program(game
        src/tiles.cpp
        src/tile_handlers.cpp
        src/game.cpp
        src/model.cpp
        src/view.cpp
        src/controller.cpp)
target_link_libraries(game ge211)


