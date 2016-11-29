#ifndef NAVE_H
#define NAVE_H

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

#include <iostream>
using namespace std;

///#include "GLOBAL.h"

void gotoxy(int x, int y);
void color(int X);

class NAVE{
private:
	int x,y;
	int corazones;
	int vidas;
public:
	NAVE(int , int , int , int );///:x(_x),y(_y),corazones(_corazones),vidas(_vidas){}
	int X(){return x; }
	int Y(){return y; }
	int VID(){return vidas;}
	int CO(){return corazones;}
	void COR(){corazones--;}
	void CORZ(){corazones++;}
	void pintar();
	void borrar();
	void mover();
	void pintar_corazones();
	void morir();
};


#endif // NAVE_H
