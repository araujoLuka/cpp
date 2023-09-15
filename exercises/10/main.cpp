#include <iostream>

#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "ConteudoMinistrado.hpp"
#include "Console.hpp"
#include "SalaAula.hpp"

int main(){
    Disciplina dis1{"C++", nullptr};
    Disciplina* dis2 = new Disciplina{"Java", nullptr};
    
    SalaAula sala{"Lab 5", 30};
    dis1.setSalaAula(&sala);
    dis2->setSalaAula(&sala);

    std::list<Disciplina*> disciplinas = sala.getDisciplinas();
    std::list<Disciplina*>::iterator it;
    for (it = disciplinas.begin(); it != disciplinas.end(); ++it)
        std::cout << (*it)->getNome() << '\n';

    delete dis2;
    std::cout << "Fim do programa\n";

    return 0;
}
