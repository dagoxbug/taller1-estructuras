//
// Created by nakos on 29-09-2026.
//

#include "../include/struct/ArregloDinamicoUsuario.h"


ArregloDinamicoUsuario::ArregloDinamicoUsuario() {

    cantidad = 0;
    capacidad = 1;

    usuarios = (Usuario**)malloc(capacidad * sizeof(Usuario*));
}


void ArregloDinamicoUsuario::agregarUsuario(Usuario* usuario) {

    // si la cantidad de elementos es igual que la capacidad se agrega mas espacios
    if (cantidad == capacidad) {
        capacidad = capacidad + 1;

        usuarios = (Usuario**)realloc(usuarios, capacidad * sizeof(Usuario*));
    }

    usuarios[cantidad] = usuario;
    cantidad++;
}


void ArregloDinamicoUsuario::eliminarUsuario(int id) {

    // falta eliminar temas publicados por el usuario
    // eliminar respuestas del usuario
    // y mostrar la cantidad de temas y respuestas del usuario y verificar si se borra o no


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

Usuario* ArregloDinamicoUsuario::buscarUsuario(int id) {
    for (int i = 0; i < cantidad; i++) {
        if (usuarios[i]->getId() == id) {
            return usuarios[i];
        }
    }
    return nullptr;
}

void ArregloDinamicoUsuario:: mostrarUsuarios() {

    for (int i = 0; i < cantidad; i++) {
        std::cout << "D: " << usuarios[i]->getId() << " | Nombre: "
        << usuarios[i]->getNombre() << std::endl;

    }
}