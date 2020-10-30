# This file configures how the code in this project is built. You
# should not need to modify it, but you may want to read it.

cmake_minimum_required(VERSION 3.3)
project(lab05 CXX)
include(.cs211/cmake/CMakeLists.txt)

# Builds program `game` from the two listed source files:
add_program(game
        src/game_main.cxx
        src/ui.cxx
        src/model.cxx)
# Links `game` against the GE211 game engine:
target_link_libraries(game ge211)

# Builds test program `game_test`:
add_test_program(model_test
        test/model_test.cxx src/model.cxx)
# Links `game_test` against the GE211 game engine:
target_link_libraries(model_test ge211)

