#include "SalaAula.hpp"
#include <iostream>

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
	:nome{nome}, capacidade{capacidade}{
}

SalaAula::~SalaAula(){
    // Avisa as disciplinas da lista disciplinasMinistradas que sala vai deixar de existir
    std::list<Disciplina*>::iterator it{disciplinasMinistradas.begin()};
    while(it != disciplinasMinistradas.end()){
        // std::cerr << "DEBUG: Removendo disciplina " << (*it)->getNome() << " da sala de aula\n";
        
        // Como a lista sera alterada enquanto esta sendo iterada
        // eh necessario realizar um procedimento especial para a remocao da sala:
        // 1) Salva o endereco apontado pelo iterador com o objeto a ser removido
        Disciplina* d = (*it);
        // 2) incrementa o iterador antes que a lista seja modificada
        it++;
        // 3) define a sala como nula, sendo removida da lista de disciplinasMinistradas
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
