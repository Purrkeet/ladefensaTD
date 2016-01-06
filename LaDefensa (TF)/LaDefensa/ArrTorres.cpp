#include "stdafx.h"
#include "ArrTorres.h"


CArrTorres::CArrTorres()
{
	CantidadTorres = 0;
	torres= new list<CTorre*>();
}


CArrTorres::~CArrTorres()
{
}
void CArrTorres::DibujarTorres(array<System::Drawing::Bitmap^>^ imgs, System::Drawing::Graphics ^gr){
	list<CTorre*>::iterator it;
	for ( it = torres->begin(); it != torres->end(); it++)
	{
		//pregunta por el tipo de torre
		int indiceTipoImagen = 1;
		(*it)->Dibujar(imgs[indiceTipoImagen],gr);
		if ((*it)->GetTorreClikeada() == 1)
			(*it)->DibujarRango(gr);
		
	}
}
int CArrTorres::Colisiona(COleadas* oleada){
	int totalDinero=0;
	for (list<CTorre*>::iterator it = torres->begin(); it != torres->end(); it++){
		if ((*it)->GetTipo() == 1){
			totalDinero+=((CTorreAtaque*)(*it))->ColisionaEnemigo(oleada);
		}
	}
	return totalDinero;
}
void CArrTorres::MoverBalasdeTorres(Rectangle^r){
	for (list<CTorre*>::iterator it = torres->begin(); it != torres->end(); it++){
		//revisar si el if funciona
		//pregunta si el elemento se puede castear a CtorreAtaque
		if ((*it)->GetTipo() == 1){
			((CTorreAtaque*)(*it))->MoverBalas(r);
		}
		
	}
}
void CArrTorres::AgregarTorre(CTorre* oTorre){
	torres->push_back(oTorre);
	++CantidadTorres;
}
int CArrTorres::getCantTorres(){return CantidadTorres;}
void CArrTorres::Eliminar(CTorre* eTorre)
{
	list <CTorre*>* aux;
	list<CTorre*>::iterator i;
	for (i = torres->begin(); i != torres->end(); i++)
		if ((*i)->GetColision()->GetCentro()->GetX() == eTorre->GetColision()->GetCentro()->GetX()
			&& (*i)->GetColision()->GetCentro()->GetY() == eTorre->GetColision()->GetCentro()->GetY())
			break;
	torres->remove(*i);
}
CTorre* CArrTorres ::BuscarTorreClick(int x, int y)
{
	for (list<CTorre*>::iterator i = torres->begin(); i != torres->end(); i++)
		(*i)->SetTorreClikeada(0);
	int encontro = 0;
	list<CTorre*>::iterator it;
	for (it = torres->begin(); it != torres->end(); it++)
	{
		
		if (x > (*it)->GetColision()->GetCentro()->GetX() - (*it)->GetColision()->GetRadio()
			&& x<(*it)->GetColision()->GetCentro()->GetX() + (*it)->GetColision()->GetRadio()
			&& y>(*it)->GetColision()->GetCentro()->GetY() - (*it)->GetColision()->GetRadio()
			&& y < (*it)->GetColision()->GetCentro()->GetY() + (*it)->GetColision()->GetRadio())
		{
			encontro = 1;
			(*it)->SetTorreClikeada(1);
			break;
		}
	}
	
	if (encontro == 1)
			return (*it);
	else
	{
		
		return nullptr;
	}
		
}
void CArrTorres::guardarArchivo(FILE * archivo)
{
	fwrite(&CantidadTorres,sizeof(CantidadTorres),1,archivo);
	for (list<CTorre*>::iterator it = torres->begin(); it != torres->end(); it++)
		(*it)->guardarArchivo(archivo);

}
void CArrTorres::leerArchivo(FILE * archivo)
{
	fread(&CantidadTorres,sizeof(CantidadTorres),1,archivo);
	for (list<CTorre*>::iterator it = torres->begin(); it != torres->end(); it++)
		(*it)->leerArchivo(archivo);
}
void CArrTorres::TorresDisparen(COleadas* oleada){
list<CTorre*>::iterator it;
for (it = torres->begin(); it != torres->end(); it++)
{
if((*it)->GetTipo()!=1) continue;
((CTorreAtaque*)(*it))->Disparar(oleada);
}

}
void  CArrTorres::DibujarBalas(System::Drawing::Graphics ^gr)
{
	for (list<CTorre*>::iterator it = torres->begin(); it != torres->end(); it++){
		//revisar si el if funciona
		//pregunta si el elemento se puede castear a CtorreAtaque
		if ((*it)->GetTipo() == 1){
			((CTorreAtaque*)(*it))->DibujarBalas(gr);
		}
		
	}
}