#include <iostream>
#include <list>

#include "Livro.hpp"
#include "Ementa.hpp"

int main(){
    ufpr::Livro l1{"C++ How To Program", 2017};
    l1.addAutor("Paul Deitel");
    l1.addAutor("Harvey Deitel");

    ufpr::Livro l2{"The C++ Programming Language", 2013};
    l1.addAutor("Bjarne Stroustrup ");

    ufpr::Ementa* ementa1{new ufpr::Ementa{"Curso de C++. Aulas de Orientação a Objetos."}};
    ementa1->addLivro(l1);
    ementa1->addLivro(l2);

    ufpr::Ementa ementaCopia{*ementa1};

    std::cout << "Dados da Ementa Copia " << ementaCopia.getDescricao() << '\n';
    std::list<ufpr::Livro>::const_iterator it{ementaCopia.getLivros()->begin()};
    for( ; it != ementaCopia.getLivros()->end(); ++it){
        std::cout << it->getTitulo() << '\n';
    }

   return 0;
}