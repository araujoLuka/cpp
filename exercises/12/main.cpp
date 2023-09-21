#include <iostream>

#include "Pilha.hpp"
#include "Queue.hpp"

int main() {
    int retorno;
    Pilha<int, 4> p;
    Queue<int, 4> q;

    // title of the problem
    std::cout << "Exercício 12\n\n";

    // description of the test algorithm
    std::cout << "Algoritmo main: Instancia uma pilha e uma fila com tamanho máximo de 4 elementos.\n"
                 "                Insere 4 elementos e tenta inserir o quinto. Remove um elemento\n"
                 "                e insere para testar o wrap around. Imprime os elementos da pilha\n"
                 "                e da fila.\n\n";

    std::cout << "Inicio";

    std::cout << "\n\nPilha\n";

    std::cout << "Inserindo 1, 2, 3, 4\n";
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);

    std::cout << "Tentando inserir 5\n";
    if (!p.push(5)) std::cout << "Pilha cheia\n";

    std::cout << "Removendo para inserir 5\n";
    p.pop(&retorno);
    std::cout << "Removido: " << retorno << "\n";
    p.push(5);

    std::cout << "Pilha final\n";
    while (!p.estaVazia()) {
        p.pop(&retorno);
        std::cout << retorno << "\n";
    }

    std::cout << "\n\nFila\n";

    std::cout << "Inserindo 1, 2, 3, 4\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    std::cout << "Tentando inserir 5\n";
    if (!q.enqueue(5)) std::cout << "Fila cheia\n";

    std::cout << "Removendo para inserir 5\n";
    q.dequeue(&retorno);
    std::cout << "Removido: " << retorno << "\n";
    q.enqueue(5);

    std::cout << "Fila final\n";
    while (!q.isEmpty()) {
        q.dequeue(&retorno);
        std::cout << retorno << "\n";
    }

    std::cout << "Fim\n";

    return 0;
}
