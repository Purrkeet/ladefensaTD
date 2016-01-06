#include "stdafx.h"
#include "ArrBalas.h"


CArrBalas::CArrBalas(int Danio)
{
	this->Danio = Danio;
	balas=new list<CBala*>();
	Velocidad=40;
}


CArrBalas::~CArrBalas()
{
}
void CArrBalas::DibujarBalas(System::Drawing::Graphics ^gr){
	if(balas->size()==0)return;
	for (list<CBala*>::iterator it = balas->begin(); it != balas->end(); it++){
		//ingresar la imagen de las balas
		(*it)->Dibujar(gr);
	}
}
void CArrBalas::MoverBalas(int radio,Rectangle^ r){
	
	for (list<CBala*>::iterator it = balas->begin(), prev= balas->end(); it != balas->end();prev=it, it++){
		(*it)->Mover();
		//TODO
		if((*it)->GetPosicion()->GetX()>r->Width || (*it)->GetPosicion()->GetX()<0){		
			
			balas->remove((*it));
			if(prev==balas->end())
				(it)=balas->begin();
			else
			(it)=prev;
			if(balas->empty())break;
			continue;
		}
		if((*it)->GetPosicion()->GetY()>r->Height || (*it)->GetPosicion()->GetY()<0){		
			
			balas->remove((*it));
			if(prev==balas->end())
				(it)=balas->begin();
			else
			(it)=prev;
			if(balas->empty())break;
			continue;
		}

	}
}
int CArrBalas::ColisionArrEnemigos(ArrEnemigos* enemigos ){
	int dineroTotal=0;
	for(list<CEnemigo*>::iterator it = enemigos->getListEnemigos()->begin(),prev=enemigos->getListEnemigos()->end() ; it != enemigos->getListEnemigos()->end();prev=it, ++it){
					 for (list<CBala*>::iterator bal = balas->begin(), prevb= balas->end(); bal != balas->end();prevb=bal, bal++){
						 if((*it)->GetColision()->Colisiona((*bal)->GetColision()->GetCentro(),(*bal)->GetColision()->GetRadio())){
							 (*it)->SetVida((*it)->GetVida()-(*bal)->GetDanio());
							 //elimina bala
							 balas->remove((*bal));
							if(prevb==balas->end())
								(bal)=balas->begin();
							else
							(bal)=prevb;
							if(balas->empty())break;

							continue;
			
						 }
					 }
	 //si ya no tiene vida el enemigo
			 if((*it)->GetVida() <= 0){
			 //aniadir dinero
				 dineroTotal+=(*it)->GetDinero();		 
				 //eliminar enemigo
				 enemigos->getListEnemigos()->remove((*it));
				if(prev==enemigos->getListEnemigos()->end())
					(it)=enemigos->getListEnemigos()->begin();
				else
				(it)=prev;
					if(enemigos->getListEnemigos()->size()==0){
						break;	
					}
					continue;
			 }
	
	}
	return dineroTotal;
}	
void CArrBalas::Bang(float vX, float vY, CPunto* pos){
	balas->push_back(new CBala(pos, "", nullptr, nullptr, new CPunto(10, 10), new CCirculo(pos,5),
		new CPunto(vX, vY), Danio));
}
float CArrBalas::getVelocidad(){
	return Velocidad;
}