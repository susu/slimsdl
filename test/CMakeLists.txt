
# required for igloo:
add_definitions(-Wno-deprecated-declarations)
include_directories(igloo)

set(TEST_SOURCE_FILES
    test_runner.cpp
    simple_sdl_mock.cpp
    Context.cpp
    ImageContext.cpp
    )

add_executable(test_runner ${TEST_SOURCE_FILES})
target_link_libraries(test_runner slimsdl ${LIBS})

get_target_property(TEST_RUNNER_BIN test_runner LOCATION) # for running

add_custom_target(check DEPENDS test_runner)
add_custom_command(TARGET check
                   COMMAND ${TEST_RUNNER_BIN} --verbose)

add_custom_target(memcheck DEPENDS test_runner)
add_custom_command(TARGET memcheck
                   COMMAND valgrind -v --leak-check=full ${TEST_RUNNER_BIN})
