#pragma once

int leerColor(int color) {
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