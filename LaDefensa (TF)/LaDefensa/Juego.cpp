#include "stdafx.h"
#include "Juego.h"

CJuego::CJuego(std::string nom) 
{
	NombreJugador = nom;
	JuegoEnPausa = false;
	TotalVidas = 20;
	TotalDinero = 500;
	Puntaje = 0;
	TiempoJugado = 0;
}
CJuego::~CJuego()
{
}
void CJuego::BajarVida(int cantidad)
{
	TotalVidas=TotalVidas-cantidad;
}