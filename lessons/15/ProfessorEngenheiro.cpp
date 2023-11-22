#include "ProfessorEngenheiro.hpp"

#include <iostream>

ProfessorEngenheiro::ProfessorEngenheiro(const std::string& nome, const unsigned long cpf, const float valorHora,
                                         const unsigned short cargaHoraria, const unsigned int numeroCrea)
    : Pessoa(nome, cpf), Professor(nome, cpf, valorHora, cargaHoraria), Engenheiro(nome, cpf, numeroCrea) {
    std::cout << "Professor Engenheiro criado!" << std::endl;
}

ProfessorEngenheiro::~ProfessorEngenheiro() {}
