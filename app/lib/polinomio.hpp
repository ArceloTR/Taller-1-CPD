#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <vector>
#include <compare>
#include "monomio.hpp"

class Polinomio
{
public:
    using terminos_t = std::vector<Monomio>;
    terminos_t terminos;

    Monomio::grado_t grado() const;

    /**
     * Constructor de la clase Polinomio.
     */
    Polinomio(terminos_t terminos);

    /**
     * Función que calcula el valor del polinomio para un valor de x.
     * @return El valor del polinomio para un valor de x.
     */
    double evaluar(double x) const;

    /**
     * Función que calcula la raíz del polinomio utilizando el método Newton-Raphson.
     * @return La raíz del polinomio.
     */
    double raiz() const;

    /**
     * Función que calcula el derivado del polinomio.
     * @return El derivado del polinomio.
     */
    Polinomio derivado() const;

    /**
     * Operador de comparaciones de ordenamiento.
     * @param otro El polinomio comparado.
     */
    auto operator<=>(const Polinomio &otro) const {
        if (terminos < otro.terminos) return -1;
        if (terminos > otro.terminos) return 1;
        return 0;
    }

    /**
     * Operador de comparaciones de igualdad.
     * @param otro El polinomio comparado.
     */
    bool operator==(const Polinomio &otro) const = default;

    /**
     * Operador de salida.
     * @param out El stream de salida.
     * @param polinomio El polinomio de salida.
     * @return El stream de salida.
     */
    friend std::ostream& operator<<(std::ostream& out, const Polinomio& polinomio);
};

#endif
