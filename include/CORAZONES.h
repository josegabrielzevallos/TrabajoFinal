#ifndef CORAZONES_H
#define CORAZONES_H

#include "AST.h"

void gotoxy(int x, int y);
void color(int X);
template<class T,class D>

class CORAZONES:public AST<int,NAVE>
{

    public:
        CORAZONES(){}
        CORAZONES(T, T);
        void pintar();
        void mover();
        void choque(D &);

        ~CORAZONES();

};

#endif // CORAZONES_H
