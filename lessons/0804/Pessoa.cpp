/* Autor: Lucas Correira de Araujo
 * GRR: 20206150
 * Aula 04/08/2023 - Orientacao a Objetos C++
 * Implementacao das funcoes membro da classe Pessoa
 */

#include <iostream>

#include "Pessoa.hpp"

bool Pessoa::validarCPF(uint64_t cpfTeste) {
    #ifdef DEBUG
    std::cout << "DEBUG: Validando CPF %ld\n" << cpf;
    #endif /* DEBUG */
    
    unsigned int validaPenultimo{0};
    unsigned int validaUltimo{0};
    unsigned int restoValidador{0};
    uint8_t dig;

    /*
        * Armazena os dois ultimos digitos para valida-los
        * com a somatoria dos demais digitos
    */
    uint8_t ultimoDigito{(uint8_t)(cpfTeste % 10)};
    cpfTeste /= 10;
    uint8_t penultimoDigito{(uint8_t)(cpfTeste % 10)};
    cpfTeste /= 10;

    #ifdef DEBUG
    std::cout << "DEBUG: Penultimo digito eh %d\n" << penultimoDigito;
    std::cout << "DEBUG: Ultimo digito eh    %d\n" << ultimoDigito;
    #endif /* DEBUG */

    // Nao existe necessidade de auxiliar
    // uint64_t aux = cpf;

    if (cpfTeste == 0)
        return false;
    
    // Calcula o somatorio de validacao dos digitos do cpf
    for (uint8_t i = 9; cpfTeste != 0; i--) {
        dig = cpfTeste % 10;
        validaPenultimo += dig * i;
        validaUltimo += dig * (i-1);
        cpfTeste /= 10;
    }

    #ifdef DEBUG
    std::cout << "DEBUG: Somatorio de validacao do penultimo digito eh %d\n" << validaPenultimo;
    #endif /* DEBUG */
    
    // Valida o penultimo digito
    restoValidador = (validaPenultimo % 11) % 10;
    if (restoValidador != penultimoDigito) {
        #ifdef DEBUG
        std::cout << "DEBUG: CPF invalido! Penultimo digito esta incorreto\n";
        std::cout << "DEBUG: Penultimo digito eh %d mas deveria ser %d\n" << penultimoDigito << restoValidador;
        #endif /* DEBUG */
        return false;
    }
    #ifdef DEBUG
    std::cout << "DEBUG: Penultimo digito validado com sucesso!\n";
    #endif /* DEBUG */

    validaUltimo += restoValidador * 9;

    #ifdef DEBUG
    std::cout << "DEBUG: Somatorio de validacao do ultimo digito eh %d\n" << validaUltimo;
    #endif /* DEBUG */

    // Valida o ultimo digito
    restoValidador = (validaUltimo % 11) % 10;
    if (restoValidador != ultimoDigito) {
        #ifdef DEBUG
        std::cout << "DEBUG: CPF invalido! Ultimo digito esta incorreto\n";
        std::cout << "DEBUG: Ultimo digito eh %d mas deveria ser %d\n" << ultimoDigito << restoValidador;
        #endif /* DEBUG */
        return false;
    }
    #ifdef DEBUG
    std::cout << "DEBUG: Ultimo digito validado com sucesso!\n";
    #endif /* DEBUG */
    
    #ifdef DEBUG
    std::cout << "DEBUG: CPF validado com sucesso!\n";
    #endif /* DEBUG */
    
    return true;
}
