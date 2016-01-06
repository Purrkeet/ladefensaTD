#include "stdafx.h"
#include "Figura.h"


CFigura::CFigura(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam, CCirculo* pAreaColision)
{
	Posicion = pPos;
	RutaImagen = pRutaImg;
	IndiceSpriteActual = pISA;
	IndiceSpriteMax = pISM;
	Tamanio = pTam;
	desfase = 1;
	Colision = pAreaColision;
	
	CantImgxSprites =new CPunto(1, 1);
	IndiceSpriteMin = new CPunto(0, 0);
}
CFigura::~CFigura(void)
{
	delete Posicion;
	delete IndiceSpriteActual;
	delete IndiceSpriteMax;
	delete Tamanio;
	delete Colision;
}
void CFigura::Dibujar(Bitmap ^bmp,Graphics ^gr)
{
	//calculo de tamaño del sprite chico
	/*Bitmap^ img = gcnew Bitmap(gcnew System::String(GetRutaImg().c_str()));
	img->MakeTransparent(img->GetPixel(0, 0));*/

	float anchoSpr = bmp->Size.Width / (float)GetCantIxS()->GetX();
	float altoSpr = bmp->Size.Height / (float)GetCantIxS()->GetY();
	Rectangle recOrigen = Rectangle(this->GetISA()->GetX()*anchoSpr, this->GetISA()->GetY()*altoSpr, anchoSpr, altoSpr);
	Rectangle recDestino = Rectangle(GetPosicion()->GetX(), GetPosicion()->GetY(), GetTamanio()->GetX(), GetTamanio()->GetY());
	//Rectangle recDestino = Rectangle(GetPosicion()->GetX(), GetPosicion()->GetY(), 100, 100);
	gr->DrawImage(bmp, recDestino, recOrigen, GraphicsUnit::Pixel);
	/*gr->DrawEllipse(Pens::Red, this->GetColision()->GetPosicion()->GetX(), this->GetColision()->GetPosicion()->GetY()
		, this->GetColision()->GetRadio()*2., this->GetColision()->GetRadio()*2.);
	gr->DrawLine(Pens::Yellow, this->GetColision()->GetCentro()->GetX(), this->GetColision()->GetCentro()->GetY()
		, this->GetColision()->GetCentro()->GetX(), this->GetColision()->GetCentro()->GetY());*/
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
	//eliminando lo usado
	
}
void CFigura::SetISMin(CPunto* pISMin){
	IndiceSpriteMin = pISMin;

}
CPunto* CFigura::GetPosicion()
{
	return Posicion;
}
string CFigura::GetRutaImg()
{
	return RutaImagen;
}
CPunto* CFigura::GetISA()
{
	return IndiceSpriteActual;
}
CPunto* CFigura::GetISM()
{
	return IndiceSpriteMax;
}
CCirculo* CFigura::GetColision()
{
	return Colision;
}
void CFigura::SetPosicion(CPunto* pPosicion)
{
	Posicion = pPosicion;
	//SetColision(new CCirculo(new CPunto(pPosicion->GetX()+desfase, pPosicion->GetY()+desfase), GetColision()->GetRadio()));
}
void CFigura::SetRutaImg(string pRutaImg)
{
	RutaImagen = pRutaImg;
}
void CFigura::SetISA(CPunto* pISA)
{
	IndiceSpriteActual = pISA;
}
void CFigura::SetISM(CPunto* pISM)
{
	IndiceSpriteMax = pISM;
}
void CFigura::SetColision(CCirculo* areaColision)
{
	Colision = areaColision;
}
void CFigura::SetCantIxS(CPunto* pCantIxS){ CantImgxSprites = pCantIxS; }
CPunto* CFigura::GetCantIxS(){ return CantImgxSprites; }
float CFigura::GetDesfase()
{
	return desfase;
}
void  CFigura::guardarArchivo(FILE * archivo)
{
	Posicion->guardarArchivo(archivo);
	int lenNombre = strlen(RutaImagen.c_str());
	fwrite(&lenNombre,sizeof(lenNombre),1,archivo);
	IndiceSpriteActual->guardarArchivo(archivo);
	char* Rutatemp = new char[lenNombre + 1];
	strcpy_s(Rutatemp,lenNombre + 1,RutaImagen.c_str());
	fwrite(Rutatemp,sizeof(char),lenNombre,archivo);
	IndiceSpriteMax->guardarArchivo(archivo);
	IndiceSpriteMin->guardarArchivo(archivo);
	CantImgxSprites->guardarArchivo(archivo);
	Tamanio->guardarArchivo(archivo);
	Colision->guardarArchivo(archivo);
}
void  CFigura::leerArchivo(FILE * archivo)
{
	Posicion->leerArchivo(archivo);
	int lenNombre ;
	fread(&lenNombre,sizeof(lenNombre),1,archivo);
	IndiceSpriteActual->guardarArchivo(archivo);
	char* Rutatemp = new char[lenNombre + 1];
	fread(Rutatemp,sizeof(char),lenNombre,archivo);
	Rutatemp[lenNombre] = '\0';
	RutaImagen = Rutatemp;
	IndiceSpriteActual->leerArchivo(archivo);
	IndiceSpriteMax->leerArchivo(archivo);
	IndiceSpriteMin->leerArchivo(archivo);
	CantImgxSprites->leerArchivo(archivo);
	Tamanio->leerArchivo(archivo);
	Colision->leeArchivo(archivo);
}