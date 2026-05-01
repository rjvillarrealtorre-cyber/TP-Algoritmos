#pragma once
#include <cstdlib>

#include "Personaje.h"
#include "Protagonista.h"
#include "ArbolDialogo.h"

class AliadoEstatico : public Personaje {
private:
	ArbolDialogo arbol;
	bool enInteraccion;
public:
	AliadoEstatico(string n, std::vector<std::vector<string>> sr, float px, float py, ArbolDialogo dl) : Personaje(n, sr, px, py) {
		arbol = dl;
		enInteraccion = false;
	}

	bool determinarCercania(Protagonista& prot) {
		if ((std::abs(prot.getX() - x) <= 6) && (std::abs(prot.getY() - y) <= 3)) 
			return true;
		return false;
	}

	void manejarInteraccion(Protagonista& prot) {
		if ((GetAsyncKeyState('E') & 0x0001) && determinarCercania(prot) && !enInteraccion) {
			enInteraccion = true;
		}
		
		if (!determinarCercania(prot) && enInteraccion) {
			enInteraccion = false;
			arbol.borrarCajaDialogo();
		}

		if(enInteraccion) arbol.manejarFlujoInteraccion(0, prot);
	}
};