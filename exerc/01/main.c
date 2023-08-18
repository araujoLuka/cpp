/* Autor: Lucas Correira de Araujo
 * GRR: 20206150
 * Exercicio 1 - Orientacao a Objetos C++
 * Leitor e validador de CPF
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME    64
#define TAM_LINE    1024
#define NUM_PESSOAS 3

struct pessoa_s {
    char nome[TAM_NOME];
    uint8_t idade;
    uint64_t cpf;
};

int validarCPF(uint64_t cpf) {
    #ifdef DEBUG
    printf("DEBUG: Validando CPF %ld\n", cpf);
    #endif /* ifdef DEBUG */

    uint8_t penultimoDigito, ultimoDigito, dig;

    uint64_t aux = cpf;
    int validaPenultimo = 0, validaUltimo = 0, restoValidador = 0;

    if (cpf == 0)
        return 0;

    /*
        * Armazena os dois ultimos digitos para valida-los
        * com a somatoria dos demais digitos
    */
    ultimoDigito = aux % 10;
    aux /= 10;
    penultimoDigito = aux % 10;
    aux /= 10;

    #ifdef DEBUG
    printf("DEBUG: Penultimo digito eh %d\n", penultimoDigito);
    printf("DEBUG: Ultimo digito eh    %d\n", ultimoDigito);
    #endif /* ifdef DEBUG */
    
    // Calcula o somatorio de validacao dos digitos do cpf
    for (uint8_t i = 9; aux != 0; i--) {
        dig = aux % 10;
        validaPenultimo += dig * i;
        validaUltimo += dig * (i-1);
        aux /= 10;
    }

    #ifdef DEBUG
    printf("DEBUG: Somatorio de validacao do penultimo digito eh %d\n", validaPenultimo);
    #endif /* ifdef DEBUG */
    
    // Valida o penultimo digito
    restoValidador = (validaPenultimo % 11) % 10;
    if (restoValidador != penultimoDigito) {
        #ifdef DEBUG
        printf("DEBUG: CPF invalido! Penultimo digito esta incorreto\n");
        printf("DEBUG: Penultimo digito eh %d mas deveria ser %d\n", penultimoDigito, restoValidador);
        #endif /* ifdef DEBUG */
        return 0;
    }
    #ifdef DEBUG
    printf("DEBUG: Penultimo digito validado com sucesso!\n");
    #endif /* ifdef DEBUG */

    validaUltimo += restoValidador * 9;

    #ifdef DEBUG
    printf("DEBUG: Somatorio de validacao do ultimo digito eh %d\n", validaUltimo);
    #endif /* ifdef DEBUG */

    // Valida o ultimo digito
    restoValidador = (validaUltimo % 11) % 10;
    if (restoValidador != ultimoDigito) {
        #ifdef DEBUG
        printf("DEBUG: CPF invalido! Ultimo digito esta incorreto\n");
        printf("DEBUG: Ultimo digito eh %d mas deveria ser %d\n", ultimoDigito, restoValidador);
        #endif /* ifdef DEBUG */
        return 0;
    }
    #ifdef DEBUG
    printf("DEBUG: Ultimo digito validado com sucesso!\n");
    #endif /* ifdef DEBUG */
    
    #ifdef DEBUG
    printf("DEBUG: CPF validado com sucesso!\n");    
    #endif /* ifdef DEBUG */
    
    return 1;
}

int main() {
    struct pessoa_s pessoas[NUM_PESSOAS];
    char buffer[TAM_LINE];
    char *end;

    for (int i = 0; i < NUM_PESSOAS; i++) {
        strcpy(pessoas[i].nome, "\0");
        pessoas[i].cpf = 0;
        pessoas[i].idade = 0;
        
        printf("# Informe os dados de quem deseja cadastrar: \n");
        
        // loop para ler um cpf valido
        while (1) {
            printf("CPF: ");
            while (!fgets(buffer, TAM_LINE, stdin));
            buffer[strlen(buffer)-1] = '\0';
            pessoas[i].cpf = strtold(buffer, &end);

            if (validarCPF(pessoas[i].cpf))
                break;

            printf("ERRO: CPF invalido! Informe novamente!\n");
        }

        printf("Nome: ");
        fgets(pessoas[i].nome, TAM_NOME, stdin);
        pessoas[i].nome[strlen(pessoas[i].nome)-1] = '\0';

        while (1) {
            printf("Idade: ");
            while (!fgets(buffer, TAM_LINE, stdin));
            buffer[strlen(buffer)-1] = '\0';
            pessoas[i].idade = (uint8_t)(atoi(buffer));

            if (pessoas[i].idade > 0)
                break;
        }

        printf("Pessoa cadastrada com sucesso!\n");
        printf("------------------------------\n");
    }

    for (int i = 0; i < 3; i++){
        printf("# Cadastro %02d\n", i+1);
        printf("- Nome:  %s\n", pessoas[i].nome);
        printf("- CPF:   %03ld.%03ld.%03ld-%02ld\n", 
               pessoas[i].cpf/(int)(1e8), 
               pessoas[i].cpf/(int)(1e5) % 1000, 
               pessoas[i].cpf/(int)(1e2) % 1000, 
               pessoas[i].cpf % 100);
        printf("- Idade: %hhd\n", pessoas[i].idade);
        printf("------------------------------\n");
    }

	return 0;
}
