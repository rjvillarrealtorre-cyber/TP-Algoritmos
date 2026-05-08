#pragma once

Protagonista setupProtagonista() {
	Protagonista prota(
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
		2,
		0,
		0,
		0
	);

	return prota;
}