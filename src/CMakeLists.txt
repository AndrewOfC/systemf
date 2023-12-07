cmake_minimum_required(VERSION 3.20)


add_library(systemf systemf.c systemf/systemf.h)

install(TARGETS systemf LIBRARY)
install(FILES systemf/systemf.h DESTINATION include/systemf)
