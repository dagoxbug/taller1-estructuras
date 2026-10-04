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
        cout << temas[i]->getId() << ": " << temas[i]->getTitulo() << "\n";
    }
}