#ifndef __RafagaBomba_H__
#define __RafagaBomba_H__

#include "Pantalla.h"
#include "Colisiones.h"
#include "Bomba.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct NodoBomba * NodoBombaPtr;


NodoBombaPtr nuevo_nodo_bomba(Bomba bomba);
void inserta_bomba(NodoBombaPtr cabecera, Bomba bomba);
void mueve_rafaga_bomba(NodoBombaPtr cabecera, Player player);
void dibuja_rafaga_bomba(NodoBombaPtr cabecera);
void colision_rafaga_bomba( NodoBombaPtr cabecera, Player player, Ejercito ejercito);
void libera_rafaga_bomba( NodoBombaPtr cabecera );


#endif
