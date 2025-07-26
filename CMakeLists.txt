cmake_minimum_required(VERSION 3.12)
project(libpoly)

# set compiler to gcc
if(NOT CMAKE_C_COMPILER)
    set(CMAKE_C_COMPILER gcc)
endif()

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# add compile options
add_compile_options(-O2)

# include directory
include_directories(include)

# collect source files
file(GLOB_RECURSE LIB_SOURCES "src/*.c")

# make shared library nemed libpoly.so
add_library(poly SHARED ${LIB_SOURCES})
set_target_properties(poly PROPERTIES OUTPUT_NAME "poly")

# exe file with Main.cpp
add_executable(test_main.exe Main.c)

# Link to library
target_link_libraries(test_main.exe PRIVATE poly m)
