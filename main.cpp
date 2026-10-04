//
// Created by killz on 9/27/2026.
//

#include "main.h"
#include <sstream>
#include <fstream>
#include <iostream>

#include "include/model/Usuario.h"
#include "include/struct/ArregloDinamicoUsuario.h"
#include "include/struct/ArregloDinamicoTemas.h"   // AGREGADO
#include "include/services/CargaTema.h"           // AGREGADO (si tu archivo es CargaTema.h, cambia el nombre)

ArregloDinamicoUsuario arregloUsuarios;
ArregloDinamicoTemas arregloTemas;                 // AGREGADO

int main() {

    std::fstream file("usuarios.csv");
    std::fstream file2("temas.csv");

    if (!file.is_open()) {
        std::cout << "Error al abrir el archivo usuarios.csv";
        exit(1);
    }
    if (!file2.is_open()) {
        std::cout << "Error al abrir el archivo temas.csv";
        return 1;
    }

    std::string linea;
    while (std::getline(file, linea)){ //usuarios
        std::stringstream ss(linea);
        std::string id,nombre;

        std::getline(ss, id, ';');
        std::getline(ss, nombre, ';');
        std::cout << id << " " << nombre << "\n";
        Usuario* usuario = new Usuario(stoi(id), nombre);

        arregloUsuarios.agregarUsuario(usuario);

    }
    //carga real de temas y respuestas (con validaciones)
    if (!cargarTemas("temas.csv", arregloUsuarios, arregloTemas)) {
        return 1;
    }

    // AGREGADO - PRUEBA TEMPORAL: borrar cuando la carga funcione
    std::cout << "\nCarga exitosa.\n\n";
    arregloTemas.mostrarTemas();

    return 0;
}