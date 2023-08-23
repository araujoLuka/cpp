#include <iostream>
#include <string>

#include "Curso.hpp"
#include "Disciplina.hpp"
#include "Pessoa.hpp"

int main() {
    Pessoa **ptr{nullptr};
    Pessoa *p1{new Pessoa{"Joao", 11111111111, 20}};
    Curso *c1{new Curso{"Ciencia da Computacao"}};
    Disciplina d1{"Orientacao a Objetos", c1};

    std::cout << "Planejando as aulas...\n";

    std::cout << "Criando Professor, Curso e Disciplina...\n";

    // vinculacao do professor a disciplina
    d1.setProfessor(p1);
    p1->setNome("Joao Almeida");

    std::cout << "Imprimindo dados do Professor, Disciplina e Curso...\n";

    // imprime dados do professor
    std::cout << "Professor:\n";
    std::cout << "- Nome: " << p1->getNome() << '\n';
    std::cout << "- Idade: " << p1->getIdade() << '\n';
    std::cout << "- CPF: " << p1->getCpf() << '\n';
    std::cout << '\n';

    // imprime dados da disciplina
    std::cout << "Disciplina:\n";
    std::cout << "- Nome: " << d1.getNome() << '\n';
    std::cout << "- Professor: " << d1.getNomeProfessor() << '\n';
    std::cout << '\n';

    // imprime dados do curso
    std::cout << "Curso:\n";
    std::cout << "- Nome: " << c1->getNome() << '\n';
    std::cout << "- Carga Horaria: " << c1->getCargaHoraria() << '\n';
    std::cout << "- Ano de Criacao: " << c1->getAnoCriacao() << '\n';
    std::cout << '\n';

    // curso da disciplina
    Curso *c2{d1.getCurso()};
    std::cout << "Curso vinculado a Disciplina " << d1.getNome() << ":\n";
    std::cout << "- Nome: " << c2->getNome() << '\n';
    std::cout << "- Carga Horaria: " << c2->getCargaHoraria() << '\n';
    std::cout << "- Ano de Criacao: " << c2->getAnoCriacao() << '\n';
    std::cout << '\n';

    std::cout << "Adicionando alunos na disciplina...\n";

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
    std::cout << '\n';

    std::cout << "Listando alunos...\n";
    
    // listagem dos alunos da disciplina
    d1.listarAlunos();
    std::cout << '\n';

    // listagem dos alunos da disciplina com ponteiro
    std::cout << "Listando alunos com ponteiro...\n";
    ptr = d1.getVetorAlunos();
    std::cout << "Alunos da disciplina " << d1.getNome() << ":\n";
    for (int i = 0; i < d1.getNumAlunos(); i++) {
        std::cout << i + 1 << '\t' << ptr[i]->getNome() << '\t'
                  << ptr[i]->getIdade() << '\t' << ptr[i]->getCpf() << '\n';
    }
    std::cout << '\n';

    // teste de remocao de aluno pelo objeto
    Pessoa *aux{al[3]};
    std::cout << "Removendo aluno " << aux->getNome() << '\n';
    if (!d1.removerAluno(aux)) {
        std::cout << "Falha ao remover aluno " << aux->getNome() << '\n'
                  << " - Aluno nao encontrado\n";
    } else {
        std::cout << "Aluno " << aux->getNome() << " removido com sucesso\n";
        d1.listarAlunos();
    }
    std::cout << '\n';

    // criacao de novo aluno e teste de adicao
    aux = new Pessoa{"Felipe", 44444444444, 22};
    std::cout << "Adicionando aluno " << aux->getNome() << '\n';
    if (!d1.adicionarAluno(aux)) {
        std::cout << "Falha ao adicionar aluno " << aux->getNome() << '\n'
                  << " - Turma esta cheia\n";
    } else {
        std::cout << "Aluno " << aux->getNome() << " adicionado com sucesso\n";
        d1.listarAlunos();
    }
    std::cout << '\n';

    // teste de remocao de aluno pelo CPF
    std::cout << "Removendo aluno de CPF " << 22222222222 << '\n';
    if (!d1.removerAluno(22222222222)) {
            std::cout << "Falha ao remover aluno de CPF " << 22222222222 << '\n'
                  << " - Aluno nao encontrado\n";
    } else {
        std::cout << "Aluno de CPF " << 22222222222 << " removido com sucesso\n";
        d1.listarAlunos();
    }
    std::cout << '\n';

    // teste de remocao de aluno nao existente
    Pessoa *aux2{new Pessoa("Bianca", 66666666666, 24)};
    std::cout << "Removendo aluno " << aux2->getNome() << '\n';
    if (!d1.removerAluno(aux2)) {
        std::cout << "Falha ao remover aluno " << aux2->getNome() << '\n'
                  << " - Aluno nao encontrado\n";
    } else {
        std::cout << "Aluno " << aux2->getNome() << " removido com sucesso\n";
        d1.listarAlunos();
    }

    // liberacao de memoria
    for (int i = 0; i < 5; i++) delete al[i];
    delete[] al;
    delete p1;
    delete c1;
    delete aux2;

    return 0;
}
