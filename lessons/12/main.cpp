#include <iostream>

#include "Pilha.hpp"

int main(){
	int retorno;
	Pilha<int, 3> p;
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);

	while(!p.estaVazia()){
		p.pop(&retorno);
		std::cout << retorno << "\n";
	}
	

	std::cout << "Fim\n";

	return 0;
}
