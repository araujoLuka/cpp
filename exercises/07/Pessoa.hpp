#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstdint>
#include <string>

class Pessoa {
   public:
    Pessoa();
    Pessoa(std::string nome);
    Pessoa(std::string nome, uint64_t cpf, uint8_t idade);

    uint64_t getCpf();
    void setCpf(uint64_t cpf);

    std::string getNome();
    void setNome(std::string nome);

    unsigned short getIdade();
    void setIdade(unsigned short idade);

   private:
    bool validarCPF(uint64_t cpfTeste);

    std::string nome;
    uint64_t cpf;
    uint8_t idade;
};
#endif
