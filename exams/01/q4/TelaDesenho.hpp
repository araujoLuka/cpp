#ifndef TELA_DESENHO_HPP
#define TELA_DESENHO_HPP

#include <list>

#include "Forma.hpp"

class TelaDesenho {
   public:
    TelaDesenho();
    virtual ~TelaDesenho();

    void adicionarForma(const Forma* const forma);
    const double calcularAreaTotal() const;

   private:
    std::list<const Forma*> *formas;
};

#endif
