//
// Created by nakos on 03-10-2026.
//

#ifndef TALLER1_SISTEMA_H
#define TALLER1_SISTEMA_H
#include "include/struct/ArregloDinamicoTemas.h"
#include "include/struct/ArregloDinamicoUsuario.h"

/**
 * @class Sistema
 * @brief controla el funcionamiento principal del sistema
 */
class Sistema {
private:

    ArregloDinamicoUsuario usuarios;
    ArregloDinamicoTemas temas;

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
    void publicar();
    void estadisticas();

};


#endif //TALLER1_SISTEMA_H
