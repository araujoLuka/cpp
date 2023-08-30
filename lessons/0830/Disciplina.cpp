#include "Disciplina.hpp"

#include <iostream>

// Construtores

Disciplina::Disciplina(std::string nome, Curso *curso)
    : nome{nome}, numAlunos{0}, curso{curso} {}

// Getters e Setters

std::string Disciplina::getNome() { return nome; }
void Disciplina::setNome(std::string nome) { this->nome = nome; }

int Disciplina::getCargaHoraria() { return cargaHoraria; }
void Disciplina::setCargaHoraria(unsigned int cargaHoraria) {
    this->cargaHoraria = cargaHoraria;
}

Pessoa *Disciplina::getProfessor() { return professor; }
void Disciplina::setProfessor(Pessoa *professor) {
    this->professor = professor;
}

std::string Disciplina::getNomeProfessor() { return professor->getNome(); }

int Disciplina::getNumAlunos() { return numAlunos; }

Curso *Disciplina::getCurso() { return curso; }

// Funcoes membro

bool Disciplina::adicionarAluno(Pessoa *aluno) {
    if (numAlunos >= MAX_ALUNOS) return false;

    alunos[numAlunos] = aluno;
    numAlunos++;

    return true;
}

Pessoa **Disciplina::getVetorAlunos() { return alunos; }

void Disciplina::listarAlunos() {
    std::cout << "Alunos da disciplina " << nome << ":\n";
    for (int i = 0; i < numAlunos; i++) {
        std::cout << i + 1 << '\t' << alunos[i]->getNome() << '\t'
                  << alunos[i]->getIdade() << '\t' << alunos[i]->getCpf()
                  << '\n';
    }
}

bool Disciplina::removerAluno(Pessoa *aluno) {
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i] == aluno) {
            alunos[i] = alunos[numAlunos - 1];
            numAlunos--;
            return true;
        }
    }
    return false;
}

bool Disciplina::removerAluno(uint64_t cpfAluno) {
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i]->getCpf() == cpfAluno) {
            alunos[i] = alunos[numAlunos - 1];
            numAlunos--;
            return true;
        }
    }
    return false;
}
