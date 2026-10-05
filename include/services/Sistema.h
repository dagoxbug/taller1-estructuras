//
// Created by nakos on 03-10-2026.
//

#ifndef TALLER1_SISTEMA_H
#define TALLER1_SISTEMA_H
#include "include/struct/ArregloDinamicoTemas.h"
#include "include/struct/ArregloDinamicoUsuario.h"
#include "include/struct/ListaRespuestas.h"

/**
 * @class Sistema
 * @brief controla el funcionamiento principal del sistema
 */
class Sistema {
private:

    ArregloDinamicoUsuario usuarios;
    ArregloDinamicoTemas temas;
    ListaRespuestas respuestas;

    /**
     * @brief Usuario que se encuentra actualmente autenticado
     */
    Usuario* usuarioActual;

public:
    /**
     * @brief Constructor de la clase sistema
     */
    Sistema();

    /**
     * @brief Inicia el funcionamiento del sistema.
     *
     * Realiza las operaciones necesarias para iniciar el sistema,
     * autenticar al usuario y posteriormente mostrar el menú principal.
     */
    void iniciarSistema();

    /**
     * @brief Autentica a un usuario mediante su identificador.
     *
     * Solicita el ID del usuario y verifica que exista dentro del
     * arreglo de usuarios. Si el ID no es válido, vuelve a solicitarlo.
     *
     * @return Usuario* Puntero al usuario que ha sido autenticado.
     */
    Usuario* autenticarUsuario();

    /**
     * @brief Muestra el menú principal del sistema.
     *
     * Permite al usuario seleccionar las diferentes operaciones
     * disponibles en el sistema.
     */
    void mostrarMenu();

    /**
     * @brief Elimina un usuario del sistema.
     *
     * Solicita el ID del usuario que se desea eliminar y verifica
     * que no corresponda al usuario actualmente autenticado.
     */
    void eliminarUsuario();

    void revisarTema();

    /**
    * @brief Permite al usuario publicar un nuevo tema en el foro.
    *
    * Solicita y valida el título y contenido del tema, genera un ID unico
    * y lo agrega al arreglo de temas asociándolo al usuario actual.
    */
    void publicar();
    void estadisticas();

    /**
    * @brief Genera un identificador aleatorio para un tema.
    *
    * El identificador está compuesto por dos letras mayúsculas
    * y tres números. Se verifica que el identificador generado
    * no exista previamente entre los temas registrados.
    *
    * @return Un identificador único para el tema.
    */
    std::string generarIdTema();

    /**
     * @brief Muestra el o los usuarios con mayor cantidad de respuestas.
     *
     * Recorre las respuestas de todos los temas, cuenta las respuestas
     * realizadas por cada usuario y muestra aquellos que tengan la mayor
     * cantidad. En caso de empate, muestra todos los usuarios correspondientes.
     */
    void usuarioConMasRespuestas();

    /**
     * @brief Muestra el o los temas con mayor cantidad de respuestas.
     *
     * Recorre todos los temas del foro y determina cuál o cuáles tienen
     * la mayor cantidad de respuestas. En caso de empate, muestra todos
     * los temas que tengan la misma cantidad máxima de respuestas.
     *
     * Para cada tema se muestra su identificador, título y autor.
     */
    void temaConMasRespuestas();

};


#endif //TALLER1_SISTEMA_H
