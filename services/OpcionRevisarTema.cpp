//
// Created by nakos on 04-10-2026.
//

#include "../include/services/OpcionRevisarTema.h"
#include <iostream>
#include <string>
#include <cctype>

    const std::string ENCABEZADO = "[---------- Foro Comunitario ----------]";
    const std::string SEPARADOR  = "----------------------------------------";

    /// Convierte un texto a mayusculas (para aceptar "ab123" o "a").
    std::string aMayusculas(std::string texto) {
        for (char& c : texto) {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }
        return texto;
    }

    /// Retorna el nombre del usuario con ese Id, o un aviso si no existe.
    std::string nombreDeUsuario(ArregloDinamicoUsuario& usuarios, int idUsuario) {
        Usuario* usuario = usuarios.buscarUsuario(idUsuario);
        if (usuario == nullptr) {
            return "(usuario eliminado)";
        }
        return usuario->getNombre();
    }

    /// Muestra el tema completo con todas sus respuestas y las opciones.
    void mostrarTema(Tema* tema, ArregloDinamicoUsuario& usuarios) {
        std::cout << "\n" << ENCABEZADO << "\n\n";
        std::cout << "Titulo: " << tema->getTitulo() << "\n";
        std::cout << "Usuario: " << nombreDeUsuario(usuarios, tema->getIdUsuario()) << "\n\n";
        std::cout << tema->getContenido() << "\n";
        std::cout << SEPARADOR << "\n";

        Respuesta* actual = tema->getRespuestas().getCabeza();
        if (actual == nullptr) {
            std::cout << "\nEste tema aun no tiene respuestas.\n";
        }
        while (actual != nullptr) {
            std::cout << "\nUsuario " << nombreDeUsuario(usuarios, actual->getIdUsuario())
                      << " responde:\n";
            std::cout << actual->getContenido() << "\n";
            std::cout << SEPARADOR << "\n";
            actual = actual->getSiguiente();
        }

        std::cout << "\nA) Comentar\n";
        std::cout << "B) Atras\n";
    }

    /// Pide el Id de un tema hasta que exista. Retorna nullptr si el usuario deja vacio.
    Tema* pedirTema(ArregloDinamicoTemas& temas) {
        std::cout << "\n" << ENCABEZADO << "\n\n";
        while (true) {
            std::cout << "Ingrese el Id del tema que desea revisar (deje vacio para volver):\n";
            std::string id;
            std::getline(std::cin, id);

            if (id.empty()) {
                return nullptr;
            }
            id = aMayusculas(id);

            Tema* tema = temas.buscarTema(id);
            if (tema != nullptr) {
                return tema;
            }
            std::cout << "Error: no existe un tema con Id " << id << ".\n\n";
        }
    }

    /// Pide la opcion A o B hasta que sea valida.
    std::string pedirOpcion() {
        while (true) {
            std::cout << "Seleccione una opcion:\n";
            std::string opcion;
            std::getline(std::cin, opcion);
            opcion = aMayusculas(opcion);

            if (opcion == "A" || opcion == "B") {
                return opcion;
            }
            std::cout << "Error: opcion invalida. Ingrese A o B.\n";
        }
    }

    /// Pide el contenido de la respuesta hasta que sea valido.
    std::string pedirContenidoRespuesta() {
        while (true) {
            std::cout << "\nIngrese su respuesta:\n";
            std::string contenido;
            std::getline(std::cin, contenido);

            if (contenido.empty()) {
                std::cout << "Error: la respuesta no puede estar vacia.\n";
                continue;
            }
            if (contenido.find_first_of(",_;") != std::string::npos) {
                std::cout << "Error: la respuesta no puede contener comas (,), "
                             "guiones bajos (_) ni punto y coma (;).\n";
                continue;
            }
            return contenido;
        }
    }


void opcionRevisarTema(ArregloDinamicoTemas& temas,
                       ArregloDinamicoUsuario& usuarios,
                       Usuario* usuarioActual) {
    Tema* tema = pedirTema(temas);
    if (tema == nullptr) {
        return; // el usuario decidio volver al menu
    }

    while (true) {
        mostrarTema(tema, usuarios);

        std::string opcion = pedirOpcion();
        if (opcion == "B") {
            return; // Atras: vuelve al menu principal
        }

        // Opcion A: Comentar
        std::string contenido = pedirContenidoRespuesta();
        int nuevoId = tema->getRespuestas().getUltimoId() + 1;

        Respuesta* respuesta = new Respuesta(nuevoId, usuarioActual->getId(), contenido);
        tema->getRespuestas().agregarAlInicio(respuesta);
        temas.moverAlInicio(tema->getId());

        std::cout << "\nRespuesta publicada con exito.\n";
        // el while vuelve a mostrar el tema, con la nueva respuesta primero
    }
}