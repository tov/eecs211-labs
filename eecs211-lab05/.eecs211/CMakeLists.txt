# Turn on CTest
enable_testing()

# UnitTest++
set(UNITTESTCPP_ROOT .eecs211/lib/unittest-cpp)
add_subdirectory(${UNITTESTCPP_ROOT})
include_directories(${UNITTESTCPP_ROOT})

# Graphics
set(GRAPHICSCPP_ROOT .eecs211/lib/graphics)
add_subdirectory(${GRAPHICSCPP_ROOT})
include_directories(${GRAPHICSCPP_ROOT})

# Adds a program with the given name and source files, and sets the
# language to C++ 14
macro (add_program name)
    add_executable(${name} ${ARGN})
    set_property(TARGET ${name} PROPERTY CXX_STANDARD 14)
    set_property(TARGET ${name} PROPERTY CXX_STANDARD_REQUIRED On)
endmacro (add_program)

# Adds a test program with the given name and source files
macro (add_test_program name)
    add_program(${name} .eecs211/lib/unittest-main.cpp ${ARGN})
    target_link_libraries(${name} UnitTest++)
    add_test(Test_${name} ${name})
endmacro (add_test_program)

###
### Setting some flags, portably
###

# Sets the given flag IFF the compiler supports it
include(CheckCXXCompilerFlag)
macro (safe_add_cxx_flag flag)
    check_cxx_compiler_flag(-${flag} HAS_${flag})
    if (HAS_${flag})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -${flag}")
    endif()
endmacro (safe_add_cxx_flag)

safe_add_cxx_flag(O0)           # Don't optimize
safe_add_cxx_flag(g)            # Do include debug symbols

