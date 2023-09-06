#include <iostream>
#include <string>
#include <vector>

#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "SalaAula.hpp"

void printSala(SalaAula *sala){
    std::cout << "Sala: " << sala->getNome() 
        << " (" << sala << ")\n";
    std::cout << "Capacidade: " << sala->getCapacidade() << '\n';
    std::cout << "Disciplinas: \n";
    std::list<Disciplina*> disciplinas = sala->getDisciplinas();
    if (disciplinas.empty()){
        std::cout << '\t' << "- Nenhuma disciplina cadastrada\n";
        return;
    }
    std::list<Disciplina*>::iterator it;
    for(it = disciplinas.begin(); it != disciplinas.end(); ++it){
        //sala nula
        if ((*it)->getSala() == nullptr){
            std::cout << '\t' << "- Disciplina " << (*it)->getNome() 
                << " sem sala\n";
            continue;
        }
        if ((*it)->getSala() != sala){
            std::cout << '\t' << "- Disciplina " << (*it)->getNome() 
                << " cadastrada em outra sala (" 
                << (*it)->getSala() << ")\n";
            continue;
        }
        std::cout << '\t' << "- " << (*it)->getNome() 
            << " (Profº " << (*it)->getProfessor()->getNome() 
            << " - Sala " << (*it)->getSala()->getNome() << ")\n";
    }
}

int main(){
    // vetor de salas
    std::vector<SalaAula> salas;
    salas.push_back(SalaAula{"Lab Info 1", 30});
    salas.push_back(SalaAula{"Lab Info 2", 20});

	Pessoa prof1{"João", 11111111111, 40};
	Disciplina dis1{"Orientacao a Objetos"};
	dis1.setProfessor(&prof1);

	Pessoa prof2{"Maria", 22222222222, 30};	
	Disciplina dis2{"Sistemas Operacionais", &salas[0]};
	dis2.setProfessor(&prof2);

    dis1.setSala(&salas[0]);
    std::cout << "pointer de dis1: " << &dis1 
        << " nome: " << dis1.getNome() << '\n';
    std::cout << "pointer de dis1 na sala: " << salas[0].getDisciplinas().back()
        << " nome: " << salas[0].getDisciplinas().back()->getNome() << '\n';

    std::vector<SalaAula>::iterator sala = salas.begin();
    for (; sala != salas.end(); ++sala){
        printSala(&(*sala));
        std::cout << '\n';
    }

    std::cout << "------------------\n";
    std::cout << "Realizando alterações...\n";
    std::cout << "- Adicionando disciplina " << dis1.getNome() 
        << " na sala " << salas[1].getNome() << '\n';
    salas[1].adicionarDisciplina(&dis1);

    std::cout << "- Criando sala Lab Info 3\n";
    std::cout << "- Adicionando disciplina " << dis2.getNome() 
        << " na sala criada\n";
    SalaAula sala3{"Lab Info 3", 40};
    dis2.setSala(&sala3);
    std::cout << "------------------\n";

    sala = salas.begin();
    for (; sala != salas.end(); ++sala){
        printSala(&(*sala));
        std::cout << '\n';
    }
    printSala(&sala3);

	return 0;
}
