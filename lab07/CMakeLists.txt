cmake_minimum_required(VERSION 3.3)
project(lab07 CXX)
include(.cs211/cmake/CMakeLists.txt)

# Builds program `bejeweled` from the six listed source files:
add_program(bejeweled ASAN UBSAN
        src/bejeweled.cxx
        src/controller.cxx
        src/view.cxx
        src/model.cxx
        src/board.cxx
        src/tile.cxx
        src/actions.cxx)
target_link_libraries(bejeweled ge211)


