#include "Disciplina.hpp"

#include <iostream>

#include "SalaAula.hpp"

Disciplina::Disciplina(std::string nome) : nome{nome}, sala{nullptr} {}

Disciplina::Disciplina(std::string nome, SalaAula* sala)
    : nome{nome} {
    this->setSala(sala);
}

std::string Disciplina::getNome() { return nome; }

void Disciplina::setNome(std::string nome) { this->nome = nome; }

int Disciplina::getCargaHoraria() { return this->cargaHoraria; }

void Disciplina::setCargaHoraria(unsigned int carga) {
    this->cargaHoraria = carga;
}

Pessoa* Disciplina::getProfessor() { return this->professor; }

void Disciplina::setProfessor(Pessoa* prof) { this->professor = prof; }

SalaAula* Disciplina::getSala() { return this->sala; }

void Disciplina::setSala(SalaAula* sala) {
    if (this->sala != nullptr and !this->sala->disciplinas.empty())
        this->sala->disciplinas.remove(this);
    this->sala = sala;
    if (this->sala != nullptr)
        this->sala->disciplinas.push_back(this);
}

void Disciplina::imprimirDados(std::string& cabecalho,
                               unsigned int cargaTotalCurso) {
    double pctCurso = (double)this->cargaHoraria / cargaTotalCurso;
    pctCurso = pctCurso * 100;
    std::cout << cabecalho << '\n';
    std::cout << "Disciplina: " << this->nome << '\n';
    std::cout << "Carga: " << this->cargaHoraria << '\n';
    std::cout << "Porcentagem do curso: " << pctCurso << "%" << '\n';
    std::cout << "Professor: " << this->professor->getNome() << '\n';
}
