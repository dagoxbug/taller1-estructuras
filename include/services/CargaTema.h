//
// Created by killz on 10/4/2026.
//

#ifndef TALLER1_CARGATEMA_H
#define TALLER1_CARGATEMA_H


#include <string>
#include "../struct/ArregloDinamicoUsuario.h"
#include "../struct/ArregloDinamicoTemas.h"

/**
 * @brief Lee temas.csv y almacena los temas y sus respuestas en las estructuras.
 *
 * Valida el formato de cada linea y que todos los usuarios referenciados
 * (autores de temas y de respuestas) existan. Ante el primer error,
 * muestra el detalle por pantalla y retorna false.
 *
 * @param rutaArchivo Ruta del archivo temas.csv.
 * @param usuarios Arreglo con los usuarios ya cargados.
 * @param temas Arreglo donde se guardaran los temas.
 * @return true si la carga fue exitosa, false si hubo algun error.
 */
bool cargarTemas(const std::string& rutaArchivo,
                 ArregloDinamicoUsuario& usuarios,
                 ArregloDinamicoTemas& temas);



#endif //TALLER1_CARGATEMA_H
