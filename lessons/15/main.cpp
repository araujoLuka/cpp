#include <iostream>

#include "ProfessorAdjunto.hpp"
#include "Professor.hpp"
#include "ProfessorEngenheiro.hpp"

int main(){
    ProfessorEngenheiro pe{"Joao", 11111111111, 85, 40, 1234};

    std::cout << pe.Engenheiro::getNome() << std::endl;

	return 0;
}
