#include <iostream>
#include "Jugador.h"

#ifndef DELANTERO
#define DELANTERO

namespace dtr{
    class Delantero : public Jugador{
        private:
            std::string posicion;
            int goles;
        public:
            Delantero(){};
            ~Delantero(){};
            Delantero(std::string nombre, int numero, int rating, std::string posicion) :Jugador(nombre, numero, rating){
                this-> posicion = posicion;
                this-> goles = 0;
            };
    };
};

#endif