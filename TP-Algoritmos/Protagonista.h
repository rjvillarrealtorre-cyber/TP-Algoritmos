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
	void determinarMovimiento(const std::vector<std::vector<int>>& matrizMapa) {
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			//Restricciones
			if (!(x + ancho >= ANCHO_JUGABLE - 1) && (matrizMapa[y + 2][x + 1] == 3 || matrizMapa[y + 2][x + 1] == 4 || matrizMapa[y + 2][x + 1] == 5)) {
				dir = 'R';
				borrar(matrizMapa);
				x++;
				mostrar(matrizMapa);
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (!(x <= 1) && (matrizMapa[y + 2][x - 1] == 3 || matrizMapa[y + 2][x - 1] == 4 || matrizMapa[y + 2][x - 1] == 5)) {
				dir = 'L';
				borrar(matrizMapa);
				x--;
				mostrar(matrizMapa);
			}
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (!(y <= 1) && (matrizMapa[y - 1 + 2][x] == 3 || matrizMapa[y - 1 + 2][x] == 4 || matrizMapa[y - 1 + 2][x] == 5)) {
				borrar(matrizMapa);
				y--;
				mostrar(matrizMapa);
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (!(y + alto >= ALTO_JUGABLE - 1)) {
				borrar(matrizMapa);
				y++;
				mostrar(matrizMapa);
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

	void setX(float p) { x = p; }
};