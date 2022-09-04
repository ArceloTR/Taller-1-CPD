#include <iostream>
#include <cmath>
#include "monomio.hpp"

Monomio::Monomio(coeficiente_t coeficiente, grado_t grado)
    : coeficiente(coeficiente), grado(grado)
{
}

bool Monomio::es_cero() const
{
    return this->coeficiente == 0;
}

bool Monomio::es_constante() const
{
    return this->grado == 0;
}

double Monomio::evaluar(double x) const
{
    return this->coeficiente * std::pow(x, this->grado);
}

Monomio Monomio::derivado() const
{
    // La derivada de un monomio constante es 0.
    if (this->es_constante())
        return {0.0, 0};

    return {this->coeficiente * this->grado, this->grado - 1};
}

std::ostream &operator<<(std::ostream &out, const Monomio &monomio)
{
    return out << '{' << monomio.coeficiente << ", " << monomio.grado << '}';
}
