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

    public:
        Equipo(){};
        ~Equipo(){};
        Equipo(ptr::Portero portero, dfs::Defensa defensa1, dfs::Defensa defensa2, mdo::Medio medio1, mdo::Medio medio2, dtr::Delantero delantero1, dtr::Delantero delantero2)
        {
            this->portero = portero;
            this->defensa1 = defensa1;
            this->defensa2 = defensa2;
            this->medio1 = medio1;
            this->medio2 = medio2;
            this->delantero1 = delantero1;
            this->delantero2 = delantero2;
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
        int getPP(){
            return partidosPerdidos;
        }
        int getPE(){
            return partidosEmpatados;
        }
        int getPG(){
            return partidosGanados;
        }
        int getPuntos(){
            return puntos;
        }
        void actualizarDatos(std::string status){
            partidosJugados += 1;
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
            std::cout<<portero.getNombre()<<std::setw(10)<<portero.getNumero()<<std::endl;
            std::cout<<defensa1.getNombre()<<std::setw(10)<<defensa1.getNumero()<<std::endl;
            std::cout<<defensa2.getNombre()<<std::setw(10)<<defensa2.getNumero()<<std::endl;
            std::cout<<medio1.getNombre()<<std::setw(10)<<medio1.getNumero()<<std::endl;
            std::cout<<medio2.getNombre()<<std::setw(10)<<medio2.getNumero()<<std::endl;
            std::cout<<delantero1.getNombre()<<std::setw(10)<<delantero1.getNumero()<<std::endl;
            std::cout<<delantero2.getNombre()<<std::setw(10)<<delantero2.getNumero()<<std::endl;
        }
    };
};

#endif