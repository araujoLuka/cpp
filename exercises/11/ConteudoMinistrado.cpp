#include "ConteudoMinistrado.hpp"

unsigned int ConteudoMinistrado::proxId{0};

ConteudoMinistrado::ConteudoMinistrado(std::string descricao,
                                       unsigned short cargaHorariaConteudo)
    : descricao{descricao},
      cargaHorariaConteudo{cargaHorariaConteudo},
      id{ConteudoMinistrado::proxId} {
    ConteudoMinistrado::proxId++;
}

ConteudoMinistrado::~ConteudoMinistrado() {
    // altera a descricao para string vazia para evitar
    // que o dado fique em lixo de memoria
    this->descricao = "";
}

std::string& ConteudoMinistrado::getDescricao() { return descricao; }

unsigned short ConteudoMinistrado::getCargaHorariaConteudo() {
    return cargaHorariaConteudo;
}

unsigned int ConteudoMinistrado::getId() { return id; }
