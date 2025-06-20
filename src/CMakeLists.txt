cmake_minimum_required(VERSION 3.12)
project(pug LANGUAGES C)

# Compiler configuration
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2")

# Source files for pug executable
set(PUG_SOURCES
    storage.c
    input.c
    static.c
    type.c
    compiler.c
    parser.c
    pug.c
    gofer.c
    builtin.c
    machine.c
    output.c
)

# Executable targets
add_executable(pug ${PUG_SOURCES})
target_include_directories(pug PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pug m)

# Copy langlevels directory to build directory
add_custom_command(TARGET pug POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/langlevels
    ${CMAKE_BINARY_DIR}/langlevels
    COMMENT "Copying langlevels directory to build output"
)

# Test command integration
add_custom_target(test
    COMMAND cd .. && python3 -m unittest discover -v
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(test-reports
    COMMAND cd .. && python3 test/run_tests_with_reports.py --verbose --timeout 180
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(test-ci
    COMMAND cd .. && python3 test/run_tests_with_reports.py --verbose --xml-output test-reports --timeout 180
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
