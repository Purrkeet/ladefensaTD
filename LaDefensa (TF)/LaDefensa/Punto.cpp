#include "stdafx.h"
#include "Punto.h"


CPunto::CPunto(float px, float py)
{
	x=px;
	y=py;
}
CPunto::~CPunto(void)
{
}
float CPunto::GetX()
{
	return x;
}
float CPunto::GetY()
{
	return y;
}
void CPunto::SetX(float px)
{
	x=px;
}
void CPunto::Sety(float py)
{
	y=py;
}
void CPunto::guardarArchivo(FILE * archivo)
{
	fwrite(&x,sizeof(x),1,archivo);
	fwrite(&y,sizeof(y),1,archivo);
}
void CPunto::leerArchivo(FILE * archivo)
{
	fread(&x,sizeof(x),1,archivo);
	fread(&y,sizeof(y),1,archivo);
}