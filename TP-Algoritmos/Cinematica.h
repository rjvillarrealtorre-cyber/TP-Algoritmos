#pragma once

class Cinematica {
private:
	std::vector<string> slide;
	std::vector<std::vector<string>> cinematica;
	int numSlide;
	bool enCinematica;
	bool dibujadoPrimeraVez;
	bool seDibujaraFondoMapa;
public:
	Cinematica(std::vector<std::vector<string>> c = {}) {
		cinematica = c;
		numSlide = 0;
		enCinematica = true;
		dibujadoPrimeraVez = false;
		seDibujaraFondoMapa = false;
	}

	void agregarSlide(std::vector<string> s) {
		cinematica.push_back(s);
	}


	void dibujarBordesCinematica() {
		for (int i = 0; i < ALTO_DIAL + ALTO_JUGABLE; i++) {
			for (int j = 0; j < ANCHO_ESTAD + ANCHO_JUGABLE; j++) {
				if (i == 0 || i == ALTO_DIAL + ALTO_JUGABLE - 1 || j == 0 || j == ANCHO_ESTAD + ANCHO_JUGABLE - 1) std::cout << u8"■";
				else std::cout << " ";
			}
			std::cout << "\n";
		}
	}

	void mostrarSlide() {
		system("cls");
		dibujarBordesCinematica();

		for (int i = 0; i < cinematica[numSlide].size(); i++) {
			SetConsoleCursorPosition(hConsole, { 3, static_cast<short>(2 + i) });
			std::cout << cinematica[numSlide][i];
		}
	}

	void manejarCambioSlide() {
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001) {
			if (numSlide >= cinematica.size() - 1) {
				enCinematica = false;
				seDibujaraFondoMapa = true;
			}
			else {
				numSlide++;
				mostrarSlide();
			}
		}
		else if ((GetAsyncKeyState(VK_LEFT) & 0x0001) && (numSlide > 0)) {
			numSlide--;
			mostrarSlide();
		}
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) {
			enCinematica = false;
			seDibujaraFondoMapa = true;
		}
	}

	bool getEnCinematica() { return enCinematica; }

	bool getSeDibujaraFondoMapa() { return seDibujaraFondoMapa; }
	void setSeDibujaraFondoMapa(bool p) { seDibujaraFondoMapa = p; }

	bool getDibujadoPrimeraVez() { return dibujadoPrimeraVez; }
	void setDibujadoPrimeraVez(bool p) { dibujadoPrimeraVez = p; }
};