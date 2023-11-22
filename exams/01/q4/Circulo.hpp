#ifndef CIRCULO_HPP
#define CIRCULO_HPP

#include <cstdint>

#include "Forma.hpp"

constexpr double PI = 3.14;

class Circulo : public Forma {
   public:
    Circulo();
    Circulo(const int raio);
    virtual ~Circulo() = default;

    const int getRaio() const;
    void setRaio(const int raio);

    virtual const double area() const override;

   private:
    uint32_t raio;
};

#endif
