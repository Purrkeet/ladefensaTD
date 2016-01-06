#include "stdafx.h"
#include "TorreRecursos.h"


CTorreRecursos::CTorreRecursos(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam,
CCirculo* pColision, int pPrecioVenta, int pPrecioUpgrade, int pTipo, int pNivel, bool pPuestoEnElSuelo):
	CTorre(pPos, pRutaImg, pISA, pISM, pTam,pColision, pPrecioVenta, pPrecioUpgrade, pTipo, pNivel, pPuestoEnElSuelo)
{
	//por defecto
	PeriodoDeObtencion=200;
	DineroARecaudar=50;
}
CTorreRecursos::~CTorreRecursos()
{
}
int CTorreRecursos::GetPeriodoDeObtencion()
{
	return PeriodoDeObtencion;
}
int CTorreRecursos::GetDineroARecaudar()
{
	return DineroARecaudar;
}
void CTorreRecursos::SetPeriodoDeObtencion(int pPeriodoDeObtencion)
{
	PeriodoDeObtencion = pPeriodoDeObtencion;
}
void CTorreRecursos::SetDineroARecaudar(int pDineroARecaudar)
{
	DineroARecaudar = pDineroARecaudar;
}
