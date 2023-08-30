#ifndef CURSO_HPP
#define CURSO_HPP

#include <cstdint>
#include <string>

class Curso {
   public:
    Curso();
    Curso(std::string nome);
    Curso(std::string nome, uint16_t cargaHoraria, uint16_t anoCriacao);

    std::string getNome();
    void setNome(std::string nome);

    int getCargaHoraria();
    void setCargaHoraria(uint16_t cargaHoraria);

    int getAnoCriacao();
    void setAnoCriacao(uint16_t anoCriacao);

   private:
    std::string nome;
    uint16_t cargaHoraria;
    uint16_t anoCriacao;
};

#endif
