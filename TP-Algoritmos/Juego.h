#pragma once

// En cristiano: Un "juego" maneja y une los niveles con los menus
class Juego {
private:
	std::vector<Nivel*> niveles;
	std::vector<Menu> menus;
	Protagonista* prota;
	int nivelActual;
	int contadorFrames;

	AudioManager audio;
	ma_sound* musicaMenu;
	ma_sound* musicaNvl1;
	ma_sound* musicaNvl2;
	ma_sound* musicaNvl3;
public:
	Juego(std::vector<Nivel*> n = {}, std::vector<Menu> m = {}, Protagonista* p = nullptr) {
		niveles = n;
		menus = m;
		nivelActual = 0;
		prota = p;

		prota = setupProtagonista();

		niveles.push_back(setupNivel1());
		niveles.push_back(setupNivel2());
		niveles.push_back(setupNivel3());

		menus.push_back(setupMenuInicio());
		menus.push_back(setupMenuInstrucciones());
		menus.push_back(setupMenuCreditos());

		contadorFrames = 0;

		musicaMenu = audio.cargarSonido("bgm_action_0.wav", true);
		audio.setVolumen(musicaMenu, 0.2f);

		musicaNvl1 = audio.cargarSonido("bgm_action_1.wav", true);
		audio.setVolumen(musicaNvl1, 0.2f);

		musicaNvl2 = audio.cargarSonido("bgm_action_2.mp3", true);
		audio.setVolumen(musicaNvl2, 0.2f);

		musicaNvl3 = audio.cargarSonido("bgm_action_3.wav", true);
		audio.setVolumen(musicaNvl3, 0.2f);

		if (musicaMenu == nullptr) {
			std::cout << "ERROR MUSICA MENU\n";
			system("pause>0");
		}
	}

	~Juego() {
		for (Nivel* n : niveles) {
			delete n;
		}

		delete prota;
	}

	void manejarCambioNivel(int nuevoNivel) {
		niveles[nuevoNivel]->mostrarCinematica();
		system("cls");
		dibujarBordes();
		niveles[nuevoNivel]->dibujarMapa();
	}

	void manejarMenuInicio() {
		audio.reproducir(musicaMenu);
		menus[0].mostrarMenu(0);

		while (menus[0].getEnMenu()) {
			if (GetAsyncKeyState('1') & 0x0001) { // Jugar
				for (Menu& m : menus) {
					m.setEnMenu(false);
				}
				audio.detener(musicaMenu);
				audio.reproducir(musicaNvl1);

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

	void acabarNivel() {
		niveles[nivelActual]->mostrarCinematica(true);
		if (nivelActual < niveles.size()) nivelActual++;

		prota->setVida(100);

		if (nivelActual == 1) {
			audio.detener(musicaNvl1);
			audio.reproducir(musicaNvl2);

			prota->setAltoJugablePermitido(ALTO_JUGABLE + ALTO_DIAL - 1);
		}
		else if (nivelActual == 2) {
			audio.detener(musicaNvl2);
			audio.reproducir(musicaNvl3);

			prota->setX(20);
			prota->setY(12);

			for (Arbol* arbol : prota->getArboles()) {
				delete arbol;
			}
			prota->getArboles().clear();

			for (Enemigo* enemigo : niveles[nivelActual]->getMapaActual()->getVecEnemigo()) {
				delete enemigo;
			}

			prota->setAltoJugablePermitido(ALTO_JUGABLE - 1);
			prota->setSprite({
				{" ", " ", " ", "O", " ", " ", " ", "o", " ", " ", "O", " ", " ", "_", " ", " ", " ", " ", " "},
				{" ", "_", "—", "|", ")", "_", "_", "|", "_", "_", "|", "_", "|", "_", "\\", "_", "_", "_", "."},
				{"=", "|", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "/", " "}, }
				);
			prota->setEnBote(true);
			prota->recalcularAltoAncho();
		}
	}

	void mostrarDerrota() {
		Menu ventanaDerrota = setupMenuDerrota();
		bool enDerrota = true;

		while (true) {
			ventanaDerrota.mostrarMenu(3);

			while (enDerrota) {
				if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
					prota->setVida(100);
					prota->setSemillas(6);

					switch (nivelActual) {
					case 0: delete niveles[nivelActual]; niveles[nivelActual] = setupNivel1(); break;
					case 1: delete niveles[nivelActual]; niveles[nivelActual] = setupNivel2(); break;
					case 2: delete niveles[nivelActual]; niveles[nivelActual] = setupNivel3(); break;
					}

					enDerrota = false;
					break;
				}

				if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) {
					exit(0);
				}
			}

			if (!enDerrota) break;
		}
	}

	void manejarVictoriaDerrota() {
		if (prota->getVida() <= 0) mostrarDerrota();

		if (nivelActual == 1) {
			//Victoria
			int arbolesGerminados = 0;
			for (int i = 0; i < prota->getArboles().size(); i++) {
				if (prota->getArboles()[i]->getEstaVivo() &&
					!prota->getArboles()[i]->getEstaGerminando()) arbolesGerminados++;
			}
		
			if (arbolesGerminados >= 4) acabarNivel();
		
			//Derrota
			int arbolesGerminando = 0;
			for (int i = 0; i < prota->getArboles().size(); i++) {
				if (prota->getArboles()[i]->getEstaGerminando()) arbolesGerminando++;
			}
			
			if (prota->getSemillas() <= 0 && arbolesGerminados < 4 && arbolesGerminando <= 0)
				mostrarDerrota();
		}
		else if (nivelActual == 2) {
			//Victoria
			float segundos = niveles[nivelActual]->getMapaActual()->getContFrames()
				* TIEMPO_SLEEP / 1000.0f;

			if (segundos >= 60.0f) {
				acabarNivel();
			}
		}
	}

	void manejarBuclePrincipal() {
		//Variables
		bool teclaE = (GetAsyncKeyState('E') & 0x0001);
		std::vector<std::vector<int>>& matrizMapa = niveles[nivelActual]->getMapaActual()->getMatrizMapa();;


		getVecNiveles()[nivelActual]->mostrarCinematica(); //si aplica...

		for (NPCInteractuable& ali : niveles[nivelActual]->getMapaActual()->getVecNPCInt()) {
			ali.mostrar(matrizMapa);

			bool aN = ali.manejarInteraccion(*prota, teclaE);

			if (aN) acabarNivel();
		}

		for (AliadoDinamico& ali : niveles[nivelActual]->getMapaActual()->getVecAliDinam()) {
			ali.manejarEstados();
			ali.manejarMovimiento(matrizMapa, *prota);
		}

		if (nivelActual == 1) {
			for (Enemigo* en : niveles[nivelActual]->getMapaActual()->getVecEnemigo()) {
				en->determinarObjetivo(prota->getArboles());
				en->verColisionJugador(*prota);
				en->manejarEstado();
				en->manejarInvulnerabilidad();
				en->borrar(matrizMapa);
				en->manejarMovimiento(prota->getArboles());

				if (!niveles[nivelActual]->getMapaActual()->getVecAliDinam().empty())
					en->sabotear(prota->getArboles(), niveles[nivelActual]->getMapaActual()->getVecAliDinam()[0]);

				en->mostrar(matrizMapa);
			}

			prota->plantarArbol(teclaE, matrizMapa);
		}

		if (nivelActual == 2) {
			for (EnemigoBote* enB : niveles[nivelActual]->getMapaActual()->getVecEnemBote()) {
				enB->borrar(matrizMapa);
				enB->manejarMovimiento(*prota);
				enB->mostrar(matrizMapa);

				enB->manejarDisparos(*prota, matrizMapa);
				enB->manejarColisiones(*prota);

				niveles[nivelActual]->getMapaActual()->getManejoObstaculos().manejarObstaculos(matrizMapa, *prota);
			}
		}


		for (Arbol* arbol : prota->getArboles()) {
			arbol->manejarCrecimiento(matrizMapa);
			arbol->mostrar(matrizMapa);

		}

		niveles[nivelActual]->getMapaActual()->anadirEnemigosNivel2(nivelActual);

		prota->determinarMovimiento(matrizMapa);
		prota->manejarInvulnerabilidad();
		prota->mostrar(matrizMapa);

		// Otros
		if (nivelActual == 0) niveles[nivelActual]->observarPorCambioMapa(*prota, teclaE);

		manejarVictoriaDerrota();

		// Estadisticas
		bool estadis = nivelActual == 1 ? true : false;

		mostrarEstadisticas(*prota, niveles[nivelActual]->getMapaActual()->getContFrames(), estadis);
		if(nivelActual == 1)
			mostrarEstadisticasNivel2(*prota, niveles[nivelActual]->getMapaActual()->getVecAliDinam()[0]);

		//Miscelanea
		contadorFrames++;
		niveles[nivelActual]->getMapaActual()->anadirContadorFrames();

		//Texto nivel 3:

		if (nivelActual == 2) {
			std::vector<string> lineas = {
				u8"MATEO: Tengo el dossier. Lo cuidaré. Pero... Necesitamos resistir.",
				u8"WILMER: ¡Vamos! ¡Solo son unas cuántas horas río abajo! ¡Resistid!",
				u8"JEREMÍAS: Iré atrás. Veré si... si el motor funciona.",
			};
			short centrar = (ANCHO_JUGABLE - lineas[0].size()) / 2;

			for (auto l : lineas) {
				SetConsoleCursorPosition(hConsole, { short(centrar + 1), short(ALTO_JUGABLE + 1) });
				std::cout << l;
			}
		}

		Sleep(TIEMPO_SLEEP);
	}

	std::vector<Nivel*>& getVecNiveles() { return niveles; }
	int getNivelActual() { return nivelActual; }
	Protagonista* getProtagonista() { return prota; }
	void setProtagonista(Protagonista* p) { prota = p; }
};