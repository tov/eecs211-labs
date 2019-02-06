cmake_minimum_required(VERSION 3.3)
project(project-base CXX)
include(.eecs211/cmake/CMakeLists.txt)

add_program(game src/game.cpp)
target_link_libraries(game ge211)

# Builds program client from the two listed source files:
add_program(client src/client.cpp src/shared.cpp)

# Builds test program shared_test from the two listed source files:
add_test_program(shared_test test/shared_test.cpp src/shared.cpp)

