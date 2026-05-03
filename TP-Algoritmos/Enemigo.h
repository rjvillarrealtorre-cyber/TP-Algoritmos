#pragma once
#include "Personaje.h"

class Enemigo : public Personaje {
protected:
    int dx, dy;
public:
    Enemigo(float px, float py) : Personaje("", {}, {}, 'R', 100, px, py, 1) {
        dx = (rand() % 3 + 1) * (rand() % 2 == 0 ? 1 : -1);
        dy = (rand() % 3 + 1) * (rand() % 2 == 0 ? 1 : -1);
    }

    virtual ~Enemigo() {}

    void mover() {
        if (x + ancho >= ANCHO_JUGABLE - 6 || x <= 4) dx *= -1;

        if (y + alto >= ALTO_JUGABLE - 4 || y <= 4) dy *= -1;

        x += dx;
        y += dy;
    }

    void manejarMovimiento(std::vector<std::vector<int>>& matrizMapa) {
        borrar(matrizMapa);
        mover();
        mostrar(matrizMapa);
    }
};

class EnemigoTalador : public Enemigo {
public:
    EnemigoTalador(float px, float py) : Enemigo(px, py) {
        spriteR = {
            { " ", "_", " ", " ", " "},
            { " ", "Ø", " ", "|", ">"},
            { "<", "|", "-", "|", " "},
            { " ", "|", "\\", " ", " "},
        };

        spriteL = {
            { " ", " ", " ", "_", " "},
            { "<", "|", " ", "Ø", " "},
            { " ", "|", "-", "|", ">"},
            { " ", " ", "/", "|", " "},
        };

        int dx = (rand() % 3 + 1) * (rand() % 2 == 0 ? 1 : -1);

        velocidad = dx;
    }
};

class EnemigoSaboteador : public Enemigo {
public:
    EnemigoSaboteador(float px, float py) : Enemigo(px, py) {
        spriteR = {
            { " ", "0", " ", "/"},
            { "<", "/", "/", " "},
            { "/", ">", " ", " "},
        };

        spriteL = {
            { "\\", " ", "0", " ", " "},
            { " ", "\\", "/", "\\", ">"},
            { " ", " ", " ", "<", "\\"},
        };

        int dx = (rand() % 5 + 2) * (rand() % 2 == 0 ? 1 : -1);
        velocidad = dx;
    }
};
