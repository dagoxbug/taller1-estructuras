cmake_minimum_required(VERSION 4.2)
project(Taller1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Taller1
        main.cpp
        model/Usuario.cpp
        model/Tema.cpp
        model/Respuesta.cpp
        struct/ArregloDinamicoUsuario.cpp
        struct/ArregloDinamicoTemas.cpp
        services/Sistema.cpp
        struct/ListaRespuestas.cpp
        include/struct/ListaRespuestas.h
)