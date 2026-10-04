//
// Created by nakos on 29-09-2026.
//

#ifndef TALLER1_ESTRUCTURAS_ARREGLODINAMICOUSUARIO_H
#define TALLER1_ESTRUCTURAS_ARREGLODINAMICOUSUARIO_H
#include "include/model/Usuario.h"

/**
 * @class ArregloDinamicoUsuario
 * @brief Administra un arreglo dinamico de usuarios
 *
 * Esta clase permite almacenar, agregar, eliminar y mostrar usuarios.
 * El arreglo puede modificar su capacidad segun la cantidad de usuarios almacenados
 */
class ArregloDinamicoUsuario {
private:
    /**
     * @brief Arreglo dinamico que almacena los usuarios
     */
    Usuario** usuarios;

    /**
     * @brief Cantidad actual de usuarios almacenados
     */
    int cantidad;

    /**
     * @brief capacidad maxima actual del arreglo
     */
    int capacidad;

public:
    /**
     * @brief Constructor de la clase
     *
     * Inicializa el arreglo dinamico, la cantidad de usuarios
     * y la capacidad inicial
     */
    ArregloDinamicoUsuario();

    //falta implementar
    ~ArregloDinamicoUsuario();

    /**@brief agrega un usuario al arreglo
     *
     * si el arreglo no tiene espacio disponible, aumneta su capacidad
     * utilizando realloc antes de almacenar el nuevo usuario
     *
     * @param usuario puntero al usuario que se desea agregar
     */
    void agregarUsuario(Usuario* usuario);

    /**
     * @brief Elimina un usuario del arreglo mediante su ID.
     *
     * Busca el usuario por su identificador. Si lo encuentra, lo elimina
     * y desplaza los usuarios siguientes para mantener el arreglo ordenado.
     *
     * @param id Identificador del usuario que se desea eliminar.
     */
    void eliminarUsuario(int id);

    /**
     * @brief Busca un usuario mediante su identificador
     *
     * Recorre el arreglo dinamico y busca un usuario que tenga
     * el ID indicado
     *
     * @param id identificador del usuario que se desea buscar
     * @return Usuario* puntero al usuario encontrado, si no existe,
     * retorna nullptr
     */
    Usuario* buscarUsuario(int id);

    /**
     * @brief Muestra los usuarios almacenados en el arreglo.
     *
     * Recorre el arreglo y muestra la información de cada usuario.
     */
    void mostrarUsuarios();

};


#endif //TALLER1_ESTRUCTURAS_ARREGLODINAMICOUSUARIO_H
