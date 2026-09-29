//
// Created by nakos on 29-09-2026.
//

#ifndef TALLER1_ESTRUCTURAS_USUARIO_H
#define TALLER1_ESTRUCTURAS_USUARIO_H
#include <iostream>

/**
 * @class Usuario
 * @brief Representa a un usuario perteneciente al foro
 */
class Usuario {

    int id;                 ///< Identificador unico del usuario
    std::string nombre;     ///< Nombre del usuario

public:
    Usuario(int id, std::string nombre);
};


#endif //TALLER1_ESTRUCTURAS_USUARIO_H
