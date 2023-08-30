#include <iostream>
#include <string>

#include "Disciplina.hpp"
#include "Pessoa.hpp"

int main() {
    Pessoa **ptr{nullptr};
    Pessoa *p1{new Pessoa{"Joao", 11111111111, 20}};
    Disciplina d1{"Orientacao a Objetos"};

    d1.setProfessor(p1);
    p1->setNome("Joao Almeida");

    std::cout << p1->getNome() << '\t' << p1->getIdade() << '\t' << p1->getCpf()
              << '\n';

    std::cout << d1.getNome() << '\t' << d1.getNomeProfessor() << '\n';

    // alocacao do vetor inicial de alunos
    Pessoa **al{new Pessoa *[5]};

    // alocacao de cada aluno
    al[0] = new Pessoa{"Carlos"};
    al[1] = new Pessoa{"Joana"};
    al[2] = new Pessoa{"Maria", 22222222222, 19};
    al[3] = new Pessoa{"Jose"};
    al[4] = new Pessoa{"Ana", 33333333333, 21};

    // adicao dos alunos na disciplina
    for (int i = 0; i < 5; i++) {
        if (!d1.adicionarAluno(al[i]))
            std::cout << "Falha ao adicionar aluno " << al[i]->getNome() << '\n'
                      << " - Turma esta cheia\n";
        else
            std::cout << "Aluno " << al[i]->getNome() << " adicionado com sucesso\n";
    }
    
    // listagem dos alunos da disciplina
    ptr = d1.getVetorAlunos();
    std::cout << "Alunos da Disciplina:\n";
    for (int i = 0; i < d1.getNumAlunos(); i++)
        std::cout << i + 1 << '\t' << ptr[i]->getNome() << '\n';

    Pessoa *aux{al[3]};

    // teste de remocao de aluno pelo objeto
    if (!d1.removerAluno(aux)) {
        std::cout << "Falha ao remover aluno " << aux->getNome() << '\n'
                  << " - Aluno nao encontrado\n";
    } else {
        std::cout << "Aluno " << aux->getNome() << " removido com sucesso\n";
    }

    // listagem dos alunos da disciplina
    ptr = d1.getVetorAlunos();
    std::cout << "Alunos da Disciplina:\n";
    for (int i = 0; i < d1.getNumAlunos(); i++)
        std::cout << i + 1 << '\t' << ptr[i]->getNome() << '\n';

    // criacao de novo aluno e teste de adicao
    delete aux;
    aux = new Pessoa{"Jorge", 44444444444, 22};
    al[3]->setNome("Afonso");
    if (!d1.adicionarAluno(aux)) {
        std::cout << "Falha ao adicionar aluno " << aux->getNome() << '\n'
                  << " - Turma esta cheia\n";
    } else {
        std::cout << "Aluno " << aux->getNome() << " adicionado com sucesso\n";
    }

    // listagem dos alunos da disciplina
    ptr = d1.getVetorAlunos();
    std::cout << "Alunos da Disciplina:\n";
    for (int i = 0; i < d1.getNumAlunos(); i++)
        std::cout << i + 1 << '\t' << ptr[i]->getNome() << '\n';

    // teste de remocao de aluno pelo CPF
    if (!d1.removerAluno(22222222222)) {
            std::cout << "Falha ao remover aluno de CPF " << 22222222222 << '\n'
                  << " - Aluno nao encontrado\n";
    } else {
        std::cout << "Aluno de CPF " << 22222222222 << " removido com sucesso\n";
    }

    // listagem dos alunos da disciplina
    ptr = d1.getVetorAlunos();
    std::cout << "Alunos da Disciplina:\n";
    for (int i = 0; i < d1.getNumAlunos(); i++)
        std::cout << i + 1 << '\t' << ptr[i]->getNome() << '\n';

    // liberacao de memoria
    delete p1;
    for (int i = 0; i < 5; i++) delete al[i];
    delete[] al;

    return 0;
}
