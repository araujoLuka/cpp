#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

#include "Curso.hpp"
#include "Pessoa.hpp"

#define MAX_ALUNOS 50

class Disciplina {
   public:
    Disciplina(std::string nome, Curso *curso);

    std::string getNome();
    void setNome(std::string nome);

    int getCargaHoraria();
    void setCargaHoraria(unsigned int cargaHoraria);

    Pessoa *getProfessor();
    void setProfessor(Pessoa *professor);

	std::string getNomeProfessor();

	int getNumAlunos();

    Curso *getCurso();

	bool adicionarAluno(Pessoa *aluno);

	Pessoa **getVetorAlunos();

    void listarAlunos();

	bool removerAluno(Pessoa *aluno);

	bool removerAluno(uint64_t cpfAluno);

   private:
    std::string nome;
    unsigned short int cargaHoraria;

    Pessoa *professor;

	unsigned short int numAlunos;
	Pessoa *alunos[MAX_ALUNOS];

    Curso *curso;
};

#endif
