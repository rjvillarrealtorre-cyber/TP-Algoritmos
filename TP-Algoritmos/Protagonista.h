#pragma once
#include "Personaje.h"
#include "Arbol.h"

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
	int semillas;

	std::vector<Arbol*> arboles;

	int altoJugablePermitido;
public:
	Protagonista(string n, std::vector<std::vector<string>> sr, std::vector<std::vector<string>> sl, char d, int v, float px, float py, int vlc, int cnf, int ev, int cl) : 
		Personaje(n, sr, sl, d, v, px, py, vlc) {
		confianza = cnf;
		evidencia = ev;
		conocimientoLengua = cl;

		semillas = 6;
		arboles = {};

		altoJugablePermitido = ALTO_JUGABLE;
		contFramesInvulnerabilidad = 0;
	}

	~Protagonista() {
		for (Arbol* arbol : arboles) {
			delete arbol;
		}
	}

	// Permite el movimiento con las flechas direccionales
	void determinarMovimiento(const std::vector<std::vector<int>>& matrizMapa) {
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			//Restricciones	
			if (!(x + ancho >= ANCHO_JUGABLE - 1) && (matrizMapa[y + 2][x + 1] == 3 || matrizMapa[y + 2][x + 1] == 4 || matrizMapa[y + 2][x + 1] == 5)) {
				dir = 'R';
				borrar(matrizMapa);
				x += velocidad;
				mostrar(matrizMapa);
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (!(x <= 1) && (matrizMapa[y + 2][x - 1] == 3 || matrizMapa[y + 2][x - 1] == 4 || matrizMapa[y + 2][x - 1] == 5)) {
				dir = 'L';
				borrar(matrizMapa);
				x -= velocidad;
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
			if (!(y + alto >= altoJugablePermitido - 1)) {
				borrar(matrizMapa);
				y++;
				mostrar(matrizMapa);
			}
		}
	}

	void plantarArbol(bool teclaE, std::vector<std::vector<int>> matrizMapa) {
		if (!teclaE || semillas <= 0) return;

		semillas--;

		if (dir == 'R' && matrizMapa[y - 1][x + ancho] == 4) {
			arboles.push_back(new Arbol("arbol", {}, float(x + ancho + 1), float(y)));
		}
		else if (dir == 'L' && matrizMapa[y - 1][x - 2] == 4) {
			arboles.push_back(new Arbol("arbol", {}, float(x - 1), float(y)));
		}
	}

	//Getters

	int getConfianza() { return confianza; }
	int getEvidencia() { return evidencia;}
	int getConocimientoLengua() { return conocimientoLengua;}
	std::vector<Arbol*>& getArboles() { return arboles; }
	int getSemillas() { return semillas; }


	// Setters

	void setConfianza(int p) { confianza = p; }
	void setEvidencia(int p) { evidencia = p; }
	void setConocimientoLengua(int p) { conocimientoLengua = p; }
	void setAltoConfiablePermitido(int p) { altoJugablePermitido = p; }
	
};