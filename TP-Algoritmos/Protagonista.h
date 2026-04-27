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

	//Getters

	int getConfianza() { return confianza; }
	int getEvidencia() { return evidencia;}
	int getConocimientoLengua() { return conocimientoLengua;}
};