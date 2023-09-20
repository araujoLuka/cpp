/* Autor: Lucas Correira de Araujo
 * GRR: 20206150
 * Aula 04/08/2023 - Orientacao a Objetos C++
 * Leitor e validador de CPF em C++ com classe
 */

#include <iomanip>
#include <iostream>

#include "Pessoa.hpp"

int main() {
    Pessoa p1;
    int idadeAux;

    std::cout << "# Informe os dados para cadastro: \n";

    std::cout << "CPF: ";
    std::cin >> p1.cpf;

    while (!p1.validarCPF(p1.cpf)) {
        std::cout << "ERRO: CPF Invalido - Informe novamente!\n";
        std::cout << "CPF: ";
        std::cin >> p1.cpf;
    }

    std::cout << "Nome: ";
    std::cin >> p1.nome;
    
    std::cout << "Idade: ";
    std::cin >> idadeAux;
    p1.idade = idadeAux;

    std::cout << "Pessoa cadastrada com suceso!\n";

    std::cout << "- Nome:  " << p1.nome << '\n';
    std::cout << "- CPF:   ";
    std::cout << std::setfill('0') << std::setw(3) << p1.cpf/(int)(1e8) << '.'; 
    std::cout << std::setfill('0') << std::setw(3) << p1.cpf/(int)(1e5) % 1000 << '.'; 
    std::cout << std::setfill('0') << std::setw(3) << p1.cpf/(int)(1e2) % 1000 << '-'; 
    std::cout << p1.cpf % 100 << '\n';
    std::cout << "- Idade: " << (unsigned short int)p1.idade << '\n';

    return 0;
}
