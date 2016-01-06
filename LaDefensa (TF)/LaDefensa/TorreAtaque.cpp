#include "stdafx.h"
#include "TorreAtaque.h"
#include "TorreRecursos.h"


CTorreAtaque::CTorreAtaque(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam,
	CCirculo* pColision, int pPrecioVenta, int pPrecioUpgrade, int pTipo, int pNivel, bool pPuestoEnElSuelo)
	:CTorre( pPos,  pRutaImg,  pISA,  pISM,  pTam,
	 pColision,  pPrecioVenta,  pPrecioUpgrade,  pTipo,  pNivel,  pPuestoEnElSuelo)
{
	//por defecto
	VeCamuflados = false;
	
	arrDearrDeBalas= new list<CArrBalas*>();
	arrDearrDeBalas->push_back(new CArrBalas());
}

CTorreAtaque::~CTorreAtaque()
{
}

void CTorreAtaque::DibujarBalas(System::Drawing::Graphics ^gr){
	for (list<CArrBalas*>::iterator it = arrDearrDeBalas->begin(); it != arrDearrDeBalas->end(); it++){
		(*it)->DibujarBalas(gr);
	}
}
void CTorreAtaque::MoverBalas(Rectangle^ r){
	for (list<CArrBalas*>::iterator it = arrDearrDeBalas->begin(); it != arrDearrDeBalas->end(); it++){
		(*it)->MoverBalas(GetRango(),r);
	}
	
}
void CTorreAtaque::Disparar(COleadas* oOleada){
//codigo
//for (list<CArrBalas*>::iterator i = arrDearrDeBalas->begin(); i != arrDearrDeBalas->end(); i++)
//{
//}
for (list<ArrEnemigos*>::iterator it = oOleada->GetTropasList()->begin(); it != oOleada->GetTropasList()->end(); it++)
{//pregunta si esta en el rango
//en rango te devuelve el iterador del enemigo que este primero dentro del radio
	if ( (*it)->enRango(this->GetColision()->GetCentro(), this->GetRango(), VeCamuflados) )
//si esta en el rango ataca a ese enemigo que esta apuntando el iterador del iterador
	{
		if(arrDearrDeBalas->size()==0)continue;
		list<CArrBalas*>::iterator balas ; 
		for (balas= arrDearrDeBalas->begin();
			balas!= arrDearrDeBalas->end(); balas++)
		{
//por todos los arreglos de balas se añade una sola bala con direccion al personaje que apunte el iterador
//velocidad es igual a distancia entre velocidad
//mejorar algoritmo
		float dx = GetColision()->GetCentro()->GetX() - (*(*it)->getIteradorEnemigo())->GetColision()->GetCentro()->GetX();
		float dy = GetColision()->GetCentro()->GetY() - (*(*it)->getIteradorEnemigo())->GetColision()->GetCentro()->GetY();
//se elevan al cuadrado cada uno
		float dX = dx* dx; float dY= dy * dy;
//distancia es la raiz de diferencia de x al cuadrado mas diferencia de y al cuadrado
		float Distancia = sqrt(dX+dY);//aplicamos pitadrogas
		float Velocidad = Distancia /(*balas)->getVelocidad()*-1;
		float velX = dx / Velocidad; float velY = dy / Velocidad;
		(*balas)->Bang(velX, velY, GetColision()->GetCentro());
		}
	}
}
}
int CTorreAtaque::ColisionaEnemigo(COleadas* oOleada){
	int totalDinero=0;
	for (list<ArrEnemigos*>::iterator it = oOleada->GetTropasList()->begin(); it != oOleada->GetTropasList()->end(); it++){
	
		for (list<CArrBalas*>::iterator itb = arrDearrDeBalas->begin(); itb != arrDearrDeBalas->end(); itb++){
			totalDinero+=(*itb)->ColisionArrEnemigos((*it));
		}
		return totalDinero;
	}



}