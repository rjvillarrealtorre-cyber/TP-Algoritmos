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
public:
	ManejoObstaculos() {
		segundosEntreAparicion = 5;
		countFramesAparicion = 0;
	}

	~ManejoObstaculos() {
		for (Obstaculo* o : obstaculos) delete o;
	}

	void agregarObstaculo() {
		int yA = rand() % (ALTO_JUGABLE - 2 - 2) + 2;;
		obstaculos.push_back(new Obstaculo(ANCHO_JUGABLE - 9, yA));
	}

	void manejarAgregarObstaculo() {
		countFramesAparicion++;

		float segTranscurridos = (countFramesAparicion * TIEMPO_SLEEP) / 1000.0f;

		if (segTranscurridos >= 5) {
			agregarObstaculo();
			countFramesAparicion = 0;
		}
	}

	void borrarObstaculo(int i) {
		delete obstaculos[i];
		obstaculos.erase(obstaculos.begin() + i);
	}

	void moverObstaculo(int i) {
		obstaculos[i]->setX(obstaculos[i]->getX() - 1);
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