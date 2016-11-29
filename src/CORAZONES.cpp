#include "CORAZONES.h"

CORAZONES::CORAZONES(int x, int y):AST(x,y){}

void CORAZONES::pintar()
{
    color(12);
    gotoxy(x,y); printf("%c",3);
    color(7);
}


void CORAZONES::mover()
{
    gotoxy(x,y); printf(" ");
	y++;
	if(y > 32){
		x = rand()%71 + 4;
		y = 4;

	}
	pintar();
}

void CORAZONES::choque(NAVE &N)
{
    if( x >= N.X() and x < N.X()+6 and y >= N.Y() and y < N.Y()+2)
    {

        if(N.CO() < 3)
        {
            N.CORZ();
            N.pintar_corazones();
        }
        N.borrar();
        N.pintar();
        x = rand()%71 + 4;
        y = 4;

    }
}


//bool fuera(){cout << "Yo TAMPOCO :,v" << endl;}

CORAZONES::~CORAZONES()
{
    ///dtor
}
