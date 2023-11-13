#include <iostream>
#include <iomanip>
#include "Jornada.h"


#ifndef LIGA
#define LIGA

namespace lg {
    class Liga {
        private:
            jrn::Jornada jornada1;
            jrn::Jornada jornada2;
            jrn::Jornada jornada3;
            jrn::Jornada jornada4;
            jrn::Jornada jornada5;
            jrn::Jornada jornada6;
            jrn::Jornada jornada7;
            jrn::Jornada jornada8;
            jrn::Jornada jornada9;
        public:
            Liga(){};
            ~Liga(){};
            Liga(jrn::Jornada jornada1, jrn::Jornada jornada2, jrn::Jornada jornada3, jrn::Jornada jornada4, jrn::Jornada jornada5, jrn::Jornada jornada6, jrn::Jornada jornada7, jrn::Jornada jornada8, jrn::Jornada jornada9){
                this-> jornada1 = jornada1;
                this-> jornada2 = jornada2;
                this-> jornada3 = jornada3;
                this-> jornada4 = jornada4;
                this-> jornada5 = jornada5;
                this-> jornada6 = jornada6;
                this-> jornada7 = jornada7;
                this-> jornada8 = jornada8;
                this-> jornada9 = jornada9;
            }
            void mostrarTabla(){
                    std::cout << std::setw(10) << "Nombre"
                        << std::setw(10) << "Goles"
                        << std::setw(10) << "PG"
                        << std::setw(10) <<"PP"
                        << std::setw(10) << "PE"
                        << std::setw(10) << "puntos" << std::endl;
                    std::cout << std::setfill('-') << std::setw(100) 
                        << "" << std::setfill(' ') << std::endl;
            }
    };
};

#endif