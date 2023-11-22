#ifndef CPF_INVALIDO_EXCEPTION_HPP
#define CPF_INVALIDO_EXCEPTION_HPP

#include <stdexcept>

class CPFInvalidoException : public std::runtime_error {
    public:
        const unsigned long cpf;
        
        CPFInvalidoException(const unsigned long cpf);
        virtual ~CPFInvalidoException() = default;
};

#endif
