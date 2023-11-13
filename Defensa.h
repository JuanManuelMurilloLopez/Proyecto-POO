#include <iostream>
#include "Jugador.h"

#ifndef DEFENSA
#define DEFENSA

namespace dfs {
    class Defensa : public Jugador{
        private:
            std::string posicion;
            int intercepcionesPPartido;
        public:
            Defensa(){};
            ~Defensa(){};
            Defensa(std::string nombre, int numero, int rating, std::string posicion) : Jugador(nombre, numero, rating){
                this-> intercepcionesPPartido = 0;
                this-> posicion = posicion;
            };
    };
};

#endif