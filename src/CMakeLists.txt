# This file exists solely for debugging purposes in IDEs. It is not used at runtime.
# Helium uses a local clang (windows) or GCC (linux) installation to compile, not make/cmake.

cmake_minimum_required(VERSION 3.21)
project(crossroads)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(indexer)

add_executable(crossroads
        indexer/castleindex.h
        indexer/castleindexer.cpp
        indexer/castleindexer.h
        crossroads.cpp
        indexer/castleindex.cpp
        indexer_api.h
        api_base.h
        indexer_api.cpp
        api_base.cpp)
