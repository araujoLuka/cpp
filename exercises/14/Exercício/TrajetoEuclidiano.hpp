#ifndef TRAJETO_EUCLIDIANO_HPP
#define TRAJETO_EUCLIDIANO_HPP

#include "Trajeto.hpp"

class TrajetoEuclidiano: public Trajeto{
    public:
        using Trajeto::Trajeto;
        virtual ~TrajetoEuclidiano() = default;
    protected:
        virtual double calcularDistanciaPontos(const Ponto* const p1, const Ponto* const p2) const override;
};

#endif
