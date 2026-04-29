#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <clocale>
using std::string;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int ANCHO_JUGABLE = 80;
const int ANCHO_ESTAD = 30;
const int ALTO_JUGABLE = 21;
const int ALTO_DIAL = 8;

const int TIEMPO_SLEEP = 75;

#include "Personaje.h"
#include "ArbolDialogo.h"
#include "Protagonista.h"
#include "AliadoEstatico.h"
#include "Interfaz.h"

int main()
{
    // ------------------- Setup inicial -------------------

    // Líneas para poder usar carácteres unicode/ascii expandido
    std::setlocale(LC_ALL, ".UTF8");

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    //Dibujar los bordes
    dibujarBordes();

    //Tiempo transcurrido
    int contadorFrames = 0;

    // ------------------- Setup personajes -------------------

    //Personaje principal
    std::vector<std::vector<string>> sr = {
        {"_", "∧", "_"},
        {" ", "O"},
        {"<", "|", "\\"},
        {" ", "|", "\\"}
    };

    std::vector<std::vector<string>> sl = {
        {"_", "∧", "_"},
        {" ", "O"},
        {"/", "|", ">"},
        {"/", "|"}
    };

    Protagonista prot("Mateo", sr, sl, 'R', 100, 10, 10, 1, 0, 0, 0);

    ArbolDialogo arbol;
    arbol.agregarInteraccionVacia();

    // ---- DIALOGO 0 ----
    std::vector<Opcion> opciones0 = {
        {"Quiero conocer la verdad.", {0,0,0}, 1},
        {"Escribir mi artículo e irme.", {0,0,0}, 2},
        {"No tengo por qué contártelo", {0,0,0}, 2}
    };

    Dialogo d0({
        "Wilmer: ¿Que es lo que quieres realmente, periodista?"
        }, opciones0);

    arbol.agregarDialogo(d0, 0);

    // ---- DIALOGO 1 ----
    std::vector<Opcion> opciones1 = {
        {"Y tu puedes guiarme hacia ella.", {10,0,0}, 3},
        {"Dejadme ver a vuestro lider.", {0,0,0}, 4, 50}, // req confianza 50
        {"Salir", {0,0,0}, 0}
    };

    Dialogo d1({
        "Wilmer: ¿La verdad, eh? Eso es algo nuevo.",
        "Pero la verdad no se cuenta, se observa."
        }, opciones1);

    arbol.agregarDialogo(d1, 0);

    // ---- DIALOGO 2 ----
    std::vector<Opcion> opciones2 = {
        {"Requiero vuestra ayuda para empezar.", {5,0,0}, 3},
        {"Dejadme ver a vuestro lider.", {0,0,0}, 4, 50},
        {"Salir", {0,0,0}, 0}
    };

    Dialogo d2({
        "Wilmer: Ah... asi que eres uno mas de ellos.",
        "Haz lo que tengas que hacer y largate."
        }, opciones2);

    arbol.agregarDialogo(d2, 0);

    // ---- DIALOGO 3 ----
    Dialogo d3({
        "Wilmer: Mmm... interesante.",
        "Quizas no eres como los demas."
        });

    arbol.agregarDialogo(d3, 0);

    // ---- DIALOGO 4 (requiere confianza >= 50) ----
    Dialogo d4({
        "Wilmer: He de admitir que me has sorprendido.",
        "Ven, Don Evaristo te espera en su cabana."
        });

    arbol.agregarDialogo(d4, 0);

    AliadoEstatico wilmer("Wilmer", sl, 15, 10, arbol);

    // ------------------- Bucle Principal -------------------

    while (true) {
        wilmer.mostrar();
        wilmer.manejarInteraccion(prot);

        prot.determinarMovimiento();

        mostrarEstadisticas(prot, contadorFrames);

        // Miscelánea
        contadorFrames++;

        Sleep(TIEMPO_SLEEP);
    }
}