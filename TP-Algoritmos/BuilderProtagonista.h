#pragma once

Protagonista* setupProtagonista() {
	Protagonista* prota = new Protagonista(
		"Mateo",
		{ {"_", u8"∧", "_"},
			{" ", "O"},
			{"<", "|", "\\"},
			{" ", "|", "\\"} },
		{ {"_", u8"∧", "_"},
			{" ", "O"},
			{"/", "|", ">"},
			{"/", "|"} },
		'R',
		100,
		25, 15,
		1,
		30,
		0,
		0
	);

	return prota;
}