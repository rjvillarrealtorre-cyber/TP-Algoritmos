#pragma once
#include <string>

inline void mostrarEstadisticasNivel2(Protagonista& prot, AliadoDinamico ali) {
    SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), 14 });
    std::cout << "[SEMILLAS]: " << prot.getSemillas() << " ";

    string estadoAliado = ali.getEstado() == "seguir" ? "SIGUIENDO" : "INMOVIL";

    SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), 16 });
    std::cout << "[ALIADO]: " << estadoAliado << "   ";
}

inline void mostrarEstadisticas(Protagonista& prot, int contadorFrames, bool esNivel2) {
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

    //Mostrar tiempo
    short alturaTiempo = esNivel2 ? 18 : 14;

    int segundos = ((contadorFrames * TIEMPO_SLEEP) / 1000) % 60;
    int minutos = ((contadorFrames * TIEMPO_SLEEP) / 1000) / 60;

    string mostrarSegundos = (segundos < 10) ? ("0" + std::to_string(segundos)) : std::to_string(segundos);

    SetConsoleCursorPosition(hConsole, { short(ANCHO_JUGABLE + 2), alturaTiempo });
    std::cout << "[TIEMPO]: " << minutos << ":" << mostrarSegundos << "    ";
}
