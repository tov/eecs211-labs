cmake_minimum_required(VERSION 3.3)
project(key_racer CXX)
include(.cs211/cmake/CMakeLists.txt)

# Builds program `key_racer` from the four listed source files:
add_program(key_racer
        src/key_racer.cxx
        src/model.cxx
        src/view.cxx
        src/controller.cxx)
target_link_libraries(key_racer ge211)

# Builds test program `model_test` from the two listed source files:
add_test_program(model_test
        test/model_test.cxx
        src/model.cxx)
target_link_libraries(model_test ge211)
