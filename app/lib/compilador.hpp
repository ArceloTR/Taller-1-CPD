#ifndef COMPILADOR_HPP
#define COMPILADOR_HPP

#include <string>
#include <regex>
#include "polinomio.hpp"

/**
 * Tokens que se pueden encontrar en una expresión de monomio.
 */
enum Token
{
    EXPRESION = 0,
    SIGNO,
    COEFICIENTE,
    VARIABLE,
    GRADO,
};

class Compilador
{
public:
    using token_t = std::string;
    using tokens_t = std::vector<token_t>;

    std::string expresion;

    /**
     * Formato de un monomio.
     */
    static const std::regex formato_monomio;

    /**
     * Constructor de la clase Compilador.
     */
    Compilador(std::string expresion);

    /**
     * Función que compila la expresión en un polinomio.
     * @return El polinomio compilado a partir de la expresión.
     */
    Polinomio compilar() const;

private:
    /**
     * Función que determina si la expresión es válida.
     * @return true si la expresión es válida, false en caso contrario.
     */
    bool es_token_valido(const std::string &token) const;

    /**
     * Función que separa la expresión en tokens.
     * @return Los tokens extraídos de la expresión.
     */
    tokens_t separar() const;

    /**
     * Función que extrae componentes de un token.
     * @param token El token a extraer.
     * @return El resultado de la extracción de componentes.
     */
    std::smatch extraer_token(const std::string &token) const;

    /**
     * Función que convierte un token a monomio.
     * @return El monomio convertido a partir del token.
     */
    Monomio evaluar_token(const std::string &token) const;

    /**
     * Función que adapta la expresión para ser tokenizada.
     * @return La expresión adaptada.
     */
    std::string procesar() const;

    /**
     * Función que parsea el coeficiente de un monomio.
     * @param token_signo El token del signo del monomio.
     * @param token_coeficiente El token del coeficiente del monomio.
     * @return El coeficiente del monomio.
     */
    Monomio::coeficiente_t
    parse_coeficiente(const std::string &token_signo,
                      const std::string &token_coeficiente) const;

    /**
     * Función que parsea el grado de un monomio.
     * @param token_signo El token de la variable del monomio.
     * @param token_coeficiente El token del grado del monomio.
     * @return El grado del monomio.
     */
    Monomio::grado_t
    parse_grado(const std::string &token_variable,
                const std::string &token_grado) const;
};

#endif
