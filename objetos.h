#include <iostream>
#include <vector>
#include <array>
#include "Jugador.h"
#include "Equipo.h"
#include "Jornada.h"
#include "Liga.h"

#ifndef OBJETOS
#define OBJETOS

    //Equipo1
    ptr::Portero portero1Eq1("Curtois",1,209);
    dfs::Defensa defensa1Eq1("Juanfran",2,238,"pos");
    dfs::Defensa defensa2Eq1("Miranda",3,212,"pos");
    mdo::Medio medio1Eq1("Gabi",4,236,"pos");
    mdo::Medio medio2Eq1("Felipe",5,238,"pos");
    dtr::Delantero delantero1Eq1("Diego Costa",6,236,"pos");
    dtr::Delantero delantero2Eq1("Raul Garcia",7,212,"pos");

    eqp::Equipo equipo1("Atletico de Madrid",portero1Eq1, defensa1Eq1, defensa2Eq1, medio1Eq1, medio2Eq1, delantero1Eq1, delantero2Eq1);

    //Equipo2
    ptr::Portero portero1Eq2("Victor Valdes",1,212);
    dfs::Defensa defensa1Eq2("Dani Alves",2,244,"pos");
    dfs::Defensa defensa2Eq2("Mascherano",3,222,"pos");
    mdo::Medio medio1Eq2("Xavi",4,246,"pos");
    mdo::Medio medio2Eq2("Iniesta",5,240,"pos");
    dtr::Delantero delantero1Eq2("Messi",6,238,"pos");
    dtr::Delantero delantero2Eq2("Pedro",7,217,"pos");

    eqp::Equipo equipo2("Barcelona",portero1Eq2, defensa1Eq2, defensa2Eq2, medio1Eq2, medio2Eq2, delantero1Eq2, delantero2Eq2);

    //Equipo3
    ptr::Portero portero1Eq3("Casilla",1,205);
    dfs::Defensa defensa1Eq3("Hector Moreno",2,222,"pos");
    dfs::Defensa defensa2Eq3("Javi Lopez",3,205,"pos");
    mdo::Medio medio1Eq3("Victor Sanchez",4,220,"pos");
    mdo::Medio medio2Eq3("Simao",5,200,"pos");
    dtr::Delantero delantero1Eq3("Torje",6,192,"pos");
    dtr::Delantero delantero2Eq3("Lanzarote",7,192,"pos");

    eqp::Equipo equipo3("Espanyol",portero1Eq3, defensa1Eq3, defensa2Eq3, medio1Eq3, medio2Eq3, delantero1Eq3, delantero2Eq3);

    //Equipo4
    ptr::Portero portero1Eq4("Casillas",1,207);
    dfs::Defensa defensa1Eq4("Pepe",2,233,"pos");
    dfs::Defensa defensa2Eq4("Marcelo",3,234,"pos");
    mdo::Medio medio1Eq4("Xabi Alonso",4,242,"pos");
    mdo::Medio medio2Eq4("Illarramendi",5,222,"pos");
    dtr::Delantero delantero1Eq4("Cristiano Ronaldo",6,241,"pos");
    dtr::Delantero delantero2Eq4("Benzema",7,214,"pos");

    eqp::Equipo equipo4("Real Madrid",portero1Eq4, defensa1Eq4, defensa2Eq4, medio1Eq4, medio2Eq4, delantero1Eq4, delantero2Eq4);

    //Equipo5
    ptr::Portero portero1Eq5("Bravo",1,212);
    dfs::Defensa defensa1Eq5("Carlos Martinez",2,209,"pos");
    dfs::Defensa defensa2Eq5("Mikel Gonzalez",3,204,"pos");
    mdo::Medio medio1Eq5("Markel",4,202,"pos");
    mdo::Medio medio2Eq5("Xabi Prieto",5,217,"pos");
    dtr::Delantero delantero1Eq5("Carlos Vela",6,226,"pos");
    dtr::Delantero delantero2Eq5("Aguirretxe",7,212,"pos");

    eqp::Equipo equipo5("Real Sociedad",portero1Eq5, defensa1Eq5, defensa2Eq5, medio1Eq5, medio2Eq5, delantero1Eq5, delantero2Eq5);

    //Equipo6
    ptr::Portero portero1Eq6("Beto",1,195);
    dfs::Defensa defensa1Eq6("Fernando Navarro",2,202,"pos");
    dfs::Defensa defensa2Eq6("Carrico",3,202,"pos");
    mdo::Medio medio1Eq6("Rakitic",4,228,"pos");
    mdo::Medio medio2Eq6("Iborra",5,124,"pos");
    dtr::Delantero delantero1Eq6("Bacca",6,213,"pos");
    dtr::Delantero delantero2Eq6("Gameiro",7,215,"pos");

    eqp::Equipo equipo6("Sevilla",portero1Eq6, defensa1Eq6, defensa2Eq6, medio1Eq6, medio2Eq6, delantero1Eq6, delantero2Eq6);
    
    //Equipo7
    ptr::Portero portero1Eq7("Diego Lopez",1,207);
    dfs::Defensa defensa1Eq7("Matheu",2,225,"pos");
    dfs::Defensa defensa2Eq7("Bernat",3,214,"pos");
    mdo::Medio medio1Eq7("Banega",4,228,"pos");
    mdo::Medio medio2Eq7("Parejo",5,207,"pos");
    dtr::Delantero delantero1Eq7("Pavon",6,211,"pos");
    dtr::Delantero delantero2Eq7("Helder Postiga",7,211,"pos");

    eqp::Equipo equipo7("Valencia",portero1Eq7, defensa1Eq7, defensa2Eq7, medio1Eq7, medio2Eq7, delantero1Eq7, delantero2Eq7);

    //Equipo8
    ptr::Portero portero1Eq8("Gorka Iraizoz",1,209);
    dfs::Defensa defensa1Eq8("Iraola",2,230,"pos");
    dfs::Defensa defensa2Eq8("Laporte",3,205,"pos");
    mdo::Medio medio1Eq8("De Marcos",4,217,"pos");
    mdo::Medio medio2Eq8("Susaeta",5,221,"pos");
    dtr::Delantero delantero1Eq8("Sola",6,203,"pos");
    dtr::Delantero delantero2Eq8("Ibai Gomez",7,192,"pos");

    eqp::Equipo equipo8("Athetic Club",portero1Eq8, defensa1Eq8, defensa2Eq8, medio1Eq8, medio2Eq8, delantero1Eq8, delantero2Eq8);

    //Equipo9
    ptr::Portero portero1Eq9("Esteban",1,199);
    dfs::Defensa defensa1Eq9("Rafita",2,196,"pos");
    dfs::Defensa defensa2Eq9("Trujillo",3,202,"pos");
    mdo::Medio medio1Eq9("Soriano",4,214,"pos");
    mdo::Medio medio2Eq9("Aleix Vidal",5,197,"pos");
    dtr::Delantero delantero1Eq9("Suso",6,210,"pos");
    dtr::Delantero delantero2Eq9("Oscar Diaz",7,189,"pos");

    eqp::Equipo equipo9("Almeria",portero1Eq9, defensa1Eq9, defensa2Eq9, medio1Eq9, medio2Eq9, delantero1Eq9, delantero2Eq9);

    //Equipo10
    ptr::Portero portero1Eq10("Marino",1,195);
    dfs::Defensa defensa1Eq10("Rukavina",2,222,"pos");
    dfs::Defensa defensa2Eq10("Baraja",3,195,"pos");
    mdo::Medio medio1Eq10("Larsson",4,197,"pos");
    mdo::Medio medio2Eq10("Ebert",5,219,"pos");
    dtr::Delantero delantero1Eq10("Javi Guerra",6,214,"pos");
    dtr::Delantero delantero2Eq10("Victor Perez",7,196,"pos");

    eqp::Equipo equipo10("Valladolid",portero1Eq10, defensa1Eq10, defensa2Eq10, medio1Eq10, medio2Eq10, delantero1Eq10, delantero2Eq10);

eqp::Equipo arrayEquipos[10] = {equipo1, equipo2, equipo3, equipo4, equipo5, equipo6, equipo7, equipo8, equipo9, equipo10};
std::string nombresEquipos[10] = {equipo1.getNombre(),equipo2.getNombre(),equipo3.getNombre(),equipo4.getNombre(),equipo5.getNombre(),equipo6.getNombre(),equipo7.getNombre(),equipo8.getNombre(),equipo9.getNombre(),equipo10.getNombre()};

ptd::Partido partido1J1(arrayEquipos[0], arrayEquipos[9]);
ptd::Partido partido2J1(arrayEquipos[1], arrayEquipos[8]);
ptd::Partido partido3J1(arrayEquipos[2], arrayEquipos[7]);
ptd::Partido partido4J1(arrayEquipos[3], arrayEquipos[6]);
ptd::Partido partido5J1(arrayEquipos[4], arrayEquipos[5]);
std::array<ptd::Partido, 5> partidosJ1 = {partido1J1, partido2J1, partido3J1, partido4J1, partido5J1};

ptd::Partido partido1J2(arrayEquipos[0], arrayEquipos[8]);
ptd::Partido partido2J2(arrayEquipos[9], arrayEquipos[7]);
ptd::Partido partido3J2(arrayEquipos[1], arrayEquipos[6]);
ptd::Partido partido4J2(arrayEquipos[2], arrayEquipos[5]);
ptd::Partido partido5J2(arrayEquipos[3], arrayEquipos[4]);
std::array<ptd::Partido, 5> partidosJ2 = {partido1J2, partido2J2, partido3J2, partido4J2, partido5J2};

ptd::Partido partido1J3(arrayEquipos[0], arrayEquipos[7]);
ptd::Partido partido2J3(arrayEquipos[8], arrayEquipos[6]);
ptd::Partido partido3J3(arrayEquipos[9], arrayEquipos[5]);
ptd::Partido partido4J3(arrayEquipos[1], arrayEquipos[4]);
ptd::Partido partido5J3(arrayEquipos[2], arrayEquipos[3]);
std::array<ptd::Partido, 5> partidosJ3 = {partido1J3, partido2J3, partido3J3, partido4J3, partido5J3};

ptd::Partido partido1J4(arrayEquipos[0], arrayEquipos[6]);
ptd::Partido partido2J4(arrayEquipos[7], arrayEquipos[5]);
ptd::Partido partido3J4(arrayEquipos[8], arrayEquipos[4]);
ptd::Partido partido4J4(arrayEquipos[9], arrayEquipos[3]);
ptd::Partido partido5J4(arrayEquipos[1], arrayEquipos[2]);
std::array<ptd::Partido, 5> partidosJ4 = {partido1J4, partido2J4, partido3J4, partido4J4, partido5J4};

ptd::Partido partido1J5(arrayEquipos[0],arrayEquipos[5]);
ptd::Partido partido2J5(arrayEquipos[6],arrayEquipos[4]);
ptd::Partido partido3J5(arrayEquipos[7],arrayEquipos[3]);
ptd::Partido partido4J5(arrayEquipos[8],arrayEquipos[2]);
ptd::Partido partido5J5(arrayEquipos[9],arrayEquipos[1]);
std::array<ptd::Partido, 5> partidosJ5 = {partido1J5, partido2J5, partido3J5, partido4J5, partido5J5};

ptd::Partido partido1J6(arrayEquipos[0],arrayEquipos[4]);
ptd::Partido partido2J6(arrayEquipos[5],arrayEquipos[3]);
ptd::Partido partido3J6(arrayEquipos[6],arrayEquipos[2]);
ptd::Partido partido4J6(arrayEquipos[7],arrayEquipos[1]);
ptd::Partido partido5J6(arrayEquipos[8],arrayEquipos[9]);
std::array<ptd::Partido, 5> partidosJ6 = {partido1J6, partido2J6, partido3J6, partido4J6, partido5J6};

ptd::Partido partido1J7(arrayEquipos[0],arrayEquipos[3]);
ptd::Partido partido2J7(arrayEquipos[4],arrayEquipos[2]);
ptd::Partido partido3J7(arrayEquipos[5],arrayEquipos[1]);
ptd::Partido partido4J7(arrayEquipos[6],arrayEquipos[9]);
ptd::Partido partido5J7(arrayEquipos[7],arrayEquipos[8]);
std::array<ptd::Partido, 5> partidosJ7 = {partido1J7, partido2J7, partido3J7, partido4J7, partido5J7};

ptd::Partido partido1J8(arrayEquipos[0],arrayEquipos[2]);
ptd::Partido partido2J8(arrayEquipos[3],arrayEquipos[1]);
ptd::Partido partido3J8(arrayEquipos[4],arrayEquipos[9]);
ptd::Partido partido4J8(arrayEquipos[5],arrayEquipos[8]);
ptd::Partido partido5J8(arrayEquipos[6],arrayEquipos[7]);
std::array<ptd::Partido, 5> partidosJ8 = {partido1J8, partido2J8, partido3J8, partido4J8, partido5J8};

ptd::Partido partido1J9(arrayEquipos[0],arrayEquipos[1]);
ptd::Partido partido2J9(arrayEquipos[2],arrayEquipos[9]);
ptd::Partido partido3J9(arrayEquipos[3],arrayEquipos[8]);
ptd::Partido partido4J9(arrayEquipos[4],arrayEquipos[7]);
ptd::Partido partido5J9(arrayEquipos[5],arrayEquipos[6]);
std::array<ptd::Partido, 5> partidosJ9 = {partido1J9, partido2J9, partido3J9, partido4J9, partido5J9};

std::array<std::array<ptd::Partido, 5>, 9> partidosLiga = {partidosJ1, partidosJ2, partidosJ3, partidosJ4, partidosJ5, partidosJ6, partidosJ7, partidosJ8, partidosJ9};




#endif
