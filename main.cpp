//
// Created by killz on 9/27/2026.
//

#include "main.h"
#include <sstream>
#include <fstream>
#include <iostream>

#include "include/model/Usuario.h"
using namespace std;

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

    }

    while (std::getline(file2, linea)){ //temas
        std::stringstream ss(linea);
        std::string id2,titulo,contenido,idusuario,respuestas;

        std::getline(ss, id2, ';');
        std::getline(ss, titulo, ';');
        std::getline(ss, contenido, ';');
        std::getline(ss, idusuario, ';');
        std::getline(ss, respuestas, ';');
    }
    return 0;
}
