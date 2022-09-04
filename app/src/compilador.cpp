#include <iostream>
#include <charconv>
#include <regex>
#include <algorithm>
#include "utils.hpp"
#include "compilador.hpp"
#include "monomio.hpp"

#define FORMATO_MONOMIO "^([\\-\\+])?(\\d*\\.?\\d+)?(?:(x)(?:(?:\\*\\*)([0-9]))?)?$"

const std::regex Compilador::formato_monomio = std::regex(FORMATO_MONOMIO);

Compilador::Compilador(std::string expresion)
{
    using namespace utils;
    this->expresion = con_negativos_explicitos(a_minusculas(sin_espacios(expresion)));
}

Compilador::tokens_t Compilador::separar() const
{
    return utils::separar(this->expresion, '+');
}

std::smatch Compilador::extraer_token(const std::string &token) const
{
    return *std::sregex_iterator(token.begin(), token.end(),
                                 Compilador::formato_monomio);
}

// @TODO Implementar método.
Monomio Compilador::evaluar_token(const std::string &token) const
{
    if (!this->es_token_valido(token))
        throw std::invalid_argument("El token no es válido: " + token);

    std::smatch match = this->extraer_token(token);

    auto coeficiente = this->parse_coeficiente(match[Token::SIGNO],
                                               match[Token::COEFICIENTE]);

    auto grado = this->parse_grado(match[Token::VARIABLE],
                                   match[Token::GRADO]);

    return {coeficiente, grado};
}

Monomio::coeficiente_t
Compilador::parse_coeficiente(const std::string &token_signo,
                              const std::string &token_coeficiente) const
{
    // Si el token del coeficiente está vacío, el coeficiente es 1.0.
    auto token_coeficiente_explicito = token_coeficiente.empty() ? "1.0" : token_coeficiente;
    return std::stod(token_signo + token_coeficiente_explicito);
}

Monomio::grado_t
Compilador::parse_grado(const std::string &token_variable,
                        const std::string &token_grado) const
{
    // Si el token del grado está vacío, el grado es 0 si, a su vez, el token de
    // la variable está vacío, y 1 en caso contrario.
    // Ej: "2" -> grado 0, "2x" -> grado 1.
    if (token_grado.empty())
        return !token_variable.empty();

    return std::stoul(token_grado);
}

bool Compilador::es_token_valido(const std::string &token) const
{
    return std::regex_match(token, Compilador::formato_monomio);
}

Polinomio Compilador::compilar() const
{
    Polinomio::terminos_t terminos;

    for (const auto &token : this->separar())
        terminos.push_back(this->evaluar_token(token));

    return {terminos};
}
