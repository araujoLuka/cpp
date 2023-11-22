#include <array>
#include <iostream>

#include "Console.hpp"
#include "Trajeto.hpp"
#include "TrajetoEuclidiano.hpp"
#include "TrajetoManhattan.hpp"

int main(){
    std::array<Trajeto*, 2> t = {new TrajetoEuclidiano(), new TrajetoManhattan()};
    Ponto p1(0, 0), p2(1, 1);

    for(int i{0}; i < 2; i++) {
        t[i]->adicionarPonto(p1.getCoordX(), p1.getCoordY());
        t[i]->adicionarPonto(p2.getCoordX(), p2.getCoordY());
    }

    std::cout << "Trajeto Euclidiano: " << std::endl;
    Console::imprimirDadosTrajeto(t[0]);
    std::cout << "Trajeto Manhattan: " << std::endl;
    Console::imprimirDadosTrajeto(t[1]);

    std::array<Trajeto*, 2>::iterator it;
    for(it = t.begin(); it != t.end(); ) {
        Trajeto* trajeto = *it;
        it++;
        delete trajeto;
    }

	return 0;
}
