/**
 * @file Bomba.h
 * @author Enrique
 * @brief Fichero de cabecera para poder usar las funciones de la Bomba
 * @version 0.1
 * @date 2019-05-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __Bomba_H__
#define __Bomba_H__

#include "Pantalla.h"
#include "Colisiones.h"
#include "Player.h"
#include "Ejercito.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief TDA Bomba
 * 
 */
typedef struct BombaRep* Bomba;

/**
 * @brief Crea e inicializa una bomba
 * 
 * @param x Coordenada x de la bomba 
 * @param y Coordenada y de la bomba
 * @param imagenes Array de imagenes precargadas
 * @return Bomba 
 */
Bomba crea_bomba(double x, double y,  Imagen * imagenes);

/**
 * @brief Libera la memoria de una bomba
 * @pre La bomba debe estar inicializada

 * @param bomba
 */
void libera_bomba(Bomba bomba);

/**
 * @brief Mueve una bomba
 * @pre La bomba debe estar inicializada

 * @param bomba Puntero a estructura tipo bomba
 */
void mueve_bomba(Bomba bomba);

/**
 * @brief Dibuja una bomba en la pantalla
 * @pre La bomba debe estar inicializada

 * @param bomba Puntero a estructura tipo bomba
 */
void dibuja_bomba(Bomba bomba);

/**
 * @brief Devuelve la coordenada x de una bomba
 * @pre La bomba debe estar inicializada

 * @param bomba Puntero a estructura tipo bomba
 * @return double Coordenada x de la bomba
 */
double get_x_bomba(Bomba bomba);

/**
 * @brief Devuelve la coordenada y de una bomba
 * @pre La bomba debe estar inicializada

 * @param bomba Puntero a estructura tipo bomba
 * @return double Coordenada y de la bomba
 */
double get_y_bomba(Bomba bomba);

/**
 * @brief Devuelve la anchura de una bomba
 * @pre La bomba debe estar inicializada

 * @param bomba Puntero a estructura tipo bomba
 * @return double Anchura de una bomba
 */
double get_w_bomba(Bomba bomba);

/**
 * @brief Devuelve la coordenada altura de una bomba
 * @pre La bomba debe estar inicializada

 * @param bomba Puntero a estructura tipo bomba
 * @return double Altura de la bomba
 */
double get_h_bomba(Bomba bomba);

/**
 * @brief Gestiona la colision de una bomba con un jugador y con un ejercito de enemigos,
 * si colision con alguna de ellas, la bomba entra en estado de explosion.
 * Además:
 *  
 * - Si colisiona con un jugador: El jugador entra en estado de explosion y pierde una vida
 * - Si colision con un enemigo de un ejercito: Ese enemigo entra en estado de explosion
 * 
 * @pre La bomba, jugador y el ejercito deben estar inicializados

 * @param bomba Puntero a estructura tipo bomba
 * @param player Puntero a estructura tipo player
 * @param ejercito Puntero a estructura tipo ejercito

 */
void colision_bomba(Bomba bomba, Player player, Ejercito ejercito);


#endif

