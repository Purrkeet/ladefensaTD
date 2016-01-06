#include "stdafx.h"
#include "Oleadas.h"


COleadas::COleadas(CMapa * mapa,int * orden,int * maximos, int cantTropas)
{
	TiempoDeSalida=200;
	DineroxOleadas=250;
	tropas= new list<ArrEnemigos*>();
	//aca creamos los enemigos 

	CPunto * p = new CPunto(0,0);
	float desface = 2;
	CPunto * tamano = new CPunto(mapa->getbloqueAnchoalto()->GetX(), mapa->getbloqueAnchoalto()->GetY());
	CPunto * pCirculo = new CPunto(p->GetX() + desface, p->GetY() + desface);
	CCirculo * c = new CCirculo(new CPunto(p->GetX() + desface, p->GetY() + desface),tamano->GetX()/2.0f-desface);
	CPunto * Velocidad = new CPunto(tamano->GetX()/4.0f,0);// n
	 
	CEnemigo * enemigo = new CEnemigo(p, "sprite1(nivel1).png", new CPunto(0, 0), new CPunto(4, 0), tamano, c, 1, 10, Velocidad, 10, false);
	enemigo->SetCantIxS(new CPunto(4, 1));
	//asumiendo que INICIO es DERECHA	
	enemigo->SetDireccion((int)CMapa::MAPA::DERECHA);
	enemigo->tipoE=0;
	//0-2 mas debiles
	enemigos.push_back(enemigo);
	enemigos.push_back(new CEnemigo(new CPunto(0,0),"",new CPunto(0,0),new CPunto(5,0),tamano,new CCirculo(new CPunto(0 + desface,0 + desface),tamano->GetX()/2.0f-desface),5,20,new CPunto(tamano->GetX()/2.0f,0),30,false));
	enemigos[1]->SetCantIxS(new CPunto(6, 1));
	enemigos[1]->SetDireccion((int)CMapa::MAPA::DERECHA);
	enemigos[1]->tipoE=1;
	enemigos.push_back(new CEnemigo(new CPunto(0, 0), "", new CPunto(0, 0), new CPunto(5, 0), tamano, new CCirculo(new CPunto(0 + desface, 0 + desface), tamano->GetX() / 2.0f - desface), 20, 50, new CPunto(tamano->GetX() / 16.0f, 0), 50, false));
	enemigos[2]->SetCantIxS(new CPunto(6, 1));
	enemigos[2]->SetDireccion((int)CMapa::MAPA::DERECHA);
	enemigos[2]->tipoE=2;
	//3-5 los mas altos
	enemigos.push_back(new CEnemigo(new CPunto(0, 0), "", new CPunto(0, 0), new CPunto(4, 0), tamano, new CCirculo(new CPunto(0 + desface, 0 + desface), tamano->GetX() / 2.0f - desface), 30, 30, new CPunto(tamano->GetX() / 2.0f, 0), 30, false));
	enemigos[3]->SetCantIxS(new CPunto(4, 1));
	enemigos[3]->SetDireccion((int)CMapa::MAPA::DERECHA);
	enemigos[3]->tipoE=3;
	enemigos.push_back(new CEnemigo(new CPunto(0, 0), "", new CPunto(0, 0), new CPunto(4, 0), tamano, new CCirculo(new CPunto(0 + desface, 0 + desface), tamano->GetX() / 2.0f - desface), 35, 40, new CPunto(tamano->GetX() / 8.0f, 0), 30, false));
	enemigos[4]->SetCantIxS(new CPunto(4, 1));
	enemigos[4]->SetDireccion((int)CMapa::MAPA::DERECHA);
	enemigos[4]->tipoE=4;
	enemigos.push_back(new CEnemigo(new CPunto(0, 0), "", new CPunto(0, 0), new CPunto(4, 0), tamano, new CCirculo(new CPunto(0 + desface, 0 + desface), tamano->GetX() / 2.0f - desface), 40, 50, new CPunto(tamano->GetX() / 16.0f, 0), 50, false));
	enemigos[5]->SetCantIxS(new CPunto(4, 1));
	enemigos[5]->SetDireccion((int)CMapa::MAPA::DERECHA);
	enemigos[5]->tipoE=5;
	//6-8 bunkers
	enemigos.push_back(new CEnemigo(new CPunto(0, 0), "", new CPunto(0, 0), new CPunto(4, 0), tamano, new CCirculo(new CPunto(0 + desface, 0 + desface), tamano->GetX() / 2.0f - desface), 25, 20, new CPunto(tamano->GetX() / 4.0f, 0), 30, false));
	enemigos[6]->SetCantIxS(new CPunto(6, 1));
	enemigos[6]->SetDireccion((int)CMapa::MAPA::DERECHA);
	enemigos[6]->tipoE=6;
	enemigos.push_back(new CEnemigo(new CPunto(0, 0), "", new CPunto(0, 0), new CPunto(4, 0), tamano, new CCirculo(new CPunto(0 + desface, 0 + desface), tamano->GetX() / 2.0f - desface), 30, 25, new CPunto(tamano->GetX() / 4.0f, 0), 30, false));
	enemigos[7]->SetCantIxS(new CPunto(4, 1));
	enemigos[7]->SetDireccion((int)CMapa::MAPA::DERECHA);
	enemigos[7]->tipoE=7;
	enemigos.push_back(new CEnemigo(new CPunto(0, 0), "", new CPunto(0, 0), new CPunto(4, 0), tamano, new CCirculo(new CPunto(0 + desface, 0 + desface), tamano->GetX() / 2.0f - desface), 35, 30, new CPunto(tamano->GetX() / 4.0f, 0), 30, false));
	enemigos[8]->SetCantIxS(new CPunto(4, 1));
	enemigos[8]->SetDireccion((int)CMapa::MAPA::DERECHA);
	enemigos[8]->tipoE=8;
	contador = 0;
	if (orden != nullptr){
		this->orden = orden;		
		cantidades = maximos;
		this->maxArrEnem=cantTropas;
	}
	else{
		this->orden = new int[6];
		this->orden[0]=1;
		this->orden[1]=2;
		this->orden[2]=3;
		this->orden[3]=0;
		this->orden[4]=5;
		this->orden[5]=-1;
		
		this->cantidades = new int[5];
		cantidades[0]=8;//cantidad mas uno xd
		cantidades[1]=4;
		cantidades[2]=8;
		cantidades[3]=4;
		cantidades[4]=6;

		maxArrEnem = 5;
	}
	//revisaar si funciona
}
COleadas::~COleadas(void)
{
}

bool COleadas::AgregarTropa(CEnemigo * enemigo,int max){
	ArrEnemigos * NuevaTropa = new ArrEnemigos(max,enemigo);
	tropas->push_back(NuevaTropa);
	return true;
}
void COleadas::AparecerTropa(int c, CMapa* mapa)
{//las tropas ya deben existir en memoria
	
	if (contador < maxArrEnem && c % TiempoDeSalida == 0)
	{
		if (orden[contador] != -1)//al encontrar -1 ya no salen mas
		{
			int tipoEnemigo = orden[contador];
			AgregarTropa(enemigos[tipoEnemigo], cantidades[contador]);
			++contador;
		}
		else
			contador = maxArrEnem;
	}
	for (list<ArrEnemigos*>::iterator it = tropas->begin(); it != tropas->end(); it++)
		(*it)->aparecerEnemigo(c,mapa);
	
}
void COleadas::DibujarOleada(array<System::Drawing::Bitmap^>^ imgs, Graphics ^ g)
{
	for (list<ArrEnemigos*>::iterator it = tropas->begin(); it != tropas->end(); it++)
		(*it)->dibujarEnemigo(imgs,g);
}

int COleadas::moverTropas(CMapa* mapa){
	int vidas=0;
	for (list<ArrEnemigos*>::iterator it = tropas->begin(); it != tropas->end(); it++)
		vidas +=(*it)->moverEnemigo(mapa);
	return vidas;
}
list<ArrEnemigos*>* COleadas::GetTropasList(){
	return tropas;
}
void COleadas::escribirArchivos(FILE * archivo,CMapa * m)
{
	fwrite(&TiempoDeSalida,sizeof(TiempoDeSalida),1,archivo);
	fwrite(&maxArrEnem,sizeof(maxArrEnem),1,archivo);
	fwrite(&DineroxOleadas,sizeof(DineroxOleadas),1,archivo);
	for(int i = 0; i < 6; i++)
		fwrite(&orden[i],sizeof(orden[i]),1,archivo);
	for(int i = 0 ; i< 5;i++)
		fwrite(&cantidades[i],sizeof(cantidades[i]),1,archivo);
	for (list<ArrEnemigos*>::iterator it = tropas->begin(); it != tropas->end(); it++)
		(*it)->guardarArchivo(archivo);
}
void COleadas::leerArchivo(FILE * archivo,CMapa * m)
{
	int cont;
	int i;
	fread(&TiempoDeSalida,sizeof(TiempoDeSalida),1,archivo);
	fread(&maxArrEnem,sizeof(maxArrEnem),1,archivo);
	fread(&DineroxOleadas,sizeof(DineroxOleadas),1,archivo);
	for(int i = 0; i < 6; i++) 
		fread(&orden[i],sizeof(orden[i]),1,archivo);
	for(int i = 0 ; i< 5;i++)
		fread(&cantidades[i],sizeof(cantidades[i]),1,archivo);
	while(cont < maxArrEnem)
	{
		AgregarTropa(enemigos[cont],maxArrEnem);
		cont++;
	}
	for (list<ArrEnemigos*>::iterator it = tropas->begin(); it != tropas->end(); it++)
		(*it)->leerArchvio(archivo,m);
}