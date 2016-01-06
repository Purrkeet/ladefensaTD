#include "stdafx.h"
#include "Enemigo.h"

CEnemigo::CEnemigo(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam, CCirculo* pColision, int pVida,int pDinero, CPunto* pVel,int pPunt, bool pCamu) : CFigura(pPos,pRutaImg,pISA,pISM,pTam,pColision)
{
	Vida = pVida;
	Dinero = pDinero;
	Velocidad = pVel;
	Puntaje = pPunt;
	Camuflado = pCamu;
	liberado = true;
	contaTiempo=0;
	tipoE=0;
}
CEnemigo::~CEnemigo(void)
{
	delete Velocidad;
}
void CEnemigo::Mover()
{ 
	this->SetPosicion(new CPunto(this->GetPosicion()->GetX() + this->GetVelocidad()->GetX(),
		this->GetPosicion()->GetY()+this->GetVelocidad()->GetY()));
	//moviendo el circulo de colision tambien
	this->GetColision()->SetPosicion(new CPunto(this->GetColision()->GetPosicion()->GetX() + this->GetVelocidad()->GetX(),
		this->GetColision()->GetPosicion()->GetY() + this->GetVelocidad()->GetY()));
	

}
int CEnemigo::GetVida()
{
	return Vida;
}
int CEnemigo::GetDinero()
{
	return Dinero;
}
CPunto* CEnemigo::GetVelocidad()
{
	return Velocidad;
}
bool CEnemigo::getLiberado()
{
	return liberado;
}
int CEnemigo::GetPuntaje()
{
	return Puntaje;
}
bool CEnemigo::GetCamuflado()
{
	return Camuflado;
}
void CEnemigo::SetVida(int pVida)
{
	Vida = pVida;
}
void CEnemigo::SetDinero(int pDinero)
{
	Dinero = pDinero;
}
void CEnemigo::SetVelocidad(CPunto* pVelocidad)
{
	Velocidad = pVelocidad;
}
void CEnemigo::SetPuntaje(int pPuntaje)
{
	Puntaje = pPuntaje;
}
void CEnemigo::SetCamuflado(bool pCamuflado)
{
	Camuflado = pCamuflado;
}
int CEnemigo::getTiempo()
{
	return contaTiempo;
}
void CEnemigo::setTiempo(int pTiempo)
{
	contaTiempo = pTiempo;

}
bool CEnemigo::EsLaMismaDireccion(int direc){
	return (Direccion == direc) ? true : false;
}
void CEnemigo::SetDireccion(int direc){
	Direccion = direc;
}
void CEnemigo::leerArchivo(FILE *archivo)
{
	fread(&Vida,sizeof(Vida),1,archivo);
	fread(&Dinero,sizeof(Dinero),1,archivo);
	Velocidad->leerArchivo(archivo);
	fread(&Puntaje,sizeof(Puntaje),1,archivo);
	fread(&Camuflado,sizeof(Camuflado),1,archivo);
	fread(&liberado,sizeof(liberado),1,archivo);
	fread(&Direccion,sizeof(Direccion),1,archivo);
	fread(&contaTiempo,sizeof(contaTiempo),1,archivo);
}
void CEnemigo::guardarArchivo(FILE *archivo)
{
	fwrite(&Vida,sizeof(Vida),1,archivo);
	fwrite(&Dinero,sizeof(Dinero),1,archivo);
	Velocidad->guardarArchivo(archivo);
	fwrite(&Puntaje,sizeof(Puntaje),1,archivo);
	fwrite(&Camuflado,sizeof(Camuflado),1,archivo);
	fwrite(&liberado,sizeof(liberado),1,archivo);
	fwrite(&Direccion,sizeof(Direccion),1,archivo);
	fwrite(&contaTiempo,sizeof(contaTiempo),1,archivo);
}

