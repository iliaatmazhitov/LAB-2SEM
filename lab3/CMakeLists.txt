cmake_minimum_required(VERSION 3.28)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 main.cpp
        UI.h
        UI.cpp
        tests.h
        tests.cpp
        Vector.cpp
)
