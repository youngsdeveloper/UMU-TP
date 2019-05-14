#ifndef __Rafaga_H__
#define __Rafaga_H__

#include "Bala.h"
#include "Enemy.h"

#include "Pantalla.h"
#include "Colisiones.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Nodo * NodoPtr;


NodoPtr nuevo_nodo(Bala bala);
void inserta_rafaga(NodoPtr cabecera, Bala bala);
void mueve_rafaga(NodoPtr cabecera);

void impactaBalaEnemigo(NodoPtr cabecera, Enemy enemy);
void dibuja_rafaga(NodoPtr cabecera);
#endif


