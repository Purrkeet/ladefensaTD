#include "stdafx.h"
#include "Bunker.h"


CBunker::CBunker(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam, CCirculo* pColision, int pVida,int pDinero, CPunto* pVel,int pPunt, bool pCamu,
		int pContadorEnemigos, CEnemigo* enemigo) : CEnemigo(pPos,pRutaImg,pISA,pISM,pTam,pColision,pVida,pDinero,pVel,pPunt,pCamu)
{
	 ContadorEnemigos = pContadorEnemigos;
}
CBunker::~CBunker(void)
{
}
void CBunker::CrearEnemigos()
{
}
int CBunker::GetContadorEnemigos()
{
	return ContadorEnemigos;
}
void CBunker::SetContadorEnemigos(int pContadorEnemigos)
{
	ContadorEnemigos = pContadorEnemigos;
}
CEnemigo* CBunker::GetEnemigo()
{
	return enemigo;
}
void CBunker::SetEnemigo(CEnemigo* pEnemigo)
{
	enemigo = pEnemigo;
}