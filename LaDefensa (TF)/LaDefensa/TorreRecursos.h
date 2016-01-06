#pragma once
#include "Torre.h"
class CTorreRecursos:public CTorre
{
private:
	int PeriodoDeObtencion;
	int DineroARecaudar;
public:
	CTorreRecursos(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam,
		CCirculo* pColision, int pPrecioVenta, int pPrecioUpgrade, int pTipo, int pNivel, bool pPuestoEnElSuelo);
	~CTorreRecursos();
	void ObtenerRecursos();
	int GetPeriodoDeObtencion();
	int GetDineroARecaudar();
	void SetPeriodoDeObtencion(int pPeriodoDeObtencion);
	void SetDineroARecaudar(int pDineroARecaudar);
};