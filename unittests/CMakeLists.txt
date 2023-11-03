cmake_minimum_required(VERSION 3.22)

project(systemf_unittests)

add_executable(systemf_unittests unittests.cpp)

GTEST_ADD_TESTS(TARGET systemf_unittests)

target_link_libraries(systemf_unittests systemf gtest)
