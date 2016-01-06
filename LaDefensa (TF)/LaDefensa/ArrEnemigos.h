#pragma once
#include "Enemigo.h"
#include <list>
#include  <time.h>
#include "Mapa.h"

using  namespace std;
class ArrEnemigos
{
private:
	list<CEnemigo*>* enemigos;
	int cantidad;
	int Max;
	int TiempoSalidaEnemigo;
	list<CEnemigo*>::iterator pivEnemigo;
	CEnemigo * enemigo;
public:                
	ArrEnemigos(int Max,CEnemigo * enemigo);
	~ArrEnemigos(void);
	void aparecerEnemigo(int c, CMapa* mapa);
	bool agregarEnemigo(CMapa* mapa);
	void dibujarEnemigo(array<System::Drawing::Bitmap^>^ imgs, System::Drawing::Graphics ^ g);
	int moverEnemigo(CMapa* mapa); //devuelve vidas a restar
	void liberarEnemys();
	void CambiarDirección(list<CEnemigo*>::iterator ene,int direc);
	bool enRango(CPunto* centroTorre,float radio, bool PuedeVerCamuflados);
	list<CEnemigo*>::iterator getIteradorEnemigo();
	void guardarArchivo(FILE * archivo);
	void leerArchvio(FILE * archivo,CMapa * m);
	list<CEnemigo*>* getListEnemigos(){return enemigos;}
};

