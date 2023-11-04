cmake_minimum_required(VERSION 3.22)
project(systemf LANGUAGES C CXX)

SET(CMAKE_CXX_STANDARD 20)

FIND_PACKAGE(GTest)


IF(EXISTS /opt/local)
    include_directories(/opt/local/include)
    link_directories(/opt/local/lib)
ENDIF()

include_directories(src)

add_subdirectory(src)
add_subdirectory(unittests)
