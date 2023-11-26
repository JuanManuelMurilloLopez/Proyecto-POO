/*
Simulador de Liga de Futbol 7 con 10 equipos.
Autor: Juan Manuel Murillo López
Fecha de Modificación:  26/11/23
*/

#include <iostream>
#include <vector>
#include <array>
#include <windows.h>
#include <algorithm>
#include "objetos.h"

unsigned int simularGoles(eqp::Equipo& equipo){
    const float PROB_BASE_MIN = 0.3;
    const float PROB_BASE_MAX = 0.6;
    const float RATINGAJUSTE = 0.01;
    float probabilidadBase = PROB_BASE_MIN + static_cast<float>(std::rand()) / RAND_MAX * (PROB_BASE_MAX - PROB_BASE_MIN);
    float probabilidad = probabilidadBase + RATINGAJUSTE * equipo.getRating();
    unsigned int goles = 0;
    unsigned int intentos = 1 + std::rand() % 2;
    for (unsigned int i = 0; i < intentos; ++i) {
        float random = static_cast<float>(std::rand()) / RAND_MAX;
        if (random < probabilidad) {
            goles++;
        }
    }
    return goles;
}

void simularAsistencias(eqp::Equipo& equipo1,unsigned int goles){
    for(unsigned int i = 0; i < goles; i++){
        unsigned int random = std::rand() % 2;
        if(random == 0){
            equipo1.getMedio1().setAsNueva();
        }
        else{
            equipo1.getMedio2().setAsNueva();
        }
    }
}

void simularPorteriaInvicta(eqp::Equipo& equipo, unsigned int golesEnContra){
    if(golesEnContra == 0){
        equipo.getPortero().nuevaPInv();
    }
}

void simularIntercepciones(eqp::Equipo& equipo){
    int intercepciones = std::rand() % 8;
    equipo.getDefensa1().setIntercepciones(intercepciones);
    equipo.getDefensa2().setIntercepciones(intercepciones);
}

void simularPartido(eqp::Equipo& equipo1, eqp::Equipo& equipo2){
    unsigned int golesEq1 = simularGoles(equipo1);
    unsigned int golesEq2 = simularGoles(equipo2);
    simularAsistencias(equipo1, golesEq1);
    simularAsistencias(equipo2, golesEq2);
    simularPorteriaInvicta(equipo1, golesEq2);
    simularPorteriaInvicta(equipo2, golesEq1);
    simularIntercepciones(equipo1);
    simularIntercepciones(equipo2);
    if(golesEq1 < golesEq2){
        equipo1.actualizarDatos("Perdido", golesEq1);
        equipo2.actualizarDatos("Ganado", golesEq2);
    }
    else if(golesEq1 == golesEq2){
        equipo1.actualizarDatos("Empatado", golesEq1);
        equipo2.actualizarDatos("Empatado", golesEq2);
    }
    else{
        equipo1.actualizarDatos("Ganado", golesEq1);
        equipo2.actualizarDatos("Perdido", golesEq2);
    }
}

void mostrarTabla(){
    std::vector<eqp::Equipo> arrayEquiposSort(arrayEquipos, arrayEquipos + 10);
    std::sort(arrayEquiposSort.begin(), arrayEquiposSort.end(), [](const eqp::Equipo& equipoX, const eqp::Equipo& equipoY) {
        return equipoX.getPuntos() > equipoY.getPuntos();
    });
    //Crear el diseño de la tabla
    std::cout << std::setw(10) << "Nombre"
        << std::setw(50) << "Goles"
        << std::setw(10) << "PG"
        << std::setw(10) <<"PE"
        << std::setw(10) << "PP"
        << std::setw(10) << "puntos" << std::endl;
    std::cout << std::setfill('-') << std::setw(150) 
        << "" << std::setfill(' ') << std::endl; 
    for(unsigned int i = 0;i < 10; i++){
        std::cout<<arrayEquiposSort[i].getNombre()<<std::setw(60 - arrayEquiposSort[i].getNombre().size())<<arrayEquiposSort[i].getGoles()<<std::setw(10)<<arrayEquiposSort[i].getPG()<<std::setw(10)<<arrayEquiposSort[i].getPE()<<std::setw(10)<<arrayEquiposSort[i].getPP()<<std::setw(10)<<arrayEquiposSort[i].getPuntos()<<std::endl;
    }
}





int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    unsigned int jornada = 1;
    //Iniciar Juego
    std::cout<<"Presione Enter para iniciar"<<std::endl;
    std::cin.get();
    //Crear delay
    std::cout<<"Cargando Juego"<<std::endl;
    for(unsigned int i = 0; i<10; i++){
        std::cout<<"*";
        Sleep(100);
    }
    
    std::cout<<""<<std::endl;
    //Imprimir los nombres de los equipos
    std::cout<<"Seleccione un equipo"<<std::endl;
    for(unsigned int i = 0; i<10; i++){
        std::cout<<nombresEquipos[i];
        std::cout<<" , ";
    }

    std::cout<<""<<std::endl;
    //El usuario selecciona el nombre del equipo con el que desea jugar
    std::string NomEqJug = "";
    std::getline(std::cin,NomEqJug);
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            std::cout<<"Numero de jornada: "<<jornada<<std::endl;
            std::cout<<"Partidos: "<<std::endl;
            for(int i = 0; i < 5; i++){
                partidosLiga[jornada][i].anunciarPartido();
            }
            std::cout<<"Presione Enter para jugar jornada"<<std::endl;
            std::cin.get();
            std::cout<<"Simulando Jornada"<<std::endl;
            for(unsigned int i = 0; i<10; i++){
                std::cout<<"*";
                Sleep(100);
            }
            std::cout<<""<<std::endl;
            if(jornada == 1){
                simularPartido(arrayEquipos[0], arrayEquipos[9]);
                simularPartido(arrayEquipos[1], arrayEquipos[8]);
                simularPartido(arrayEquipos[2], arrayEquipos[7]);
                simularPartido(arrayEquipos[3], arrayEquipos[6]);
                simularPartido(arrayEquipos[4], arrayEquipos[5]);              
            }
            if(jornada == 2){
                simularPartido(arrayEquipos[0], arrayEquipos[8]);
                simularPartido(arrayEquipos[9], arrayEquipos[7]);
                simularPartido(arrayEquipos[1], arrayEquipos[6]);
                simularPartido(arrayEquipos[2], arrayEquipos[5]);
                simularPartido(arrayEquipos[3], arrayEquipos[4]);
            }
            if(jornada == 3){
                simularPartido(arrayEquipos[0], arrayEquipos[7]);
                simularPartido(arrayEquipos[8], arrayEquipos[6]);
                simularPartido(arrayEquipos[9], arrayEquipos[5]);
                simularPartido(arrayEquipos[1], arrayEquipos[4]);
                simularPartido(arrayEquipos[2], arrayEquipos[3]);
            }
            if(jornada == 4){
                simularPartido(arrayEquipos[0], arrayEquipos[6]);
                simularPartido(arrayEquipos[7], arrayEquipos[5]);
                simularPartido(arrayEquipos[8], arrayEquipos[4]);
                simularPartido(arrayEquipos[9], arrayEquipos[3]);
                simularPartido(arrayEquipos[1], arrayEquipos[2]);
            }
            if(jornada == 5){
                simularPartido(arrayEquipos[0],arrayEquipos[5]);
                simularPartido(arrayEquipos[6],arrayEquipos[4]);
                simularPartido(arrayEquipos[7],arrayEquipos[3]);
                simularPartido(arrayEquipos[8],arrayEquipos[2]);
                simularPartido(arrayEquipos[9],arrayEquipos[1]);
            }
            if(jornada == 6){
                simularPartido(arrayEquipos[0],arrayEquipos[4]);
                simularPartido(arrayEquipos[5],arrayEquipos[3]);
                simularPartido(arrayEquipos[6],arrayEquipos[2]);
                simularPartido(arrayEquipos[7],arrayEquipos[1]);
                simularPartido(arrayEquipos[8],arrayEquipos[9]);
            }
            if(jornada == 7){
                simularPartido(arrayEquipos[0],arrayEquipos[3]);
                simularPartido(arrayEquipos[4],arrayEquipos[2]);
                simularPartido(arrayEquipos[5],arrayEquipos[1]);
                simularPartido(arrayEquipos[6],arrayEquipos[9]);
                simularPartido(arrayEquipos[7],arrayEquipos[8]);
            }
            if(jornada == 8){
                simularPartido(arrayEquipos[0],arrayEquipos[2]);
                simularPartido(arrayEquipos[3],arrayEquipos[1]);
                simularPartido(arrayEquipos[4],arrayEquipos[9]);
                simularPartido(arrayEquipos[5],arrayEquipos[8]);
                simularPartido(arrayEquipos[6],arrayEquipos[7]);
            }
            if(jornada == 9){
                simularPartido(arrayEquipos[0],arrayEquipos[1]);
                simularPartido(arrayEquipos[2],arrayEquipos[9]);
                simularPartido(arrayEquipos[3],arrayEquipos[8]);
                simularPartido(arrayEquipos[4],arrayEquipos[7]);
                simularPartido(arrayEquipos[5],arrayEquipos[6]);
                std::cout<<"La liga se ha terminado, consulta la tabla para conocer al ganador"<<std::endl;
            }
            jornada += 1;
        }
    }
    return 0;
};
