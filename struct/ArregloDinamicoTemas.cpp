//
// Created by nakos on 29-09-2026.
//

#include "../include/struct/ArregloDinamicoTemas.h"

ArregloDinamicoTemas::ArregloDinamicoTemas() {
    capacidad = 1;
    cantidad = 0;

    temas = (Tema**) malloc(capacidad * sizeof(Tema*));
}

void ArregloDinamicoTemas::agregarTema(Tema* tema) {

    if (cantidad == capacidad) {
        capacidad++;

        temas = (Tema**) realloc(temas, capacidad * sizeof(Tema*));
    }

    // agregamos los temas mas recientes en las posiciones mas iniciales
    for (int i = cantidad; i > 0; i--) {
        temas[i] = temas[i - 1];
    }

    temas[0] = tema;
    cantidad++;
}

void ArregloDinamicoTemas::mostrarTemas() {
    for (int i = 0; i < cantidad; i++) {
        std::cout << temas[i]->getId() << ": " << temas[i]->getTitulo() << "\n";
    }
}

void ArregloDinamicoTemas::eliminarTemasPorUsuario(int idUsuario) {
    for (int i = 0; i < cantidad; i++) {
        if (temas[i]->getIdUsuario() == idUsuario) {
            delete temas[i];

            // movemos los temas hacia la izquierda
            for (int j = i; j < cantidad - 1; j++) {
                // el elemento que estaba a la derecha ocupa el espacio que quedo vacio
                temas[j] = temas[j + 1];
            }

            cantidad--;
            i--;
        }
    }
    temas = (Tema**) realloc(temas, cantidad * sizeof(Tema*));
}

int ArregloDinamicoTemas::contarTemasPorUsuario(int idUsuario) {
    int contador = 0;

    for (int i = 0; i < cantidad; i++) {
        if (temas[i]->getIdUsuario() == idUsuario) {
            contador++;
        }
    }
    return contador;
}

bool ArregloDinamicoTemas::existeTema(std::string id) {
    return false;
}

bool ArregloDinamicoTemas::existeId(std::string id) {

    for (int i = 0; i < cantidad; i++) {

        if (temas[i]->getId() == id) {
            return true;
        }
    }
    return false;
}