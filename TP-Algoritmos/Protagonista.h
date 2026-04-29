#pragma once
#include "Personaje.h"

/*
	CLASE PROTAGONISTA:
	El protagonista es controlado por el jugador.
	Es una clase hija de "Personaje".
	El cambio significativo está en la inclusión de
	CONFIANZA, EVIDENCIA, CONOCIMIENTO DE LENGUA y
	la capacidad de moverse con las flechas e
	interactuar con los NPCs (personajes no jugables).
*/

class Protagonista : public Personaje {
private:
	int confianza;
	int evidencia;
	int conocimientoLengua;
public:
	Protagonista(string n, std::vector<std::vector<string>> sr, std::vector<std::vector<string>> sl, char d, int v, float px, float py, int vlc, int cnf, int ev, int cl) : 
		Personaje(n, sr, sl, d, v, px, py, vlc) {
		confianza = cnf;
		evidencia = ev;
		conocimientoLengua = cl;
	}

	// Permite el movimiento con las flechas direccionales
	void determinarMovimiento() {
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			//Restricciones
			if (!(x + ancho >= ANCHO_JUGABLE - 1)) {
				dir = 'R';
				borrar();
				x++;
				mostrar();
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (!(x <= 1)) {
				dir = 'L';
				borrar();
				x--;
				mostrar();
			}
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (!(y <= 1)) {
				borrar();
				y--;
				mostrar();
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (!(y + alto >= ALTO_JUGABLE - 1)) {
				borrar();
				y++;
				mostrar();
			}
		}
	}

	//Getters

	int getConfianza() { return confianza; }
	int getEvidencia() { return evidencia;}
	int getConocimientoLengua() { return conocimientoLengua;}

	float getX() { return x; }
	float getY() { return y; }

	// Setters

	void setConfianza(int p) { confianza = p; }
	void setEvidencia(int p) { evidencia = p; }
	void setConocimientoLengua(int p) { conocimientoLengua = p; }
};