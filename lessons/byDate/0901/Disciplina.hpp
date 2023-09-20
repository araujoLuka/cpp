#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

#include "Pessoa.hpp"

class SalaAula; // Forward declaration

class Disciplina{
	public:
		Disciplina(std::string nome);

		std::string getNome();
		void setNome(std::string nome);
		
		int getCargaHoraria();
		void setCargaHoraria(unsigned int carga);

		Pessoa* getProfessor();
        void setProfessor(Pessoa* prof);

        SalaAula* getSala();
        void setSala(SalaAula* sala);

		void imprimirDados(std::string& cabecalho, unsigned int cargaTotalCurso);

	private:
		std::string nome;
		unsigned short int cargaHoraria;
		Pessoa* professor;
        SalaAula* sala;
};
#endif
