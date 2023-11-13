#include <iostream>
#include "Jugador.h"

#ifndef PORTERO
#define PORTERO

namespace ptr {
    class Portero : public Jugador{
        private:
            int porteriaInvicta;
        public: 
            Portero(){
                this-> porteriaInvicta = 0;
            };
            ~Portero(){};
            Portero(std::string nombre, int numero, int rating) : Jugador(nombre, numero, rating){
                this-> porteriaInvicta = 0;
            };
            void nuevaPInv(){
                porteriaInvicta += 1;
            }
};
};

#endif