#pragma once
#include "Enemigo.h"

class CBunker : public CEnemigo
{
	int ContadorEnemigos;
	CEnemigo* enemigo;
public:
	CBunker(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam, CCirculo* pColision, int pVida,int pDinero, CPunto* pVel,int pPunt, bool pCamu,
		int pContadorEnemigos, CEnemigo* enemigo );
	~CBunker(void);
	void CrearEnemigos();
	int GetContadorEnemigos();
	void SetContadorEnemigos(int pContadorEnemigos);
	CEnemigo* GetEnemigo();
	void SetEnemigo(CEnemigo* pEnemigo);
};

