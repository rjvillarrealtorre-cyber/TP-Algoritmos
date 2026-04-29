#pragma once

// CLASE PERSONAJE: Clase padre de todas las entidades de tipo "personaje"
// como el jugador, los aliados y los enemigos.
// Jugador: Es el protagonista. Es controlado por el usuario.
// Aliados: Puede ser un NPC (se puede interactuar con él, pero no se mueve
// en el mapa) o un aliado propiamente dicho (se mueve en el mapa y tiene
// atributos similares al jugador, como vida o velocidad)
// Enemigos: Atacan al jugador o a sus aliados

class Personaje {
protected:
	string nombre;
	std::vector<std::vector<string>> spriteR;
	std::vector<std::vector<string>> spriteL;
	char dir;
	int vida;
	float x, y;
	int velocidad;
	int alto, ancho;
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

		alto = spriteR.size();
		int temp = 0;
		for (int i = 0; i < alto; i++) {
			if (spriteR[i].size() > temp) temp = spriteR[i].size();
		}
		ancho = temp;
	}

	Personaje(string n, std::vector<std::vector<string>> sr, float px, float py) {
		nombre = n;
		spriteR = spriteL = sr;
		x = px;
		y = py;

		alto = spriteR.size();
		int temp = 0;
		for (int i = 0; i < alto; i++) {
			if (spriteR[i].size() > temp) temp = spriteR[i].size();
		}
		ancho = temp;
	}

	std::vector<std::vector<string>>& direccionSprite() {
		if (dir == 'R') return spriteR;
		else return spriteL;
	}

	void borrar() {
		int anchoMax = 0;
		for (auto& fila : direccionSprite()) {
			if (fila.size() > anchoMax) anchoMax = fila.size();
		}

		for (int i = 0; i < direccionSprite().size(); i++) {
			for (int j = 0; j < anchoMax; j++) {
				SetConsoleCursorPosition(hConsole, { static_cast<short>(x + j), static_cast<short>(y + i) });
				std::cout << " ";
			}
		}
	}

	void mostrar() {
		for (int i = 0; i < direccionSprite().size(); i++) {
			for (int j = 0; j < direccionSprite()[i].size(); j++) {
				SetConsoleCursorPosition(hConsole, { static_cast<short>(x + j), static_cast<short>(y + i) });
				std::cout << direccionSprite()[i][j];
			}
		}
	}

	string getNombre() { return nombre; }
	int getVida() { return vida; }
};