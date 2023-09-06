#include "Disciplina.hpp"
#include "SalaAula.hpp"

#include <iostream>

Disciplina::Disciplina(std::string nome) : nome{nome}, sala{nullptr} {}

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
    if (this->sala == sala) return;

    if (this->sala != nullptr)
        this->sala->disciplinas.remove(this);
    this->sala = sala;
    if (this->sala != nullptr)
        this->sala->disciplinas.push_back(this);
}

void Disciplina::imprimirDados(std::string& cabecalho,
                               unsigned int cargaTotalCurso) {
    double pctCurso = (double)this->cargaHoraria / cargaTotalCurso;
    pctCurso = pctCurso * 100;
    std::cout << cabecalho << std::endl;
    std::cout << "Disciplina: " << this->nome << std::endl;
    std::cout << "Carga: " << this->cargaHoraria << std::endl;
    std::cout << "Porcentagem do curso: " << pctCurso << "%" << std::endl;
    std::cout << "Professor: " << this->professor->getNome() << std::endl;
}
