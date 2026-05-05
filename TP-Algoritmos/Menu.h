#pragma once

class Menu {
private:
	std::vector<string> titulo;
	std::vector<string> opciones;
	std::vector<std::vector<int>> matrizFondo;
	bool enMenu;
public:
	Menu(std::vector<string> t, std::vector<string> op, std::vector<std::vector<int>> mf, bool em) {
		titulo = t;
		opciones = op;
		matrizFondo = mf;
		enMenu = em;
	}

	void mostrarMenu(int tipo) {
		system("cls");
		dibujarBordesExterno();
		dibujarMapa(matrizFondo);

		//Por limitaciones t�cnicas, string.length devuelve en BYTES, as� que no se puede
		//utilizarlo para hallar la cantidad que se deber�a poner para que sea centrado.
		//Y no se puede utilizar polimorfismo pues ser�a el triple de trabajo.
		short altoTitulo, anchoTitulo;
		short altoOpciones, anchoOpciones;
		switch (tipo) {
		case 0: {
			anchoTitulo = 23;
			altoTitulo = 6;
			anchoOpciones = 48;
			altoOpciones = 16;

			break;
		}

		case 1: {
			anchoTitulo = 33;
			altoTitulo = 3;
			anchoOpciones = 23;
			altoOpciones = 13;

			break;
		}

		case 2: {
			anchoTitulo = 49;
			altoTitulo = 3;
			anchoOpciones = 37;
			altoOpciones = 11;

			break;
		}
		}

		for (int i = 0; i < titulo.size(); i++) {
			SetConsoleCursorPosition(hConsole, { anchoTitulo, static_cast<short>(altoTitulo + i) });
			SetConsoleTextAttribute(hConsole, (1 << 4 | 15));
			std::cout << titulo[i];
			SetConsoleTextAttribute(hConsole, 0x7);
		}

		for (int i = 0; i < opciones.size(); i++) {
			SetConsoleCursorPosition(hConsole, { anchoOpciones, static_cast<short>(altoOpciones + i) });
			SetConsoleTextAttribute(hConsole, (1 << 4 | 15));
			std::cout << opciones[i];
			SetConsoleTextAttribute(hConsole, 0x7);
		}
	}

	void setEnMenu(bool p) { enMenu = p; }
	bool getEnMenu() { return enMenu; }
};