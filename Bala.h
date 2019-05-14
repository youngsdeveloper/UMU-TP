#ifndef __Bala_H__
#define __Bala_H__

#include "Pantalla.h"
#include "Colisiones.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct BalaRep* Bala;

Bala crea_bala(double x, double ,  Imagen imagenBala);
void libera_bala(Bala bala);
void mueve_bala(Bala bala);
void dibuja_bala(Bala bala);
double get_x_bala(Bala bala);
double get_y_bala(Bala bala);
double get_w_bala(Bala bala);
double get_h_bala(Bala bala);

int colision_bala( Bala b, double x, double y, double w, double h );
#endif

