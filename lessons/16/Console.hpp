#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Disciplina.hpp"

class Console{
	public:
		virtual ~Console() = default;

		static void imprimirDadosDisciplina(const Disciplina& disciplina);
	
};
#endif
