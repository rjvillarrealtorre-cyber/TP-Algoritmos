#pragma once

class Menu {
private:
	std::vector<string> titulo;
	std::vector<string> opciones;
	std::vector<std::vector<int>> matrizFondo;
	bool enMenu;
public:
	Menu(std::vector<string> t, std::vector<string> op, std::vector<std::vector<int>> mf) {
		titulo = t;
		opciones = op;
		matrizFondo = mf;
		enMenu = true;
	}

	void mostrarMenu() {
		system("cls");
		dibujarBordesExterno();
		dibujarMapa(matrizFondo);

		for (int i = 0; i < titulo.size(); i++) {
			SetConsoleCursorPosition(hConsole, { 23, static_cast<short>(6 + i) });
			SetConsoleTextAttribute(hConsole, (1 << 4 | 15));
			std::cout << titulo[i];
			SetConsoleTextAttribute(hConsole, 0x7);
		}

		for (int i = 0; i < opciones.size(); i++) {
			SetConsoleCursorPosition(hConsole, { 48, static_cast<short>(16 + i) });
			SetConsoleTextAttribute(hConsole, (1 << 4 | 15));
			std::cout << opciones[i];
			SetConsoleTextAttribute(hConsole, 0x7);
		}
	}

	void manejarOpciones() {
		while (enMenu) {
			if (GetAsyncKeyState('1') & 0x0001) {
				enMenu = false;
				break;
			}
			else if (GetAsyncKeyState('2') & 0x0001) {
				enMenu = false;
				break;
			}
			else if (GetAsyncKeyState('3') & 0x0001) {
				enMenu = false;
				break;
			}
			else if (GetAsyncKeyState('4') & 0x0001) {
				exit(0);
			}
		}
	}
};