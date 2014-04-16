
# required for igloo:
add_definitions(-Wno-deprecated-declarations)
include_directories(igloo)

set(TEST_SOURCE_FILES
    test_runner.cpp
    )

add_executable(test_runner ${TEST_SOURCE_FILES})

# target_link_libraries(test_runner dsalgo)
get_target_property(TEST_RUNNER_BIN test_runner LOCATION) # for running

add_custom_target(test ALL DEPENDS test_runner)
add_custom_command(TARGET test
                   COMMAND ${TEST_RUNNER_BIN} --verbose
                   DEPENDS test_runner)
