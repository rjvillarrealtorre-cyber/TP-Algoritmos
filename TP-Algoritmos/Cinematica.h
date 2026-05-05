#pragma once

class Slide {
private:
	std::vector<string> texto;
	short x, y;
public:
	Slide(std::vector<string> t, short px, short py) {
		texto = t;
		x = px;
		y = py;
	}

	std::vector<string> getTexto() { return texto; }
	short getX() { return x; }
	short getY() { return y; }
};

class Cinematica {
private:
	std::vector<Slide> cinematica;
	int numSlide;
	bool enCinematica;
	bool dibujadoPrimeraVez;
	bool seDibujaraFondoMapa;
public:
	Cinematica() {
		cinematica = {};
		numSlide = 0;
		enCinematica = true;
		dibujadoPrimeraVez = false;
		seDibujaraFondoMapa = false;
	}

	void agregarSlide(std::vector<string> s, short px, short py) {
		Slide nuevaSlide(s, px, py);
		cinematica.push_back(nuevaSlide);
	}

	void mostrarSlide() {
		system("cls");
		dibujarBordesExterno();

		for (int i = 0; i < cinematica[numSlide].getTexto().size(); i++) {
			SetConsoleCursorPosition(hConsole, { cinematica[numSlide].getX(), static_cast<short>(cinematica[numSlide].getY() + i)});
			std::cout << cinematica[numSlide].getTexto()[i];
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