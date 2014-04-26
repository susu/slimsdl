cmake_minimum_required(VERSION 2.8)
option(build_tests "Build all unit tests")

project(__write_your_project_name_here__)

set(LIBS ${LIBS})

if(APPLE OR UNIX)
  set(CMAKE_CXX_COMPILER "clang++")
endif()

if(UNIX)
    message("Looking for libc++ and libc++abi ...")
    find_library(libcpp_abi c++abi)
    if(libcpp_abi)
        message("libc++ found: ${libcpp_abi}")
        set(LIBS ${LIBS} ${libcpp_abi} -stdlib=libc++)
        add_definitions(-stdlib=libc++)
    else()
        message("... not found, falling back to libstdc++")
    endif()
endif(UNIX)

include_directories(include)

add_definitions(-std=c++11
                -Wall
                -Werror
                -g
                )

add_subdirectory(src)
add_subdirectory(test)

install(DIRECTORY include DESTINATION .)
