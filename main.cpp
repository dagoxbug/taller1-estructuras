//
// Created by killz on 9/27/2026.
//

#include "main.h"
#include <cstdlib>
#include <ctime>
#include "include/services/Sistema.h"

int main() {
    srand(time(nullptr));   // para que generarIdTema no repita la misma secuencia en cada ejecucion

    Sistema sistema;

    if (!sistema.cargarDatos()) {
        return 1;
    }

    sistema.iniciarSistema();
    return 0;
}