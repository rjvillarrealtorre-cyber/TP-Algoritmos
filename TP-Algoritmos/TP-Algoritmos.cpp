#include <iostream>
#include <Windows.h>
#include <vector>
#include <clocale>
using std::string;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#include "Personaje.h"
#include "Protagonista.h"

int main()
{
    std::setlocale(LC_ALL, ".UTF8");

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

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

    Protagonista prot("Mateo", sr, sl, 'R', 100, 1, 1, 1, 0, 0, 0);

    while (true) {
        prot.determinarMovimiento();

        Sleep(75);
    }
}