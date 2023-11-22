#include "TrajetoEuclidiano.hpp"
#include <cmath>
#include <iostream>

double TrajetoEuclidiano::calcularDistanciaPontos(const Ponto* const p1, const Ponto* const p2) const{
    return std::sqrt(std::pow(p1->getCoordX() - p2->getCoordX(), 2) + std::pow(p1->getCoordY() - p2->getCoordY(), 2));
}
