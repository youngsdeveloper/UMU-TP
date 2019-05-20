/**
 * @file Ejercito.h
 * @author Ejercito
 * @brief Fichero de cabecera para poder usar las funciones del Ejercito (Grupo de enemigos)
 * @version 0.1
 * @date 2019-05-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __Ejercito_H__
#define __Ejercito_H__

#include "Enemy.h"

#include "Pantalla.h"
#include "Colisiones.h"
#include "GameUtils.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief TDA Ejercito
 * 
 */
typedef struct EjercitoRep * Ejercito;

/**
 * @brief Crea e inicializa un ejercito
 * @return Ejercito 
 */
Ejercito crea_ejercito();

/**
 * @brief Inserta un enemigo dentro de un ejercito
 * @pre El enemigo y el ejercito deben estar inicializados
 * @param e Puntero a estructura tipo ejecito
 * @param enemy Puntero a estructura tipo enemigo
 */
void inserta_enemigo(Ejercito e, Enemy enemy);

/**
 * @brief Dibuja un ejercito
 * @pre El ejercito debe estar inicializados
 * @param e Puntero a estructura tipo ejecito
 */
void dibuja_ejercito(Ejercito e);

/**
 * @brief Mueve un ejercito, tambien elimina los enemigos que se salen fuera de los limites
 * @pre El ejercito y el jugador deben estar inicializados
 * @param e Puntero a estructura tipo ejecito
 * @param player Puntero a estructura tipo player
 */
void mueve_ejercito(Ejercito e, Player player);

/**
 * @brief Gestiona las colisiones de un ejercito con un jugador
 * @pre El ejercito y el jugador deben estar inicializados
 * @param e Puntero a estructura tipo ejecito
 * @param player Puntero a estructura tipo player 
 */
void colision_ejercito(Ejercito e, Player player);

/**
 * @brief Inserta n enemigos a un ejercito
 * @pre El ejercito debe estar inicializados

 * @param e Puntero a estructura tipo ejecito
 * @param n Numero de enemigos a crear
 * @param puntos Puntos del jugador en ese momento, se utiliza para generar la dificultad de los enemigos en función a su puntuación. A más puntuación, se generan enemigos más complicados de eliminar.
 */
void genera_ejercito(Ejercito e, int n, int puntos);

/**
 * @brief Suprime un enemigo de un ejercito
 * @pre El ejercito debe estar inicializados, pos >= 0

 * @param e Puntero a estructura tipo ejecito
 * @param pos Posicion del enemigo en el ejercito
 */
void suprime_enemy(Ejercito e, int pos);

/**
 * @brief Gestiona la colision de un ejercito con una bomba
 * @pre El ejercito debe estar inicializados

 * @param e Puntero a estructura tipo ejecito
 * @param x Coordenada x de la bomba
 * @param y Coordenada y de la bomba
 * @param w Anchura de la bomba
 * @param h Altura de la bomba
 * @return int Devuelve 1 si se ha producido alguna colision del ejercito con una bomba
 */

int	colision_ejercito_bomba( Ejercito e, double x, double y, double w, double h); 

/**
 * @brief Devuelve el numero de enemigos activos de un ejercito
 * @pre El ejercito debe estar inicializados

 * @param e 
 * @return int Numero de enemigos de un ejercito
 */
int cuenta_ejercito(Ejercito e);

/**
 * @brief Elimina todos los enemigos de un ejercito
 * @pre El ejercito debe estar inicializados

 * @param e 
 */
void reset_ejercito(Ejercito e);

/**
 * @brief Libera la memoria de un ejercito
 * @pre El ejercito debe estar inicializados

 * @param e 
 */
void libera_ejercito(Ejercito e);

#endif



