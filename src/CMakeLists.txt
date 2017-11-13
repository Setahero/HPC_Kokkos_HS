cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

# This project is C++ based.
project(your_app CXX)

# Instruct cmake to find the HPX settings
find_package(HPX REQUIRED)

# build your application using HPX
add_hpx_executable(heat
    ESSENTIAL
    SOURCES heat_diff_hpx.cpp)


#include_directories(/home/andrey/Schreibtisch/HauptS/hpx/include/hpx)
#link_directories(/home/andrey/Schreibtisch/HauptS/hpx/lib)

#set(CMAKE_BINARY_DIR ./)
#set(EXECUTABLE_OUTPUT_PATH ./)
#set(LIBRARY_OUTPUT_PATH ./)
#add_executable(heat ./heat_diff_hpx.cpp)