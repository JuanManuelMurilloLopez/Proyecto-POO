#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Equipo.h"

#ifndef PARTIDO
#define PARTIDO

namespace ptd{
    class Partido{
        private:
            eqp::Equipo equipo1;
            eqp::Equipo equipo2;
            std::string eqGanador;
            int golesEq1;
            int golesEq2;
            
            int simularGoles(eqp::Equipo& equipo) {
                float probabilidad = equipo.getRating();
                float random = static_cast<float>(std::rand())/RAND_MAX;
                if (random < probabilidad) {
                    return 1;
                }
                else{
                    return 0;
                }
            }
            void simularAsistencias(eqp::Equipo& equipo, int goles){
                for (int i = 0; i<goles; i++){
                    int random = std::rand() % 2;
                    if(random == 0){
                        equipo.getMedio1().setAsNueva();
                    }
                    else{
                        equipo.getMedio2().setAsNueva();
                    }
                }
            }
            void simularPorteriaInvicta(eqp::Equipo& equipo, int golesEnContra) {
                if (golesEnContra == 0){
                    equipo.getPortero().nuevaPInv();
                }
            }
            void simularIntercepciones(eqp::Equipo& equipo) {
                int intercepciones = std::rand() % 8;
                equipo.getDefensa1().setIntercepciones(intercepciones);
                equipo.getDefensa2().setIntercepciones(intercepciones);
            }
            void setEqGanador(){
                if(golesEq1 < golesEq2){
                    eqGanador = equipo2.getNombre();
                    equipo2.actualizarDatos("Ganado", golesEq1);
                    equipo1.actualizarDatos("Perdido", golesEq2);
                }
                else if(golesEq1 > golesEq2){
                    eqGanador = equipo1.getNombre();
                    equipo1.actualizarDatos("Ganado", golesEq1);
                    equipo2.actualizarDatos("Perdido", golesEq2);
                }
                else{
                    eqGanador = "Empate";
                    equipo2.actualizarDatos("Empatado", golesEq1);
                    equipo1.actualizarDatos("Empatado", golesEq2);
                }
            }
        public:
            Partido(){};
            ~Partido(){};
            Partido(eqp::Equipo equipo1, eqp::Equipo equipo2){
                setEquipos(equipo1, equipo2);
            };
            void setEquipos(eqp::Equipo equipo1, eqp::Equipo equipo2){
                this-> equipo1 = equipo1;
                this-> equipo2 = equipo2;
            }
            int getGolesEq1(){
                return golesEq1;
            }
            int getGolesEq2(){
                return golesEq2;
            }
            eqp::Equipo getEquipo1(){
                return equipo1;
            }
            eqp::Equipo getEquipo2(){
                return equipo2;
            }
            void simularPartido(){
                std::srand(static_cast<unsigned int>(std::time(nullptr)));
                golesEq1 = simularGoles(equipo1);
                golesEq2 = simularGoles(equipo2);
                equipo1.setGoles(golesEq1);
                equipo2.setGoles(golesEq2);
                
                simularAsistencias(equipo1, golesEq1);
                simularAsistencias(equipo2, golesEq2);

                simularPorteriaInvicta(equipo1, golesEq1);
                simularPorteriaInvicta(equipo2, golesEq1);

                simularIntercepciones(equipo1);
                simularIntercepciones(equipo2);

                setEqGanador();
            }
            void anunciarPartido(){
                std::cout<<equipo1.getNombre()<<" vs "<<equipo2.getNombre()<<std::endl;
            }
    };
};

#endif