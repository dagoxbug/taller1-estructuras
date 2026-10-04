//
// Created by nakos on 03-10-2026.
//

#include "../include/services/Sistema.h"


Usuario* Sistema::autenticarUsuario() {
    int id;
    usuarioActual = nullptr;

    // preguntar hasta que el usuario se pueda autenticar
    while (usuarioActual == nullptr) {

        std::cout << "Ingrese su ID: ";
        std::cin >> id;

        usuarioActual = usuarios.buscarUsuario(id);

        if (usuarioActual == nullptr) {
            std::cout << "Error: usuario no encontrado \n";
        }
    }

    std::cout << "Bienvenido/a " << usuarioActual->getId() << "\n";
    return usuarioActual;
}

void Sistema::iniciarSistema() {

    usuarioActual = autenticarUsuario();

    mostrarMenu();
}

void Sistema::mostrarMenu() {

    std::cout << "[---------- Foro Comunitario ----------]\n";
    // falta agregar todos los temas con sus id
}

void Sistema::eliminarUsuario() {

    std::cout << "[---------- Usuarios disponibles ----------]\n";
    usuarios.mostrarUsuarios();

    int id;

    std::cout << "Ingrese el ID del usuario que desea eliminar: ";
    std::cin >> id;

    // verificar que el usuario no se elimine a si mismo
    if (usuarioActual->getId() == id) {
        std::cout << "No puedes eliminarte a ti mismo \n";
        return;
    }
    usuarios.eliminarUsuario(id);
}
