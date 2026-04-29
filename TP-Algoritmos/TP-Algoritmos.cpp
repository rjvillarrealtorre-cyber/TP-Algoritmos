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

    // ------------------- Bucle Principal -------------------

    while (true) {
        prot.determinarMovimiento();

        mostrarEstadisticas(prot);

        Sleep(75);
    }
}