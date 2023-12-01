#include <iostream>
#include <iomanip>
#ifndef JUGADOR
#define JUGADOR

class Jugador{
    protected:
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
        virtual void mostrarDatos(){
            std::cout<<"Nombre: "<<getNombre()<<std::endl;
            std::cout<<"Numero: "<<getNumero()<<std::endl;
            std::cout<<"Rating: "<<getRating()<<std::endl;
        }
};

#endif
