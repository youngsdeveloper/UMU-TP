#ifndef __Plataforma_H__
#define __Plataforma_H__

#include "Pantalla.h"
#include "Colisiones.h"
#include "Player.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct PlataformaRep * Plataforma;

Plataforma crea_plataforma(double x, double y, double w, double h, int isH, int isV);

void dibuja_plataforma(Plataforma plataforma);
int colision_plataforma_player(Plataforma plataforma, Player player);
void colisiones_plataforma(Plataforma plataforma, Player player);
 

#endif

