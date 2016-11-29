#include "AST.h"

AST::AST()
{
    this->x = 0;
    this->y = 0;
}
///AST(int _x, int _y):x(_x),y(_y){}
AST::AST(int x, int y)
{
    this->x = x;
    this->y = y;
}

void AST::pintar(){
    color(6);
	gotoxy(x,y); printf("%c",184);
    color(7);

}

void AST::mover(){
	gotoxy(x,y); printf(" ");
	y++;
	if(y > 32){
		x = rand()%71 + 4;
		y = 4;

	}
	pintar();

}

void AST::choque(NAVE &N){
	if( x >= N.X() and x < N.X()+6 and y >= N.Y() and y < N.Y()+2){
		N.COR();
		N.borrar();
		N.pintar();
		N.pintar_corazones();
		x = rand()%71 + 4;
		y = 4;

	}

}

bool AST::fuera(){cout << "no hago nada :v" << endl;}

AST::~AST(){ }
