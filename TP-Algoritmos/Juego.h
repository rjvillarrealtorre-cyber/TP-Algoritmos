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

	void manejarMenuInicio() {
		menus[0].mostrarMenu(0);

		while (menus[0].getEnMenu()) {
			if (GetAsyncKeyState('1') & 0x0001) { // Jugar
				for (Menu& m : menus) {
					m.setEnMenu(false);
				}

				break;
			}
			else if (GetAsyncKeyState('2') & 0x0001) { // Instrucciones
				menus[0].setEnMenu(false);
				menus[1].setEnMenu(true);

				manejarSubMenu(1);

				break;
			}
			else if (GetAsyncKeyState('3') & 0x0001) { // Creditos
				menus[0].setEnMenu(false);
				menus[2].setEnMenu(true);

				manejarSubMenu(2);

				break;
			}
			else if (GetAsyncKeyState('4') & 0x0001) { // Salir
				exit(0);
			}
		}
	}

	void manejarSubMenu(int menuActual) {
		menus[menuActual].mostrarMenu(menuActual);

		while (menus[menuActual].getEnMenu()) {
			if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) {
				menus[0].setEnMenu(true);
				menus[menuActual].setEnMenu(false);

				break;
			}
		}

		manejarMenuInicio();
	}
};