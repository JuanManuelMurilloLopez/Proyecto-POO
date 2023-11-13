#include <iostream>
#include "Jugador.h"
#include "Portero.h"
#include "Defensa.h"
#include "Medio.h"
#include "Delantero.h"
#include "Equipo.h"
#include "Partido.h"
#include "Jornada.h"
#include "Liga.h"

int main(){
    dtr::Delantero delantero1("Messi",10,100,"DC");
    dfs::Defensa defensa1("Pique",3,90,"Def Central");
    mdo::Medio medio1("Xavi",6,95,"MCO");

    std::cout<<delantero1.getNombre()<<std::endl;
    std::cout<<defensa1.getNumero()<<std::endl;
    std::cout<<medio1.getRating()<<std::endl;
    return 0;
};