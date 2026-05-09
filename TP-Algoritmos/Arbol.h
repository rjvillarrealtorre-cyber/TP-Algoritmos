#pragma once
#include <cmath>

class Arbol : public Personaje {
private:
	bool vivo;
	bool germinando;
	bool siendoSaboteado;
	int contadorGerminar;
	int contadorSabotear;
	float velocidadSabotaje;

	int contFramesGerminar;
	float contFramesSabotear;

	int multiplicadorSabotaje; // # enemigos en el árbol
public:
	Arbol(string n = "", std::vector<std::vector<string>> sr = {}, float px = 1, float py = 1) : Personaje(n, sr, px, py) {
		spriteR = {
			{",",},
			{"j",},
		};
		spriteL = spriteR;

		alto = spriteR.size();
		int temp = 0;
		for (int i = 0; i < alto; i++) {
			if (spriteR[i].size() > temp) temp = spriteR[i].size();
		}
		ancho = temp;

		x = px;
		y = py;

		vivo = true;
		germinando = true;
		siendoSaboteado = false;
		contadorGerminar = 0;
		contadorSabotear = 0;
		contFramesGerminar = 0;
		contFramesSabotear = 0;
		multiplicadorSabotaje = 0;
	}

	void manejarVida() {
		if (contadorSabotear >= 10 && germinando) {
			vivo = false;
			germinando = false;
			siendoSaboteado = false;

			spriteR = {
				{"x", "'", "x"},
			};
			spriteL = spriteR;
		}
	}

	void manejarContadores() {
		if (!vivo) return;
		if (!germinando) return;

		if (siendoSaboteado) contFramesSabotear += velocidadSabotaje;
		contFramesGerminar++;

		contadorGerminar = contFramesGerminar / (1000 / TIEMPO_SLEEP);
		if(siendoSaboteado) contadorSabotear = contFramesSabotear / (1000 / TIEMPO_SLEEP);
	}

	void mostrarContadores() {
		if (!vivo) return;
		if (!germinando) return;

		SetConsoleCursorPosition(hConsole, { short(x + ceil(ancho/2) - 2), short(y + alto)});
		std::cout << "G: " << contadorGerminar;

		SetConsoleCursorPosition(hConsole, { short(x + ceil(ancho / 2) - 2), short(y - 1) });
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "S: " << contadorSabotear;
		SetConsoleTextAttribute(hConsole, 0x7);
	}

	void cambiarSprites(std::vector<std::vector<int>> matrizMapa) {
		if (!vivo) return;
		if (!germinando) return;

		if (contadorGerminar >= 5 && contadorGerminar < 10) {
			spriteR = {
				{"c", "|", u8"ɔ"},
				{"_", "|", "_"},
			};
			spriteL = spriteR;
			borrar(matrizMapa);
		}
		else if (contadorGerminar >= 20) {
			germinando = false;
			spriteR = {
			{ " ", " ", u8"∧", " ", " " },
			{ " ", "/", " ",  "\\", " " },
			{ "/", "_", "_",  "_", "\\" },
			{ " ", " ", "|",  " ", " " },
			};
			spriteL = spriteR;
			borrar(matrizMapa);
		}
	}

	void manejarCrecimiento(std::vector<std::vector<int>> matrizMapa) {
		if (!vivo) return;

		multiplicadorSabotaje = 0;

		manejarVida();
		manejarContadores();
		mostrarContadores();
		cambiarSprites(matrizMapa);

		velocidadSabotaje = 1;
	}

	bool getEstaVivo() { return vivo; }
	bool getEstaGerminando() { return germinando; }
	void setSiendoSabotead(bool p) { siendoSaboteado = p; }
	bool getSiendoSaboteado() { return siendoSaboteado; }

	int getContFramesSabotear() { return contFramesSabotear; }
	void setContFramesSabotear(int p) { contFramesSabotear = p; }

	void setVelocidadSabotaje(float p) { velocidadSabotaje = p; }
	int getMultiplicadorSabotaje() { return multiplicadorSabotaje; }
	void setMultiplicadorSabotaje(int p) { multiplicadorSabotaje = p; }

	void anadirMultiplicador() { multiplicadorSabotaje++; }
};