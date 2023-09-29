#include <iostream>

#include "ProfessorAdjunto.hpp"
#include "Professor.hpp"

int main(){
    Pessoa* ptr{new ProfessorAdjunto{"João", 12345678901, 5000, 40}};

    Professor* pr{(Professor*)ptr};

    std::cout << ptr->getNome() << " " << pr->getSalario() << std::endl;

    delete ptr;

    return 0;
}
