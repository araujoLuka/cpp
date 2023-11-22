#include "Ementa.hpp"


namespace ufpr{

Ementa::Ementa():livros{new std::list<Livro>}{}

Ementa::Ementa(const std::string descricao)
        :descricao{descricao}, livros{new std::list<Livro>}{
}

Ementa::Ementa(const Ementa& ementa)
        :descricao{ementa.descricao}, livros{new std::list<Livro>{*ementa.livros}}{
}

Ementa::Ementa(Ementa&& ementa)
        :descricao(ementa.descricao), livros(ementa.livros){
    ementa.livros = nullptr;
}

Ementa::~Ementa(){
    delete livros;    
}

void Ementa::setDescricao(const std::string& descricao){
    this->descricao = descricao;
}

const std::string& Ementa::getDescricao() const{
    return this->descricao;
}

void Ementa::addLivro(const Livro& livro){
    this->livros->push_back(livro);
}

const std::list<Livro>* Ementa::getLivros() const{
    return this->livros;
}

Ementa& Ementa::operator=(Ementa&& ementa) {
    if (this == &ementa)
        return *this;
    this->descricao = ementa.descricao;
    this->livros = ementa.livros;
    ementa.livros = nullptr;

    return *this;
}

const Ementa& Ementa::operator=(const Ementa& ementa) {
    if (this == &ementa)
        return *this;
    this->descricao = ementa.descricao;
    delete this->livros;
    this->livros = new std::list<Livro>(*ementa.livros);

    return *this;
}

}
