#pragma once

class Mapa {
private:
	std::vector<std::vector<int>> matrizMapa;
	std::vector<AliadoEstatico> vecAliEst;
	// std::vector<Enemigo> vecEnemigo;
	// std::vector<AliadoDinamico> vecAliDinam;

public:
	Mapa(std::vector<std::vector<int>> mm, std::vector<AliadoEstatico> vae) {
		matrizMapa = mm;
		vecAliEst = vae;
	}

	void dibujarMapa() {
		for (int i = 0; i < matrizMapa.size(); i++) {
			for (int j = 0; j < matrizMapa[i].size(); j++) {
				SetConsoleCursorPosition(hConsole, { static_cast<short>(j + 1), static_cast<short>(i + 1) });
				SetConsoleTextAttribute(hConsole, leerColor(matrizMapa[i][j]));
				std::cout << " ";

				SetConsoleTextAttribute(hConsole, 0x7);
			}
		}
	}

	//Setters y getters

	std::vector<std::vector<int>> getMatrizMapa() { return matrizMapa; }
};