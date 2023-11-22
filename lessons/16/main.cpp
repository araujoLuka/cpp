#include <iostream>
#include <stdexcept>

#include "CPFInvalidoException.hpp"
#include "Pessoa.hpp"
#include "ProfessorEngenheiro.hpp"

int main(){
    std::string nome;
    int idade;
    unsigned long cpf;

    std::cout << "Digite o nome: ";
    std::getline(std::cin, nome);
    std::cout << "Digite a idade: ";
    std::cin >> idade;
    std::cout << "Digite o CPF: ";
    std::cin >> cpf;

    try {
        Pessoa* p = new Pessoa{nome, cpf, 18};
        p->setIdade(idade);
        std::cout << "Nome: " << p->getNome() << std::endl;
        std::cout << "Idade: " << p->getIdade() << std::endl;
        std::cout << "CPF: " << p->getCpf() << std::endl;
    } catch (std::invalid_argument& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    } catch (CPFInvalidoException& e) {
        std::cout << "Erro: " << e.what() << std::endl;
        std::cout << "CPF: " << e.cpf << std::endl;
    } catch (std::exception& e) {
        std::cout << "Erro desconhecido: " << e.what() << std::endl;
    }

    return 0;
}
