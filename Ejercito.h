#ifndef __Ejercito_H__
#define __Ejercito_H__

#include "Bala.h"
#include "Enemy.h"

#include "Pantalla.h"
#include "Colisiones.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct EjercitoRep * Ejercito;

Ejercito crea_ejercito();
void inserta_enemigo(Ejercito e, Enemy enemy);
void dibuja_ejercito(Ejercito e);
void mueve_ejercito(Ejercito e);
double genera_aleatorio(int n, int m);
void colision_ejercito(Ejercito e, Player player);

void genera_ejercito(Ejercito e, int n);

void suprime_enemy(Ejercito e, int pos);



#endif



