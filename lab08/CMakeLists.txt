cmake_minimum_required(VERSION 3.3)
project(lab08 CXX)
include(.cs211/cmake/CMakeLists.txt)

# Builds program `game` from the six listed source files:
add_program(game
        src/game.cxx
        src/model.cxx
        src/view.cxx
        src/space_object.cxx
        src/controller.cxx)
target_link_libraries(game ge211)


