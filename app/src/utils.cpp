#include <vector>
#include <string>
#include <regex>
#include "utils.hpp"

namespace utils
{
    std::string a_minusculas(const std::string &cadena)
    {
        auto copia = cadena;
        std::transform(copia.begin(), copia.end(), copia.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });
        return copia;
    }

    std::string sin_espacios(const std::string &cadena)
    {
        auto copia = cadena;
        copia.erase(std::remove(copia.begin(), copia.end(), ' '), copia.end());
        return copia;
    }

    std::string con_negativos_explicitos(const std::string &cadena)
    {
        return std::regex_replace(cadena, std::regex("-"), "+-");
    }

    std::vector<std::string> separar(const std::string &cadena, unsigned char delimitador)
    {
        auto start = 0u;
        auto end = cadena.find(delimitador);
        std::vector<std::string> valores;

        while (end != std::string::npos)
        {
            valores.push_back(cadena.substr(start, end - start));
            start = end + 1;
            end = cadena.find(delimitador, start);
        }

        valores.push_back(cadena.substr(start, end));
        return valores;
    }
}
