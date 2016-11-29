#ifndef AST_H
#define AST_H

#include "NAVE.h"

void gotoxy(int x, int y);
void color(int X);
template<class T,class D>
class AST
{
    protected:
        T x,y;
    public:
        AST();
        AST(T , T );
        virtual void pintar();
        virtual void mover();
        virtual void choque(D &);
        virtual bool fuera();
        T X(){ return x;}
        T Y(){ return y;}
        ~AST();
};


#endif // AST_H
