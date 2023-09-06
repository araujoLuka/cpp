#ifndef SALA_AULA_H
#define SALA_AULA_H

#include <string>
#include <list>

#include "Disciplina.hpp"

class SalaAula{
    friend void Disciplina::setSala(SalaAula* sala);

	public:
		SalaAula(std::string nome, unsigned int capacidade);
		
		std::string getNome();
		void setNome(std::string nome);

		unsigned int getCapacidade();
		void setCapcidade(unsigned int capacidade);

        std::list<Disciplina*>& getDisciplinas();

        void adicionarDisciplina(Disciplina* disciplina);
        void removerDisciplina(Disciplina* disciplina);

	private:
		std::string nome;
		unsigned int capacidade;
        std::list<Disciplina*> disciplinas;
};
#endif
