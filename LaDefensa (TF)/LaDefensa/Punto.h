#pragma once
#include <stdio.h>
class CPunto
{
private:
	float x;
	float y;
public:
	CPunto(float px, float py);
	~CPunto(void);
	//void CPunto(CPunto* p);
	float GetX();
	float GetY();
	void SetX(float px);
	void Sety(float py);
	void guardarArchivo(FILE * archivo);
	void leerArchivo(FILE * archivo);
};

