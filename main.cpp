#include <iostream>
#include <vector>
#include <array>
#include <windows.h>
#include "Jugador.h"
#include "Portero.h"
#include "Defensa.h"
#include "Medio.h"
#include "Delantero.h"
#include "Equipo.h"
#include "Partido.h"
#include "Jornada.h"
#include "Liga.h"
#include "objetos.h"

void mostrarTabla(){
    //Crear el diseño de la tabla
    std::cout << std::setw(10) << "Nombre"
        << std::setw(60) << "Goles"
        << std::setw(10) << "PG"
        << std::setw(10) <<"PP"
        << std::setw(10) << "PE"
        << std::setw(10) << "puntos" << std::endl;
    std::cout << std::setfill('-') << std::setw(150) 
        << "" << std::setfill(' ') << std::endl; 
    for(int i = 0;i < 10; i++){
        std::cout<<arrayEquipos[i].getNombre()<<std::setw(60 - arrayEquipos[i].getNombre().size())<<arrayEquipos[i].getGoles()<<std::setw(10)<<arrayEquipos[i].getPG()<<std::setw(10)<<arrayEquipos[i].getPE()<<std::setw(10)<<arrayEquipos[i].getPP()<<std::setw(10)<<arrayEquipos[i].getPuntos()<<std::endl;
    }
}

int main(){

    //Iniciar Juego
    std::cout<<"Presione Enter para iniciar"<<std::endl;
    std::cin.get();
    //Crear delay
    std::cout<<"Cargando Juego"<<std::endl;
    for(int i = 0; i<10; i++){
        std::cout<<"*";
        Sleep(100);
    }
    std::cout<<""<<std::endl;
    //Imprimir los nombres de los equipos
    std::cout<<"Seleccione un equipo"<<std::endl;
    for(int i = 0; i<10; i++){
        std::cout<<nombresEquipos[i];
        std::cout<<"  ,  ";
    }
    std::cout<<""<<std::endl;
    //El usuario selecciona el nombre del equipo con el que desea jugar
    std::string NomEqJug = "";
    std::cin>>NomEqJug;
    int NumEqJug = -1;
    for(int i = 0; i<10; i++){
        if(NomEqJug == nombresEquipos[i]){
            arrayEquipos[i].setNombre(arrayEquipos[i].getNombre() + "(Mi Eq.)");
            NumEqJug = i;
        }
    }
    Sleep(500);
    std::cout<<std::setw(50)<<"Menu Principal"<<std::endl;
    unsigned int opcionMP = 0;
    //Se crea un menú ciclado para el Menú Principal
    while(opcionMP != 5){
        //Se da a elegir entre las funcionalidades
        std::cout<<"1- Mostrar Plantilla"<<std::endl;
        std::cout<<"2- Mostrar Estadisticas/Datos"<<std::endl;
        std::cout<<"3- Mostrar Tabla"<<std::endl;
        std::cout<<"4- Siguiente Jornada"<<std::endl;
        std::cout<<"5- Salir"<<std::endl;
        std::cin>>opcionMP;
        if(opcionMP == 1){
            arrayEquipos[NumEqJug].mostrarPlantilla();
        }
        else if(opcionMP == 2){
            unsigned int opcionEst = 0;
            std::cout<<"1- Estadisticas/Datos del equipo"<<std::endl;
            std::cout<<"2- Estadisticas/Datos de jugadores"<<std::endl;
            std::cin>>opcionEst;
            if(opcionEst == 1){
                arrayEquipos[NumEqJug].mostrarDatos();
            }
            else if(opcionEst == 2){
                //Muestra todos los jugadores del equipo y da la opcion de elegir uno para mostrar sus datos
                unsigned int opcEstJug = 0;
                std::cout<<"1- "<<arrayEquipos[NumEqJug].getPortero().getNombre()<<std::endl;
                std::cout<<"2- "<<arrayEquipos[NumEqJug].getDefensa1().getNombre()<<std::endl;
                std::cout<<"3- "<<arrayEquipos[NumEqJug].getDefensa2().getNombre()<<std::endl;
                std::cout<<"4- "<<arrayEquipos[NumEqJug].getMedio1().getNombre()<<std::endl;
                std::cout<<"5- "<<arrayEquipos[NumEqJug].getMedio2().getNombre()<<std::endl;
                std::cout<<"6- "<<arrayEquipos[NumEqJug].getDelantero1().getNombre()<<std::endl;
                std::cout<<"7- "<<arrayEquipos[NumEqJug].getDelantero2().getNombre()<<std::endl;
                std::cin>>opcEstJug;
                if(opcEstJug == 1){
                    arrayEquipos[NumEqJug].getPortero().mostrarDatos();
                }
                else if(opcEstJug == 2){
                    arrayEquipos[NumEqJug].getDefensa1().mostrarDatos();
                }
                else if(opcEstJug == 3){
                    arrayEquipos[NumEqJug].getDefensa2().mostrarDatos();
                }
                else if(opcEstJug == 4){
                    arrayEquipos[NumEqJug].getMedio1().mostrarDatos();
                }
                else if(opcEstJug == 5){
                    arrayEquipos[NumEqJug].getMedio2().mostrarDatos();
                }
                else if(opcEstJug == 6){
                    arrayEquipos[NumEqJug].getDelantero1().mostrarDatos();
                }
                else if(opcEstJug == 7){
                    arrayEquipos[NumEqJug].getDelantero2().mostrarDatos();
                }
            }
        }
        else if(opcionMP == 3){
            mostrarTabla();
        }
        else if(opcionMP == 4){
            std::cout<<"Proimamente"<<std::endl;
        }
    }
    return 0;
};
