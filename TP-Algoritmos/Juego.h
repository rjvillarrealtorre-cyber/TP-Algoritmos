#pragma once

// En cristiano: Un "juego" maneja y une los niveles con los menus
class Juego {
private:
	std::vector<Nivel> niveles;
	std::vector<Menu> menus;
	int nivelActual;
public:
	Juego(std::vector<Nivel> n, std::vector<Menu> m = {}) {
		niveles = n;
		menus = m;
		nivelActual = 0;
	}

	void manejarCambioNivel(int nuevoNivel) {
		niveles[nuevoNivel].mostrarCinematica();
		system("cls");
		dibujarBordes();
		niveles[nuevoNivel].dibujarMapa();
	}
};