#include "stdafx.h"
#include "Bala.h"

CBala::CBala(CPunto* pPosicion, string pRutaImagen, CPunto* pISA, CPunto* pISM, CPunto* pTam, CCirculo* pAreaColision, CPunto* pVel, int pDanio):CFigura(pPosicion,pRutaImagen,pISA,pISM,pTam,pAreaColision)
{
	Velocidad = pVel;
	Danio = pDanio;
}
CBala::~CBala(void)
{
	delete Velocidad;
}
void CBala::Mover()
{
	float equis=GetPosicion()->GetX();
	float ye=GetPosicion()->GetY();
	float cx=Velocidad->GetX(),cy=Velocidad->GetY();
	
	float nuevaX= equis+ cx;
	float nuevaY= ye + cy;
	this->SetPosicion(new CPunto( equis+ cx, ye + cy));
	this->GetColision()->SetPosicion( GetPosicion());
}
int CBala::GetDanio()
{
	return Danio;
}
CPunto* CBala::GetVelocidad()
{
	return Velocidad;
}
void CBala::SetDanio(int pDanio)
{
	Danio = pDanio;
}
void CBala::SetVelocidad(CPunto* pVel)
{
	Velocidad = pVel;
}
void CBala::Dibujar(Graphics^g){
	g->DrawEllipse(Pens::Black, this->GetColision()->GetPosicion()->GetX(), this->GetColision()->GetPosicion()->GetY()
		, this->GetColision()->GetRadio()*2.0f, this->GetColision()->GetRadio()*2.0f);
	g->FillEllipse(Brushes::White, this->GetColision()->GetPosicion()->GetX(), this->GetColision()->GetPosicion()->GetY()
		, this->GetColision()->GetRadio()*2.0f, this->GetColision()->GetRadio()*2.0f);
}