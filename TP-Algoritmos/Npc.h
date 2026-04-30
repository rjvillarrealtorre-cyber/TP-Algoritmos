#pragma once
class NPC : public Personaje {
protected:
	int confianza;
	string dialogo;

public:
	NPC(string n, vector<vector<string>> sr, vector<vector<string>> sl,
		char d, int v, float px, float py, int vel,
		int c, string dlg)
		: Personaje(n, sr, sl, d, v, px, py, vel)
	{
		confianza = c;
		dialogo = dlg;
	}

	void hablar() {
		COORD pos = { 0, 20 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << nombre << ": " << dialogo << endl;
	}

	int getConfianza() {
		return confianza;
	}
};
