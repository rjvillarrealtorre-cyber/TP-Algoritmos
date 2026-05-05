#pragma once

#include "Utilidades.h"
#include "Cinematica.h"

Cinematica setupCinNvl1Inicio() {
	Cinematica cin;

	cin.agregarSlide({
		u8"▄▄  ▄▄ ▄▄ ▄▄ ▄▄      ▄██     ▄▄▄▄▄ ▄▄       ▄▄▄▄ ▄▄ ▄▄    ▄▄▄▄▄ ▄▄  ▄▄  ▄▄▄▄ ▄▄  ▄▄▄    ▄▄▄▄  ▄▄▄▄▄ ▄▄      ▄▄▄▄  ▄▄  ▄▄▄ ",
		u8"███▄██ ██▄██ ██       ██ ▀   ██▄▄  ██      ███▄▄ ██ ██    ██▄▄  ███▄██ ██▀▀▀ ██ ██▀██   ██▀██ ██▄▄  ██      ██▄█▄ ██ ██▀██",
		u8"██ ▀██  ▀█▀  ██▄▄▄    ██ ▄   ██▄▄▄ ██▄▄▄   ▄▄██▀ ██ ██▄▄▄ ██▄▄▄ ██ ▀██ ▀████ ██ ▀███▀   ████▀ ██▄▄▄ ██▄▄▄   ██ ██ ██ ▀███▀",
		u8" ",
		u8" ",
		u8"                  ┏━┓╻┏━┓   ┏━╸┏┓╻┏━╸     ┏━┓┏━╸╻  ╻ ╻┏━┓   ┏━╸┏━╸┏┓╻╺┳╸┏━┓┏━┓╻       ┏━┓┏━╸┏━┓╻ ╻                  ",
		u8"                  ┣┳┛┃┃ ┃   ┣╸ ┃┗┫┣╸      ┗━┓┣╸ ┃  ┃┏┛┣━┫   ┃  ┣╸ ┃┗┫ ┃ ┣┳┛┣━┫┃       ┣━┛┣╸ ┣┳┛┃ ┃                  ",
		u8"                  ╹┗╸╹┗━┛   ┗━╸╹ ╹┗━╸ ┛   ┗━┛┗━╸┗━╸┗┛ ╹ ╹   ┗━╸┗━╸╹ ╹ ╹ ╹┗╸╹ ╹┗━╸ ┛   ╹  ┗━╸╹┗╸┗━┛                  ",
		u8"                                                                                                                    ",
		u8"                                                                                                                    ",
		u8" ┃ ┏━┓╻ ╻┏━╸╺┳┓┏━╸   ╻ ╻┏┓╻   ┏━╸┏━┓┏━┓┏━┓┏━┓╺┳╸┏━╸┏━┓┏━┓   ┏━╸┏━┓┏━╸╻ ╻┏━╸╻ ╻┏━┓┏━┓   ╻ ╻┏┓╻┏━┓   ╻ ╻╻┏━┓╺┳╸┏━┓┏━┓╻┏━┓",
		u8"┏━ ┣━┛┃ ┃┣╸  ┃┃┣╸    ┃ ┃┃┗┫   ┣╸ ┃ ┃┣┳┛┣━┫┗━┓ ┃ ┣╸ ┣┳┛┃ ┃   ┣╸ ┗━┓┃  ┃ ┃┃  ┣━┫┣━┫┣┳┛   ┃ ┃┃┗┫┣━┫   ┣━┫┃┗━┓ ┃ ┃ ┃┣┳┛┃┣━┫",
		u8"┗━┛╹  ┗━┛┗━╸╺┻┛┗━╸   ┗━┛╹ ╹   ╹  ┗━┛╹┗╸╹ ╹┗━┛ ╹ ┗━╸╹┗╸┗━┛   ┗━╸┗━┛┗━╸┗━┛┗━╸╹ ╹╹ ╹╹┗╸   ┗━┛╹ ╹╹ ╹   ╹ ╹╹┗━┛ ╹ ┗━┛╹┗╸╹╹ ╹",
		u8"         ┏━┓╻ ╻┏━╸   ┏┓╻┏━┓   ┏━┓┏━╸   ┏━╸╻ ╻┏━╸┏┓╻╺┳╸┏━┓   ┏━╸┏━┓┏┓╻   ┏━┓┏━┓╻  ┏━┓┏┓ ┏━┓┏━┓┏━┓┏━┓                 ",
		u8"         ┃┓┃┃ ┃┣╸    ┃┗┫┃ ┃   ┗━┓┣╸    ┃  ┃ ┃┣╸ ┃┗┫ ┃ ┣━┫   ┃  ┃ ┃┃┗┫   ┣━┛┣━┫┃  ┣━┫┣┻┓┣┳┛┣━┫┗━┓ ╺┛                 ",
		u8"         ┗┻┛┗━┛┗━╸   ╹ ╹┗━┛   ┗━┛┗━╸   ┗━╸┗━┛┗━╸╹ ╹ ╹ ╹ ╹   ┗━╸┗━┛╹ ╹   ╹  ╹ ╹┗━╸╹ ╹┗━┛╹┗╸╹ ╹┗━┛ ╹                  ",
		u8"                                                                                                                    ",
		u8"                                                                                                                    ",
		u8"    ┏━ ╺┳╸┏━╸┏━╸╻  ┏━┓┏━┓   ╺┳┓╻┏━┓ ━┓   ┏━╸┏━┓┏┓╻╺┳╸╻┏┓╻╻ ╻┏━┓┏━┓         ┏━ ┏━╸┏━┓┏━╸ ━┓   ┏━┓┏━┓╻  ╺┳╸┏━┓┏━┓                   ",
		u8"    ┃   ┃ ┣╸ ┃  ┃  ┣━┫┗━┓    ┃┃┃┣┳┛  ┃   ┃  ┃ ┃┃┗┫ ┃ ┃┃┗┫┃ ┃┣━┫┣┳┛   ╺━╸   ┃  ┣╸ ┗━┓┃    ┃   ┗━┓┣━┫┃   ┃ ┣━┫┣┳┛                   ",
		u8"    ┗━  ╹ ┗━╸┗━╸┗━╸╹ ╹┗━┛   ╺┻┛╹╹┗╸ ━┛   ┗━╸┗━┛╹ ╹ ╹ ╹╹ ╹┗━┛╹ ╹╹┗╸         ┗━ ┗━╸┗━┛┗━╸ ━┛   ┗━┛╹ ╹┗━╸ ╹ ╹ ╹╹┗╸                   ",
		}, 8, 6);

	cin.agregarSlide({
		u8"“Remontar ese río era como viajar de regreso a los primeros orígenes del mundo,",
		u8" cuando la vegetación se desbordaba sobre la tierra y los grandes árboles eran",
		u8" reyes. Un curso de agua vacío, un gran silencio, una selva impenetrable.   El",
		u8" aire era cálido, espeso, pesado, lento. No había alegría en el fulgor del sol.",
		u8" [...] Y esa quietud de la vida no se parecía en absoluto a la paz.     Era la",
		u8" quietud  de  una  fuerza   implacable  que  se  cernía  sobre  una  intención ",
		u8" inescrutable. Te miraba con un aire vengativo.”",
		u8"                                             — Joseph Conrad, Heart of Darkness",
		u8"",
		u8" Cuando viajé por primera a  través  del  Río  Ene, entendí por qué los nativos,",
		u8" entendí por qué  los  nativos  dicen  que  los  ríos  tienen alma. Turbulencia.",
		u8" Estruendo. Desasosiego. Extenuación. Era como si la Providencia, a través de la",
		u8" voz de la  naturaleza, estuviese  recitando  la  elegía  de la defunción de sus",
		u8" guardianes. Estuve así por tres largos días, acompañado, gracias a Dios, por un",
		u8" remero, el único que aceptó llevarme a Kametsa Pampa. Tres días de un calor so-",
		u8" focante, de mosquitos zumbando  en  el oído, y de sentir en carne propia la Ira",
		u8" de Dios... un  concepto  no  ajeno   ni   a   los nativos ni a los exploradores",
		u8" españoles que penetraron estas faces hace cinco centurias.",
		u8"",
		u8" Yo no soy tan diferente a  ellos. Yo  también  estoy  movido  por la codicia...",
		u8" de conocimiento. Ansias por descubrir, no  solo la verde beldad de Natura, sino",
		u8" de aquello que no se cuenta con palabras.",
		u8" De lo que todos parlan con laudable actitud,  de  aquello que todos buscan pero",
		u8" que pocos defienden: la Verdad (sí, con mayúscula)..."
		}, 29, 4);

	return cin;
}