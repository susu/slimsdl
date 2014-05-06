slim-sdl
========

A thin C++11 wrapper for SDL2

Usage example
=============

Install
=======

Prerequisities
--------------

Supported and tested platform: linux

git, cmake, decent C++11 compiler (GCC 4.8 or clang 3.3)

Steps
-----

{{{
    git clone https://github.com/susu/slimsdl
    git submodule update --init
    cd slimsdl
    mkdir build/
    cd build
    cmake ..
    make
    make install
}}}

You might configure the install path:
{{{
    cmake -DCMAKE_INSTALL_PREFIX=<YOUR-INSTALL-PATH> ..
}}}


If you want to use it in a CMake project, you can add it as an external project. E.g.:

{{{
include(ExternalProject)

ExternalProject_Add(
    SDL2MINE
    GIT_REPOSITORY https://github.com/susu/slimsdl
    GIT_TAG v0.3
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/thirdparty/
    )
}}}

License
=======

MIT

Contribution
============

Fork and send pull request!
