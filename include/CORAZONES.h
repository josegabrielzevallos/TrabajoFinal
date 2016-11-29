#ifndef CORAZONES_H
#define CORAZONES_H

#include "AST.h"

void gotoxy(int x, int y);
void color(int X);

class CORAZONES:public AST
{

    public:
        CORAZONES(){}
        CORAZONES(int, int);
        void pintar();
        void mover();
        void choque(NAVE &);

        ~CORAZONES();

};

#endif // CORAZONES_H
