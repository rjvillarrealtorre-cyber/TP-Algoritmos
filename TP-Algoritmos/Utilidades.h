#pragma once

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <clocale>
using std::string;

extern HANDLE hConsole;

extern const int ANCHO_JUGABLE;
extern const int ANCHO_ESTAD;
extern const int ALTO_JUGABLE;
extern const int ALTO_DIAL;

extern const int TIEMPO_SLEEP;

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