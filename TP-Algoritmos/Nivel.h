#pragma once

class Nivel {
private:
	// Atributos
	string nombre;
	int num;
	string objetivo;

	std::vector<Mapa> nivel;

public:
	Nivel(std::vector<Mapa> nv) {
		nivel = nv;
		num = 0;
	}

	Mapa& getMapaActual() { return nivel[num]; }

	void dibujarMapa() {
		system("cls");
		dibujarBordes();
		nivel[num].dibujarMapa();
	}

	void observarPorCambioMapa(Protagonista& prot) {
		if ((GetAsyncKeyState('E') & 0x8000) && (prot.getX() >= ANCHO_JUGABLE - 6) && (num < nivel.size())) {
			num++;
			prot.setX(3);

			dibujarMapa();
		}
		if ((GetAsyncKeyState('E') & 0x8000) && (prot.getX() <= 6) && (num > 0)) {
			num--;
			prot.setX(ANCHO_JUGABLE - 3);

			dibujarMapa();
		}
	}
};