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


    void eliminarTema(int id);

    /**
    * @brief Muestra todos los temas almacenados por su ID y titulo
    */
    void mostrarTemas();
    int getCantidad();
    bool existeId(std::string id);

    /**
    * @brief Comprueba si un identificador ya existe.
    *
    * Recorre los temas almacenados y compara sus identificadores
    * con el identificador recibido.
    *
    * @param id Identificador que se desea buscar.
    * @return true si el identificador ya existe, false en caso contrario.
    */
    bool existeTema(std::string id);

};


#endif //TALLER1_ESTRUCTURAS_ARREGLODINAMICOTEMAS_H
