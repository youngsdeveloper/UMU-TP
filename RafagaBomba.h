/**
 * @file RafagaBomba.h
 * @author Enrique
 * @brief Fichero de cabecera para poder usar las funciones de la RafagaBomba
 * @version 0.1
 * @date 2019-05-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __RafagaBomba_H__
#define __RafagaBomba_H__

#include "Pantalla.h"
#include "Colisiones.h"
#include "Bomba.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief TDA Rafaga Bomba
 * 
 */
typedef struct NodoBomba * NodoBombaPtr;

/**
 * @brief Crea un nuevo nodo para la lista dinamica Bomba
 * 
 * @param bomba Puntero a estructura tipo bomba 
 * @return NodoBombaPtr Puntero a estructura tipo NodoBomba
 */
NodoBombaPtr nuevo_nodo_bomba(Bomba bomba);


/**
 * @brief Añade una bomba a la Rafaga de Bombas
 * @pre NodoBomba y Bomba deben estar inicializados
 * @param cabecera Puntero a estructura tipo NodoBomba 
 * @param bomba Puntero a estructura tipo bomba 
 */
void inserta_bomba(NodoBombaPtr cabecera, Bomba bomba);

/**
 * @brief Gestion el movimiento de una rafaga de bombas
 * @pre NodoBomba y Player deben estar inicializados
 * @param cabecera Puntero a estructura tipo NodoBomba 
 * @param player Puntero a estructura tipo player 
 */
void mueve_rafaga_bomba(NodoBombaPtr cabecera, Player player);


/**
 * @brief Dibuja una rafaga de bombas
 * @pre NodoBomba  debe estar inicializado
 * @param cabecera Puntero a estructura tipo NodoBomba 
 */
void dibuja_rafaga_bomba(NodoBombaPtr cabecera);

/**
 * @brief Gestiona la colision de una rafaga de bombas con un player y un ejercito
 * @pre NodoBomba, Ejercito y Player deben estar inicializados
 * @param cabecera Puntero a estructura tipo NodoBomba 
 * @param player Puntero a estructura tipo Player 
 * @param ejercito Puntero a estructura tipo Ejercito 

 */
void colision_rafaga_bomba( NodoBombaPtr cabecera, Player player, Ejercito ejercito);

/**
 * @brief Libera la memoria de una rafaga de bombas
 * @pre NodoBomba  debe estar inicializado
 * @param cabecera Puntero a estructura tipo NodoBomba 
 */
void libera_rafaga_bomba( NodoBombaPtr cabecera );


#endif
