#include <iostream>
#include <string>

#include "CPF.hpp"
#include "Pessoa.hpp"

int main() {
    ufpr::CPF cpf{11111111111};
    ufpr::CPF cpf2{11111111111};
    ufpr::Pessoa p1{"Joao", cpf};

    if (cpf == cpf2) {
        std::cout << "CPF iguais\n";
    } else {
        std::cout << "CPF diferentes\n";
    }

    std::cout << p1.getCpf().getNumero() << '\n';

    return 0;
}
