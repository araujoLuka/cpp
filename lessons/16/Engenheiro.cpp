#include "Engenheiro.hpp"

Engenheiro::Engenheiro(){};

Engenheiro::Engenheiro(const unsigned int numeroCrea) : numeroCrea(numeroCrea){
}

Engenheiro::Engenheiro(const std::string& nome, const unsigned long cpf, const unsigned int numeroCrea)
		:Pessoa(nome, cpf), numeroCrea(numeroCrea){

}

Engenheiro::~Engenheiro(){}

unsigned int Engenheiro::getNumeroCrea() const{
	return this->numeroCrea;
}

void Engenheiro::setNumeroCrea(const unsigned int numeroCrea){
	this->numeroCrea = numeroCrea;
}

unsigned int Engenheiro::getSalario() const{
	return Engenheiro::salarioPadrao;
}