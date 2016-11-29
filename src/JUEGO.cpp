#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
#include "BALA.h"
#include "JUEGO.h"

///VARIABLES O FUNCIONES GLOBALES

void color(int X)
{
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}


void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);
}

void OcultarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon,&cci);


}

void pintar_limites(){
	for(int i = 2 ; i<78 ; i++){
		gotoxy(i,3); printf("%c",205);
		gotoxy(i,33); printf("%c",205);
	}

	for(int i = 4; i<33 ; i++){
		gotoxy(2,i); printf("%c",186);
		gotoxy(77,i); printf("%c",186);
	}

	gotoxy(2,3); printf("%c",201);
	gotoxy(2,33); printf("%c",200);
	gotoxy(77,3); printf("%c",187);
	gotoxy(77,33); printf("%c",188);
}

void borrarlimites()
{
    for(int i = 3 ; i<77 ; i++){
        for(int j = 5; j<33 ; j++)
        {
		gotoxy(i,j); printf(" ");
		gotoxy(i,j); printf(" ");
        }
    }

}
void puntajes()
{
    ifstream source("puntajes1.txt");
    int puntaje_alto;
    source >> puntaje_alto;
    pintar_limites();
    gotoxy(75/2-1,29/2+3); printf("El puntaje mas alto es: %d",puntaje_alto);
    source.close();
}

void creditos()
{
    gotoxy(75/2-1,29/2+2); printf("GANASTE");
    gotoxy(75/2-9,29/2+3); printf("Gracias por jugar :v");
    gotoxy(75/2-9,29/2+5); printf("INTEGRANTES: ");
    gotoxy(75/2-9,29/2+7); printf(" - Paulo Mendoza");
    gotoxy(75/2-9,29/2+9); printf(" - Gabriel Zevallos");
    gotoxy(75/2-9,29/2+11); printf(" - Renato Monroy");
}

int menu()
{
    int starter;
    pintar_limites();
    gotoxy(75/2-1,29/2+2); printf("ASTEROIDS");
    gotoxy(75/2-1,29/2+3); printf("1 Iniciar juego");
    gotoxy(75/2-1,29/2+5); printf("2 Creditos");
    gotoxy(75/2-1,29/2+7); printf("3 Puntajes");
    gotoxy(75/2-1,29/2+9); printf("4 Salir");
    scanf("%d",&starter);
    switch (starter) {
    case 1:
        borrarlimites();
        return 1;
    case 2:
        borrarlimites();
        creditos();
        Sleep(3000);
        borrarlimites();
        return -1;
    case 3:
        borrarlimites();
        puntajes();
        Sleep(3000);
        borrarlimites();
        return -1;
    case 4:
        borrarlimites();
        return 0;
    }
}


///CONTRUCTOR CLASE JUEGO
JUEGO::JUEGO()
{

    while(menu() == -1);
    if (menu() == 0) return;
    ifstream source("puntajes1.txt");
    int M;
    source >> M;
	OcultarCursor();
	pintar_limites();
	NAVE N(37,30,3,3);
	N.pintar();
	N.pintar_corazones();

    CORAZONES<int,NAVE> hp(rand()%75 + 3, rand()%5 + 4);

	list<AST<int,NAVE>*> A ;
	list<AST<int,NAVE>*>::iterator itA;
	for(int i = 0; i<5; i++){
		A.push_back(new AST<int,NAVE>(rand()%75 + 3, rand()%5 + 4));
	}

	///POLIMORFISMO, vector de tipo AST, crea objetos BALA en linea 102
	list<AST<int,NAVE>*> B;
	list<AST<int,NAVE>*>::iterator it;

	bool game_over = false;
	int puntos = 0;
	while(!game_over)
    {

		gotoxy(4,2); printf("Puntos %d", puntos);
		if(kbhit())
		{
			char tecla = getch();
			if(tecla == 'a' || tecla == ' ')
			B.push_back(new BALA(N.X()+2 , N.Y()-1 ));
		}

		for(it = B.begin(); it != B.end(); it ++)
		{
			(*it)->mover();
			if((*it)->fuera()){
				gotoxy((*it)->X(), (*it)->Y()); printf(" ");
				delete(*it);
				it = B.erase(it);


			}
		}

		for(itA = A.begin(); itA != A.end(); itA++){
			(*itA)->mover();
			(*itA)->choque(N);

		}

		for(itA = A.begin(); itA!=A.end(); itA++){
			for(it = B.begin(); it != B.end(); it++){
				if((*itA)->X() == (*it)->X() and ( (*itA)-> Y()+1 == (*it)->Y()  or ( (*itA)-> Y() == (*it)->Y() )) ){
					gotoxy((*it)->X(),(*it)->Y()); printf(" ");
					delete(*it);
					it = B.erase(it);

					A.push_back(new AST<int,NAVE>(rand()%74 + 3, 4 ));
					gotoxy((*itA)->X(),(*itA)->Y()); printf(" ");
					delete(*itA);
					itA = A.erase(itA);

					puntos+=10;

				}
			}

		}


        hp.mover();
        hp.choque(N);

		if(N.VID() == 0) game_over = true;
		if(puntos > M) {
            ofstream destination("puntajes1.txt");
            destination << puntos;
        }
		N.morir();
		N.mover();
		Sleep(30);
	}

}

///desarrollado el metodo
JUEGO  *JUEGO::instancia()
{
    if(!_instancia)
        _instancia = new JUEGO();
    return _instancia;
}

///INICIALIZAMOS EL PUNTERO QUE INSTANCIARA EL CONSTRUCTO PRIVATE
JUEGO *JUEGO::_instancia = NULL;


JUEGO::~JUEGO()
{
    //dtor
}
