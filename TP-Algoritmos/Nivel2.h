#pragma once
#include <iostream> 
#include <time.h>
#include <conio.h>
#include <math.h> 
#define FILAS 25
#define COLUMNAS 100

using namespace std;
using namespace System;

int mapa2[FILAS][COLUMNAS] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,2,2,2,2,2,2,2,2,3,3,3,3},
    {3,3,3,3,3,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,3,2,2,2,2,2,2,3,3,3,3,3,3,3,3},
    {3,3,3,3,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,2,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,2,2,2,3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,3,4,3,4,3,3,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {3,3,3,3,3,2,0,2,3,3,3,3,4,4,4,4,4,4,4,4,4,4,3,4,3,4,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,3,4,4,4,3,4,3,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4},
    {3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,3,4,3,3,3,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,4,4,4,4,4,4,4,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3},
    {3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,4,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,4,4,3,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,3},
    {3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,3,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,4,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,4,4,3,3,4,3,3,3,3,3,3,3,3,4,3,3,3,3,3,4,4,3,3,4,4,3,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,3},
    {3,3,3,3,3,3,3,3,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,0,2,3},
    {3,3,3,3,3,3,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2},
    {3,3,3,3,3,4,4,4,4,4,4,4,4,3,3,3,4,3,3,4,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,3,2,2,2,2},
    {3,3,3,3,3,3,3,3,4,4,4,3,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,4,4,4,4,4,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2},
    {3,3,3,3,3,3,3,3,4,3,4,4,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,4,3,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,4,4,4,3,3,3,4,3,3,4,3,4,4,4,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,3,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,4,3,3,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,4,4,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,3,3,3,3,3,4,4,4,3,3,3,3,3,3,3,3,3},
    {3,4,4,4,3,4,4,4,3,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,3,3,3,3,3,3,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3},
    {3,4,4,4,3,4,3,3,3,3,3,3,4,4,3,3,3,3,3,4,4,3,3,3,3,3,2,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,3,4,4,4,4,3,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,4,4,4,4,4,4,4,4,3,3,3,3,3,3,4,3,3,3,3,2,2,2,3,3,3,3,3,2,2,2,3,3,3,3,3,4,3,3,4,4,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,2,2,3,3,3,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,3,3,3,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,2,0,2,3,3,2,3,3,4,4,4,4,4,4,4,4,4,3,3,3,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,2,2,2,3,3,3,3,3,2,2,2,3,3,3,3,3,3,3,4,3,3,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,3,4,4,4,3,3,3,4,4,4,4,3,3,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,3,2,0,2,3,3,3,3,3,2,0,2,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,3,4,4,4,3,3,3,3,3,2,2,2,3,3,3,3,3,3,3,3,3,3,3,2,2,3,3,4,4,4,3,3,3,3,4,4,3,3,3,3,2,2,3,3,2,2},
};
 
void cursor(int x, int y) {
    Console::SetCursorPosition(x, y);
}

void imprimeMapa2() {
    Console::SetWindowSize(130, 30);
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            cursor(c, f);
            if (mapa2[f][c] == 0) Console::ForegroundColor = ConsoleColor::Black;
            if (mapa2[f][c] == 2) Console::ForegroundColor = ConsoleColor::DarkYellow;
            if (mapa2[f][c] == 3) Console::ForegroundColor = ConsoleColor::DarkGray;
            if (mapa2[f][c] == 4) Console::ForegroundColor = ConsoleColor::Gray;
            cout << (char)219;
        }
    }
}

class Limites {
protected:
    int x, y, ancho, alto;
    bool activo;
public:
    Limites(int px, int py, int a, int h) : x(px), y(py), ancho(a), alto(h), activo(true) {}
    virtual void dibujaArbol() = 0;
     
    void borrarM(int mapa[FILAS][COLUMNAS]) {
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                int fy = y + i;
                int cx = x + j;
                if (fy >= 0 && fy < FILAS && cx >= 0 && cx < COLUMNAS) {
                    Console::SetCursorPosition(cx, fy);
                    int val = mapa[fy][cx];
                    if (val == 0) Console::ForegroundColor = ConsoleColor::Black;
                    else if (val == 2) Console::ForegroundColor = ConsoleColor::DarkYellow;
                    else if (val == 3) Console::ForegroundColor = ConsoleColor::DarkGray;
                    else if (val == 4) Console::ForegroundColor = ConsoleColor::Gray;
                    cout << (char)219;
                }
            }
        }
    }

    int getX() { return x; } int getY() { return y; }
    int getA() { return ancho; } int getH() { return alto; }
    bool getActivo() { return activo; }
    void setActivo(bool v) { activo = v; }
};

class Personaje : public Limites {
protected:
    int dx, dy;
    ConsoleColor color;
public:
    Personaje(int px, int py, int a, int h) : Limites(px, py, a, h) {
        dx = dy = 1;
    }
};

class Arbol : public Limites {
private:
    int contador;
    bool enPeligro;
public:
    Arbol(int px, int py) : Limites(px, py, 3, 3), contador(100), enPeligro(false) {}
    void setPeligro(bool v) { enPeligro = v; if (!v) contador = 100; }
    bool getPeligro() { return enPeligro; }
    void reducirContador() { if (enPeligro) contador--; if (contador <= 0) activo = false; }

    void dibujaArbol() {
        if (!activo) return;
        Console::ForegroundColor = enPeligro ? ConsoleColor::Red : ConsoleColor::DarkGreen;
        Console::SetCursorPosition(x, y);     cout << " ^ ";
        Console::SetCursorPosition(x, y + 1); cout << "/ \\";
        Console::SetCursorPosition(x, y + 2); cout << " | ";
        if (enPeligro) { Console::SetCursorPosition(x, y - 1); cout << contador / 10; }
    }
};

class PerPrincipal : public Personaje {
public:
    PerPrincipal(int px, int py) : Personaje(px, py, 3, 3) { color = ConsoleColor::White; }

    
    void mover(char t, int mapa[FILAS][COLUMNAS]) {
        int nx = x, ny = y;
        if (t == 72) ny--;      // Arriba  
        if (t == 80) ny++;      // Abajo
        if (t == 75) nx--;      // Izquierda
        if (t == 77) nx++;      // Derecha
         //movimiento dentro del mapa
        if (ny >= 0 && ny + alto <= FILAS && nx >= 0 && nx + ancho <= COLUMNAS) {
            if (mapa[ny][nx] == 0 || mapa[ny][nx] == 3 || mapa [ny][nx] == 4) {
                borrarM(mapa);
                x = nx; y = ny;
            }
        }
    }

    void dibujaArbol() {
        Console::ForegroundColor = color;

        Console::SetCursorPosition(x, y);     cout << " o ";
        Console::SetCursorPosition(x, y + 1); cout << "/|\\";
        Console::SetCursorPosition(x, y + 2); cout << "/ \\";
    }
};

class Enemigo : public Personaje {
public:
    Enemigo(int px, int py) : Personaje(px, py, 6, 3) {
        dx = (rand() % 2 == 0) ? 1 : -1;
        dy = (rand() % 2 == 0) ? 1 : -1;
        color = ConsoleColor::Red;
    }

    // enemigos no pueden pasar por 2
    void mover(int mapa[FILAS][COLUMNAS]) {
        borrarM(mapa);
        if (x + dx < 0 || x + dx + ancho > COLUMNAS || (mapa[y][x + dx] != 0 && mapa[y][x + dx] != 3)) dx *= -1;
        if (y + dy < 0 || y + dy + alto > FILAS || (mapa[y + dy][x] != 0 && mapa[y + dy][x] != 3 && mapa [y + dy][x] != 4)) dy *= -1;
        x += dx; y += dy;
    }

    void dibujaArbol() {
        Console::ForegroundColor = color;
        Console::SetCursorPosition(x, y);     cout << "  0 |>";
        Console::SetCursorPosition(x, y + 1); cout << "<|-| L";
        Console::SetCursorPosition(x, y + 2); cout << " |\\";
    }
};

class ControlGeneral {
private:
    PerPrincipal* objJ;
    Enemigo** arrE;
    Arbol** arrA;
    int numEnemigo, numArbol;

private:
    int contarArboles() {
        int c = 0;
        for (int i = 0; i < numArbol; i++) if (arrA[i]->getActivo()) c++;
        return c;
    }

    void eliminarEnemigo(int pos, int mapa[FILAS][COLUMNAS]) {
        arrE[pos]->borrarM(mapa); // Borrar antes de eliminar de memoria
        Enemigo** aux = new Enemigo * [numEnemigo - 1];
        for (int i = 0; i < pos; i++) aux[i] = arrE[i];
        for (int i = pos + 1; i < numEnemigo; i++) aux[i - 1] = arrE[i];
        delete arrE[pos];
        delete[] arrE;
        arrE = aux;
        numEnemigo--;
    }

public:
    ControlGeneral() {
        objJ = new PerPrincipal(1, 1); // Posición inicial segura
        numEnemigo = 3; numArbol = 5;
        arrE = new Enemigo * [numEnemigo];
        arrA = new Arbol * [numArbol];
        for (int i = 0; i < numEnemigo; i++) arrE[i] = new Enemigo(rand() % 20 + 50, rand() % 10 + 5);
        for (int i = 0; i < numArbol; i++) arrA[i] = new Arbol(rand() % 80 + 10, rand() % 15 + 5);
    }

    bool colision(Limites* e1, Limites* e2) {
        return (e1->getX() < e2->getX() + e2->getA() && e1->getX() + e1->getA() > e2->getX() &&
            e1->getY() < e2->getY() + e2->getH() && e1->getY() + e1->getH() > e2->getY());
    }

    void procesarEntrada(char tecla, int mapa[FILAS][COLUMNAS]) {
        objJ->mover(tecla, mapa);
    }

    void ejecutarJuego(int mapa[FILAS][COLUMNAS]) {
        Console::SetCursorPosition(0, 0); Console::ForegroundColor = ConsoleColor::Cyan;
        cout << "Enemigos restantes: " << numEnemigo << " | Arboles vivos: " << contarArboles() << " / 5 ";

        for (int i = 0; i < numEnemigo; i++) {
            arrE[i]->mover(mapa);
            for (int j = 0; j < numArbol; j++) {
                if (arrA[j]->getActivo() && colision(arrE[i], arrA[j])) arrA[j]->setPeligro(true);
            }

            if (colision(objJ, arrE[i])) {
                eliminarEnemigo(i, mapa);
                i--;
            }
        }

        for (int j = 0; j < numArbol; j++) {
            if (arrA[j]->getActivo()) {
                if (colision(objJ, arrA[j])) arrA[j]->setPeligro(false);
                arrA[j]->reducirContador();
                arrA[j]->dibujaArbol();
            }
        }
        objJ->dibujaArbol();
        for (int i = 0; i < numEnemigo; i++) arrE[i]->dibujaArbol();
    }

    bool verificarFinal() {
        int vicos = contarArboles();
        if (vicos < 2) {
            Console::ForegroundColor = ConsoleColor::Red;
            Console::SetCursorPosition(35, 10); cout << "********************************";
            Console::SetCursorPosition(35, 11); cout << "*           PERDISTE           *";
            Console::SetCursorPosition(35, 12); cout << "*    Dejaste que los enemigos  *";
            Console::SetCursorPosition(35, 13); cout << "*    deforestaran el bosque    *";
            Console::SetCursorPosition(35, 14); cout << "*Presiona ENTER para reintentar*";
            Console::SetCursorPosition(35, 15); cout << "*    Presiona ESC para Salir   *";
            Console::SetCursorPosition(35, 16); cout << "********************************";
            return true;
        }
        if (numEnemigo == 0 && vicos >= 2) { //voy a implentar una matriz 
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::SetCursorPosition(35, 12); cout << "*************************************";
            Console::SetCursorPosition(35, 13); cout << "*         ¡VICTORIA! GANASTE        *";
            Console::SetCursorPosition(35, 14); cout << "*  Presiona ENTER para repetir nivel*";
            Console::SetCursorPosition(35, 15); cout << "*      Presiona ESC para Salir      *";
            Console::SetCursorPosition(35, 16); cout << "*************************************";
            return true;
        }
        return false;
    }
};

//Poner jugarNi2(); en el main para jugarlo

void jugarNi2() {
    srand(time(NULL));
    Console::CursorVisible = false;
    bool jugarDeNuevo = true;

    while (jugarDeNuevo) {
        Console::Clear();
        imprimeMapa2();  
        ControlGeneral* juego = new ControlGeneral();

        while (true) {
            if (_kbhit()) {
                char tecla = _getch();
                if (tecla == -32 || tecla == 0) tecla = _getch();
                if (tecla == 27) { jugarDeNuevo = false; break; }
                juego->procesarEntrada(tecla, mapa2); // Pasar mapa
            }

            juego->ejecutarJuego(mapa2); // Pasar mapa

            if (juego->verificarFinal()) {
                while (true) {
                    if (_kbhit()) {
                        char postJuego = _getch();
                        if (postJuego == 13) { jugarDeNuevo = true; break; }
                        if (postJuego == 27) { jugarDeNuevo = false; break; }
                    }
                }
                break;
            }
            _sleep(100);
        }
        delete juego;
    }
}