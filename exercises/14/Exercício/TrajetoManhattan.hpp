#ifndef TRAJETO_MANHATTAN_HPP
#define TRAJETO_MANHATTAN_HPP

#include "Trajeto.hpp"

class TrajetoManhattan: public Trajeto{
    public:
        using Trajeto::Trajeto;
        virtual ~TrajetoManhattan() = default;
    protected:
        virtual double calcularDistanciaPontos(const Ponto* const p1, const Ponto* const p2) const override;
};

#endif
