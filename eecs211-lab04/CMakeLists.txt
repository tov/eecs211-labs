cmake_minimum_required(VERSION 3.3)
project(lab04 CXX)
include(.eecs211/cmake/CMakeLists.txt)

# Builds program client from the two listed source files:
add_program(game src/game.cpp src/model.cpp)
target_link_libraries(game ge211)
add_test_program(game_test test/game_test.cpp src/model.cpp)
target_link_libraries(game_test ge211)
target_link_libraries(game_test catch)

