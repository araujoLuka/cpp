// Author: Lucas Correia de Araujo
//
// Description:
// - This program is the aswer for the question 4 of the first exam of the
// discipline of Object Oriented Programming with C++ of UFPR
//
// Date: 04/10/2023

#include <iostream>

#include "Circulo.hpp"
#include "Retangulo.hpp"
#include "TelaDesenho.hpp"

int main() {
    TelaDesenho tela;

    std::cout << "Tela de desenho criada" << std::endl;
    std::cout << "Area total: " << tela.calcularAreaTotal() << std::endl;
    std::cout << std::endl;

    std::cout << "Criando as formas:" << std::endl;
    std::cout << "- Circulo de raio 10 com ponteiro de Forma" << std::endl;
    std::cout << "- Circulo de raio 12" << std::endl;
    std::cout << std::endl;
    Forma *forma1 = new Circulo(10);
    Circulo *circulo = new Circulo(12);

    std::cout << "Areas das formas:" << std::endl;
    double area1 = forma1->area();
    double area2 = circulo->area();
    std::cout << "- Circulo de raio 10: " << area1 << std::endl;
    std::cout << "- Circulo de raio 12: " << area2 << std::endl;
    std::cout << "- Soma das areas: " << area1 + area2 << std::endl;
    std::cout << std::endl;

    std::cout << "Adicionando as formas na tela de desenho" << std::endl;
    tela.adicionarForma(forma1);
    tela.adicionarForma(circulo);

    std::cout << "Area total: " << tela.calcularAreaTotal() << std::endl;
    std::cout << std::endl;

    std::cout << "Criando as formas:" << std::endl;
    std::cout << "- Retangulo de largura 10 e altura 40 com ponteiro de Forma"
              << std::endl;
    std::cout << "- Retangulo de largura 10 e altura 10" << std::endl;
    std::cout << std::endl;
    Forma *forma2 = new Retangulo(10, 40);
    Retangulo *retangulo = new Retangulo(10, 10);

    std::cout << "Areas das formas:" << std::endl;
    area1 = forma2->area();
    area2 = retangulo->area();
    std::cout << "- Retangulo de largura 10 e altura 40: " << area1 << std::endl;
    std::cout << "- Retangulo de largura 10 e altura 10: " << area2 << std::endl;
    std::cout << "- Soma das areas: " << area1 + area2 << std::endl;
    std::cout << std::endl;

    std::cout << "Adicionando as formas na tela de desenho" << std::endl;
    tela.adicionarForma(forma2);
    tela.adicionarForma(retangulo);

    std::cout << "Area total: " << tela.calcularAreaTotal() << std::endl;

    return 0;
}
