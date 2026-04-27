#pragma once
#include "Personaje.h"

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

	void determinarMovimiento() {
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			dir = 'R';
			borrar();
			x++;
			avanzar();
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			dir = 'L';
			borrar();
			x--;
			avanzar();
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			borrar();
			y--;
			avanzar();
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			borrar();
			y++;
			avanzar();
		}
	}

	//Getters

	int getConfianza() { return confianza; }
	int getEvidencia() { return evidencia;}
	int getConocimientoLengua() { return conocimientoLengua;}
};