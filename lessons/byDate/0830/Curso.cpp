#include "Curso.hpp"

Curso::Curso() : nome{"Sem nome"}, cargaHoraria{2500}, anoCriacao{2023} {}

Curso::Curso(std::string nome) : nome{nome}, cargaHoraria{2500}, anoCriacao{2023} {}

std::string Curso::getNome() { return nome; }
void Curso::setNome(std::string nome) { this->nome = nome; }

int Curso::getCargaHoraria() { return cargaHoraria; }
void Curso::setCargaHoraria(uint16_t cargaHoraria) { this->cargaHoraria = cargaHoraria; }

int Curso::getAnoCriacao() { return anoCriacao; }
void Curso::setAnoCriacao(uint16_t anoCriacao) { this->anoCriacao = anoCriacao; }
