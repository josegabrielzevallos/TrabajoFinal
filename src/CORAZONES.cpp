#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

#include "../include/CORAZONES.h"
template<class T,class D>

CORAZONES<T,D>::CORAZONES(T x, T y):AST(x,y){}
template<class T,class D>

void CORAZONES<T,D>::pintar()
{
    color(12);
    gotoxy(x,y); printf("%c",3);
    color(7);
}

template<class T,class D>

void CORAZONES<T,D>::mover()
{
    gotoxy(x,y); printf(" ");
	y++;
	if(y > 32){
		x = rand()%71 + 4;
		y = 4;

	}
	pintar();
}
template<class T,class D>

void CORAZONES<T,D>::choque(D &N)
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
template<class T,class D>

CORAZONES<T,D>::~CORAZONES()
{
    ///dtor
}

template class CORAZONES<int,NAVE>;

