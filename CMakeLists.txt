cmake_minimum_required(VERSION 3.16..3.8)

project(IntervalTree
        VERSION 0.0.1
        DESCRIPTION "IntervalTree project"
        LANGUAGES CXX
)
include(cmake/UpdateSubmodules.cmake) # updates google tests properly, no outdated version of the submodule
include(CTest)

add_subdirectory(external)
add_subdirectory(test)