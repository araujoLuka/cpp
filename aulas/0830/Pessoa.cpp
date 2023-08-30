#include "Pessoa.hpp"

Pessoa::Pessoa() : nome{"Sem nome"}, cpf{0}, idade{0} {}

Pessoa::Pessoa(std::string nome) : nome{nome}, cpf{0}, idade{0} {}

Pessoa::Pessoa(std::string nomePessoa, uint64_t cpf, uint8_t idade)
    : Pessoa{nomePessoa} {
    setCpf(cpf);
    setIdade(idade);
}

uint64_t Pessoa::getCpf() {
    // retorna uma cópia do cpf
    return cpf;
}

void Pessoa::setCpf(uint64_t cpf) {
    if (validarCPF(cpf)) {
        this->cpf = cpf;
        return;
    }
    this->cpf = 0;  // indica que não é um cpf válido
    return;
}

std::string Pessoa::getNome() { return nome; }
void Pessoa::setNome(std::string nome) { this->nome = nome; }

unsigned short Pessoa::getIdade() { return (unsigned short)idade; }
void Pessoa::setIdade(unsigned short idade) {
    if (idade < 120)
        this->idade = (uint8_t)idade;
    else
        this->idade = 0;  // indicar erro
}

bool Pessoa::validarCPF(uint64_t cpfTeste) {
    unsigned int somatorioValidaUltimo;
    unsigned int modulo;
    unsigned int somatorioValidaPenultimo{0};
    unsigned int ultimo{(unsigned int)(cpfTeste % 10)};
    cpfTeste = cpfTeste / 10;
    unsigned int penultimo{(unsigned int)(cpfTeste % 10)};
    cpfTeste = cpfTeste / 10;

    somatorioValidaUltimo = penultimo * 2;
    for (int i{2}; i <= 11; i++) {
        modulo = cpfTeste % 10;
        cpfTeste = cpfTeste / 10;
        somatorioValidaPenultimo += modulo * i;
        somatorioValidaUltimo += modulo * (i + 1);
    }
    modulo = somatorioValidaPenultimo % 11;
    if (modulo < 2) {
        if (penultimo != 0) return false;  // cpf invalido
    } else {
        if (penultimo != 11 - modulo) return false;  // cpf invalido
    }
    modulo = somatorioValidaUltimo % 11;
    if (modulo < 2) {
        if (!ultimo) return false;  // cpf invalido
    } else {
        if (ultimo != 11 - modulo) return false;  // cpf invalido
    }
    return true;  // cpf valido
}
