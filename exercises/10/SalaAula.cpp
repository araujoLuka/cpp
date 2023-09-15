#include "SalaAula.hpp"
#include <iostream>

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
	:nome{nome}, capacidade{capacidade}{
}

SalaAula::~SalaAula(){
    std::cerr << "Destruindo sala de aula " << this->nome << '\n';
    std::list<Disciplina*>::iterator it{disciplinasMinistradas.begin()};
    while(it != disciplinasMinistradas.end()){
        std::cerr << "DEBUG: Removendo disciplina " << (*it)->getNome() << " da sala de aula\n";
        Disciplina* d = (*it);
        it++;
        d->setSalaAula(nullptr);
    }
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
    return disciplinasMinistradas;
}
