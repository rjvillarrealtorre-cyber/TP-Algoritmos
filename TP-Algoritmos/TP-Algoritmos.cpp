#include <iostream>
#include <Windows.h>
#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Winmm.lib")
#include <cstdlib>
#include <vector>
#include <clocale>
#include <direct.h>
using std::string;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

constexpr int ANCHO_JUGABLE = 110;
constexpr int ANCHO_ESTAD = 30;
constexpr int ALTO_JUGABLE = 25;
constexpr int ALTO_DIAL = 10;

constexpr int TIEMPO_SLEEP = 75;

#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

#include "AudioManager.h"

#include "Utilidades.h"
#include "Personaje.h"
#include "ArbolDialogo.h"
#include "Arbol.h"
#include "Protagonista.h"
#include "Npc.h"
#include "AliadoDinamico.h"
#include "NPCInteractuable.h"
#include "Enemigo.h"
#include "Obstaculo.h"

#include "Cinematica.h"
#include "Mapa.h"
#include "Nivel.h"
#include "Interfaz.h"
#include "Menu.h"

#include "BuilderMenu.h"
#include "BuilderCinematica.h"
#include "BuilderNPCInteractuable.h"
#include "BuilderProtagonista.h"
#include "BuilderNivel.h"

#include "Juego.h"


int main()
{
    // ------------------- Setup inicial -------------------

    // Líneas para poder usar carácteres unicode/ascii expandido
    std::setlocale(LC_ALL, ".UTF8");

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::srand(std::time(NULL));

    // ------------------- Inicio ----------------------------
    std::cout << "Antes de continuar, por favor ponga la consola en pantalla completa\n";
    std::cout << "Si tiene problemas con la resolución, haga sus carácteres más pequeños\n";
    std::cout << "presionando CTRL, y mueva la ruedita del mouse.\n";
    std::cout << "\nPresione cualquier tecla para continuar...";
    system("pause > 0");
    system("cls");

    // ------------------- Setup personajes -------------------

    Juego juego;
    juego.manejarMenuInicio();

    // ------------------- Bucle Principal -------------------


    while (true) {
        juego.manejarBuclePrincipal();
    }
}
