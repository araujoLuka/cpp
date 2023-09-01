#include "Disciplina.hpp"

#include <iostream>

// Construtores

Disciplina::Disciplina(std::string nome, Curso *curso)
    : nome{nome}, curso{curso} {}

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

std::string Disciplina::getNomeProfessor() {
    return this->professor->getNome();
}

int Disciplina::getNumAlunos() { return this->alunos.size(); }

Curso *Disciplina::getCurso() { return this->curso; }

std::map<int, Pessoa *> Disciplina::getAlunos() { return this->alunos; }

// Member functions

// Generate a unique ID for a student
int Disciplina::gerarId(Pessoa *aluno) {
    if (this->alunos.size() == 0) return 1;
    std::pair<int, Pessoa *> last{*(--this->alunos.end())};
    return last.first + 1;
}

// Add a student to the class
bool Disciplina::adicionarAluno(Pessoa *aluno) {
    if (this->alunos.size() >= MAX_ALUNOS) return false;

    int id = gerarId(aluno);
    
    this->alunos.insert({id, aluno});
    return true;
}

// Remove a student based on their object pointer
bool Disciplina::removerAluno(Pessoa *aluno) {
    if (this->alunos.size() == 0) return false;
    
    if (aluno == nullptr) return false;

    std::map<int, Pessoa*>::iterator it;
    for (it = this->alunos.begin(); it != this->alunos.end(); it++) {
        if (it->second == aluno) {
            this->alunos.erase(it);
            return true;
        }
    }
    return false;
}

// Remove a student based on their CPF
bool Disciplina::removerAluno(uint64_t cpf) {
    if (this->alunos.size() == 0) return false;

    if (cpf == 0) return false;

    std::map<int, Pessoa*>::iterator it;
    for (it = this->alunos.begin(); it != this->alunos.end(); it++) {
        if (it->second->getCpf() == cpf) {
            this->alunos.erase(it);
            return true;
        }
    }
    return false;
}

// Remove a student based on their ID
bool Disciplina::removerAlunoPorId(int id) {
    if (this->alunos.size() == 0) return false;

    if (id == 0) return false;

    if (this->alunos.find(id) == this->alunos.end()) return false;

    this->alunos.erase(id);
    return true;
}

// List all students in the class
void Disciplina::listarAlunos() {
    std::cout << "Turma: " << this->nome << '\n';
    std::cout << "Tamanho da turma: " << this->alunos.size() << '\n';
    std::cout << "Alunos da disciplina " << nome << ":\n";
    // list with const_iterator, 'cause we don't want to change the students
    std::map<int, Pessoa*>::const_iterator it;
    for (it = alunos.cbegin(); it != alunos.cend(); it++) {
        std::cout << it->first << '\t'
                  << it->second->getNome() << '\t'
                  << it->second->getIdade() << '\t'
                  << it->second->getCpf() << '\n';
    }
}
