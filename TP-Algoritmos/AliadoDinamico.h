#pragma once
#include <cstdlib>

#include "Personaje.h"

class AliadoDinamico : public Personaje {
private:
	string estado;
public:
	AliadoDinamico(string n, std::vector<std::vector<string>> sr, std::vector<std::vector<string>> sl, char d, int v, float px, float py, int vlc) 
		: Personaje(n, sr, sl, d, v, px, py, vlc) {
		estado = "seguir";
	}

	void seguirProtagonista(Protagonista& prot) {
		if (prot.getX() - x > 5) {
			dir = 'R';
			x++;
		}
		else if (prot.getX() - x < -5) {
			dir = 'L';
			x--;
		}

		if (prot.getY() - y > 2) y++;
		else if (prot.getY() - y < -2) y--;
	}

	void manejarEstados() {
		if (GetAsyncKeyState('Q') & 0x0001) {
			if (estado == "seguir") estado = "parar";
			else if (estado == "parar") estado = "seguir";
		}
	}

	void manejarMovimiento(std::vector<std::vector<int>>& mapaDinamico, Protagonista& prot) {
		if (estado == "seguir") {
			borrar(mapaDinamico);
			seguirProtagonista(prot);
			mostrar(mapaDinamico);
		}
		else {
			mostrar(mapaDinamico);
		}
	}
};