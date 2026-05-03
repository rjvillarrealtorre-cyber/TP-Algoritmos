#pragma once

class Nivel {
private:
	// Atributos
	string nombre;
	int num;
	string objetivo;

	std::vector<Mapa*> nivel;
	std::vector<Cinematica> vecCinem;
	int numCinem;
public:
	Nivel(std::vector<Mapa*> nv, std::vector<Cinematica> vc) {
		nivel = nv;
		vecCinem = vc;
		num = 0;
		numCinem = -1;
	}

	Mapa* getMapaActual() { return nivel[num]; }

	void dibujarMapa() {
		system("cls");
		dibujarBordes();
		nivel[num]->dibujarMapa();
	}

	void observarPorCambioMapa(Protagonista& prot) {
		if ((GetAsyncKeyState('E') & 0x8000) && (prot.getX() >= ANCHO_JUGABLE - 6) && (num < nivel.size() - 1)) {
			num++;
			prot.setX(3);

			dibujarMapa();
			prot.mostrar(nivel[num]->getMatrizMapa());
		}
		if ((GetAsyncKeyState('E') & 0x8000) && (prot.getX() <= 6) && (num > 0)) {
			num--;
			prot.setX(ANCHO_JUGABLE - 3);

			dibujarMapa();
			prot.mostrar(nivel[num]->getMatrizMapa());
		}
	}

	void mostrarCinematica() {
		//determinar si es cinem inicial o final
		if (num == 0) numCinem = 0;
		else if (num == nivel.size() - 1) numCinem = 1;

		while (vecCinem[numCinem].getEnCinematica()) {
			if (numCinem == 0 || numCinem == 1) {
				if (!vecCinem[numCinem].getDibujadoPrimeraVez()) {
					vecCinem[numCinem].mostrarSlide();
					vecCinem[numCinem].setDibujadoPrimeraVez(true);
				}

				vecCinem[numCinem].manejarCambioSlide();
			}
		}

		if (vecCinem[numCinem].getSeDibujaraFondoMapa()) {
			system("cls");
			dibujarBordes();
			nivel[num]->dibujarMapa();
			vecCinem[numCinem].setSeDibujaraFondoMapa(false);
		}
	}
};