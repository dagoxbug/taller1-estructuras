//
// Created by nakos on 29-09-2026.
//

#ifndef TALLER1_ESTRUCTURAS_RESPUESTA_H
#define TALLER1_ESTRUCTURAS_RESPUESTA_H
#include <iostream>

/**
 * @class Respuesta
 * @brief Representa la respuesta de un tema en el foro
 */
class Respuesta {

    int id;                 ///< Identificador unico del mensaje
    int idUsuario;          ///< identificador del usuario que envio la respuesta
    std::String contenido;  ///< Contenido de la respuesta
};


#endif //TALLER1_ESTRUCTURAS_RESPUESTA_H
