#pragma once
#include "ArrEnemigos.h"
#include <vector>

class COleadas
{
private:
	list<ArrEnemigos*>* tropas;
	int TiempoDeSalida;
	int DineroxOleadas;
	vector<CEnemigo*> enemigos;
	int * orden;
	int  maxArrEnem;
	int contador;
	int * cantidades;
public:
	COleadas(CMapa * mapa, int * orden = nullptr, int * maximos = nullptr, int cantTropas=1);
	~COleadas(void);
	bool AgregarTropa(CEnemigo * enemigo, int max);
	void AparecerTropa(int c , CMapa* mapa);
	void DibujarOleada(array<System::Drawing::Bitmap^>^ imgs, Graphics ^ g);
	int moverTropas(CMapa* mapa);
	void escribirArchivos(FILE * archivo,CMapa * m);
	void leerArchivo(FILE * archivo,CMapa * m);
	
list<ArrEnemigos*>* GetTropasList();
};