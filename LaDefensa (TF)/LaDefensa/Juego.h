#pragma once
#include "Nivel.h"
class CJuego
{
public:
	CJuego(std::string nom);
	~CJuego();
	void PantallaMenu();
	void PantallaGameOver();
	void EmpezarJuego();
	void CrealPanelHerramientas();
	void GuardarJuego();
	void CargarJuego();
	void PausarJuego();
	void BajarVida(int cantidad);
	bool GameOver();
	//por mientras
	bool JuegoEnPausa;
	int TotalVidas;
	int TotalDinero;
	int Puntaje;
	int TiempoJugado;
	std::string NombreJugador;
private:
	//bool JuegoEnPausa;
	//int TotalVidas;
	//int TotalDinero;
	//int Puntaje;
	//int TiempoJugado;
	//std::string NombreJugador;
};
