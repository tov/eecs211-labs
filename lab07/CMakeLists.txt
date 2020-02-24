cmake_minimum_required(VERSION 3.3)
project(lab06 CXX)
include(.cs211/cmake/CMakeLists.txt)

# Builds program `bejeweled` from the six listed source files:
add_program(bejeweled
        src/bejeweled.cxx
        src/controller.cxx
        src/view.cxx
        src/model.cxx
        src/tiles.cxx
        src/tile_handlers.cxx)
target_link_libraries(bejeweled ge211)


