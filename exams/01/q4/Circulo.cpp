#include "Circulo.hpp"

Circulo::Circulo() : raio(0) {}

Circulo::Circulo(const int raio) : Circulo{} {
    this->setRaio(raio);
}

const int Circulo::getRaio() const {
    return this->raio;
}

void Circulo::setRaio(const int raio) {
    if (raio > 0) {
        this->raio = raio;
    }
}

const double Circulo::area() const {
    return PI * this->raio * this->raio;
}
