#include "NAVE.h"

static int ARRIBA = 72;
static int IZQUIERDA = 75;
static int DERECHA = 77;
static int ABAJO = 80;

///NAVE(int _x, int _y, int _corazones, int _vidas):x(_x),y(_y),corazones(_corazones),vidas(_vidas){}
NAVE::NAVE(int x, int y, int corazones, int vidas)
{
    this->x = x;
    this->y = y;
    this->corazones = corazones;
    this->vidas = vidas;

}

void NAVE::pintar(){

	gotoxy(x,y); printf("  %c",30);
	gotoxy(x,y+1); printf(" %c%c%c",40,207,41);
	gotoxy(x,y+2); printf("%c%c %c%c",30,190,190,30);


}

void NAVE::borrar(){
	gotoxy(x,y);   printf("        ");
	gotoxy(x,y+1); printf("        ");
	gotoxy(x,y+2); printf("        ");

}

void NAVE::mover(){
	if(kbhit())
	{
			char tecla = getch();
			borrar();
			if(tecla == IZQUIERDA and x > 3) x--;
			if(tecla == DERECHA and x+6 < 77) x++;
			if(tecla == ARRIBA and y > 4) y--;
			if(tecla == ABAJO and y+3 < 33) y++;
			pintar();

		}

}

void NAVE::pintar_corazones(){

	gotoxy(50,2); printf("VIDAS %d", vidas);
	gotoxy(64,2); printf("Salud");
	gotoxy(70,2); printf("      ");
	for(int i = 0; i < corazones; i++){

		gotoxy(70+i,2); printf("%c",3);
	}
}

void NAVE::morir(){
	if(corazones == 0){
		borrar();
		color(12);
		gotoxy(x-1,y);   printf("   **   ");
		gotoxy(x-1,y+1); printf("  ****  ");
		gotoxy(x-1,y+2); printf("   **  ");
		Sleep(200);

		borrar();
		gotoxy(x-1,y);   printf(" * ** *");
		gotoxy(x-1,y+1); printf("  ****  ");
		gotoxy(x-1,y+2); printf(" * ** *");
		Sleep(200);
		color(7);
		borrar();
		vidas--;
		corazones = 3;
		pintar_corazones();
		pintar();


	}

}
