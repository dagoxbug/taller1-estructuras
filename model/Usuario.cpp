//
// Created by nakos on 29-09-2026.
//

#include "../include/model/Usuario.h"

Usuario::Usuario(int id, std::string nombre) {
    this->id = id;
    this->nombre = nombre;
}
int Usuario::getId() {
    return this->id;
}
void Usuario::setId(int id) {
    this->id = id;
}
std::string Usuario::getNombre() {
    return this->nombre;
}
void Usuario::setNombre(std::string nombre) {
    this->nombre = nombre;
}
