#ifndef EMENTA_HPP
#define EMENTA_HPP

#include <string>
#include <list>

#include "Livro.hpp"

namespace ufpr{
class Ementa{
    public:
        Ementa();
        Ementa(const std::string descricao);
        Ementa(const Ementa& ementa);
        Ementa(Ementa&& ementa);
        virtual ~Ementa();

        void setDescricao(const std::string& descricao);
        const std::string& getDescricao() const;

        void addLivro(const Livro& livro);
        const std::list<Livro>* getLivros() const;

        Ementa& operator=(Ementa&& ementa);
        const Ementa& operator=(const Ementa& ementa);

    private:
        std::string descricao;
        std::list<Livro>* livros;
};
}
#endif
