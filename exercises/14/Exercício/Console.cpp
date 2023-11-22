#include "Console.hpp"
#include "Trajeto.hpp"
#include "TrajetoEuclidiano.hpp"
#include "TrajetoManhattan.hpp"

#include <iostream>

void Console::imprimirDadosTrajeto(const Trajeto* const trajeto) {
    std::cout << "Distância percrida: " << trajeto->getDistanciaPercorrida() << std::endl;
    std::cout << "Pontos percorridos: " << std::endl;
    trajeto->imprimirTrajeto();
}
