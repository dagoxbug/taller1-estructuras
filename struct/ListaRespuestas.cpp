//
// Created by nakos on 29-09-2026.
//

#include "../include/struct/ListaRespuestas.h"

ListaRespuestas::ListaRespuestas()
    : cabeza(nullptr), cantidad(0), ultimoId(0) {
}

ListaRespuestas::~ListaRespuestas() {
    Respuesta* actual = cabeza;
    while (actual != nullptr) {
        Respuesta* siguiente = actual->getSiguiente(); // guardar antes de borrar
        delete actual;
        actual = siguiente;
    }
    cabeza = nullptr;
}

void ListaRespuestas::agregarAlInicio(Respuesta* respuesta) {
    respuesta->setSiguiente(cabeza);
    cabeza = respuesta;
    cantidad++;

    if (respuesta->getId() > ultimoId) {
        ultimoId = respuesta->getId();
    }
}

Respuesta* ListaRespuestas::getCabeza() const {
    return cabeza;
}

int ListaRespuestas::getCantidad() const {
    return cantidad;
}

int ListaRespuestas::getUltimoId() const {
    return ultimoId;
}