#include <iostream>
#include "Jugador.h"

#ifndef DEFENSA
#define DEFENSA

namespace dfs {
    class Defensa : public Jugador{
        private:
            std::string posicion;
            int intercepciones;
        public:
            Defensa(){};
            ~Defensa(){};
            Defensa(std::string nombre, int numero, int rating, std::string posicion) : Jugador(nombre, numero, rating){
                this-> intercepciones = 0;
                this-> posicion = posicion;
            };
            void setIntercepciones(int intercep){
                this-> intercepciones += intercep;
            }
            int getIntercepciones(){
                return intercepciones;
            }
            void mostrarDatos() override {
                std::cout<<"Nombre: "<<getNombre()<<std::endl;
                std::cout<<"Numero: "<<getNumero()<<std::endl;
                std::cout<<"Rating: "<<getRating()<<std::endl;
                std::cout<<"Intercepciones: "<<getIntercepciones()<<std::endl;
            }
    };
};

#endif
