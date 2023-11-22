#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <cstdint>

#include "Pessoa.hpp"

class Professor : public Pessoa {
   public:
    Professor(const std::string& nome, const uint64_t cpf,
              const unsigned int valorHora, const unsigned short cargaHoraria);
    ~Professor();

    unsigned int getValorHora() const;
    void setValorHora(const unsigned int valorHora);

    unsigned int getCargaHoraria() const;
    void setCargaHoraria(const unsigned short cargaHoraria);

    unsigned int getSalario() const;

   private:
    unsigned int valorHora;
    unsigned short cargaHoraria;
};

#endif
