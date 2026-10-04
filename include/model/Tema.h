//
// Created by nakos on 29-09-2026.
//

#ifndef TALLER1_ESTRUCTURAS_TEMA_H
#define TALLER1_ESTRUCTURAS_TEMA_H
#include <iostream>

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

    //ListaRespuestas respuestas;   <- lista enlazada

public:
    Tema(std::string id, std::string titulo, std::string contenido, int idUsuario);

    int getId();
    std::string getTitulo();
    std::string getContenido();
    int getIdUsuario();

};


#endif //TALLER1_ESTRUCTURAS_TEMA_H
