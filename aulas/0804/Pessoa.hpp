/* Autor: Lucas Correira de Araujo
 * GRR: 20206150
 * Aula 04/08/2023 - Orientacao a Objetos C++
 * Cabecalho com interface da classe Pessoa
 */

#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <cstdint>

class Pessoa {
    public:
        bool validarCPF(uint64_t cpfTeste);

        char nome[50];
        uint64_t cpf;
        uint8_t idade;
};
#endif
