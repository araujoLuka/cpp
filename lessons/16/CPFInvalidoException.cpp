#include "CPFInvalidoException.hpp"

CPFInvalidoException::CPFInvalidoException(const unsigned long cpf)
    : std::runtime_error{"CPF inválido"}, cpf{cpf} {}
