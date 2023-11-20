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
            int getGoles(){
                return goles;
            }
            void mostrarDatos() override {
                std::cout<<"Nombre: "<<getNombre()<<std::endl;
                std::cout<<"Numero: "<<getNumero()<<std::endl;
                std::cout<<"Rating: "<<getRating()<<std::endl;
                std::cout<<"Goles: "<<getGoles()<<std::endl;
            }
    };
};

#endif
