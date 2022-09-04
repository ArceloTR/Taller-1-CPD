#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>

namespace utils
{
    /**
     * Convierte una cadena a minúsculas.
     * @param cadena Cadena a convertir.
     * @return std::string Cadena convertida.
     */
    std::string a_minusculas(const std::string &cadena);

    /**
     * Elimina los espacios de una cadena.
     * @param cadena Cadena a convertir.
     * @return std::string Cadena convertida.
     */
    std::string sin_espacios(const std::string &cadena);

    /**
     * Función que agrega signos positivos a los negativos.
     * @return La expresión adaptada.
     */
    std::string con_negativos_explicitos(const std::string &cadena);

    /**
     * Función que separa una cadena en un vector de cadenas.
     * @param cadena Cadena a separar.
     * @param delimitador Carácter delimitador.
     * @return Vector de cadenas.
     */
    std::vector<std::string> separar(const std::string &cadena, unsigned char delimitador);
}

#endif
