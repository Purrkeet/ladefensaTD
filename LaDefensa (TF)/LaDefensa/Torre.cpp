#include "stdafx.h"
#include "Torre.h"


CTorre::CTorre(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam, 
	CCirculo* pColision,int pPrecioVenta, int pPrecioUpgrade, int pTipo, int pNivel, bool pPuestoEnElSuelo) : CFigura(pPos,pRutaImg,pISA,pISM,pTam,pColision)
{
	PrecioVenta = pPrecioVenta;
	PrecioUpgrade = pPrecioUpgrade;
	Tipo = pTipo;
	Nivel = pNivel;
	PuestoEnElSuelo = pPuestoEnElSuelo;
	switch (Tipo)
	{
	case 1:
		rango = 100;
		Ataque = 20;
		Velocidad = 10;
		TipoEscrito = "Ataque";
		break;
	case 2:
		break;
	case 3:
		break;
	}
	TorreClikeada=0;
}
CTorre::~CTorre(void)
{
}

void CTorre::MoverBalas()
{
}
void CTorre::DibujarRango(Graphics ^gr)
{
	
	gr->DrawEllipse(Pens::Blue, this->GetColision()->GetCentro()->GetX() - rango, this->GetColision()->GetCentro()->GetY() - rango
		, rango*2.,rango*2.);
}
void CTorre::Dibujar(Bitmap ^bmp, Graphics ^gr)
{
	float anchoSpr = bmp->Size.Width / (float)GetCantIxS()->GetX();
	float altoSpr = bmp->Size.Height / (float)GetCantIxS()->GetY();
	Rectangle recOrigen = Rectangle(this->GetISA()->GetX()*anchoSpr, this->GetISA()->GetY()*altoSpr, anchoSpr, altoSpr);
	Rectangle recDestino = Rectangle(GetPosicion()->GetX(), GetPosicion()->GetY(), GetTamanio()->GetX(), GetTamanio()->GetY());
	//Rectangle recDestino = Rectangle(GetPosicion()->GetX(), GetPosicion()->GetY(), 100, 100);
	gr->DrawImage(bmp, recDestino, recOrigen, GraphicsUnit::Pixel);
	gr->DrawEllipse(Pens::Green, this->GetPosicion()->GetX(), this->GetPosicion()->GetY()
		, this->GetColision()->GetRadio()*2., this->GetColision()->GetRadio()*2.);
	gr->DrawLine(Pens::Yellow, this->GetColision()->GetCentro()->GetX(), this->GetColision()->GetCentro()->GetY()
		, this->GetColision()->GetCentro()->GetX(), this->GetColision()->GetCentro()->GetY());
	//algoritmo de movimiento de Sprites
	
	if (IndiceSpriteMin->GetX() != IndiceSpriteMax->GetX()){
		IndiceSpriteActual->SetX(IndiceSpriteActual->GetX() + 1);
		if (IndiceSpriteActual->GetX() >= IndiceSpriteMax->GetX()){
			IndiceSpriteActual->SetX(IndiceSpriteMin->GetX());
		}
	}
	if (IndiceSpriteMin->GetY() != IndiceSpriteMax->GetY()){
		IndiceSpriteActual->Sety(IndiceSpriteActual->GetY() + 1);
		if (IndiceSpriteActual->GetY() >= IndiceSpriteMax->GetY()){
			IndiceSpriteActual->Sety(IndiceSpriteMin->GetY());
		}
	}
}
int CTorre::GetPrecioVenta()
{
	return PrecioVenta;
}
int CTorre::GetPrecioUpgrade()
{
	return PrecioUpgrade;
}
int CTorre::GetTipo()
{
	return Tipo;
}
int CTorre::GetNivel()
{
	return Nivel;
}
bool CTorre::GetPuestoEnElSuelo()
{
	return PuestoEnElSuelo;
}
void CTorre::SetPrecioVenta(int pPrecioVenta)
{
	PrecioVenta = pPrecioVenta;
}
void CTorre::SetPrecioUpgrade(int pPrecioUpgrade)
{
	PrecioUpgrade = pPrecioUpgrade;
}
void CTorre::SetTipo(int pTipo)
{
	Tipo = pTipo;
}
void CTorre::SetNivel(int pNivel)
{
	Nivel = pNivel;
}
void CTorre::SetPuestoEnElSuelo(bool pPuestoEnElSuelo)
{
	PuestoEnElSuelo = pPuestoEnElSuelo;
}
string CTorre::GetTipoEscrito()
{
	
	return TipoEscrito;
}
int CTorre::GetAtaque()
{
	return Ataque;
}
int CTorre::GetVelocidad()
{
	return Velocidad;
}
int CTorre::GetTorreClikeada()
{
	return TorreClikeada;
}
void CTorre::SetTorreClikeada(int dato)
{
	TorreClikeada = dato;
}
int CTorre::GetRango()
{
	return rango;
}
void CTorre::guardarArchivo(FILE * archivo)
{
	fwrite(&PrecioVenta,sizeof(PrecioVenta),1,archivo);
	fwrite(&PrecioUpgrade,sizeof(PrecioUpgrade),1,archivo);
	fwrite(&Tipo,sizeof(Tipo),1,archivo);
	fwrite(&Nivel,sizeof(Nivel),1,archivo);
	fwrite(&PuestoEnElSuelo,sizeof(PuestoEnElSuelo),1,archivo);
}
void CTorre::leerArchivo(FILE * archivo)
{
	fread(&PrecioVenta,sizeof(PrecioVenta),1,archivo);
	fread(&PrecioUpgrade,sizeof(PrecioUpgrade),1,archivo);
	fread(&Tipo,sizeof(Tipo),1,archivo);
	fread(&Nivel,sizeof(Nivel),1,archivo);
	fread(&PuestoEnElSuelo,sizeof(PuestoEnElSuelo),1,archivo);
}