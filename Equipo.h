#include <iostream>
#include <iomanip>
#include "Portero.h"
#include "Defensa.h"
#include "Medio.h"
#include "Delantero.h"

#ifndef EQUIPO
#define EQUIPO

namespace eqp {
    class Equipo
    {
    private:
        ptr::Portero portero;
        dfs::Defensa defensa1;
        dfs::Defensa defensa2;
        mdo::Medio medio1;
        mdo::Medio medio2;
        dtr::Delantero delantero1;
        dtr::Delantero delantero2;
        int partidosPerdidos;
        int partidosJugados;
        int partidosGanados;
        int partidosEmpatados;
        int puntos;
        int goles;
        float rating;
        std::string nombre;

    public:
        Equipo(){};
        ~Equipo(){};
        Equipo(std::string nombre, ptr::Portero portero, dfs::Defensa defensa1, dfs::Defensa defensa2, mdo::Medio medio1, mdo::Medio medio2, dtr::Delantero delantero1, dtr::Delantero delantero2)
        {
            this->portero = portero;
            this->defensa1 = defensa1;
            this->defensa2 = defensa2;
            this->medio1 = medio1;
            this->medio2 = medio2;
            this->delantero1 = delantero1;
            this->delantero2 = delantero2;
            this-> nombre = nombre;
            setRating();
            this-> goles = 0;
            this-> partidosPerdidos = 0;
            this-> partidosEmpatados = 0;
            this-> partidosGanados = 0;
            this-> puntos = 0;
        }

        void setRating(){
            this-> rating = (portero.getRating() + defensa1.getRating() + defensa2.getRating() + medio1.getRating() + medio2.getRating()  + delantero1.getRating() + delantero2.getRating())/7;
        };

        float getRating(){
            return rating;
        }

        ptr::Portero getPortero(){
            return portero;
        }

        dfs::Defensa getDefensa1(){
            return defensa1;
        }

        dfs::Defensa getDefensa2(){
            return defensa2;
        }

        mdo::Medio getMedio1(){
            return medio1;
        }

        mdo::Medio getMedio2(){
            return medio2;
        }

        dtr::Delantero getDelantero1(){
            return delantero1;
        }

        dtr::Delantero getDelantero2(){
            return delantero2;
        }

        int getGoles(){
            return goles;
        }

        void setGoles(int nGoles){
            goles += nGoles;
        }

        std::string getNombre(){
            return nombre;
        }

        void setNombre(std::string nombre){
            this-> nombre = nombre;
        }

        int getPP(){
            return partidosPerdidos;
        }

        int getPE(){
            return partidosEmpatados;
        }

        int getPG(){
            return partidosGanados;
        }

        int getPuntos() const {
            return puntos;
        }

        void actualizarDatos(std::string status, unsigned int gol){
            partidosJugados += 1;
            goles += gol;
            if (status == "Ganado"){
                partidosGanados += 1;
                puntos += 3;
            }
            else if (status == "Perdido"){
                partidosPerdidos += 1;
            }
            else if (status == "Empatado"){
                partidosEmpatados += 1;
                puntos += 1;
            }
        }

        void mostrarPlantilla(){
            std::cout<<"Nombre: "<<portero.getNombre()<<std::setw(20 - portero.getNombre().size())<<"Numero: "<<portero.getNumero()<<std::endl;
            std::cout<<"Nombre: "<<defensa1.getNombre()<<std::setw(20 - defensa1.getNombre().size())<<"Numero: "<<defensa1.getNumero()<<std::endl;
            std::cout<<"Nombre: "<<defensa2.getNombre()<<std::setw(20 - defensa2.getNombre().size())<<"Numero: "<<defensa2.getNumero()<<std::endl;
            std::cout<<"Nombre: "<<medio1.getNombre()<<std::setw(20 - medio1.getNombre().size())<<"Numero: "<<medio1.getNumero()<<std::endl;
            std::cout<<"Nombre: "<<medio2.getNombre()<<std::setw(20 - medio2.getNombre().size())<<"Numero: "<<medio2.getNumero()<<std::endl;
            std::cout<<"Nombre: "<<delantero1.getNombre()<<std::setw(20 - delantero1.getNombre().size())<<"Numero: "<<delantero1.getNumero()<<std::endl;
            std::cout<<"Nombre: "<<delantero2.getNombre()<<std::setw(20 - delantero2.getNombre().size())<<"Numero: "<<delantero2.getNumero()<<std::endl;
        }
        
        void mostrarDatos(){
            std::cout<<"Nombre: "<<nombre<<std::setw(20 - nombre.size())<<"Goles: "<<goles<<std::setw(20)<<"Rating: "<<rating<<std::endl;
        }
    };
};

#endif
