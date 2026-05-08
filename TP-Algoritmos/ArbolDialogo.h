#pragma once
#include "Protagonista.h"

// OPCIONES: Da la posibilidad al jugador de elegir cómo responder
// a ciertas interacciones. Por lo general, estas elecciones
// tienen consecuencias en la confianza, lengua o evidencia,
// y dan lugar a distintas respuestas.
// Es aquí donde se añade un elemento interactivo y rejugabilidad
// al juego, pues cada decisión influye en el gameplay.
// Y también aquí es cómo se entiende el concept de "árbol de diálogo"
// pues cada opción tiene varios "nodos" o "ramas" como posibles
// consecuencias.
struct Opcion {
	string texto;
	std::vector<int> efectos; // {confianza, lengua, evidencia}
	int siguienteDialogo;
	int confianzaReq = 0;
	int lenguaReq = 0;
	bool acabaNivel = false;
};

// Diálogo: Lo que se muestra en la caja de diálogo. Un ejemplo de diálogo sería:
// WILMER: ¿Qué es lo que buscas, periodista? <- Linea
// 1. Quiero conocer la verdad     \
// 2. Hacer mi trabajo e irme      |> Opciones
// 3. No tengo por qué responderte /
// Si existen opciones, "poderElegir" es "true", y la elección (1, 2 o 3),
// es almacenada en int eleccion
class Dialogo {
private:
	std::vector<string> lineas;

	bool poderElegir;
	int eleccion;
	std::vector<Opcion> opciones;

	int sigDialogo;
	bool yaMostrado;
	bool estaEnEspanol;

	int randNum;
public:
	Dialogo(std::vector<string> l, int sd = -1, bool eee = true) { //Constructor si no se puede elegir
		lineas = l;
		poderElegir = false;
		eleccion = -1; // -1: aún no se eligió nada / elección inválida
		sigDialogo = sd;
		estaEnEspanol = eee;
		yaMostrado = false;
		randNum = std::rand() % 101;
	}

	Dialogo(std::vector<string> l, std::vector<Opcion> opc, bool eee = true) { // Constructor si se puede elegir
		lineas = l;
		poderElegir = true;
		opciones = opc;
		eleccion = -1;
		sigDialogo = -1;
		estaEnEspanol = eee;
		yaMostrado = false;
		randNum = std::rand() % 101;
	}

	void mostrarLineas(int numConLengua) { //Imprime el diálogo en la pantalla
		if (yaMostrado) return;
		yaMostrado = true;

		short centrar = (ANCHO_JUGABLE - lineas[0].size()) / 2;

		for (int i = 0; i < lineas.size(); i++) {
			if (!estaEnEspanol && (lineas[i][0] != '[' && lineas[i][0] != '|')) {
				for (int j = 0; j < lineas[i].size(); j++) {
					SetConsoleCursorPosition(hConsole, { short(centrar + 1 + j), static_cast<short>(ALTO_JUGABLE + 1 + i) });
			
					if (lineas[i][j] == ' ' || lineas[i][j] == ',' || lineas[i][j] == '.' || (lineas[i][j] >= 65 && lineas[i][j] <= 90) || lineas[i][j] == ':') {
						std::cout << lineas[i][j];
					}
					else if (randNum <= numConLengua) {
						std::cout << lineas[i][j];
					}
					else {
						std::cout << "?";
					}
				}
			}
			else {
				SetConsoleCursorPosition(hConsole, { short(centrar + 1), static_cast<short>(ALTO_JUGABLE + 1 + i) });
				std::cout << lineas[i];
			}
		}

		for (int i = 0; i < opciones.size(); i++) {
			SetConsoleCursorPosition(hConsole, { short(centrar + 1), static_cast<short>(ALTO_JUGABLE + 1 + lineas.size() + i) });
			std::cout << (i + 1) << ": " << opciones[i].texto;
		}
	}

	//elegir: Maneja la lógica de la elección
	void elegir(Protagonista& prot) {
		// Ve si el jugador ha presionado ciertos botones
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
		if (prot.getConfianza() < op.confianzaReq || prot.getConocimientoLengua() < op.lenguaReq) {
			eleccion = -1;
			return;
		}

		//Llamando a determinarConsecuencia...
		if (eleccion != -1) determinarConsecuencia(prot, op);
	}

	void determinarConsecuencia(Protagonista& prot, Opcion& op) {
		if (!poderElegir || eleccion == -1) return;

		prot.setConfianza(prot.getConfianza() + op.efectos[0]);
		prot.setConocimientoLengua(prot.getConocimientoLengua() + op.efectos[1]);
		prot.setEvidencia(prot.getEvidencia() + op.efectos[2]);
	}

	// Para "borrar el caché" y que el sistema se restaure con cada nueva elección
	void resetEleccion() { eleccion = -1; }

	//Setters y getters

	int getEleccion() { return eleccion; }
	bool getPoderElegir() { return poderElegir; }
	int getSiguienteDialogo() { return sigDialogo; }

	void setYaMostrad(bool p) { yaMostrado = p; }
	
	Opcion& getOpcionElegida() {
		return opciones[eleccion - 1];
	}
};

// Interacción: Es un conjunto de DIÁLOGOS
// Ejemplo de interacción (simplificada)
// Frame 1: ¿Qué es lo que quieres, periodista?
// Frame 2: (Varía según la respuesta) ¿La verdad, eh? Eso es nuevo...
// Frame 3: He de admitir que me has sorprendido...
// ---
// Árbol de diálogos. Cada personaje (aliado o enemigo) tiene uno.
// Representa todas las posibles interacciones que el protagonista
// puede tener con cada uno de ellos.
// De forma técnica: es un conjunto de INTERACCIONES.
// Por ejemplo, la primera interacción con Wilmer ocurre cuando
// el protagonista llega a la aldea; la segunda interacción
// con el mismo personaje ocurre al finalizar la misión.
class ArbolDialogo {
private:
	std::vector < std::vector<Dialogo> > arbol; // -> Conjunto de interacciones
	// Una interacción sería: std::vector<Dialogo> interaccion;
	int numDialogo;
public:
	ArbolDialogo(std::vector < std::vector<Dialogo> > a = {}) {
		numDialogo = 0;
		arbol = a;
	}

	// Para el setup...
	void agregarDialogo(Dialogo d, int numInteraccion) {
		if (arbol.empty()) {
			std::vector<Dialogo> interaccion;
			arbol.push_back(interaccion);
		}

		arbol[numInteraccion].push_back(d);
	}

	void agregarInteraccionVacia() {
		std::vector<Dialogo> interaccion;
		arbol.push_back(interaccion);
	}

	// Borra la caja de diálogo
	void borrarCajaDialogo() {
		for (int i = 0; i < ALTO_DIAL - 1; i++) {
			for (int j = 0; j < ANCHO_JUGABLE - 3; j++) {
				SetConsoleCursorPosition(hConsole, { static_cast<short>(2 + j), static_cast<short>(ALTO_JUGABLE + i)});
				std::cout << " ";
			}
		}
	}

	// Imprime la interacción en la panatalla
	void mostrarInteraccion(int numInteraccion, int numConLengua) {
		if (numDialogo >= arbol[numInteraccion].size() || numDialogo < 0) return;

		arbol[numInteraccion][numDialogo].mostrarLineas(numConLengua);
	}

	// Función más importante. Se encarga del funcionamiento
	// de cada interacción.
	bool manejarFlujoInteraccion(bool teclaE, int numInteraccion, Protagonista& prot) {
		Dialogo& d = arbol[numInteraccion][numDialogo];

		mostrarInteraccion(numInteraccion, prot.getConocimientoLengua());

		// Caso sin elección (avanza con E)
		if (!d.getPoderElegir() && teclaE) {
			borrarCajaDialogo();
			d.setYaMostrad(false);

			if (d.getSiguienteDialogo() != -1)
				numDialogo = d.getSiguienteDialogo();
			else
				numDialogo++;

			if (numDialogo >= arbol[numInteraccion].size())
				numDialogo = 0;
		}
		// Caso con opciones
		else if (d.getPoderElegir()) {
			d.elegir(prot);

			if (d.getEleccion() == -1) return false;

			Opcion& op = d.getOpcionElegida();

			d.resetEleccion();

			if (op.acabaNivel) return true;

			d.setYaMostrad(false);
			borrarCajaDialogo();

			// cambiar al siguiente nodo según opción
			numDialogo = op.siguienteDialogo;

			if (numDialogo >= arbol[numInteraccion].size()) numDialogo = 0;
		}
		return false;
	}

	void resetDialogo() {
		for (auto& interaccion : arbol) {
			for (auto& dialogo : interaccion) {
				dialogo.setYaMostrad(false);
			}
		}
	}

};