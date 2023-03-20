cmake_minimum_required(VERSION 3.24)
project(shareable)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(shareable
        Count.ino
        getch.c
        p4-03-01-2023.c
        rough.c
        problem1.c bubble_sort_optimised.c det_nxn.c)
