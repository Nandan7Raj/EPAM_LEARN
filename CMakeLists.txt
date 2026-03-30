cmake_minimum_required(VERSION 3.20)

project(Modules_EPAM
        VERSION 1.0
        LANGUAGES C CXX)

# ---- C standard ----
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ---- C++ standard ----
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)   # pure ISO C++

add_subdirectory(1_module)
add_subdirectory(2_module)
add_subdirectory(practice)
add_subdirectory(3_module)
add_subdirectory(4_module)
add_subdirectory(5_module)
add_subdirectory(6_module)
add_subdirectory(7_module)

# Only if you actually have a root main.cpp / main.c
