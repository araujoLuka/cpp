#include "Professor.hpp"

#include <iomanip>
#include <iostream>

Professor::Professor(const std::string& nome, const unsigned long cpf,
               const unsigned int valorHora, const unsigned short cargaHoraria)
        :Pessoa(nome, cpf), valorHora(valorHora), cargaHoraria(cargaHoraria) {
}

void Professor::setValorHora(const unsigned int valorHora){
    if(valorHora > 0)
        this->valorHora = valorHora;
}

unsigned int Professor::getValorHora() const{
    return this->valorHora;
}

void Professor::setCargaHoraria(const unsigned short cargaHoraria){
    if(cargaHoraria > 0)
        this->cargaHoraria = cargaHoraria;
}

unsigned short Professor::getCargaHoraria() const{
    return this->cargaHoraria;
}

unsigned int Professor::getSalario() const{
    //assumindo que um mês tem aprox 4.5 semanas
    return valorHora * cargaHoraria * 4.5;
}

void Professor::printSalario(){
    int reais = this->getSalario() / 100;
    int centavos = this->getSalario() % 100;
    std::cout << "Salario: R$ " << reais << ','
        << std::setfill('0') << std::setw(2) << centavos << std::endl;
}
