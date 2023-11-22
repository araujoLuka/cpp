#ifndef PROFESSOR_ADJUNTO_HPP
#define PROFESSOR_ADJUNTO_HPP

#include <string>

#include "Professor.hpp"

class ProfessorAdjunto : public Professor {
   public:
    // This constructor will call the constructor of the base class
    // Valid only for C++11 or newer
    using Professor::Professor;

    const std::string& getLinhaPesquisa() const;
    void setLinhaPesquisa(const std::string& linhaPesquisa);

    unsigned int getSalario() const;

   private:
    std::string linhaPesquisa;
};

#endif
