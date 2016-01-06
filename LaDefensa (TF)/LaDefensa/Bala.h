#pragma once
#include "Figura.h"
class CBala : public CFigura
{
private:
	int Danio;
	CPunto* Velocidad;
public:
	CBala(CPunto* pPosicion, string pRutaImagen, CPunto* pISA, CPunto* pISM, CPunto* pTam, CCirculo* pAreaColision, CPunto* pVel, int pDanio);
	~CBala(void);
	void Mover();
	int GetDanio();
	CPunto* GetVelocidad();
	void SetDanio(int pDanio);
	void SetVelocidad(CPunto* pVel);
	void Dibujar(Graphics^g);
};

