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
            int getPorteriaInvicta(){
                return porteriaInvicta;
            }
            void mostrarDatos() override {
                std::cout<<"Nombre: "<<getNombre()<<std::endl;
                std::cout<<"Numero: "<<getNumero()<<std::endl;
                std::cout<<"Rating: "<<getRating()<<std::endl;
                std::cout<<"Porterias Invictas: "<<getPorteriaInvicta()<<std::endl;
            }
};
};

#endif
