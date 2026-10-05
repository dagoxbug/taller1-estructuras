//
// Created by nakos on 29-09-2026.
//

#ifndef TALLER1_ESTRUCTURAS_ARREGLODINAMICOTEMAS_H
#define TALLER1_ESTRUCTURAS_ARREGLODINAMICOTEMAS_H
#include "include/model/Tema.h"

/**
 * @brief Arreglo dinámico que almacena los temas del foro.
 *
 * El arreglo aumenta su capacidad de forma dinámica
 * cuando se queda sin espacio.
 */
class ArregloDinamicoTemas {
private:
    /**
     * @brief Arreglo de punteros a objetos Tema.
     */
    Tema** temas;

    /**
     * @brief Cantidad actual de temas almacenados.
     */
    int cantidad;

    /**
     * @brief Capacidad actual del arreglo.
     */
    int capacidad;

public:
    /**
     * @brief Constructor de la clase.
     *
     * Inicializa el arreglo dinámico y establece
     * la cantidad de elementos en cero.
     */
    ArregloDinamicoTemas();

    // falta implementar
    //~ArregloDinamicoTemas();

    /**
    * @brief Agrega un nuevo tema al arreglo.
    *
    * Si el arreglo está lleno, aumenta su capacidad
    * en una posición utilizando realloc.
    * Los temas existentes se desplazan una posición hacia
    * la derecha para dejar espacio al nuevo tema.
    *
    * @param tema Puntero al tema que se desea agregar.
    */
    void agregarTema(Tema* tema);

    /**
    * @brief Muestra todos los temas almacenados por su ID y titulo
    */
    void mostrarTemas();

    /**
     * @brief Obtiene la cantidad actual de temas almacenados.
     *
     * @return Cantidad de temas almacenados.
     */
    int getCantidad() const;

    /**
     * @brief Obtiene el tema ubicado en una posición del arreglo.
     *
     * @param posicion Posición del tema dentro del arreglo.
     * @return Puntero al tema almacenado en la posición indicada.
     */
    Tema* getTema(int posicion) const;


    /**
    * Elimina todos los temas creados por un usuario.
    *
    * Recorre el arreglo de temas y elimina aquellos cuyo ID de usuario
    * coincide con el ID recibido. Luego reorganiza los elementos restantes
    * y actualiza la cantidad de temas almacenados.
    *
    * @param idUsuario ID del usuario cuyos temas se desean eliminar.
    */
    void eliminarTemasPorUsuario(int idUsuario);

    /**
    * @brief Cuenta la cantidad de temas creados por un usuario.
    *
    * @param idUsuario ID del usuario cuyos temas se desean contar.
    * @return Cantidad de temas creados por el usuario.
    */
    int contarTemasPorUsuario(int idUsuario);

    /**
    * @brief Comprueba si un identificador ya existe.
    *
    * Recorre los temas almacenados y compara sus identificadores
    * con el identificador recibido.
    *
    * @param id Identificador que se desea buscar.
    * @return true si el identificador ya existe, false en caso contrario.
    */
    bool existeId(std::string id);

    bool existeTema(std::string id);

    Tema* buscarTema(const std::string& id);
    bool moverAlInicio(const std::string& id);

};


#endif //TALLER1_ESTRUCTURAS_ARREGLODINAMICOTEMAS_H
