#ifndef JUEGO_H
#define JUEGO_H

#include "CORAZONES.h"
#include "BALA.h"
#include <list>

class JUEGO
{
    public:
        static JUEGO *instancia();/// funcion que retorna objeto de tipo JUEGO
        ~JUEGO();
    private:
        JUEGO(); /// PATRON DISENHO SINGLETON
        static JUEGO *_instancia; /// PUNTERO QUE INSTANCIARA EL FUNCION PARA LLAMAR AL CONSTRUCTOR
};

#endif // JUEGO_H
