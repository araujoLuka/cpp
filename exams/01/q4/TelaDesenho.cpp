#include "TelaDesenho.hpp"

TelaDesenho::TelaDesenho() {
    this->formas = new std::list<const Forma*>();
}

TelaDesenho::~TelaDesenho() {
    std::list<const Forma*>::iterator it{this->formas->begin()};
    for (; it != this->formas->end(); ++it) {
        delete *it;
    }
    delete this->formas;
}

void TelaDesenho::adicionarForma(const Forma* const forma) {
    this->formas->push_back(forma);
}

const double TelaDesenho::calcularAreaTotal() const {
    double areaTotal = 0.0;

    std::list<const Forma*>::const_iterator it{this->formas->begin()};
    for (; it != this->formas->end(); ++it) {
        areaTotal += (*it)->area();
    }

    return areaTotal;
}
