//
// Created by nakos on 29-09-2026.
//

#include "../include/model/Tema.h"

Tema::Tema(const std::string& id, const std::string& titulo,
           const std::string& contenido, int idUsuario)
    : id(id), titulo(titulo), contenido(contenido), idUsuario(idUsuario) {
    // respuestas se construye vacia automaticamente
}

std::string Tema::getId() {
    return id;
}

std::string Tema::getTitulo() {
    return titulo;
}

std::string Tema::getContenido() {
    return contenido;
}

int Tema::getIdUsuario() {
    return idUsuario;
}

ListaRespuestas& Tema::getRespuestas() {
    return respuestas;
}
