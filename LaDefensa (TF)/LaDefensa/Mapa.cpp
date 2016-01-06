#include "stdafx.h"
#include "Mapa.h"



CMapa::CMapa(void)
{
	//inicializas en blanco
	anchoBloque=1;
	altoBloque=1;
}
CMapa::~CMapa(void)
{
}
void CMapa::pasarMapa(int pmapa[BLOQUESVERTICALES][BLOQUESHORIZONTALES])
{
	pmapa = mapa;
}
void  CMapa::LeerdeArchivo(FILE * archivo){
	char strMapa[BLOQUESVERTICALES][BLOQUESHORIZONTALES + 1];
	for (int i = 0; i < BLOQUESVERTICALES; i++)
	{
		fscanf(archivo,"%s",strMapa[i]);
	}
	for (int i = 0; i < BLOQUESVERTICALES; i++)
	{
		for (int j = 0; j < BLOQUESHORIZONTALES; j++)
		{
			mapa[i][j]=strMapa[i][j]-'0';
		}
	}
	cantBlqHor = BLOQUESHORIZONTALES;
	cantBlqVert = BLOQUESVERTICALES;
}
void CMapa::ConstruirMapa()
{//coger de los sprites
}

void CMapa::DibujarMapa(array<System::Drawing::Bitmap^>^ imgs, System::Drawing::Graphics^ gr, Rectangle ^r){
	int c;
	gr->DrawImage(imgs[0],0, 0, r->Width, r->Height);
	int ancho = (r->Width) / BLOQUESHORIZONTALES;
	int alto = (r->Height) / BLOQUESVERTICALES;
	if(ancho>alto)ancho=alto;
	else alto=ancho;
	
	for (int i = 0; i < BLOQUESVERTICALES; i++)
	{
		for (int j = 0; j < BLOQUESHORIZONTALES; j++)
		{
			switch (mapa[i][j])
			{
			case MAPA::START:
			case MAPA::DERECHA:
			case MAPA::IZQUIERDA:
			case MAPA::ABAJO:
			case MAPA::ARRIBA:
			case MAPA::EXIT: c = 2; break;
			case MAPA::BLOCKED:c = 0; break;

			case MAPA::FREE: c = 0; break;
			}

			if (c != 0)
			{

				gr->DrawImage(imgs[1], j*ancho, i*alto, ancho, alto);


			}
		}
	}
	anchoBloque=ancho;
	altoBloque=alto;
}

CPunto* CMapa::getbloqueAnchoalto(){
	return new CPunto(anchoBloque, altoBloque);
}
int CMapa::GetCaracterDelMapa(int x, int y){
	if (x < BLOQUESHORIZONTALES && y < BLOQUESVERTICALES)
		return mapa[y][x];
	else
		// No existen tales bloques
		return MAPA::BLOCKED;
}
void CMapa::BloquearCaracterMapa(int x, int y){
	mapa[y][x] = (int)MAPA::BLOCKED;
}
void CMapa::DesBloquearCaracterMapa(int x, int y){
	mapa[y][x] = (int)MAPA::FREE;
}
