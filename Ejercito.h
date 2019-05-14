#ifndef __Ejercito_H__
#define __Ejercito_H__

#include "Bala.h"
#include "Enemy.h"

#include "Pantalla.h"
#include "Colisiones.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Nodo * NodoEjercito;


NodoEjercito nuevo_nodo_ejercito(Enemy bala);

#endif



