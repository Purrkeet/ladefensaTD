#pragma once
#include <iostream>
#include "Punto.h"
#define BLOQUESHORIZONTALES 30
#define BLOQUESVERTICALES 20

using namespace System::Drawing;
class CMapa
{
	
	int mapa[BLOQUESVERTICALES][BLOQUESHORIZONTALES];
	int anchoBloque;
	int altoBloque;
	int cantBlqVert;
	int cantBlqHor;
public:
	enum MAPA
	{
		FREE, BLOCKED, START, EXIT, DERECHA, IZQUIERDA, ARRIBA, ABAJO
	};
	void ConstruirMapa();
	void LeerdeArchivo(FILE * archivo);
	void DibujarMapa(array<System::Drawing::Bitmap^>^ imgs, System::Drawing::Graphics^ gr, Rectangle ^r);
	void pasarMapa(int pmapa[BLOQUESVERTICALES][BLOQUESHORIZONTALES]);
	CMapa(void);
	~CMapa(void);
	CPunto* getbloqueAnchoalto();// devuelve CPunto(anchoBloque, altoBloque);
	int GetCaracterDelMapa(int x, int y); //x,y
	void BloquearCaracterMapa(int x, int y);
	void DesBloquearCaracterMapa(int x, int y);
};

