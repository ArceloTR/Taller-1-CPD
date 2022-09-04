#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "polinomio.hpp"

// EPSILON es equivalente al grado de presición.
#define EPSILON 0.001

Polinomio::Polinomio(terminos_t terminos) : terminos(terminos)
{
}

Monomio::grado_t Polinomio::grado() const
{
    // Encuentra el monomio de grado mayor.
    auto mayor = std::max_element(this->terminos.begin(), this->terminos.end(),
                                  [](const Monomio &lhs, const Monomio &rhs)
                                  { return lhs < rhs; });
    return mayor->grado;
}

double Polinomio::evaluar(double x) const
{
    auto resultado = 0.0;

    for (const auto &monomio : this->terminos)
        resultado += monomio.evaluar(x);

    return resultado;
}

double Polinomio::raiz() const
{
    // Calcula el cociente de la función evaluada, dividida 
    // entre la derivada de la función evaluada. 
    const auto derivado = this->derivado();
    double x = 0.0, fx, fdx;

    while (std::fabs(fx = this->evaluar(x)) >= EPSILON)
    {
        fdx = derivado.evaluar(x);

        if (fdx == 0.0)
            throw std::runtime_error("La derivada del polinomio es cero. "
                                     "El método Newton-Raphson no converge.");

        x -= fx / fdx;
    }

    return x;
}

Polinomio Polinomio::derivado() const
{
    terminos_t derivados;

    for (const auto &monomio : this->terminos)
    {
        auto derivado = monomio.derivado();

        // No agregar a la lista de términos aquellos monomios que sean cero.
        if (!derivado.es_cero())
            derivados.push_back(derivado);
    }

    return Polinomio(derivados);
}

std::ostream &operator<<(std::ostream &out, const Polinomio &polinomio)
{
    for (auto monomio : polinomio.terminos)
        out << monomio << " ";

    return out;
}
