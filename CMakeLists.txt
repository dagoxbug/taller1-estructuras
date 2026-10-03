cmake_minimum_required(VERSION 4.2)
project(Taller1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Taller1
        main.cpp
        main.h
        model/Usuario.cpp
        struct/ArregloDinamicoUsuario.cpp
)