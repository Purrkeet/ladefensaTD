#pragma once
#include "Punto.h"
class CCirculo
{
private:
	CPunto* Posicion;
	CPunto* Centro;
	float Radio;
public:
	CCirculo(CPunto* pPos, float pRadio);
	~CCirculo(void);
	CPunto* GetPosicion();
	CPunto* GetCentro();
	float GetRadio();
	void SetPosicion(CPunto* pPosicion);
	void SetCentro(CPunto* pCentro);
	void SetRadio(float pRadio);
	bool Colisiona(CPunto* ocentro,float radio);
	void guardarArchivo(FILE * archivo);
	void leeArchivo(FILE * archvo);
};

