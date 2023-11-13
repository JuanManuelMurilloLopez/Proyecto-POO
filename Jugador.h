#include <iostream>
#ifndef JUGADOR
#define JUGADOR

class Jugador{
    private:
        std::string nombre;
        int numero;
        int rating;
    public: 
        Jugador(){
            this-> nombre = "";
            this-> numero = 0;
            this-> rating = 0;
        };
        ~Jugador(){};
        Jugador(std::string nombre, int numero, int rating){
            this-> nombre = nombre;
            setNumero(numero);
            setRating(rating);
        };
        void setNumero(int numero){
            this-> numero = numero;
        }
        void setRating(int rating){
            this-> rating = rating;
        }
        std::string getNombre(){
            return nombre;
        }
        int getNumero(){
            return numero;
        }
        int getRating(){
            return rating;
        }
};

#endif