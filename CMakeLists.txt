cmake_minimum_required(VERSION 2.8)

project(__write_your_project_name_here__)

###########
# OPTIONs

option(sanitize "Select sanitizer (address,memory,thread,...)" OFF)

if(UNIX)
    option(enable_libc++ "Enable looking for LLVM's libc++ and using it as standard library if found")
endif(UNIX)

#
##########

set(LIBS ${LIBS})

find_library(SDL2 SDL2_image REQUIRED)
set(LIBS ${LIBS} SDL2 SDL2_image)

message("LIBS: ${LIBS}")

if(UNIX)
    if(enable_libc++)
        message("--> Looking for libc++ and libc++abi ...")
        find_library(libcpp_abi c++abi)
        if(libcpp_abi)
            message("libc++ found: ${libcpp_abi}")
            set(LIBS ${LIBS} ${libcpp_abi} -stdlib=libc++)
            add_definitions(-stdlib=libc++)
        else(libcpp_abi)
          message("libc++ not found, falling back to libstdc++")
        endif(libcpp_abi)
    else(enable_libc++)
        message("--> Using libstdc++ as standard library")
    endif(enable_libc++)
endif(UNIX)

include_directories(include)

add_definitions(-std=c++14
                -Wall
                -Werror
                -g
                -fPIC
                )


if(sanitize)
    message("--> Sanitize: ${sanitize}")
    list(APPEND LIBS -fsanitize=${sanitize})
    add_definitions(-fsanitize=${sanitize})
else(sanitize)
    message("--> Sanitizing is disabled.")
endif(sanitize)

## 3rd party libs

include_directories(SYSTEM thirdparty/include)
link_directories(${CMAKE_SOURCE_DIR}/thirdparty/lib)

include(ExternalProject)
ExternalProject_Add(
    GOODIES
    GIT_REPOSITORY https://github.com/susu/goodies
    GIT_TAG v0.6
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/thirdparty/
    )

list(APPEND LIBS goodies)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)

## Install section
install(DIRECTORY include DESTINATION .)
