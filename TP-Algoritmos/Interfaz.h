#pragma once

void dibujarBordes() {
    for (int i = 1; i <= ALTO_JUGABLE + ALTO_DIAL; i++) {
        for (int j = 1; j <= ANCHO_JUGABLE + ANCHO_ESTAD; j++) {
            if (i == 1 || i == ALTO_JUGABLE || i == ALTO_JUGABLE + ALTO_DIAL || j == 1 || j == ANCHO_JUGABLE || j == ANCHO_JUGABLE + ANCHO_ESTAD)
                std::cout << u8"■";
            else std::cout << " ";
        }
        std::cout << "\n";
    }
}

void mostrarEstadisticas(Protagonista& prot) {
    SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), 2 });
    std::cout << "[NOMBRE]:" << prot.getNombre();

    SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), 4 });
    std::cout << "[VIDA]:" << prot.getVida() << "    ";

    SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), 6 });
    std::cout << "[CONFIANZA]: " << prot.getConfianza() << "    ";

    SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), 8 });
    std::cout << "[CONOC. LENG.]: " << prot.getConocimientoLengua() << "    ";

    SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), 10 });
    std::cout << "[EVIDENCIA]: " << prot.getEvidencia() << "    ";

    SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), 12 });
    std::cout << "[NIVEL]: 1" << "    ";

    SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), 14 });
    std::cout << "[TIEMPO]: 1:32" << "    ";
}