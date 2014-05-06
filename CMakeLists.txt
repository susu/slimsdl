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

add_definitions(-std=c++11
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

add_subdirectory(src)
add_subdirectory(test)

## Install section
install(DIRECTORY include DESTINATION .)
