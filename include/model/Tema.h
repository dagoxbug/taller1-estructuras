//
// Created by nakos on 29-09-2026.
//

#ifndef TALLER1_ESTRUCTURAS_TEMA_H
#define TALLER1_ESTRUCTURAS_TEMA_H
#include <iostream>


#include "include/struct/ListaRespuestas.h"

/**
 * @class Tema
 * @brief Representa el tema escrito en el foro
 */
class Tema {
private:
    std::string id;             ///< Identificador unico del tema
    std::string titulo;         ///< titulo del foro
    std::string contenido;      ///< Contenido del tema
    int idUsuario;              ///< identificador del usuario que escribio el tema
    ListaRespuestas respuestas;

public:
    Tema(const std::string& id, const std::string& titulo,
         const std::string& contenido, int idUsuario);
    Tema(const Tema&) = delete;

    /// Getters
    std::string getId();
    std::string getTitulo();
    std::string getContenido();
    int getIdUsuario();
    ListaRespuestas& getRespuestas();

};


#endif //TALLER1_ESTRUCTURAS_TEMA_H
