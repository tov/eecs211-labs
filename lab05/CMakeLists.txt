# This file configures how the code in this project is built. You
# should not need to modify it.

cmake_minimum_required(VERSION 3.3)
project(lab05 CXX)
include(.cs211/cmake/CMakeLists.txt)

# Builds program `game` from the two listed source files:
add_program(game src/game.cxx src/model.cxx)
# Links `game` against the GE211 game engine:
target_link_libraries(game ge211)

# Builds test program `game_test`:
add_test_program(game_test test/game_test.cxx src/model.cxx)
# Links `game_test` against the GE211 game engine:
target_link_libraries(game_test ge211)

