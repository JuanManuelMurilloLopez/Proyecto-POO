#include <iostream>
#include "Jugador.h"

#ifndef MEDIO
#define MEDIO

namespace mdo {
    class Medio : public Jugador{
        private:
            std::string posicion;
            int asistencias;
        public:
            Medio(){};
            ~Medio(){};
            Medio(std::string nombre, int numero, int rating, std::string posicion) : Jugador(nombre, numero, rating){
                this-> posicion = posicion;
                this-> asistencias = 0;
            };
    };

};

#endif