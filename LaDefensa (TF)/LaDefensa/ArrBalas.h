#pragma once
#include <list>
#include "Bala.h"
#include "ArrEnemigos.h"
class CArrBalas
{
private:
	list<CBala*>* balas;
	float Velocidad;
	int Danio;
	
public:
	CArrBalas(int Danio=1);
	~CArrBalas();
	void Bang(float vX, float vY, CPunto* pos);
	void DibujarBalas(System::Drawing::Graphics ^gr);
	void MoverBalas(int radio,Rectangle^ r);
	float getVelocidad();
	int ColisionArrEnemigos(ArrEnemigos* enemigos);//cantidad de dinero por colision
};

