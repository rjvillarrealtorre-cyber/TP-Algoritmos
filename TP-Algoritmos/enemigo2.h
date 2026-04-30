#pragma once
#include "Personaje.h"
using namespace std;

class EnemigoSaboteador : public Personaje {
public:
    EnemigoSaboteador(float px, float py) : Personaje("Saboteador", {}, {}, 'L', 80, px, py, 2) {
 
        vector<string> f0 = { " ", " ", "0", " ", "/", " " };    
        vector<string> f1 = { "<", "/", "\\", "/", " ", " " };
        vector<string> f2 = { " ", "/", ">", " ", " ", " " };

        spriteL.push_back(f0);
        spriteL.push_back(f1);
        spriteL.push_back(f2);

        spriteR = spriteL;  

        actualizarDimensiones();

        
        dx = (rand() % 5 + 2) * (rand() % 2 == 0 ? 1 : -1);
        dy = (rand() % 3 + 1) * (rand() % 2 == 0 ? 1 : -1);
    }

    void dibujar() {
        mostrar();
    }

    void mover() {
        borrar(); 
        if (x + dx < 0 || x + dx + ancho >= 120) dx *= -1;
        if (y + dy < 0 || y + dy + alto >= 30) dy *= -1;
        x += dx;
        y += dy;

        mostrar();
    }
};
