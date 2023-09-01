#include <iostream>
#include <array>
#include <string>
#include <vector>

#include "Curso.hpp"
#include "Disciplina.hpp"
#include "Pessoa.hpp"

int main() {
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

    // imprime dados do curso
    std::cout << "Curso:\n";
    std::cout << "- Nome: " << c1->getNome() << '\n';
    std::cout << "- Carga Horaria: " << c1->getCargaHoraria() << '\n';
    std::cout << "- Ano de Criacao: " << c1->getAnoCriacao() << '\n';
    std::cout << '\n';

    // imprime dados da disciplina
    std::cout << "Disciplina:\n";
    std::cout << "- Nome: " << d1.getNome() << '\n';
    std::cout << "- Professor: " << d1.getNomeProfessor() << '\n';
    std::cout << "- Carga Horaria: " << d1.getCargaHoraria() << '\n';
    std::cout << "- Curso: " << d1.getCurso()->getNome() << '\n';
    std::cout << "---\n";
    std::cout << "Pressione ENTER para continuar...";
    std::cin.get();
    std::cout << '\n';

    std::cout << "Adicionando alunos na disciplina...\n";
    // alocacao de array de alunos
    std::array<Pessoa*, 5> arr{new Pessoa{"Carlos"},
                                new Pessoa{"Joana"},
                                new Pessoa{"Maria", 22222222222, 19},
                                new Pessoa{"Jose"},
                                new Pessoa{"Ana", 33333333333, 21}};

    // insercao de alunos na disciplina
    std::array<Pessoa*, arr.size()>::iterator arrIt{arr.begin()};
    for (; arrIt != arr.end(); arrIt++) {
        if (!d1.adicionarAluno(*arrIt))
            std::cout << "Falha ao adicionar aluno " << (*arrIt)->getNome() << '\n'
                      << " - Turma esta cheia\n";
        else
            std::cout << "Aluno " << (*arrIt)->getNome() << " adicionado com sucesso\n";
    }
    std::cout << '\n';

    std::cout << "Listando alunos...\n";
    // listagem dos alunos da disciplina
    d1.listarAlunos();
    std::cout << '\n';

    // listagem dos alunos da disciplina com ponteiro
    std::cout << "Listando alunos com ponteiro...\n";
    std::map<int, Pessoa*> alunos{d1.getAlunos()};
    std::cout << "Alunos da disciplina " << d1.getNome() << ":\n";
    std::map<int, Pessoa*>::iterator it{alunos.begin()};
    for (; it != alunos.end(); it++) {
        std::cout << it->first << '\t'
                  << it->second->getNome() << '\t'
                  << it->second->getIdade() << '\t'
                  << it->second->getCpf() << '\n';
    }
    std::cout << "---\n";
    std::cout << "Pressione ENTER para continuar...";
    std::cin.get();
    std::cout << '\n';

    // teste de remocao de aluno da posicao 3 de arr
    std::cout << "Removendo o terceiro aluno inserido...\n";
    Pessoa *aux{arr[2]};
    std::cout << "Removendo aluno " << aux->getNome() << '\n';
    if (!d1.removerAluno(aux)) {
        std::cout << "Falha ao remover aluno " << aux->getNome() << '\n'
                  << " - Aluno nao encontrado\n";
    } else {
        std::cout << "Aluno " << aux->getNome() << " removido com sucesso\n";
        d1.listarAlunos();
        delete aux;
        arr[2] = nullptr;
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
    std::cout << "---\n";
    std::cout << "Pressione ENTER para continuar...";
    std::cin.get();
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
    std::cout << '\n';

    // remocao de aluno por ID
    int id{d1.getAlunos().begin()->first};
    std::cout << "Removendo aluno de ID: " << id << '\n';
    if (!d1.removerAlunoPorId(id)) {
        std::cout << "Falha ao remover aluno de ID: " << id << '\n'
                  << " - Aluno nao encontrado\n";
    } else {
        std::cout << "Aluno de ID: " << id << " removido com sucesso\n";
        d1.listarAlunos();
    }

    // liberacao de memoria
    for (std::array<Pessoa*, arr.size()>::iterator it{arr.begin()}; it != arr.end(); it++) {
        delete *it;
        *it = nullptr;
    }

    delete p1;
    delete c1;
    delete aux;
    delete aux2;

    return 0;
}
