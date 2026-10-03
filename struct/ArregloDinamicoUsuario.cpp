//
// Created by nakos on 29-09-2026.
//

#include "../include/struct/ArregloDinamicoUsuario.h"

arregloDinamicoUsuario::arregloDinamicoUsuario() {

    cantidad = 0;
    capacidad = 1;

    usuarios = (Usuario**)malloc(capacidad * sizeof(Usuario*));
}


void arregloDinamicoUsuario::agregarUsuario(Usuario* usuario) {

    // si la cantidad de elementos es igual que la capacidad se agrega mas espacios
    if (cantidad == capacidad) {
        capacidad = capacidad * 2;

        Usuario = (Usuario**)realloc(Usuario, capacidad * sizeof(Usuario*));
    }

    usuarios[cantidad] = usuario;
    cantidad++;
}


void arregloDinamicoUsuario::eliminarUsuario(int id) {

    int posicion = -1;

    // Buscar el usuario
    for (int i = 0; i < cantidad; i++) {

        if (usuarios[i]->getId() == id) {
            posicion = i;
            break;
        }
    }

    // si el usuario no existe
    if (posicion == -1) {
        std::cout << "El usuario no existe\n" << std::endl;
        return;
    }

    // eliminar al usuario
    delete usuarios[posicion];

    //mover los elementos
    for (int i = posicion; i < cantidad - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }

    // disminuir la cantidad
    cantidad--;

    // reducir la capacidad si corresponde
    if (cantidad <= capacidad / 2 && capacidad > 1) {

        capacidad = capacidad / 2;

        usuarios = (Usuario**)realloc(usuarios, cantidad * sizeof(Usuario*));
    }
}