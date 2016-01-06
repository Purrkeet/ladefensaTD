#include "stdafx.h"
#include "Arrenemigos.h"


ArrEnemigos::ArrEnemigos(int Max,CEnemigo * enemigo)
{
	enemigos=new list<CEnemigo*>();
	this->Max = Max;
	this->enemigo = enemigo;
	cantidad=0;//la cantiddad no disminuye
	TiempoSalidaEnemigo=10;
	pivEnemigo = enemigos->begin();

	
}
ArrEnemigos::~ArrEnemigos(void)
{
}
void ArrEnemigos::aparecerEnemigo(int c, CMapa* mapa){

	if (cantidad <= Max && c % TiempoSalidaEnemigo == 0)
		agregarEnemigo(mapa);
}
bool ArrEnemigos::agregarEnemigo(CMapa* mapa)
{

	CEnemigo* aux= new CEnemigo(new CPunto(enemigo->GetPosicion()->GetX(),enemigo->GetPosicion()->GetY()),enemigo->GetRutaImg(),enemigo->GetISA(),enemigo->GetISM(),enemigo->GetTamanio(),
		new CCirculo(new CPunto(enemigo->GetColision()->GetPosicion()->GetX(),enemigo->GetColision()->GetPosicion()->GetY()),enemigo->GetColision()->GetRadio()),enemigo->GetVida(),enemigo->GetDinero(),new CPunto(enemigo->GetVelocidad()->GetX(),enemigo->GetVelocidad()->GetX()),enemigo->GetPuntaje(),enemigo->GetCamuflado());
	aux->SetCantIxS(enemigo->GetCantIxS());
	aux->SetDireccion((int)CMapa::MAPA::DERECHA);
	aux->liberar();
	aux->tipoE=enemigo->tipoE;
	enemigos->push_back(aux);
	cantidad++;
	
	return true;	
}

void ArrEnemigos::dibujarEnemigo(array<System::Drawing::Bitmap^>^ imgs, System::Drawing::Graphics ^ g)
{
	for(list<CEnemigo*>::iterator it = enemigos->begin() ; it != enemigos->end(); it++)
	{
		//se indica que imagen le pertenece segun el enemigo
		//if enemigo es troll pasar la imagen troll
		int tipo=(*it)->tipoE;
		(*it)->Dibujar(imgs[tipo], g);
	}
}
int ArrEnemigos::moverEnemigo(CMapa* mapa)
{
	int vidas=0;
	for(list<CEnemigo*>::iterator it = enemigos->begin() ,prev =enemigos->end(); it != enemigos->end();prev=it, it++)
	{
		//consegir la posición
		//Si el centro del circulo de colisión esta en un cuadrado que tiene otra dirección
		  //Primero ubicamos el cuadrado en el que esta
		CPunto * centroEnemigo=(*it)->GetColision()->GetCentro();
		CPunto * AnchoAlto = mapa->getbloqueAnchoalto();
		int posX= centroEnemigo->GetX() / AnchoAlto->GetX();
		int posY = centroEnemigo->GetY() / AnchoAlto->GetY();
		//centro del bloque
		float centroBloqueX=posX*AnchoAlto->GetX() + AnchoAlto->GetX() / 2.f;
		float centroBloqueY = posY*AnchoAlto->GetY() + AnchoAlto->GetY() / 2.f;
		  //obteniendo el cuadrado, preguntamos si la dirección que contiene es su misa 
		  // dirección
		if (centroEnemigo->GetX() == centroBloqueX && centroEnemigo->GetY() == centroBloqueY){
			//eso es al inicio
			if (!(*it)->EsLaMismaDireccion(mapa->GetCaracterDelMapa(posX, posY)))
			{
				//si no lo es cambiar de dirección
				CambiarDirección(it, mapa->GetCaracterDelMapa(posX, posY));
			}
		
		}		
		(*it)->Mover();
		if((*it)->GetPosicion()->GetY()>AnchoAlto->GetX()*BLOQUESVERTICALES)
		{
			vidas+=(*it)->GetVida();
			 //eliminar enemigo
			 enemigos->remove((*it));
			if(prev==enemigos->end())
				(it)=enemigos->begin();
			else
			(it)=prev;
				if(enemigos->size()==0){
					break;	
				}
				continue;
		}
	}
	return vidas;
}
void ArrEnemigos::liberarEnemys()
{
}
bool ArrEnemigos::enRango(CPunto* centroTorre, float radio, bool PuedeVerCamuflados){
	for (pivEnemigo = enemigos->begin(); pivEnemigo != enemigos->end(); pivEnemigo++)
	{
		if ((*pivEnemigo)->getLiberado() == true){
		//si ha sido liberado
			if (((*pivEnemigo)->GetCamuflado() && PuedeVerCamuflados) || !((*pivEnemigo)->GetCamuflado()))
				//ataca a los primero que ve
				if ((*pivEnemigo)->GetColision()->Colisiona(centroTorre, radio)){
					return true;
				}
		}
	}
	return false;
}
void ArrEnemigos::CambiarDirección(list<CEnemigo*>::iterator ene, 
	int direc){
	CPunto* velocidad=(*ene)->GetVelocidad();
	float velX = velocidad->GetX();
	float velY = velocidad->GetY();
	float velocidadEnemigo = 0;
	//como la velocidades solo lo contiene uno buscamos cual
	if (velX == 0){
		velocidadEnemigo = (velY > 0) ? velY : velY*-1;
	}
	else{
		velocidadEnemigo = (velX > 0) ? velX : velX*-1;
	}

	switch (direc)
	{//asumiendo que START es DERECHA
	case CMapa::MAPA::START: 
	case CMapa::MAPA::DERECHA: 
		velocidad->SetX(velocidadEnemigo);
		velocidad->Sety(0);
		break;
	case CMapa::MAPA::IZQUIERDA: 
		velocidad->SetX(velocidadEnemigo*-1);
		velocidad->Sety(0);
		break;
		//Asumiendo que Exit Es abajo
	case CMapa::MAPA::EXIT: 
		//al llegar a exit muere
		//quita vidas

		//elimina enemigo
		//return;
	case CMapa::MAPA::ABAJO: 
		velocidad->Sety(velocidadEnemigo);
		velocidad->SetX(0);
		break;
	case CMapa::MAPA::ARRIBA: 
		velocidad->Sety(velocidadEnemigo*-1);
		velocidad->SetX(0);
		break;

	}
	(*ene)->SetDireccion(direc);
	(*ene)->SetVelocidad(velocidad);
}
list<CEnemigo*>::iterator ArrEnemigos::getIteradorEnemigo(){
	return pivEnemigo;
}
void ArrEnemigos::guardarArchivo(FILE * archivo)
{
	fwrite(&Max,sizeof(Max),1,archivo);
	fwrite(&cantidad,sizeof(cantidad),1,archivo);
	fwrite(&TiempoSalidaEnemigo,sizeof(TiempoSalidaEnemigo),1,archivo);
	for(list<CEnemigo*>::iterator it = enemigos->begin() ; it != enemigos->end(); it++)
		(*it)->guardarArchivo(archivo);
}
void ArrEnemigos::leerArchvio(FILE * archivo,CMapa * m)
{
	int cont = 0;
	fread(&Max,sizeof(Max),1,archivo);
	fread(&cantidad,sizeof(cantidad),1,archivo);
	fread(&TiempoSalidaEnemigo,sizeof(TiempoSalidaEnemigo),1,archivo);
	while(cont < Max)
	{
		agregarEnemigo(m);
		cont++;
	}
	cont = 0;
	for(list<CEnemigo*>::iterator it = enemigos->begin()  ; it != enemigos->end(); it++)
	{
		(*it)->leerArchivo(archivo);
	}
}