#ifndef RETANGULO_HPP
#define RETANGULO_HPP

#include <cstdint>
#include "Forma.hpp"

class Retangulo : public Forma {
   public:
    Retangulo();
    Retangulo(const int largura, const int altura);
    virtual ~Retangulo() = default;

    const int getLargura() const;
    const int getAltura() const;
    void setLargura(const int largura);
    void setAltura(const int altura);

    virtual const double area() const override;

   private:
    uint32_t largura;
    uint32_t altura;
};

#endif
