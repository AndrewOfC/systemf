cmake_minimum_required(VERSION 3.20)

project(systemf_unittests)

add_executable(systemf_unittests unittests.cpp)

target_include_directories(systemf_unittests PUBLIC /usr/local/include)
target_link_directories(systemf_unittests PUBLIC /usr/local/lib)

GTEST_ADD_TESTS(TARGET systemf_unittests)

target_link_libraries(systemf_unittests systemf gtest pthread)
