#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

#include "Pessoa.hpp"

#define MAX_ALUNOS 50

class Disciplina {
   public:
    Disciplina(std::string nomeDisciplina);

    std::string getNome();
    void setNome(std::string novoNome);

    int getCargaHoraria();
    void setCargaHoraria(unsigned int novaCarga);

    Pessoa *getProfessor();
    void setProfessor(Pessoa *novoProf);

	std::string getNomeProfessor();

	int getNumAlunos();

	bool adicionarAluno(Pessoa *aluno);

	Pessoa **getVetorAlunos();

	bool removerAluno(Pessoa *aluno);

	bool removerAluno(uint64_t cpfAluno);

   private:
    std::string nome;
    unsigned short int cargaHoraria;

    Pessoa *professor;

	unsigned short int numAlunos;
	Pessoa *alunos[MAX_ALUNOS];
};
#endif
