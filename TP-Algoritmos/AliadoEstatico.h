#pragma once
#include <cstdlib>

#include "Personaje.h"
#include "Protagonista.h"
#include "ArbolDialogo.h"

class AliadoEstatico : public Personaje {
private:
	ArbolDialogo dial;
public:
	AliadoEstatico() = default;
};