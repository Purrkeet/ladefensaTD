#include "stdafx.h"
#include "Nivel.h"


CNivel::CNivel(int maximo,int  orden[30][10])
{
	//TODO terminar leer de archivo
	Torres = new CArrTorres();
	TiempoDeSalida = 10;
	waves=new list<COleadas*>();
	//for (int i = 0; i < 30; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		//orden[i][j] = ;
	//	}
	//}
	//if(orden == nullptr){
	//	int orden1 [3][10]=  {2};
	//	orden= orden1;
	//	//orden[0]= new int [3];
	//}
	//
	contOrden = 0;
	this->maximo = maximo;
	m = new CMapa();
}

CNivel::~CNivel(void)
{
}
void CNivel::MostrarTropa(int acelerar, CMapa* mapa,int c)
{
	if ( contOrden > maximo && c % TiempoDeSalida == 0)
	{
		waves->push_back(new COleadas(mapa));
	}
	 
}
void CNivel::MostrarTropa(int acelerar, int c)
{
	if ( contOrden < maximo && c % TiempoDeSalida == 0)
	{
		waves->push_back(new COleadas(m));
		
		++contOrden;
	}
	for (list<COleadas*>::iterator it = waves->begin(); it != waves->end(); it++){
		 (*it)->AparecerTropa(c,m);
	}

}
void CNivel::dibujarMapa(array<System::Drawing::Bitmap^>^ imgs, Graphics ^ g, Rectangle r)
{
	m->DibujarMapa(imgs,g,r);
}
void CNivel::moverBalas(Rectangle^r){

	
	if(Torres->getCantTorres()==0)return;
	Torres->MoverBalasdeTorres(r);
}
CMapa * CNivel::getmapa()
{
	return m;
}
COleadas * CNivel::getOleada(){
	//return waves;
	return nullptr;
}
int CNivel::Colisiona(){
	int totalDinero=0;
for (list<COleadas*>::iterator it = waves->begin(); it != waves->end(); it++)
	{
		totalDinero+=Torres->Colisiona(*it);
	}	
return totalDinero;
}
void  CNivel::setmapa(CMapa * pmapa)
{
	m = pmapa;
}
void CNivel::inicializarMap(FILE * archivo,System::Drawing::Graphics^ gr,Rectangle ^r)														
{
	m->LeerdeArchivo(archivo);
	m->pasarMapa(map1);
	Color c;
	int ancho = (r->Width) / BLOQUESHORIZONTALES;
	int alto = (r->Height) / BLOQUESVERTICALES;
	
	for (int i = 0; i < BLOQUESVERTICALES; i++)
	{
		for (int j = 0; j < BLOQUESHORIZONTALES; j++)
		{
			switch (map1[i][j])
			{
			case MAP1::START : c=Color::Green; break;
			case MAP1::DERECHA : c=Color::Red; break;
			case MAP1::IZQUIERDA : c=Color::Blue; break;
			case MAP1::ABAJO : c=Color::Yellow; break;
			case MAP1::ARRIBA : c=Color::Ivory; break;
			case MAP1::BLOCKED : c=Color::Black; break;
			case MAP1::EXIT : c=Color::Green; break;
			case MAP1::FREE : c=Color::SkyBlue; break;
			}
			gr->FillRectangle(gcnew SolidBrush(c),j*ancho,i*alto,ancho,alto);
			gr->DrawRectangle(Pens::Black,j*ancho,i*alto,ancho,alto);
			//gr->FillRectangle(gcnew SolidBrush(c),i+i*ancho,j+j*alto,ancho,alto);
		}
	}
	

}
void CNivel::agregarOleada(COleadas * oleada)
{
	waves->push_back(oleada);
	
}
void CNivel::dibujarOlas(array<System::Drawing::Bitmap^>^ imgs, Graphics ^ g){
	for (list<COleadas*>::iterator it = waves->begin(); it != waves->end(); it++)
	{
		(*it)->DibujarOleada( imgs,g);
	}

}
void CNivel::MoverOlas(CMapa* mapa){
	for (list<COleadas*>::iterator it = waves->begin(); it != waves->end(); it++){
		(*it)->moverTropas(mapa);
	}
		
}
int CNivel::MoverOlas(){
	int vidas=0;
	for (list<COleadas*>::iterator it = waves->begin(); it != waves->end(); it++){
		vidas+=(*it)->moverTropas(m);
	}
	return vidas;
}
void CNivel::CrearTorre(CTorre* oTorre){
	Torres->AgregarTorre(oTorre);

}
void  CNivel::dibujarTorres(array<System::Drawing::Bitmap^>^ imgs, Graphics ^ g){
	Torres->DibujarTorres(imgs,g);
}
CTorre* CNivel::BuscarTorreSeleccionada(int x, int y)
{
	return Torres->BuscarTorreClick(x, y);
}
void CNivel::EliminarTorre(CTorre*Teliminar)
{
	Torres->Eliminar(Teliminar);
}
void CNivel::dibujarBalas(Graphics^ g){
	Torres->DibujarBalas(g);

}
void  CNivel::LeerNiveldeArchivo(FILE* archivo)
{

	int cantOleadas;
	fread(&cantOleadas,sizeof(cantOleadas),1,archivo);
	for (int i = 0 ; i < cantOleadas;i++)
	{
		waves->push_back(new COleadas(m));
	}
	for(list<COleadas*>::iterator it = waves->begin(); it != waves->end();it++)
		(*it)->leerArchivo(archivo,m);
	
	
	Torres->leerArchivo(archivo);
	fread(&TiempoDeSalida,sizeof(TiempoDeSalida),1,archivo);
	int map1[BLOQUESVERTICALES][BLOQUESHORIZONTALES];
	for(int i = 0; i < 30;i ++)
		for(int k = 0; k < 10 ; k++)
			for(int j = 0 ; j < 10 ; j++)
				fread(&orden[i][k][j],sizeof(&orden[i][k][j]),1,archivo);
	fread(&contOrden,sizeof(contOrden),1,archivo);
	fread(&maximo,sizeof(maximo),1,archivo);
}
void  CNivel::guardarArchivo(FILE * archivo)
{
	CMapa * m;
	int cantOleadas = waves->size();
	fwrite(&cantOleadas,sizeof(cantOleadas),1,archivo);
	for (list<COleadas*>::iterator it = waves->begin(); it != waves->end(); it++)
	{
		(*it)->escribirArchivos(archivo,m);
	}
	Torres->guardarArchivo(archivo);
	fwrite(&TiempoDeSalida,sizeof(TiempoDeSalida),1,archivo);
	int map1[BLOQUESVERTICALES][BLOQUESHORIZONTALES];
	for(int i = 0 ; i < BLOQUESVERTICALES ;i++)
		for(int j = 0 ; j < BLOQUESHORIZONTALES ; j ++)
			fwrite(&map1[i][j],sizeof(map1[i][j]),1,archivo);
	for(int i = 0; i < 30;i ++)
		for(int k = 0; k < 10 ; k++)
			for(int j = 0 ; j < 10 ; j++)
				fwrite(&orden[i][k][j],sizeof(&orden[i][k][j]),1,archivo);
	fwrite(&contOrden,sizeof(contOrden),1,archivo);
	fwrite(&maximo,sizeof(maximo),1,archivo);
}
void CNivel::dispararTorres()
{
	if(Torres->getCantTorres()==0) return;
	for(list<COleadas*>::iterator it = waves->begin(); it != waves->end(); it++)
	{
		Torres->TorresDisparen((*it));
	}
}