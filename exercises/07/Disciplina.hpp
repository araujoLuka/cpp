#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <map>
#include <string>

#include "Curso.hpp"
#include "Pessoa.hpp"

#define MAX_ALUNOS 50   // Define the maximum number of students in a class

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

    // Retrieve a container of all students
    std::map<int, Pessoa*> getAlunos();

    // Add a student to the class
    bool adicionarAluno(Pessoa* aluno);

    // Remove a student based on their object pointer
    bool removerAluno(Pessoa* aluno);

    // Remove a student based on their CPF
    bool removerAluno(unsigned long cpf);

    // Remove a student based on their ID
    bool removerAlunoPorId(int id);

    // List all students in the class
    void listarAlunos();

   private:
    std::string nome;
    unsigned short int cargaHoraria;

    Pessoa *professor;

    Curso *curso;

    std::map<int, Pessoa*> alunos;

    // Generate a unique ID for a student
    int gerarId(Pessoa* aluno);
};

#endif
