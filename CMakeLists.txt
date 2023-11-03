cmake_minimum_required(VERSION 3.22)
project(systemf LANGUAGES C CXX)

FIND_PACKAGE(GTest)

include_directories(src)

add_subdirectory(src)
add_subdirectory(unittests)
