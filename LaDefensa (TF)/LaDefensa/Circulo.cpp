#include "stdafx.h"
#include "Circulo.h"

CCirculo::CCirculo(CPunto* pPos, float pRadio)
{
	Posicion = pPos;
	Radio = pRadio;
	SetCentro(new CPunto(pPos->GetX() + Radio,pPos->GetY() + Radio));
}
CCirculo::~CCirculo(void)
{
}
CPunto* CCirculo::GetPosicion()
{
	return Posicion;
}
CPunto* CCirculo::GetCentro()
{
	return Centro;
}
float CCirculo::GetRadio()
{
	return Radio;
}
void CCirculo::SetPosicion(CPunto* pPosicion)
{
	Posicion = pPosicion;
	SetCentro(new CPunto(pPosicion->GetX() + Radio, pPosicion->GetY() + Radio));
}
void CCirculo::SetCentro(CPunto* pCentro)
{
	Centro = pCentro;
}
void CCirculo::SetRadio(float pRadio)
{
	Radio = pRadio;
}
bool CCirculo::Colisiona(CPunto* oCentro, float radio){
	//obtiene distancia
	float x=oCentro->GetX() - Centro->GetX();
	x *= x;
	float y = oCentro->GetY() - Centro->GetY();
	y *= y;
	float _radio = radio + Radio;
	_radio *= _radio;
	//compara con suma de radios
	if (x + y < (_radio))
		return true;
	return false;

}
void CCirculo::guardarArchivo(FILE * archivo)
{
	fwrite(&Radio,sizeof(Radio),1,archivo);
	Posicion->guardarArchivo(archivo);
	Centro->guardarArchivo(archivo);
}
void CCirculo::leeArchivo(FILE * archivo)
{
	fread(&Radio,sizeof(Radio),1,archivo);
	Posicion->leerArchivo(archivo);
	Centro->leerArchivo(archivo);
}