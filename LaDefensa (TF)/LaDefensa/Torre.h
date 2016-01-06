#pragma once
#include "Figura.h"
class CTorre : public CFigura
{
private:
	int PrecioVenta;
	int PrecioUpgrade;
	int Tipo;
	int Nivel;
	bool PuestoEnElSuelo;
	float rango;
	string TipoEscrito;
	int Ataque;
	int Velocidad;
	int TorreClikeada;
	//CArrBalas **Balas;
public:
	CTorre(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam, CCirculo* pColision,int pPrecioVenta, int pPrecioUpgrade, int pTipo, int pNivel, bool pPuestoEnElSuelo);
	~CTorre(void);
	//CTorre(CTorre* torre){  }

	
	void MoverBalas();
	void DibujarRango(Graphics ^gr);
	int GetPrecioVenta();
	int GetPrecioUpgrade();
	int GetTipo();
	int GetNivel();
	bool GetPuestoEnElSuelo();
	void SetPrecioVenta(int pPrecioVenta);
	void SetPrecioUpgrade(int pPrecioUpgrade);
	void SetTipo(int pTipo);
	void SetNivel(int pNivel);
	void SetPuestoEnElSuelo(bool pPuestoEnElSuelo);
	string GetTipoEscrito();
	int GetAtaque();
	int GetVelocidad();
	int GetTorreClikeada();
	int GetTorre();
	int GetRango();
	void Dibujar(Bitmap ^bmp, Graphics ^gr);
	void SetTorreClikeada(int dato);
	void guardarArchivo(FILE * archivo);
	void leerArchivo(FILE * archivo);
	//virtual method
	
	
};

