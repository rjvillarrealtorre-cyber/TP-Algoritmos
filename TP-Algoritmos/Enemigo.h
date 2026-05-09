#pragma once
#include "Personaje.h"
#include "Proyectil.h"

class Enemigo : public Personaje {
protected:
    float xI, yI;
    int arbolObjetivo;

    bool primeraVezHuye;
    bool enHuida;
    int contFramesHuida;
public:
    Enemigo(float px, float py) : Personaje("", {}, {}, 'R', 100, px, py, 1) {
        xI = px;
        yI = py;
        arbolObjetivo = -1;

        primeraVezHuye = true;
        enHuida = false;
        contFramesHuida = 0;
    }

    virtual ~Enemigo() {}

    void determinarObjetivo(std::vector<Arbol*> arboles) {
        if (arboles.size() == 0) return;

        if ((arbolObjetivo != -1 && (!arboles[arbolObjetivo]->getEstaVivo() || !arboles[arbolObjetivo]->getEstaGerminando())) || (arbolObjetivo == -1)) {
            arbolObjetivo = rand() % arboles.size();
        }
    }

    void mover(std::vector<Arbol*> arboles) {
        if (arbolObjetivo == -1) return;

        if (arboles[arbolObjetivo]->getX() - x > 2) {
            dir = 'R';
            x++;
        }
        else if (arboles[arbolObjetivo]->getX() - x < -2) {
            dir = 'L';
            x--;
        }

        if (arboles[arbolObjetivo]->getY() - y > 0) y++;
        else if (arboles[arbolObjetivo]->getY() - y < 0) y--;
    }

    void moverInicio() {
        if (xI - x > 0) {
            dir = 'R';
            x++;
        }
        else if (xI - x < 0) {
            dir = 'L';
            x--;
        }

        if (yI - y > 0) y++;
        else if (yI - y < 0) y--;
    }

    void manejarEstado() {
        if (enHuida) contFramesHuida++;

        if (contFramesHuida >= 10 * (1000 / TIEMPO_SLEEP)) {
            enHuida = false;
            primeraVezHuye = false;
        }
    }

    void manejarMovimiento(std::vector<Arbol*> arboles) {
        if (enHuida) moverInicio();
        else mover(arboles);
    }

    bool determinarCercaniaAliado(AliadoDinamico ali) {
        if ((std::abs(ali.getX() - x) <= 6) && (std::abs(ali.getY() - y) <= 3))
            return true;
        return false;
    }

    void sabotear(std::vector<Arbol*>& arboles, AliadoDinamico ali) {
        if (arbolObjetivo == -1) return;
        
        bool hayColision = verificarColision({ short(x), short(y) }, ancho + 2, alto + 2,
            { short(arboles[arbolObjetivo]->getX()), short(arboles[arbolObjetivo]->getY()) },
            arboles[arbolObjetivo]->getAncho(), arboles[arbolObjetivo]->getAlto());
        
        if (hayColision && determinarCercaniaAliado(ali)) {
            arboles[arbolObjetivo]->anadirMultiplicador();
            arboles[arbolObjetivo]->setVelocidadSabotaje(0.5 * (arboles[arbolObjetivo]->getMultiplicadorSabotaje() + 1));
            arboles[arbolObjetivo]->setSiendoSabotead(true);
        }
        else if (hayColision) {
            // ---
            arboles[arbolObjetivo]->anadirMultiplicador();
            arboles[arbolObjetivo]->setVelocidadSabotaje(1 * (arboles[arbolObjetivo]->getMultiplicadorSabotaje() + 1));
            arboles[arbolObjetivo]->setSiendoSabotead(true);
        }
        //else if (!hayColision && arboles[arbolObjetivo]->getSiendoSaboteado()) {
        //    arboles[arbolObjetivo]->setSiendoSabotead(false);
        //}
    }

    void verColisionJugador(Protagonista& prot) {
        bool hayColision = verificarColision({ short(x), short(y) }, ancho, alto,
            { short(prot.getX()), short(prot.getY()) }, prot.getAncho(), prot.getAlto());

        if (!hayColision) return;

        if(!prot.getInvulnerable()) prot.setVida(prot.getVida() - 10);
        prot.setInvulnerable(true);
        invulnerable = true;

        if (arbolObjetivo == -1 || prot.getArboles().empty()) return;

        if (arbolObjetivo >= 0 && prot.getArboles()[arbolObjetivo]->getEstaVivo() && !invulnerable)
            prot.getArboles()[arbolObjetivo]->setContFramesSabotear(prot.getArboles()[arbolObjetivo]->getContFramesSabotear() - 3 * (1000 / TIEMPO_SLEEP));
        if (primeraVezHuye) {
            enHuida = true;
            prot.getArboles()[arbolObjetivo]->setSiendoSabotead(false);
            arbolObjetivo = -1;
        }
    }

};

class EnemigoTalador : public Enemigo {
public:
    EnemigoTalador(float px, float py) : Enemigo(px, py) {
        spriteR = {
            { " ", "_", " ", " ", " "},
            { " ", u8"Ø", " ", "|", ">"},
            { "<", "|", "-", "|", " "},
            { " ", "|", "\\", " ", " "},
        };

        spriteL = {
            { " ", " ", " ", "_", " "},
            { "<", "|", " ", u8"Ø", " "},
            { " ", "|", "-", "|", ">"},
            { " ", " ", "/", "|", " "},
        };

        int dx = (rand() % 3 + 1) * (rand() % 2 == 0 ? 1 : -1);

        velocidad = dx;

        alto = spriteR.size();
        int temp = 0;
        for (int i = 0; i < alto; i++) {
            if (spriteR[i].size() > temp) temp = spriteR[i].size();
        }
        ancho = temp;
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

        alto = spriteR.size();
        int temp = 0;
        for (int i = 0; i < alto; i++) {
            if (spriteR[i].size() > temp) temp = spriteR[i].size();
        }
        ancho = temp;
    }
};

class EnemigoBote : public Personaje {
private:
    std::vector<ProyectilEnemigo*> proyectiles;
    int disparosHechos;
    int contFramesDisparo;

    int xI, yI;
public:
    EnemigoBote(float px, float py) : Personaje("", {}, {}, 'R', 100, px, py, 1) {
        spriteR = {
            {" ", " ", " ", " ", "O", " ", " ", " ", "O", " ", " ", " ", " "},
            {" ", "_", "_", "<", "|", "L", "_", "(", "|", "\\", "_", "/", ">"},
            {u8"ᗡ", "|", "_", "_", "_", "_", "_", "_", "_", "_","/"," ", " "},
        };
        spriteL = spriteR;

        alto = spriteR.size();
        int temp = 0;
        for (int i = 0; i < alto; i++) {
            if (spriteR[i].size() > temp) temp = spriteR[i].size();
        }
        ancho = temp;

        disparosHechos = 0;
        contFramesDisparo = 0;

        xI = rand() % (50 - 15 + 1) + 15;
        yI = rand() % (5 - 0 + 1) + 1;
    }

    ~EnemigoBote() {
        for (ProyectilEnemigo* pe : proyectiles) {
            delete pe;
        }
    }

    void manejarMovimiento(Protagonista& prot) {
        if (prot.getX() - x > xI) {
            x++;
        }
        else if (prot.getX() - x < -xI) {
            x--;
        }

        if (prot.getY() - y > yI) y++;
        else if (prot.getY() - y < -yI) y--;
    }

    void disparar() {
        float randomNum = 0.5 + (static_cast<float>(std::rand()) / RAND_MAX) * 0.5;
        proyectiles.push_back(new ProyectilEnemigo(true, x + ancho + 1, y + alto / 2, '*', randomNum, 10));
    }

    void manejarTiempoDisparos(Protagonista& prot) {
        contFramesDisparo++;

        float segTranscurridos = (contFramesDisparo * TIEMPO_SLEEP) / 1000.0f;
        if (segTranscurridos >= 5) {
            disparar();
            disparosHechos++;
            contFramesDisparo = 0;
        }
    }

    void borrarProyectil(int i) {
        delete proyectiles[i];
        proyectiles.erase(proyectiles.begin() + i);
    }

    void manejarColisiones(Protagonista& prot) {
        bool invulnerable = prot.getInvulnerable();
        if (invulnerable) return;

        bool colisionBoteBote = verificarColision({ short(x), short(y) }, ancho, alto,
            { short(prot.getX()), short(prot.getY()) }, prot.getAncho(), prot.getAlto());

        if (colisionBoteBote) {
            prot.setVida(prot.getVida() - 10);
            prot.setInvulnerable(true);
        }

        for (int i = 0; i < proyectiles.size(); i++) {
            bool colisionProyectil = verificarColision({ short(proyectiles[i]->getX()), short(proyectiles[i]->getY()) },
                1, 1, { short(prot.getX()), short(prot.getY()) }, prot.getAncho(), prot.getAlto());

            if (!colisionProyectil) return;

            prot.setVida(prot.getVida() - 10);
            prot.setInvulnerable(true);
            borrarProyectil(i);
        }
    }

    void manejarDisparos(Protagonista& prot, std::vector<std::vector<int>> matrizMapa) {
        manejarTiempoDisparos(prot);

        if (proyectiles.empty()) return;

        for (int i = 0; i < proyectiles.size(); i++) {
            if (proyectiles[i]->getX() <= 0 || proyectiles[i]->getX() >= ANCHO_JUGABLE - 2) {
                borrarProyectil(i);
                continue;
            }
            proyectiles[i]->borrarProyectil(matrizMapa);
            proyectiles[i]->setX(proyectiles[i]->getX() + proyectiles[i]->getVelocidad());

            if (proyectiles[i]->getX() <= 0 || proyectiles[i]->getX() >= ANCHO_JUGABLE - 2) {
                borrarProyectil(i);
                continue;
            }

            proyectiles[i]->mostrarProyectil(matrizMapa);
        }
    }
};
