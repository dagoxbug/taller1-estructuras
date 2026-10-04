//
// Created by nakos on 29-09-2026.
//

#ifndef TALLER1_ESTRUCTURAS_LISTARESPUESTAS_H
#define TALLER1_ESTRUCTURAS_LISTARESPUESTAS_H

#include "../model/Respuesta.h"

/**
 * @class ListaRespuestas
 * @brief Lista enlazada simple que almacena las respuestas de un tema.
 *
 * Cada nueva respuesta se inserta al inicio de la lista.
 */
class ListaRespuestas {
private:
    Respuesta* cabeza;  ///< Primer nodo de la lista (nullptr si esta vacia)
    int cantidad;       ///< Cantidad de respuestas almacenadas
    int ultimoId;       ///< Mayor Id de respuesta registrado en la lista

public:
    /**
     * @brief Crea una lista vacia.
     */
    ListaRespuestas();

    /**
     * @brief Libera la memoria de todos los nodos de la lista.
     */
    ~ListaRespuestas();

    /**
     * @brief Inserta una respuesta al inicio de la lista.
     * @param respuesta Puntero a la respuesta que se desea agregar.
     */
    void agregarAlInicio(Respuesta* respuesta);

    /**
     * @brief Obtiene el primer nodo de la lista.
     * @return Puntero a la primera respuesta, o nullptr si la lista esta vacia.
     */
    Respuesta* getCabeza() const;
    int getCantidad() const;
    int getUltimoId() const;

    /**
     * @brief Cuenta la cantidad de respuestas realizadas por un usuario.
     *
     * @param idUsuario ID del usuario cuyas respuestas se desean contar.
     * @return Cantidad de respuestas realizadas por el usuario.
     */
    int contarRespuestaPorUsuario(int idUsuario);

    /**
     * @brief Elimina todas las respuestas realizadas por un usuario.
     *
     * @param idUsuario ID del usuario cuyas respuestas se desean eliminar.
     */
    void eliminarRespuestasPorUsuario(int idUsuario);
};

#endif //TALLER1_ESTRUCTURAS_LISTARESPUESTAS_H