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

int ListaRespuestas::contarRespuestaPorUsuario(int idUsuario) {
    int contador = 0;
    Respuesta* actual = cabeza;

    while (actual != nullptr) {
        if (actual->getId() == idUsuario) {
            contador++;
        }

        actual = actual->getSiguiente();
    }
    return contador;
}

void ListaRespuestas::eliminarRespuestasPorUsuario(int idUsuario) {
    Respuesta* actual = cabeza;
    Respuesta* anterior = nullptr;

    //mientras exista una respuesta, seguimos recorriendo
    while (actual != nullptr) {
        if (actual->getIdUsuario() == idUsuario) {

            // guardamos la siguiente respuesta antes de eliminar la actual
            Respuesta* siguiente = actual->getSiguiente();

            // si anterior es nullptr es porque eliminamos la primera respuesta de la lista
            if (anterior == nullptr) {
                cabeza = siguiente;
            }else {
                // si no es la primera, conectamos la respuesta anterior con la sig.
                anterior->setSiguiente(siguiente);
            }

            // eliminamos la actual
            delete actual;
            cantidad--;

            actual = siguiente;
        }else {
            // avanzamos si la respuesta no pertenece al usuario
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }
}