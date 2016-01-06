#pragma once
#include "Oleadas.h"
#include "ArrTorres.h"
//#include "Mapa.h" ya esta incluido en ArrEnemigos

class CNivel
{
	enum MAP1
	{
		FREE,BLOCKED,START,EXIT,DERECHA,IZQUIERDA,ARRIBA,ABAJO
	};
	CMapa * m;
	list<COleadas*>* waves;
	CArrTorres* Torres;
	int TiempoDeSalida;
	int map1[BLOQUESVERTICALES][BLOQUESHORIZONTALES];
	int orden[30][10][30];//cant enemigos, cantidad tropas x ola, cant olas
	int contOrden;
	int maximo;
public:
	CNivel(int maximo,int orden[30][10]=nullptr);
	~CNivel(void);
	void MostrarTropa(int acelerar, CMapa* mapa,int c);
	void MostrarTropa(int acelerar,int c);
	void MoverOlas(CMapa* mapa);
	int MoverOlas();
	void moverBalas(Rectangle^r);
	void dibujarMapa(array<System::Drawing::Bitmap^>^ imgs, Graphics ^ g, Rectangle r);
	void dibujarOlas(array<System::Drawing::Bitmap^>^ imgs, Graphics ^ g);

	void inicializarMap(FILE * archivo,System::Drawing::Graphics^ gr,Rectangle ^r);
	void CrearTorre(CTorre* oTorre);
	COleadas * getOleada();

	void LeerNiveldeArchivo(FILE* archivo);
	void agregarOleada(COleadas * oleada);
	CMapa * getmapa();

	void  setmapa(CMapa * pmapa);
	CTorre* BuscarTorreSeleccionada(int x,int y);
	void EliminarTorre(CTorre*Teliminar);
	void guardarArchivo(FILE * archivo);
	void dispararTorres();
	void dibujarTorres(array<System::Drawing::Bitmap^>^ imgs, Graphics ^ g);
	void dibujarBalas(Graphics^ g);

	int Colisiona();
};