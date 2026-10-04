//
// Created by nakos on 29-09-2026.
//

#ifndef TALLER1_ESTRUCTURAS_RESPUESTA_H
#define TALLER1_ESTRUCTURAS_RESPUESTA_H

#include <string>

/**
 * @class Respuesta
 * @brief Nodo de la lista enlazada simple que representa una respuesta a un tema.
 */
class Respuesta {
private:
    int id;                 /// Identificador correlativo de la respuesta dentro del tema
    int idUsuario;          /// Identificador del usuario que escribio la respuesta
    std::string contenido;  /// Texto de la respuesta (puede estar vacio)
    Respuesta* siguiente;   /// Puntero al siguiente nodo de la lista (nullptr si es el ultimo)

public:
    /**
     * @brief Crea una respuesta sin nodo siguiente.
     * @param id Identificador correlativo de la respuesta.
     * @param idUsuario Identificador del usuario que la escribio.
     * @param contenido Texto de la respuesta.
     */
    Respuesta(int id, int idUsuario, const std::string& contenido);

    /// Getters y Setters
    int getId() const;
    int getIdUsuario() const;
    std::string getContenido() const;
    Respuesta* getSiguiente() const; ///< Obtiene el siguiente nodo de la lista. Retorna Puntero a la siguiente respuesta, o nullptr si no hay.
    void setSiguiente(Respuesta* siguiente); ///< Cambia el nodo al que apunta esta respuesta. Parametro siguiente--> Puntero a la nueva respuesta siguiente.
};

#endif //TALLER1_ESTRUCTURAS_RESPUESTA_H