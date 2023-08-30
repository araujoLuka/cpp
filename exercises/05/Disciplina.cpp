#include "Disciplina.hpp"

// Construtores

Disciplina::Disciplina(std::string nomeDisciplina)
    : nome{nomeDisciplina}, numAlunos{0} {}

// Getters e Setters

std::string Disciplina::getNome() { return nome; }

void Disciplina::setNome(std::string novoNome) { nome = novoNome; }

int Disciplina::getCargaHoraria() { return cargaHoraria; }

void Disciplina::setCargaHoraria(unsigned int novaCarga) {
    cargaHoraria = novaCarga;
}

Pessoa *Disciplina::getProfessor() { return professor; }

void Disciplina::setProfessor(Pessoa *novoProf) { professor = novoProf; }

std::string Disciplina::getNomeProfessor() { return professor->getNome(); }

int Disciplina::getNumAlunos() { return numAlunos; }

// Funcoes membro

bool Disciplina::adicionarAluno(Pessoa *aluno) {
    if (numAlunos >= MAX_ALUNOS) return false;

    alunos[numAlunos] = aluno;
    numAlunos++;

    return true;
}

Pessoa **Disciplina::getVetorAlunos() { return alunos; }

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
