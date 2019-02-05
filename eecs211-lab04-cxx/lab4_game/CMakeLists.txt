cmake_minimum_required(VERSION 3.3)
project(ge211_examples CXX)

add_executable(lab4_game lab4_game.cpp)
target_link_libraries(lab4_game ge211)
set_property(TARGET lab4_game PROPERTY CXX_STANDARD 14)
set_property(TARGET lab4_game PROPERTY CXX_STANDARD_REQUIRED On)