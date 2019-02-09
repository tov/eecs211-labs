# Turn on CTest
enable_testing()

include_directories(src)

add_subdirectory(.eecs211/lib/catch EXCLUDE_FROM_ALL)
add_subdirectory(.eecs211/lib/ge211 EXCLUDE_FROM_ALL)

# Adds a program with the given name and source files, and sets the
# language to C++ 14
function (add_program name)
    add_executable(${name} ${ARGN})
    set_property(TARGET ${name} PROPERTY CXX_STANDARD 14)
    set_property(TARGET ${name} PROPERTY CXX_STANDARD_REQUIRED On)
endfunction (add_program)

# Adds a test program with the given name and source files
function (add_test_program name)
    add_program(${name} ${ARGN})
    target_link_libraries(${name} catch)
    add_test(Test_${name} ${name})
endfunction (add_test_program)

# Like find_file, but does not cache the result.
function (find_file_nc dest_var filename)
    set(${dest_var} "" PARENT_SCOPE)
    foreach(dir ${ARGN})
        if(EXISTS "${dir}/${filename}")
            set(${dest_var} "${dir}/${filename}" PARENT_SCOPE)
            return()
        endif()
    endforeach()
endfunction(find_file_nc)

# Adds a ge211 installer for the given program instead of just
# adding the program.
#
# Usage: add_installer(<target> <source_file>... [RESOURCES <resource_file>...])
# If no resource files are specified than all resources are included.
function (add_installer name)
    # Parse arguments into sources and resources
    foreach(arg ${ARGN})
        if (arg STREQUAL "RESOURCES")
            set(in_resources "YES")
        elseif (in_resources)
            find_file_nc(arg_file "${arg}"
                    "${CMAKE_CURRENT_SOURCE_DIR}/Resources"
                    "${GE211_RESOURCES_DIR}")
            if (EXISTS "${arg_file}")
                list(APPEND project_resources "${arg_file}")
            else ()
                message(FATAL_ERROR
                        "Could not find resource file ${arg}")
            endif ()
        else ()
            list(APPEND project_sources "${arg}")
        endif ()
    endforeach()

    # Find resources
    if (NOT in_resources)
        file(GLOB system_resources "${GE211_RESOURCES_DIR}/*")
        file(GLOB project_resources Resources/*)
    endif ()
    set(resource_files "${system_resources}" "${project_resources}")

    # Add the program target, including the resource files
    add_program(${name} ${project_sources} ${resource_files})

    # Create or add to an installer
    if (INSTALLER_ADDED)
        message(WARNING "add_installer: already added installer for "
                "${INSTALLER_ADDED}; cannot also add installer for "
                "${name} because only one installer is supported at a "
                "time. Adding ${name} to the existing installer instead.")
        add_to_ge211_installer(${name} "${resource_files}")
    else ()
        set(INSTALLER_ADDED ${name} PARENT_SCOPE)
        setup_ge211_installer(${name} "${resource_files}")
    endif ()
endfunction (add_installer)

