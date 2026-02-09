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

# Only if you actually have a root main.cpp / main.c
# add_executable(Modules_EPAM main.cpp
#         1_module/1.8_Recursion/1.8_Tsk1.cpp
#         1_module/1.8_Recursion/1.8_Tsk2.cpp
#         1_module/1.9_Array/Tsk1_1_9.cpp
#         1_module/1.9_Array/Tsk2_1_9.cpp
#         1_module/1.9_Array/Tsk3_1_9.cpp
#         1_module/1.9_Array/Tsk4_1_9.cpp
#         1_module/1.9_Array/Tsk5_1_9.cpp
#         1_module/1.10_Str_Un/Tsk1_1_10.c
#         1_module/1.11_Ptr/Tsk1_1_11.c
#         1_module/1.11_Ptr/Tsk2_1_11.cpp
#         1_module/1.11_Ptr/Tsk3_1_11.c
#         1_module/1.11_Ptr/Tsk4_1_11.c
#         1_module/1.11_Ptr/Tsk5_1_11.c
#         1_module/1.11_Ptr/Tsk6_1_11.c
#         1_module/1.11_Ptr/Tsk7_1_11.cpp
#         "1_module/1.12(File)/learn_file.cpp"
#         "1_module/1.12(File)/Tsk1_1_12.c"
#         "1_module/1.12(File)/Tsk2_1_12.c"
#         "1_module/1.12(File)/Tsk3_1_12.c"
#         "1_module/1.12(File)/Tsk4_1_12.c"
#         "1_module/1.12(File)/Tsk5_1_12.c"
#         1_module/1.1_Var_Dec/Tsk1_1_1.cpp
#         1_module/1.1_Var_Dec/Tsk2_1_1.c
#         1_module/1.2_Pf_Sf_ForSpfr/Tsk1_1_2.c
# )
