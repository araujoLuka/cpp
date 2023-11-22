#include "Professor.hpp"
#include <iostream>

Professor::Professor(const std::string& nome, const uint64_t cpf,
                     const unsigned int valorHora, const unsigned short cargaHoraria)
    : Pessoa{nome, cpf}, valorHora{valorHora}, cargaHoraria{cargaHoraria} {
    std::cout << "Construindo Professor" << std::endl;
}

Professor::~Professor() {}

unsigned int Professor::getValorHora() const { return valorHora; }

void Professor::setValorHora(const unsigned int valorHora) { this->valorHora = valorHora; }

unsigned int Professor::getCargaHoraria() const { return cargaHoraria; }

void Professor::setCargaHoraria(const unsigned short cargaHoraria) { 
    if (cargaHoraria > 0) 
        this->cargaHoraria = cargaHoraria;
};

unsigned int Professor::getSalario() const { 
    // assumindo que o professor trabalha 4.5 semanas por mês
    return valorHora * cargaHoraria * 4.5; 
}
