//
// Created by killz on 10/4/2026.
//

#include "../include/services/CargaTema.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

    /// Quita el '\r' final que dejan los archivos guardados
    void quitarRetorno(std::string& texto) {
        if (!texto.empty() && texto.back() == '\r') {
            texto.pop_back();
        }
    }

    /// Retorna true si el texto no esta vacio y son solo digitos.
    bool esNumero(const std::string& texto) {
        if (texto.empty() || texto.size() > 9) {
            return false;
        }
        for (char c : texto) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                return false;
            }
        }
        return true;
    }

    /// Retorna true si el Id tiene 2 letras seguidas de 3 digitos.
    bool esIdTemaValido(const std::string& id) {
        if (id.size() != 5) {
            return false;
        }
        for (int i = 0; i < 2; i++) {
            if (!std::isalpha(static_cast<unsigned char>(id[i]))) {
                return false;
            }
        }
        for (int i = 2; i < 5; i++) {
            if (!std::isdigit(static_cast<unsigned char>(id[i]))) {
                return false;
            }
        }
        return true;
    }

    /// Muestra un error de carga indicando la linea del archivo.
    void mostrarError(int numeroLinea, const std::string& mensaje) {
        std::cout << "Error en temas.csv (linea " << numeroLinea << "): "
                  << mensaje << "\n";
    }

    /**
     * Separa el campo de respuestas por ',' y cada respuesta por '_',
     * y las agrega a la lista del tema. Retorna false ante el primer error.
     */
    bool cargarRespuestas(const std::string& campo, Tema* tema,
                          ArregloDinamicoUsuario& usuarios, int numeroLinea) {
        std::stringstream streamCampo(campo);
        std::string pieza;

        while (std::getline(streamCampo, pieza, ',')) {
            if (pieza.empty()) {
                continue; // tolera comas sobrantes, ej: "1_4_hola,"
            }

            std::stringstream streamPieza(pieza);
            std::string idRespuesta, idAutor, contenido;

            std::getline(streamPieza, idRespuesta, '_');
            std::getline(streamPieza, idAutor, '_');
            std::getline(streamPieza, contenido); // el resto; puede quedar vacio

            if (!esNumero(idRespuesta)) {
                mostrarError(numeroLinea, "respuesta \"" + pieza +
                             "\" del tema " + tema->getId() +
                             " tiene un Id invalido.");
                return false;
            }
            if (!esNumero(idAutor)) {
                mostrarError(numeroLinea, "respuesta \"" + pieza +
                             "\" del tema " + tema->getId() +
                             " tiene un Id de usuario invalido.");
                return false;
            }
            if (usuarios.buscarUsuario(std::stoi(idAutor)) == nullptr) {
                mostrarError(numeroLinea, "la respuesta " + idRespuesta +
                             " del tema " + tema->getId() +
                             " pertenece al usuario " + idAutor +
                             ", que no existe.");
                return false;
            }

            Respuesta* respuesta = new Respuesta(std::stoi(idRespuesta),
                                                 std::stoi(idAutor),
                                                 contenido);
            tema->getRespuestas().agregarAlInicio(respuesta);
        }
        return true;
    }

bool cargarTemas(const std::string& rutaArchivo,
                 ArregloDinamicoUsuario& usuarios,
                 ArregloDinamicoTemas& temas) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cout << "Error: no se pudo abrir el archivo " << rutaArchivo << "\n";
        return false;
    }

    std::string linea;
    int numeroLinea = 0;

    while (std::getline(archivo, linea)) {
        numeroLinea++;
        quitarRetorno(linea);
        if (linea.empty()) {
            continue; // ignora lineas en blanco
        }

        std::stringstream streamLinea(linea);
        std::string id, titulo, contenido, idUsuario, respuestas;

        std::getline(streamLinea, id, ';');
        std::getline(streamLinea, titulo, ';');
        std::getline(streamLinea, contenido, ';');
        std::getline(streamLinea, idUsuario, ';');
        std::getline(streamLinea, respuestas); // el resto de la linea; puede estar vacio

        // ---- Validaciones del tema ----
        if (!esIdTemaValido(id)) {
            mostrarError(numeroLinea, "el Id \"" + id +
                         "\" no tiene el formato de 2 letras y 3 digitos.");
            return false;
        }
        if (temas.existeId(id)) {
            mostrarError(numeroLinea, "el Id " + id + " esta repetido.");
            return false;
        }
        if (titulo.empty()) {
            mostrarError(numeroLinea, "el tema " + id + " no tiene titulo.");
            return false;
        }
        if (contenido.empty()) {
            mostrarError(numeroLinea, "el tema " + id + " no tiene contenido.");
            return false;
        }
        if (!esNumero(idUsuario)) {
            mostrarError(numeroLinea, "el tema " + id +
                         " tiene un Id de usuario invalido.");
            return false;
        }
        if (usuarios.buscarUsuario(std::stoi(idUsuario)) == nullptr) {
            mostrarError(numeroLinea, "el tema " + id + " pertenece al usuario " +
                         idUsuario + ", que no existe.");
            return false;
        }

        // ---- Crear el tema y sus respuestas ----
        Tema* tema = new Tema(id, titulo, contenido, std::stoi(idUsuario));

        if (!respuestas.empty() &&
            !cargarRespuestas(respuestas, tema, usuarios, numeroLinea)) {
            delete tema; // libera el tema y las respuestas que alcanzo a cargar
            return false;
        }

        temas.agregarTema(tema);
    }

    return true;
}