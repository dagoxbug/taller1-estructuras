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
private:
    int id;                 ///< Identificador unico del usuario
    std::string nombre;     ///< Nombre del usuario

public:
    /**
     * @brief Constructor de la clase Usuario.
     *
     * Inicializa un usuario con un identificador y un nombre.
     *
     * @param id Identificador del usuario.
     * @param nombre Nombre del usuario.
     */
    Usuario(int id, std::string nombre);

    //Getters y setters
    int getId();
    std::string getNombre();
    void setId(int id);
    void setNombre(std::string nombre);
};


#endif //TALLER1_ESTRUCTURAS_USUARIO_H
