//
// Created by nakos on 29-09-2026.
//

#include "../include/model/Tema.h"

Tema::Tema(std::string id, std::string titulo, std::string contenido, int idUsuario) {
    this->id = id;
    this->titulo = titulo;
    this->contenido = contenido;
    this->idUsuario = idUsuario;
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
