#pragma once
#include "TorreAtaque.h"
#include <list>
class CArrTorres
{
private:
	list <CTorre*>* torres;
	int CantidadTorres;
public:
	int getCantTorres();
	CArrTorres();
	~CArrTorres();
	void DibujarTorres(array<System::Drawing::Bitmap^>^ imgs, System::Drawing::Graphics ^gr);
	void MoverBalasdeTorres(Rectangle^r);
	void AgregarTorre(CTorre* oTorre);
	void Eliminar(CTorre* eTorre);
	CTorre * BuscarTorreClick(int x, int y);
	void guardarArchivo(FILE * archivo);
	void leerArchivo(FILE * archivo);
	void TorresDisparen(COleadas* oleada);
	void DibujarBalas(System::Drawing::Graphics ^gr);
	int Colisiona(COleadas* oleada);
};

