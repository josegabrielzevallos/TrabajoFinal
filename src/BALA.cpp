#include "BALA.h"

BALA::BALA(int x, int y)
{
    this->x = x;
    this->y = y;
}

void BALA::mover()
{
    color(10);
	gotoxy(x,y); printf(" ");
	y--;
	gotoxy(x,y); printf("#");
    color(7);
}

bool BALA::fuera()
{
	if(y==4) return true;
	return false;
}

BALA::~BALA()
{
    //dtor
}
