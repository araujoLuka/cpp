/*
* Using list and iterator
*/

#include <iostream>
#include <iterator>
#include <list>

#include "Curso.hpp"
#include "Disciplina.hpp"
#include "Pessoa.hpp"

int main() {
    std::list<Pessoa*> lista;

    lista.push_back(new Pessoa("Ramom"));
    lista.push_back(new Pessoa("Luan"));
    lista.push_front(new Pessoa("Maria"));
    lista.push_front(new Pessoa("Maria"));
    lista.push_front(new Pessoa("Maria"));

    std::list<Pessoa*>::iterator it;

    std::cout << "First list size: " << lista.size() << '\n';

    // Deleting elements from list, while iterating
    // through it
    for (it = lista.begin(); it != lista.end(); ++it) {
        if ((*it)->getNome() == "Maria") {
            Pessoa *ptr{*it};
            it = lista.erase(it); // it <- next item from the deleted element
            --it;   // return to don't skip element in list
            delete ptr;
        }
    }

    std::cout << "New list size: " << lista.size() << '\n';

    for (it = lista.begin(); it != lista.end(); ++it){
        std::cout << (*it)->getNome() << '\n';
        delete *it;
    }

    return 0;
}
