#ifndef AST_H
#define AST_H

#include "NAVE.h"

void gotoxy(int x, int y);
void color(int X);

class AST
{
    protected:
        int x,y;
    public:
        AST();
        AST(int , int );
        virtual void pintar();
        virtual void mover();
        virtual void choque(NAVE &);
        virtual bool fuera();

        int X(){ return x;}
        int Y(){ return y;}

        ~AST();

};


#endif // AST_H
