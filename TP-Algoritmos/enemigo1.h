#pragma once
#include "Personaje.h"
using namespace std;
class EnemigoTalador : public Personaje {
public:
    EnemigoTalador(float px, float py) : Personaje("Talador", {}, {}, 'R', 100, px, py, 1) {  
        vector<string> f0 = { " ", " ", "_", " ", "|", ">" }; 
        vector<string> f1 = { "<", "|", "-", "|", " ", " "}; 
        vector<string> f2 = { " ", "|", "\\", " ", " ", " " };

        spriteR.push_back(f0);
        spriteR.push_back(f1);
        spriteR.push_back(f2); 

        spriteL = spriteR;
         
        actualizarDimensiones();
         
        dx = (rand() % 3 + 1) * (rand() % 2 == 0 ? 1 : -1);
        dy = (rand() % 2 + 1) * (rand() % 2 == 0 ? 1 : -1);
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
