#include "SalaAula.hpp"

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
	:nome{nome}, capacidade{capacidade}{
}
    
std::string SalaAula::getNome(){
	return this->nome;
}

void SalaAula::setNome(std::string nome){
	this->nome = nome;
}

unsigned int SalaAula::getCapacidade(){
	return this->capacidade;
}

void SalaAula::setCapcidade(unsigned int capacidade){
	this->capacidade = capacidade;
}

std::list<Disciplina*>& SalaAula::getDisciplinas(){
    return this->disciplinas;
}

void SalaAula::adicionarDisciplina(Disciplina* disciplina){
    if (disciplina->sala == this)
        return;

    if (disciplina->sala != nullptr)
        disciplina->sala->disciplinas.remove(disciplina);
    disciplina->sala = this;
    if (disciplina->sala != nullptr)
        disciplina->sala->disciplinas.push_back(disciplina);
}

void SalaAula::removerDisciplina(Disciplina* disciplina){
    this->disciplinas.remove(disciplina);
    if (disciplina->getSala() != this)
        return;
    disciplina->sala = nullptr;
}
