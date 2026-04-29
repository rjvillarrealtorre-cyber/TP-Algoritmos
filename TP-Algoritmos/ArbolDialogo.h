#pragma once
#include "Protagonista.h"

struct Opcion {
	string texto;
	std::vector<int> efectos; // {confianza, lengua, evidencia}
	int siguienteDialogo;
	int confianzaReq = 0;
	int lenguaReq = 0;
};

class Dialogo {
private:
	std::vector<string> lineas;

	bool poderElegir;
	int eleccion;
	std::vector<Opcion> opciones;
public:
	Dialogo(std::vector<string> l) {
		lineas = l;
		poderElegir = false;
		eleccion = -1;
	}

	Dialogo(std::vector<string> l, std::vector<Opcion> opc) {
		lineas = l;
		poderElegir = true;
		opciones = opc;
		eleccion = -1;
	}

	void mostrarLineas() {
		for (int i = 0; i < lineas.size(); i++) {
			SetConsoleCursorPosition(hConsole, { 2, static_cast<short>(ALTO_JUGABLE + 1 + i) });
			std::cout << lineas[i];
		}

		for (int i = 0; i < opciones.size(); i++) {
			SetConsoleCursorPosition(hConsole, { 2, static_cast<short>(ALTO_JUGABLE + 1 + lineas.size() + i) });
			std::cout << (i + 1) << ": " << opciones[i].texto;
		}
	}

	void elegir(Protagonista& prot) {
		if (GetAsyncKeyState('1') & 0x0001) eleccion = 1;
		else if (GetAsyncKeyState('2') & 0x0001) eleccion = 2;
		else if (GetAsyncKeyState('3') & 0x0001) eleccion = 3;
		else if (GetAsyncKeyState('4') & 0x0001) eleccion = 4;

		//Comprobación...
		//Si la elección es mayor que las opciones disponibles: elección inválida
		if (eleccion > opciones.size()) {
			eleccion = -1;
			return;
		}

		Opcion& op = opciones[eleccion - 1];

		//Si no se logran los requerimientos necesarios...
		if (prot.getConfianza() < op.confianzaReq) return;
		if (prot.getConocimientoLengua() < op.lenguaReq) return;

		//Llamando a determinarConsecuencia...
		if (eleccion != -1) determinarConsecuencia(prot, op);
	}

	void determinarConsecuencia(Protagonista& prot, Opcion& op) {
		if (!poderElegir || eleccion == -1) return;

		prot.setConfianza(prot.getConfianza() + op.efectos[0]);
		prot.setConocimientoLengua(prot.getConocimientoLengua() + op.efectos[1]);
		prot.setEvidencia(prot.getEvidencia() + op.efectos[2]);
	}

	void resetEleccion() { eleccion = -1; }

	//Setters y getters

	int getEleccion() { return eleccion; }
	bool getPoderElegir() { return poderElegir; }
	
	Opcion& getOpcionElegida() {
		return opciones[eleccion - 1];
	}
};

class ArbolDialogo {
private:
	std::vector < std::vector<Dialogo> > arbol;
	int numDialogo;
public:
	ArbolDialogo() {
		numDialogo = 0;
	}

	void agregarDialogo(Dialogo d, int numInteraccion) {
		arbol[numInteraccion].push_back(d);
	}

	void agregarInteraccionVacia() {
		std::vector<Dialogo> interaccion;
		arbol.push_back(interaccion);
	}

	void borrarCajaDialogo() {
		for (int i = 0; i < ALTO_DIAL - 1; i++) {
			for (int j = 0; j < ANCHO_JUGABLE - 3; j++) {
				SetConsoleCursorPosition(hConsole, { static_cast<short>(2 + j), static_cast<short>(ALTO_JUGABLE + i)});
				std::cout << " ";
			}
		}
	}

	void mostrarInteraccion(int numInteraccion) {
		if (numDialogo >= arbol[numInteraccion].size() || numDialogo < 0) return;

		arbol[numInteraccion][numDialogo].mostrarLineas();
	}

	void manejarFlujoInteraccion(int numInteraccion, Protagonista& prot) {
		Dialogo& d = arbol[numInteraccion][numDialogo];

		// Caso sin elección (avanza con E)
		if (!d.getPoderElegir() && (GetAsyncKeyState('E') & 0x0001)) {
			borrarCajaDialogo();
			numDialogo++;

			if (numDialogo >= arbol[numInteraccion].size()) numDialogo = 0;
		}
		// Caso con opciones
		else if (d.getPoderElegir()) {
			d.elegir(prot);

			if (d.getEleccion() == -1) return;

			Opcion& op = d.getOpcionElegida();

			borrarCajaDialogo();

			// cambiar al siguiente nodo según opción
			numDialogo = op.siguienteDialogo;

			if (numDialogo >= arbol[numInteraccion].size()) numDialogo = 0;

			d.resetEleccion();
		}
	}
};