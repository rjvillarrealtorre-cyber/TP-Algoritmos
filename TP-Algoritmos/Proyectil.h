#pragma once

class ProyectilEnemigo {
private:
    bool activo;
    float x, y;
    char caracter;
    float velocidad;
    int dano;
public:
    ProyectilEnemigo(bool a, float px, float py, char c, float v, int d)
        : activo(a), x(px), y(py), caracter(c), velocidad(v), dano(d) {
    }


    void borrarProyectil(std::vector<std::vector<int>> matrizMapa) {
        SetConsoleCursorPosition(hConsole, { short(x), short(y) });
        SetConsoleTextAttribute(hConsole, leerColor(matrizMapa[int(y) - 1][int(x) - 1]));
        std::cout << " ";
        SetConsoleTextAttribute(hConsole, 0x7);
    }

    void mostrarProyectil(std::vector<std::vector<int>> matrizMapa) {
        SetConsoleCursorPosition(hConsole, { short(x), short(y) });
        SetConsoleTextAttribute(hConsole, leerColor(matrizMapa[int(y) - 1][int(x) - 1]));
        std::cout << caracter;
        SetConsoleTextAttribute(hConsole, 0x7);
    }

    bool getActivo() { return activo; }
    float getX() { return x; }
    float getY() { return y; }
    char getCaracter() { return caracter; }
    float getVelocidad() { return velocidad; }
    int getDano() { return dano; }

    void setX(float p) { x = p; }
};
