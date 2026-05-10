#pragma once

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <clocale>
using std::string;

extern HANDLE hConsole;

extern int ANCHO_JUGABLE;
extern int ANCHO_ESTAD;
extern int ALTO_JUGABLE;
extern int ALTO_DIAL;
	   
extern int TIEMPO_SLEEP;

inline int leerColor(int color) {
	switch (color) {
	case -1: return 0x0; // Fondo Negro
	case 0: return 0x80; // "" Gris Oscuro
	case 1: return 0x60; // Amarillo Oscuro
	case 2: return 0x10; // Azul oscuro
	case 3: return 0x20; // Verde oscuro
	case 4: return 0xA0; // Verde Claro
	case 5: return 0x70; // Gris claro
	case 6: return 0xC0; // Rojo claro
	case 7: return 0x40; // Rojo oscuro
	case 8: return 0x90; // Celeste
	case 9: return 0xE0; // Amarillo claro
	}
}

inline int leerColorNormal(int color) {
	switch (color) {
	case -1: return 0x0; // Fondo Negro
	case 0: return 0x8; // "" Gris Oscuro
	case 1: return 0x6; // Amarillo Oscuro
	case 2: return 0x1; // Azul oscuro
	case 3: return 0x2; // Verde oscuro
	case 4: return 0xA; // Verde Claro
	case 5: return 0x7; // Gris claro
	case 6: return 0xC; // Rojo claro
	case 7: return 0x4; // Rojo oscuro
	case 8: return 0x9; // Celeste
	case 9: return 0xE; // Amarillo claro
	}
}

inline void dibujarIndicacionesDialogo() {
	SetConsoleCursorPosition(hConsole, { 24, short(ALTO_JUGABLE + 3) });
	std::cout << u8"Interactúe con cualquier personaje presionando la TECLA 'E'";
	SetConsoleCursorPosition(hConsole, { 24, short(ALTO_JUGABLE + 4) });
	std::cout << u8"Utilice los números [1, 2, 3, 4...] para elegir una  opción";
	SetConsoleCursorPosition(hConsole, { 24, short(ALTO_JUGABLE + 5) });
	std::cout << u8"de diálogo (en caso aplique).";
}

inline void dibujarBordes() {
	for (int i = 1; i <= ALTO_JUGABLE + ALTO_DIAL; i++) {
		for (int j = 1; j <= ANCHO_JUGABLE + ANCHO_ESTAD; j++) {
			if (i == 1 || i == ALTO_JUGABLE || i == ALTO_JUGABLE + ALTO_DIAL || j == 1 || j == ANCHO_JUGABLE || j == ANCHO_JUGABLE + ANCHO_ESTAD)
				std::cout << u8"■";
			else std::cout << " ";
		}
		std::cout << "\n";
	}
}

inline void dibujarBordesExterno() {
	for (int i = 0; i < ALTO_DIAL + ALTO_JUGABLE; i++) {
		for (int j = 0; j < ANCHO_ESTAD + ANCHO_JUGABLE; j++) {
			if (i == 0 || i == ALTO_DIAL + ALTO_JUGABLE - 1 || j == 0 || j == ANCHO_ESTAD + ANCHO_JUGABLE - 1) std::cout << u8"■";
			else std::cout << " ";
		}
		std::cout << "\n";
	}
}


inline void dibujarMapa(std::vector<std::vector<int>>& matrizMapa) {
	for (int i = 0; i < matrizMapa.size(); i++) {
		for (int j = 0; j < matrizMapa[i].size(); j++) {
			SetConsoleCursorPosition(hConsole, { static_cast<short>(j + 1), static_cast<short>(i + 1) });
			SetConsoleTextAttribute(hConsole, leerColor(matrizMapa[i][j]));
			std::cout << " ";

			SetConsoleTextAttribute(hConsole, 0x7);
		}
	}
}

inline bool verificarColision(
	COORD posA, int anchoA, int altoA,
	COORD posB, int anchoB, int altoB)
{
	// Si A está completamente a la izquierda de B
	if (posA.X + anchoA <= posB.X) return false;

	// Si A está completamente a la derecha de B
	if (posB.X + anchoB <= posA.X) return false;

	// Si A está completamente arriba de B
	if (posA.Y + altoA <= posB.Y) return false;

	// Si A está completamente debajo de B
	if (posB.Y + altoB <= posA.Y) return false;

	// En cualquier otro caso, hay superposición (colisión)
	return true;
}