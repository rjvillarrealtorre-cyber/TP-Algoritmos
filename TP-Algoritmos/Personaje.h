#pragma once

class Personaje {
protected:
	string nombre;
	std::vector<std::vector<string>> spriteR;
	std::vector<std::vector<string>> spriteL;
	char dir;
	int vida;
	float x, y;
	int velocidad;
public:
	Personaje(string n, std::vector<std::vector<string>> sr, std::vector<std::vector<string>> sl,  char d, int v, float px, float py, int vlc) {
		nombre = n;
		spriteR = sr;
		spriteL = sl;
		dir = d;
		vida = v;
		x = px;
		y = py;
		velocidad = vlc;
	}

	std::vector<std::vector<string>> direccionSprite() {
		if (dir == 'R') return spriteR;
		else return spriteL;
	}

	void borrar() {
		for (int i = 0; i < direccionSprite().size(); i++) {
			for (int j = 0; j < direccionSprite()[i].size(); j++) {
				SetConsoleCursorPosition(hConsole, { static_cast<short>(x + j), static_cast<short>(y + i) });
				std::cout << " ";
			}
		}
	}

	void avanzar() {
		for (int i = 0; i < direccionSprite().size(); i++) {
			for (int j = 0; j < direccionSprite()[i].size(); j++) {
				SetConsoleCursorPosition(hConsole, { static_cast<short>(x + j), static_cast<short>(y + i) });
				std::cout << direccionSprite()[i][j];
			}
		}
	}

	void mover() {
		borrar();

		if (dir == 'R') x++;
		else x--;

		avanzar();
	}
};