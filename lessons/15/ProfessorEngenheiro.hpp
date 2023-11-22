#ifndef PROFESSOR_ENGENHEIRO_HPP
#define PROFESSOR_ENGENHEIRO_HPP

#include "Engenheiro.hpp"
#include "Professor.hpp"

class ProfessorEngenheiro : public Professor, public Engenheiro {
   public:
    ProfessorEngenheiro(const std::string& nome, const unsigned long cpf, const float valorHora,
                        const unsigned short cargaHoraria, const unsigned int numeroCrea);

    virtual ~ProfessorEngenheiro();
};

#endif
