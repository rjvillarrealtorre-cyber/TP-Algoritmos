#pragma once

class Mapa {
private:
	string nombre;
	int num;

	ManejoObstaculos controlObstaculos;
	std::vector<std::vector<int>> matrizMapa;
	std::vector<NPCInteractuable> vecNPCInt;
	std::vector<Enemigo*> vecEnemigo; // Aplicaremos polimorfismo
	std::vector<EnemigoBote*> vecEnemBote;
	std::vector<AliadoDinamico> vecAliDinam;

	int contFramesMapa;
	bool enemigoAnadido;
public:
	Mapa(std::vector<std::vector<int>> mm = {}, std::vector<NPCInteractuable> vae = {}, std::vector<AliadoDinamico> vad = {}, std::vector<Enemigo*> ve = {}) {
		matrizMapa = mm;
		vecNPCInt = vae;
		vecAliDinam = vad;
		vecEnemigo = ve;

		contFramesMapa = 0;
		enemigoAnadido = false;
	}

	~Mapa() {
		for (Enemigo* enemigo : vecEnemigo) {
			if(enemigo != nullptr) delete enemigo;
		}

		for (EnemigoBote* en : vecEnemBote) {
			if (en != nullptr) delete en;
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

	void anadirEnemigosNivel2(int nivelActual) {
		// if (nivelActual != 1) return;
		if (enemigoAnadido) return;

		int segTranscurridos = ((contFramesMapa * TIEMPO_SLEEP) / 1000) % 60;

		if (segTranscurridos == 30) {
			enemigoAnadido = true;
			vecEnemigo.push_back(new EnemigoSaboteador(20, 14));
		}
	}

	//Setters y getters

	std::vector<std::vector<int>>& getMatrizMapa() { return matrizMapa; }
	std::vector<NPCInteractuable>& getVecNPCInt() { return vecNPCInt; }
	std::vector<AliadoDinamico>& getVecAliDinam() { return vecAliDinam; }
	std::vector<Enemigo*>& getVecEnemigo() { return vecEnemigo; }
	std::vector<EnemigoBote*> getVecEnemBote() { return vecEnemBote; }
	ManejoObstaculos& getManejoObstaculos() { return controlObstaculos; }
	int getContFrames() { return contFramesMapa; }

	void setMatrizMapa(std::vector<std::vector<int>> mm) { matrizMapa = mm;}
	void setVecNPCInt(std::vector<NPCInteractuable> p) { vecNPCInt = p; }
	void setVecEnemigos(std::vector<Enemigo*>& e) { vecEnemigo = e; }
	void setVecEnemBote(std::vector<EnemigoBote*> e) { vecEnemBote = e; }
	void setVecAliDin(std::vector<AliadoDinamico> ad) { vecAliDinam = ad; }
	void setManejoObstacull(ManejoObstaculos p) { controlObstaculos = p; }

	void anadirContadorFrames() { contFramesMapa++; }
};