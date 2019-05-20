#ifndef __Bomba_H__
#define __Bomba_H__

#include "Pantalla.h"
#include "Colisiones.h"
#include "Player.h"
#include "Ejercito.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct BombaRep* Bomba;

Bomba crea_bomba(double x, double ,  Imagen * imagenes);


void libera_bomba(Bomba bomba);
void mueve_bomba(Bomba bomba);
void dibuja_bomba(Bomba bomba);
double get_x_bomba(Bomba bomba);
double get_y_bomba(Bomba bomba);
double get_w_bomba(Bomba bomba);
double get_h_bomba(Bomba bomba);
void colision_bomba(Bomba bomba, Player player, Ejercito ejercito);


#endif

