cmake_minimum_required(VERSION 3.8)
project(finalProject)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES statserve_tests.c statserve.c net.c)

add_executable(finalProject ${SOURCE_FILES})
add_executable(statserve_tests statserve_tests.c)
add_executable(statserve statserve.c statserve.h)
add_executable(net net.c net.h)
