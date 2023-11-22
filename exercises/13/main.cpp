#include <iostream>
#include <list>

#include "Disciplina.hpp"
#include "Pessoa.hpp"
#include "Professor.hpp"

int main(){
    Professor p1{"João", 12345678912, 100, 40};

    std::cout << p1.getNome() << std::endl;
    
    return 0;
}
