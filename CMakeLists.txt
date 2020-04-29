cmake_minimum_required(VERSION 3.5)

project(copy_func_mem LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(copy_func_mem main.c meme_xec.h)
#add_definitions(copy_func_mem meme_xec.h)
