cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

# This project is C++ based.
project(your_app CXX)
set (CMAKE_CXX_FLAGS "-march=native -O3")
set (CMAKE_PREFIX_PATH "/home/andrey/Schreibtisch/HauptS/my_hpx_build")

# Instruct cmake to find the HPX settings
find_package(HPX)

#SET(GCC_COVERAGE_COMPILE_FLAGS "-march=native")
#add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

add_compile_options("${GCC_COVERAGE_COMPILE_FLAGS}")

# build your application using HPX
add_hpx_executable(heat
    ESSENTIAL
    SOURCES heat_diff_hpx.cpp
    )
add_hpx_executable(heat_v2
    ESSENTIAL
    SOURCES heat_diff_hpx_v2.cpp
    )

