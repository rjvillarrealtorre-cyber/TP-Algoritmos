#pragma once

class Obstaculo : public Personaje {
private:

public:
    Obstaculo(float px, float py) : Personaje("", {}, {}, 'R', 100, px, py, 1) {
		x = px;
		y = py;

		spriteR = {
			{"(", "=", "=", "=", "=", "=", ")"},
		};
		spriteL = spriteR;

		alto = spriteR.size();
		int temp = 0;
		for (int i = 0; i < alto; i++) {
			if (spriteR[i].size() > temp) temp = spriteR[i].size();
		}
		ancho = temp;
    }
};


class ManejoObstaculos {
private:
	std::vector<Obstaculo*> obstaculos;
	int segundosEntreAparicion;
	int countFramesAparicion;
	int contFramesTotal;
public:
	ManejoObstaculos() {
		segundosEntreAparicion = 5;
		countFramesAparicion = 0;
		contFramesTotal = 0;
	}

	~ManejoObstaculos() {
		for (Obstaculo* o : obstaculos) delete o;
	}

	void agregarObstaculo() {
		int veces = 1;

		if (veces >= 10 && contFramesTotal < 20) veces = 2;
		else if (veces >= 20 && contFramesTotal < 30) veces = 3;
		else if (veces >= 40 && contFramesTotal < 60) veces = 4;

		for (int i = 0; i < veces; i++) {
			int yA = rand() % (ALTO_JUGABLE - 2 - 3) + 3;;
			obstaculos.push_back(new Obstaculo(ANCHO_JUGABLE - 9, yA));
		}

	}

	void manejarAgregarObstaculo() {
		countFramesAparicion++;
		contFramesTotal++;

		float segTotalesTranscurridos = (contFramesTotal * TIEMPO_SLEEP) / 1000.0f;
		float segTranscurridos = (countFramesAparicion * TIEMPO_SLEEP) / 1000.0f;

		int intervaloAparicion = 5;
		if (segTotalesTranscurridos >= 10 && segTotalesTranscurridos < 30) intervaloAparicion = 4;
		else if (segTotalesTranscurridos >= 30 && segTotalesTranscurridos < 40) intervaloAparicion = 3;
		else if (segTotalesTranscurridos >= 50 && segTotalesTranscurridos < 60) intervaloAparicion = 2;

		if (segTranscurridos >= intervaloAparicion) {
			agregarObstaculo();
			countFramesAparicion = 0;
		}
	}

	void borrarObstaculo(int i) {
		delete obstaculos[i];
		obstaculos.erase(obstaculos.begin() + i);
	}

	void moverObstaculo(int i) {
		float min = 0.5;
		float max = 2.0;

		float random_val = min + (static_cast<float>(std::rand()) / RAND_MAX) * (max - min);
		obstaculos[i]->setX(obstaculos[i]->getX() - random_val);
	}

	void manejarColisiones(int i, Protagonista& prot) {
		bool colision = verificarColision({short(obstaculos[i]->getX()), short(obstaculos[i]->getY())},
			obstaculos[i]->getAncho(), obstaculos[i]->getAlto(),
			{short(prot.getX()), short(prot.getY())}, prot.getAncho(), prot.getAlto());

		if (!colision) return;

		prot.setInvulnerable(true);
		prot.setVida(prot.getVida() - 10);
		borrarObstaculo(i);
	}

	void manejarObstaculos(std::vector<std::vector<int>> matrizMapa, Protagonista& prot) {
		manejarAgregarObstaculo();

		for (int i = 0; i < int(obstaculos.size()); i++) {
			obstaculos[i]->borrar(matrizMapa);
			if (obstaculos[i]->getX() <= 4) {
				obstaculos[i]->borrar(matrizMapa);
				borrarObstaculo(i);
				continue;
			}
			moverObstaculo(i);
			obstaculos[i]->mostrar(matrizMapa);

			manejarColisiones(i, prot);
		}
	}
};