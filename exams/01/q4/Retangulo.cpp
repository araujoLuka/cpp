#include "Retangulo.hpp"

Retangulo::Retangulo() : largura(0), altura(0) {}

Retangulo::Retangulo(const int largura, const int altura) : Retangulo{} {
    this->setLargura(largura);
    this->setAltura(altura);
}

const int Retangulo::getLargura() const { return this->largura; }

const int Retangulo::getAltura() const { return this->altura; }

void Retangulo::setLargura(const int largura) {
    if (largura >= 0) {
        this->largura = largura;
    }
}

void Retangulo::setAltura(const int altura) {
    if (altura >= 0) {
        this->altura = altura;
    }
}

const double Retangulo::area() const {
    double area = (double)(this->getLargura() * this->getAltura());
    return area;
}
