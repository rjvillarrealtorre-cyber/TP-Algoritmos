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
	bool enBote;
	bool altoJugablePuestoAnteriormente;
public:
	Protagonista(string n, std::vector<std::vector<string>> sr, std::vector<std::vector<string>> sl, char d, int v, float px, float py, int vlc, int cnf, int ev, int cl) : 
		Personaje(n, sr, sl, d, v, px, py, vlc) {
		confianza = cnf;
		evidencia = ev;
		conocimientoLengua = cl;

		semillas = 6;
		arboles = {};

		altoJugablePermitido = ALTO_JUGABLE - 1;
		contFramesInvulnerabilidad = 0;
		enBote = false;
		altoJugablePuestoAnteriormente = false;
	}

	~Protagonista() {

		for (Arbol* arbol : arboles) {
			if(arbol != nullptr) delete arbol;
		}
	}

	void recalcularAltoAncho() {
		alto = spriteR.size();
		int temp = 0;
		for (int i = 0; i < alto; i++) {
			if (spriteR[i].size() > temp) temp = spriteR[i].size();
		}
		ancho = temp;
	}

	// Permite el movimiento con las flechas direccionales
	void determinarMovimiento(const std::vector<std::vector<int>>& matrizMapa) {
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			//Restricciones	
			if (!(x + ancho >= ANCHO_JUGABLE - 1) && (matrizMapa[y + 2][x + 1] == 3 || matrizMapa[y + 2][x + 1] == 4 || matrizMapa[y + 2][x + 1] == 5 || (matrizMapa[y + 2][x + 1] == 8 && enBote))) {
				dir = 'R';
				borrar(matrizMapa);
				x += velocidad;
				mostrar(matrizMapa);
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (!(x <= 1) && (matrizMapa[y + 2][x - 1] == 3 || matrizMapa[y + 2][x - 1] == 4 || matrizMapa[y + 2][x - 1] == 5 || (matrizMapa[y + 2][x - 1] == 8 && enBote))) {
				dir = 'L';
				borrar(matrizMapa);
				x -= velocidad;
				mostrar(matrizMapa);
			}
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (!(y <= 1) && (matrizMapa[y - 1 + 2][x] == 3 || matrizMapa[y - 1 + 2][x] == 4 || matrizMapa[y - 1 + 2][x] == 5 || (matrizMapa[y - 1 + 2][x] == 8 && enBote))) {
				borrar(matrizMapa);
				y--;
				mostrar(matrizMapa);
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (y + alto < altoJugablePermitido) {
				borrar(matrizMapa);
				y++;
				mostrar(matrizMapa);
			}
		}
	}

	void plantarArbol(bool teclaE, std::vector<std::vector<int>> matrizMapa) {
		if (!teclaE || semillas <= 0) return;

		if (dir == 'R' && matrizMapa[y - 1][x + ancho] == 4) {
			arboles.push_back(new Arbol("arbol", {}, float(x + ancho + 1), float(y)));
			semillas--;
		}
		else if (dir == 'L' && matrizMapa[y - 1][x - 2] == 4) {
			arboles.push_back(new Arbol("arbol", {}, float(x - 1), float(y)));
			semillas--;
		}
	}

	//Getters

	int getConfianza() { return confianza; }
	int getEvidencia() { return evidencia;}
	int getConocimientoLengua() { return conocimientoLengua;}
	std::vector<Arbol*>& getArboles() { return arboles; }
	int getSemillas() { return semillas; }
	bool getAltoJugablePuestoAnteriormente() { return altoJugablePuestoAnteriormente; }


	// Setters

	void setSemillas(int p) { semillas = p; }
	void setConfianza(int p) { confianza = p; }
	void setEvidencia(int p) { evidencia = p; }
	void setConocimientoLengua(int p) { conocimientoLengua = p; }
	void setAltoJugablePermitido(int p) { altoJugablePermitido = p; }
	void setEnBote(bool p) { enBote = p; }
	void setSprite(std::vector<std::vector<string>> p) { spriteR = spriteL = p; }
	
};