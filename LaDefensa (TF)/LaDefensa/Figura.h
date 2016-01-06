#pragma once
#include "Circulo.h"
#include <string>
using namespace System::Drawing;
using namespace std;
class CFigura
{
protected:
	CPunto* Posicion;
	string RutaImagen;
	CPunto* IndiceSpriteActual;
	CPunto* IndiceSpriteMax;
	CPunto* IndiceSpriteMin;
	CPunto* CantImgxSprites;
	CPunto* Tamanio;
	CCirculo* Colision;
	float desfase;
	
public:
	CFigura(CPunto* pPosicion, string pRutaImg = " ", CPunto* pISA=nullptr, CPunto* pISM=nullptr, CPunto* pTam=nullptr, CCirculo* pAreaColision=nullptr);
	~CFigura(void);
	virtual void Dibujar(Bitmap ^bmp,Graphics ^gr);
	CPunto* GetPosicion();
	string GetRutaImg();
	CPunto* GetISA();
	CPunto* GetISM();
	
	CPunto* GetCantIxS();
	CCirculo* GetColision();
	void SetPosicion(CPunto* pPosicion);
	void SetRutaImg(string pRutaImg);
	void SetISA(CPunto* pISA); 
	void SetISM(CPunto* pISM); 
	void SetISMin(CPunto* pISMin);
	void SetCantIxS(CPunto* pCantIxS);
	void SetColision(CCirculo* areaColision);
	CPunto* GetTamanio(){ return Tamanio; }
	float GetDesfase();
	void guardarArchivo(FILE * archivo);
	void leerArchivo(FILE * archiv);

};

