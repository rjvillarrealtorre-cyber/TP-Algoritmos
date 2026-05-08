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
	Nivel(std::vector<Mapa*> nv, std::vector<Cinematica> vc = {}) {
		nivel = nv;
		vecCinem = vc;
		num = 0;
		numCinem = -1;
	}

	~Nivel() {
		for (Mapa* m : nivel) {
			delete m;
		}
	}

	void adjuntarMapas(std::vector<Mapa*> nvl) {
		nivel = nvl;
	}

	void adjuntarCinematica(std::vector<Cinematica> vc) {
		vecCinem = vc;
	}

	void setObjetivo(string obj) { objetivo = obj; }
	void setNombre(string nom) { nombre = nom; }

	Mapa* getMapaActual() { return nivel[num]; }

	void mostrarObjetivo() {
		SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), short(ALTO_JUGABLE + 1) });
		std::cout << nombre << ": ";
		SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), short(ALTO_JUGABLE + 2) });
		std::cout << objetivo;
	}

	void dibujarMapa() {
		system("cls");
		dibujarBordes();
		nivel[num]->dibujarMapa();
		mostrarObjetivo();
	}

	void observarPorCambioMapa(Protagonista& prot, bool teclaE) {
		if (teclaE && (prot.getX() >= ANCHO_JUGABLE - 6) && (num < nivel.size() - 1)) {
			num++;
			prot.setX(3);

			dibujarMapa();
			prot.mostrar(nivel[num]->getMatrizMapa());
		}
		else if (teclaE && (prot.getX() <= 6) && (num > 0)) {
			num--;
			prot.setX(ANCHO_JUGABLE - 6);

			dibujarMapa();
			prot.mostrar(nivel[num]->getMatrizMapa());
		}
	}

	void mostrarCinematica(bool esCinFinal = false) {
		if (vecCinem.empty()) return;

		if (!esCinFinal) numCinem = 0;
		else if(esCinFinal) numCinem = 1;

		if (numCinem == -1) return;

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