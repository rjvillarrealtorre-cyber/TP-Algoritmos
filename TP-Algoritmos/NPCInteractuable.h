#pragma once
#include <cstdlib>

#include "Personaje.h"
#include "Protagonista.h"
#include "ArbolDialogo.h"

class NPCInteractuable : public Personaje {
private:
	ArbolDialogo arbol;
	bool enInteraccion;
public:
	NPCInteractuable(string n, std::vector<std::vector<string>> sr, float px, float py, ArbolDialogo dl) : Personaje(n, sr, px, py) {
		arbol = dl;
		enInteraccion = false;
	}

	NPCInteractuable(string n, std::vector<std::vector<string>> sr, float px, float py) : Personaje(n, sr, px, py) {
		enInteraccion = false;
	}

	bool determinarCercania(Protagonista& prot) {
		if ((std::abs(prot.getX() - x) <= 6) && (std::abs(prot.getY() - y) <= 3)) 
			return true;
		return false;
	}

	bool manejarInteraccion(Protagonista& prot, bool teclaE) {
		if (teclaE && determinarCercania(prot) && !enInteraccion) {
			enInteraccion = true;
		}
		
		if (!determinarCercania(prot) && enInteraccion) {
			enInteraccion = false;

			arbol.resetDialogo();

			arbol.borrarCajaDialogo();
		}

		if(enInteraccion) return arbol.manejarFlujoInteraccion(teclaE, 0, prot);

		return false;
	}
};