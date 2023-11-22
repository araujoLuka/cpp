#ifndef CONSOLE_HPP
#define CONSOLE_HPP

class Trajeto;
class TrajetoManhattan;
class TrajetoEuclidiano;

class Console{
    public:
        virtual ~Console() = default;    

        static void imprimirDadosTrajeto(const Trajeto* const trajeto);
};

#endif
