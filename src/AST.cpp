#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

#include "../include/AST.h"
template<class T,class D>

AST<T,D>::AST()
{
    this->x = 0;
    this->y = 0;
}
///AST(int _x, int _y):x(_x),y(_y){}
template<class T,class D>

AST<T,D>::AST(T x, T y)
{
    this->x = x;
    this->y = y;
}
template<class T,class D>

void AST<T,D>::pintar(){
    color(6);
	gotoxy(x,y); printf("%c",184);
    color(7);

}
template<class T,class D>

void AST<T,D>::mover(){
	gotoxy(x,y); printf(" ");
	y++;
	if(y > 32){
		x = rand()%71 + 4;
		y = 4;

	}
	pintar();

}
template<class T,class D>

void AST<T,D>::choque(D &N){
	if( x >= N.X() and x < N.X()+6 and y >= N.Y() and y < N.Y()+2){
		N.COR();
		N.borrar();
		N.pintar();
		N.pintar_corazones();
		x = rand()%71 + 4;
		y = 4;

	}

}
template<class T,class D>

bool AST<T,D>::fuera(){cout << "no hago nada :v" << endl;}
template<class T,class D>

AST<T,D>::~AST(){ }
template class AST<int,NAVE>;




