#ifndef BALA_H
#define BALA_H

#include "AST.h"

void gotoxy(int x, int y);
void color(int X);

class BALA : public AST
{
    public:
        BALA(int, int);
        void mover();
        bool fuera();

        ~BALA();

    protected:

    private:
};

#endif // BALA_H
