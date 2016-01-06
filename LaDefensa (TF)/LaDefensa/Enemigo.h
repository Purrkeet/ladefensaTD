#pragma once
#include "Figura.h"

class CEnemigo : public CFigura
{
private:
	int Vida;
	int Dinero;
	CPunto* Velocidad;
//	CPunto * pPos;
	int Puntaje;
	bool Camuflado;
	bool liberado;
	int Direccion;
	int contaTiempo;

	
public:
	int tipoE;
	CEnemigo(CPunto* pPos, string pRutaImg, CPunto* pISA, CPunto* pISM, CPunto* pTam, CCirculo* pColision, int pVida,int pDinero, CPunto* pVel,int pPunt, bool pCamu);
	~CEnemigo(void);
	void Mover();
	//void Dibujar(System::Drawing::Graphics ^gr);
	int GetVida();
	int GetDinero();

	
	bool getLiberado();
	CPunto* GetVelocidad();
	int GetPuntaje();
	int getTiempo();
	void setTiempo(int pTiempo);
	bool GetCamuflado();
	void SetVida(int pVida);
	void liberar(){liberado = true;}
	void SetDinero(int pDinero);
	void SetVelocidad(CPunto* pVelocidad);
	void SetPuntaje(int pPuntaje);
	void SetCamuflado(bool pCamuflado);
	void leerArchivo(FILE *archivo);
	void guardarArchivo(FILE *archivo);

	bool EsLaMismaDireccion(int direc);
	void SetDireccion(int direc);//solo setea Usar en constructores
	
	
};