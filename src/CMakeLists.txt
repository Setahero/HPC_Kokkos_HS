cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

# This project is C++ based.
project(your_app CXX)

# Instruct cmake to find the HPX settings
find_package(HPX REQUIRED)

# build your application using HPX
add_hpx_executable(heat
    ESSENTIAL
    SOURCES heat_diff_hpx.cpp
    )
add_hpx_executable(heat_v2
    ESSENTIAL
    SOURCES heat_diff_hpx_v2.cpp
    )
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native")

