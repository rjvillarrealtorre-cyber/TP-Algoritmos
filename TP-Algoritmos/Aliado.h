#pragma once
#include "Npc.h"
class Aliado : public NPC {
public:
	Aliado(string n, vector<vector<string>> sr, vector<vector<string>> sl,
		char d, int v, float px, float py, int vel,
		int c, string dlg)
		: NPC(n, sr, sl, d, v, px, py, vel, c, dlg)
	{
	}

	void ayudar() {
		COORD pos = { 0, 22 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << nombre << ": Te ayudare en tu camino." << endl;
		confianza++;
	}

	void desbloquear() {
		COORD pos = { 0, 23 };
		SetConsoleCursorPosition(hConsole, pos);

		if (confianza >= 3) {
			cout << "Acceso desbloqueado!" << endl;
		}
		else {
			cout << "Aun no confia en mi." << endl;
		}
	}
};
