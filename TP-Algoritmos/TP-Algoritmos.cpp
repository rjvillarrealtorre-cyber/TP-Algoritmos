#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <clocale>
using std::string;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

extern const int ANCHO_JUGABLE = 110;
extern const int ANCHO_ESTAD = 30;
extern const int ALTO_JUGABLE = 25;
extern const int ALTO_DIAL = 10;

extern const int TIEMPO_SLEEP = 75;

#include "Utilidades.h"
#include "Personaje.h"
#include "ArbolDialogo.h"
#include "Arbol.h"
#include "Protagonista.h"
#include "Npc.h"
#include "AliadoDinamico.h"
#include "NPCInteractuable.h"
#include "Enemigo.h"
#include "Cinematica.h"
#include "Mapa.h"
#include "Nivel.h"
#include "Interfaz.h"
#include "Menu.h"
#include "Juego.h"

#include "BuilderMenu.h"
#include "BuilderCinematica.h"
#include "BuilderNPCInteractuable.h"
#include "BuilderProtagonista.h"
#include "BuilderNivel.h"

int main()
{
    // ------------------- Setup inicial -------------------

    // Líneas para poder usar carácteres unicode/ascii expandido
    std::setlocale(LC_ALL, ".UTF8");

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::srand(std::time(NULL));

    //Tiempo transcurrido
    int contadorFrames = 0;

    // ------------------- Inicio ----------------------------

    std::cout << "Antes de continuar, por favor ponga la consola en pantalla completa\n";
    std::cout << "Si tiene problemas con la resolución, haga sus carácteres más pequeños\n";
    std::cout << "presionando CTRL, y mueva la ruedita del mouse.\n";
    std::cout << "\nPresione cualquier tecla para continuar...";
    system("pause > 0");
    system("cls");

    // ------------------- Setup personajes -------------------

    Protagonista* prot = setupProtagonista();

    Nivel* nivel1 = setupNivel1();
    Nivel* nivel2 = setupNivel2();

    Juego juego({ nivel2 }, { setupMenuInicio(), setupMenuInstrucciones(), setupMenuCreditos() }, prot);

    juego.manejarMenuInicio();

    // ------------------- Bucle Principal -------------------

    bool primeraVez = false;

    bool teclaE = false;

    juego.getProtagonista()->setAltoConfiablePermitido(ALTO_DIAL + ALTO_JUGABLE);

    while (true) {
        teclaE = (GetAsyncKeyState('E') & 0x0001);
        int nivelActual = juego.getNivelActual();

        juego.getVecNiveles()[nivelActual]->mostrarCinematica(); //si aplica...

        if (primeraVez) {
            dibujarIndicacionesDialogo();
            juego.getProtagonista()->mostrar(juego.getVecNiveles()[nivelActual]->getMapaActual()->getMatrizMapa());
            primeraVez = false;
        }

        for (NPCInteractuable& ali : juego.getVecNiveles()[nivelActual]->getMapaActual()->getVecNPCInt()) {
            ali.mostrar(juego.getVecNiveles()[nivelActual]->getMapaActual()->getMatrizMapa());

            bool acabarNivel =
                ali.manejarInteraccion(*juego.getProtagonista(), teclaE);

            if (acabarNivel) {
                juego.acabarNivel();
            }
        }

        for (AliadoDinamico& ali : juego.getVecNiveles()[nivelActual]->getMapaActual()->getVecAliDinam()) {
            ali.manejarEstados();
            ali.manejarMovimiento(juego.getVecNiveles()[nivelActual]->getMapaActual()->getMatrizMapa(), *juego.getProtagonista());
        }

        for (Enemigo* en : juego.getVecNiveles()[nivelActual]->getMapaActual()->getVecEnemigo()) {
            en->determinarObjetivo(juego.getProtagonista()->getArboles());
            en->verColisionJugador(*juego.getProtagonista());
            en->manejarEstado();
            en->manejarInvulnerabilidad();
            en->borrar(juego.getVecNiveles()[nivelActual]->getMapaActual()->getMatrizMapa());
            en->manejarMovimiento(juego.getProtagonista()->getArboles());
            en->sabotear(juego.getProtagonista()->getArboles(), juego.getVecNiveles()[nivelActual]->getMapaActual()->getVecAliDinam()[0]);
            en->mostrar(juego.getVecNiveles()[nivelActual]->getMapaActual()->getMatrizMapa());
        }

        juego.getProtagonista()->plantarArbol(teclaE, juego.getVecNiveles()[nivelActual]->getMapaActual()->getMatrizMapa());

        for (Arbol* arbol : juego.getProtagonista()->getArboles()) {
            arbol->manejarCrecimiento(juego.getVecNiveles()[nivelActual]->getMapaActual()->getMatrizMapa());
            arbol->mostrar(juego.getVecNiveles()[nivelActual]->getMapaActual()->getMatrizMapa());

        }

        juego.getVecNiveles()[nivelActual]->getMapaActual()->anadirEnemigosNivel2(nivelActual);

        juego.getProtagonista()->determinarMovimiento(juego.getVecNiveles()[nivelActual]->getMapaActual()->getMatrizMapa());
        juego.getProtagonista()->manejarInvulnerabilidad();

        mostrarEstadisticas(*juego.getProtagonista(), contadorFrames);

        nivel1->observarPorCambioMapa(*juego.getProtagonista(), teclaE);

        // Miscelánea
        contadorFrames++;
        juego.getVecNiveles()[nivelActual]->getMapaActual()->anadirContadorFrames();

        Sleep(TIEMPO_SLEEP);
    }
}
