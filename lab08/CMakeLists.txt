cmake_minimum_required(VERSION 3.3)
project(asteroids CXX)
include(.cs211/cmake/CMakeLists.txt)

add_program(asteroids
        src/asteroids.cxx
        src/model.cxx
        src/view.cxx
        src/space_object.cxx
        src/controller.cxx)
target_link_libraries(asteroids ge211)


