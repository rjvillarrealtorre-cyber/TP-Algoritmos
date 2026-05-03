#pragma once

class Mapa {
private:
	string nombre;
	int num;

	std::vector<std::vector<int>> matrizMapa;
	std::vector<AliadoEstatico> vecAliEst;
	std::vector<Enemigo*> vecEnemigo; // Aplicaremos polimorfismo
	std::vector<AliadoDinamico> vecAliDinam;

public:
	Mapa(std::vector<std::vector<int>> mm, std::vector<AliadoEstatico> vae = {}, std::vector<AliadoDinamico> vad = {}, std::vector<Enemigo*> ve = {}) {
		matrizMapa = mm;
		vecAliEst = vae;
		vecAliDinam = vad;
		vecEnemigo = ve;
	}

	~Mapa() {
		for (Enemigo* enemigo : vecEnemigo) {
			delete enemigo;
		}
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

	std::vector<std::vector<int>>& getMatrizMapa() { return matrizMapa; }

	std::vector<AliadoEstatico>& getVecAliEst() { return vecAliEst; }

	std::vector<AliadoDinamico>& getVecAliDinam() { return vecAliDinam; }

	std::vector<Enemigo*>& getVecEnemigo() { return vecEnemigo; }
};