cmake_minimum_required(VERSION 3.20)
project(libsystemf LANGUAGES C CXX)

SET(CMAKE_CXX_STANDARD 20)

FIND_PACKAGE(GTest)

IF(EXISTS /opt/local)
    include_directories(/opt/local/include)
    link_directories(/opt/local/lib)
ENDIF()

include_directories(src)

add_subdirectory(src)
add_subdirectory(unittests)

##
## .deb and .rpm packages
##
execute_process(COMMAND ${CMAKE_CURRENT_LIST_DIR}/scripts/parseosrelease.py ID OUTPUT_VARIABLE DISTRO OUTPUT_STRIP_TRAILING_WHITESPACE)
IF( "${DISTRO}" STREQUAL "" )
  set(DISTRO "unknown")
ENDIF()

set(CPACK_PACKAGE_VENDOR "Andrew E Page")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "execute system commands with printf style parameters")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "1")

IF( ${DISTRO} STREQUAL "ubuntu")
  set(CPACK_DEBIAN_PACKAGE_MAINTAINER AndrewOfC@github.com)
  set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6")
  set(CPACK_GENERATOR DEB)
ELSEIF( ${DISTRO} STREQUAL "rhel" )
  set(CPACK_RPM_PACKAGE_REQUIRES "glibc")
  set(CPACK_RPM_PACKAGE_LICENSE "MIT")
  set(CPACK_GENERATOR RPM)
ELSE()
  MESSAGE(STATUS "Unknown distro ${DISTRO}, packaging not available")
ENDIF()

include(CPack)
