#ifndef __ListaPlataformas_H__
#define __ListaPlataformas_H__

#include "Pantalla.h"
#include "Colisiones.h"

#include "Plataforma.h"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct NodoPlataformaRep * NodoPlataforma;


NodoPlataforma nuevo_nodo_plataforma(Plataforma plataforma);
void inserta_plataforma(NodoPlataforma cabecera, Plataforma plataforma);
void dibuja_plataformas(NodoPlataforma cabecera);

void colisiones_plataformas(NodoPlataforma cabecera, Player player);

#endif


