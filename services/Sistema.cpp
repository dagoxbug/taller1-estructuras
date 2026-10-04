//
// Created by nakos on 03-10-2026.
//

#include "../include/services/Sistema.h"
#include "../include/services/OpcionRevisarTema.h"


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
    std::cout << "Temas: \n";
    temas.mostrarTemas();
    std::cout << "A) Revisar un tema\n";
    std::cout << "B) Eliminar usuario\n";
    std::cout << "C) Publicar\n";
    std::cout << "D) Estadisticas\n";
    std::cout << "E) Salir\n";

    char opcion;

    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
        case 'A':
            opcionRevisarTema(temas, usuarios, usuarioActual);
            break;

        case 'B':
            eliminarUsuario();
            break;

        case 'C':
            //publicar
            break;

        case 'D':
            //estadisticas
            break;

        case 'E':
            //salir
            break;

        default:
            std::cout << "Opcion no valida\n";
    }

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

    Usuario* usuario = usuarios.buscarUsuario(id);

    if (usuario == nullptr) {
        std::cout << "Error: usuario no existe \n";
        return;
    }

    // guardamos el nombre del usuario a eliminar
    std::string nombre = usuario->getNombre();

    int cantidadTemas = temas.contarTemasPorUsuario(id);
    int cantidadRespuestas = respuestas.contarRespuestaPorUsuario(id);

    // mostrar informacion del usuario a eliminar
    std::cout << "El usuario " << nombre << " ha creado " << cantidadTemas << " temas \n";
    std::cout << "Ha realizado " << cantidadRespuestas << " respuestas.\n";

    char confirmacion;

    while (true) {

        std::cout << "¿Desea eliminar al usuario? (s/n): ";
        std::cin >> confirmacion;

        // si se confirma que se desea eliminar el usuario
        if (confirmacion == 's' || confirmacion == 'S') {
            temas.eliminarTemasPorUsuario(id);
            respuestas.eliminarRespuestasPorUsuario(id);
            usuarios.eliminarUsuario(id);
            std::cout << "Usuario " << nombre << "eliminado con exito \n";
            break;
        }

        if (confirmacion == 'n' || confirmacion == 'N') {
            // cancelar y volver al menú
            return;
        }

        std::cout << "Opción no válida. Ingrese s o n.\n";
    }
}

void Sistema::publicar() {
    std::string titulo;
    std::string contenido;

    std::cout << "[---------- Foro Comunitario ----------]\n";
    std::cout << "Ingrese el titulo: \n";
    std::getline(std::cin, titulo);

    // preguntar hasta que el titulo no quede vacio
    while (titulo.empty()) {
        std::cout << "El titulo no puede estar vacio.\n";
        std::cout << "Ingrese el titulo: ";
        std::getline(std::cin, titulo);
    }

    std::cout << "Ingrese el contenido: \n";
    std::getline(std::cin, contenido);

    //preguntar hasta que el contenido no quede vacio
    while (contenido.empty()) {
        std::cout << "El contenido no puede estar vacio.\n";
        std::cout << "Ingrese el contenido: ";
        std::getline(std::cin, contenido);
    }

    std::string idTema = generarIdTema();
    std::cout << "Tema publicado con ID: " << idTema << "\n";

    //creamos el tema con su respectivo id e id del usuario actual
    Tema* tema = new Tema(idTema, titulo, contenido,
        usuarioActual->getId());

    // agregamos el tema al arreglo como el mas reciente
    temas.agregarTema(tema);
}

std::string Sistema::generarIdTema() {
    std::string id;

    do {
        id = "";

        //id con 2 letras mayusculas y 3 numeros
        id += 'A' + rand() % 26;
        id += 'A' + rand() % 26;

        id += '0' + rand() % 10;
        id += '0' + rand() % 10;
        id += '0' + rand() % 10;
    } while (temas.existeTema(id));

    return id;
}

void Sistema::estadisticas() {
    std::cout << "[---------- Estadísticas ----------]\n";
    std::cout << "Usuario con mas respuestas: ";
    std::cout << "Tema con mayor cantidad de respuestas: ";
    std::cout << "Número de expansiones: " << usuarios.getExpansiones() << "\n";
}
