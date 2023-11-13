#include "Partido.h"

#ifndef JORNADA
#define JORNADA

namespace jrn{
    class Jornada{
        private:
            ptd::Partido partido1;
            ptd::Partido partido2;
            ptd::Partido partido3;
            ptd::Partido partido4;
            ptd::Partido partido5;
        public:
            Jornada(){};
            ~Jornada(){};
            Jornada(ptd::Partido partidos[5]){
                this-> partido1 = partidos[0];
                this-> partido2 = partidos[1];
                this -> partido3 = partidos[2];
                this -> partido4 = partidos[3];
                this-> partido5 = partidos[4];
            };
    };
};

#endif