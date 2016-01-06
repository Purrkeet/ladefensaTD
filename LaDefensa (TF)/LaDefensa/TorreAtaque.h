#pragma once
#include "Torre.h"
#include "ArrBalas.h"
#include "Oleadas.h"
class CTorreAtaque:public CTorre
{
private:
	list<CArrBalas*>* arrDearrDeBalas;
	bool VeCamuflados;
	
public:
	CTorreAtaque(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam,
		CCirculo* pColision, int pPrecioVenta, int pPrecioUpgrade, int pTipo, int pNivel, bool pPuestoEnElSuelo);
	~CTorreAtaque();
	void DibujarBalas(System::Drawing::Graphics ^gr);
	void MoverBalas(Rectangle^ r);
	void Disparar(COleadas* oOleada);
	int ColisionaEnemigo(COleadas* oOleada);
	
};