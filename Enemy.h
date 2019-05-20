/**
 * @file Enemy.h
 * @author Enrique
 * @brief Fichero de cabecera para poder usar las funciones del Enemigo
 * @version 0.1
 * @date 2019-05-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __Enemy_H__
#define __Enemy_H__

#include "Player.h"
#include "Colisiones.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * @brief TDA Enemigo
 * 
 */
typedef struct EnemyRep * Enemy;

/**
 * @brief Crear e inicializa un enemigo
 * 
 * @param x Coordenada x del enemigo
 * @param y Coordenada y del enemigo
 * @param vx Velocidad x del enemigo
 * @param vy Velocidad y del enemigo
 * @param imagenes Array de imagenes precargas para realizar las animaciones
 * @return Enemy 
 */
Enemy crea_enemy(double x, double y, double vx, double vy, Imagen * imagenes);

/**
 * @brief Obtiene la coordenada x del enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 * @return double Coordenada x del enemigo
 */
double get_enemy_x(Enemy Enemy);

/**
 * @brief Obtiene la coordenada y del enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 * @return double Coordenada y del enemigo
 */
double get_enemy_y(Enemy Enemy);

/**
 * @brief Obtiene la velocidad x del enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 * @return double Velocidad x del enemigo
 */
double get_enemy_vx(Enemy Enemy);

/**
 * @brief Obtiene la velocidad y del enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 * @return double Velocidad y del enemigo
 */
double get_enemy_vy(Enemy Enemy);

/**
 * @brief Obtiene si el enemigo está en estado de explosión o no
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 * @return int Estado de explosion del enemigo
 */
int get_enemy_exp(Enemy Enemy);

/**
 * @brief Obtiene la anchura del enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 * @return double Anchura del enemigo
 */
int get_enemy_w(Enemy Enemy);

/**
 * @brief Obtiene la altura del enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 * @return double Altura del enemigo
 */
int get_enemy_h(Enemy Enemy);

/**
 * @brief Dibuja el enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 */
void dibuja_enemy(Enemy Enemy);

/**
 * @brief Establece la coordenada x del enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 */
void set_enemy_x(Enemy Enemy, double x);
/**
 * @brief Establece la coordenada y del enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 */
void set_enemy_y(Enemy Enemy, double y);

/**
 * @brief Establece el estado de explosion del enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 */
void set_enemy_exp(Enemy enemy, int exp);

/**
 * @brief Mueve el enemigo y gestiona las animaciones del vuelo del pajaro
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 */
void mueve_enemy(Enemy Enemy); 


/**
 * @brief Gestiona las colisiones de un enemigo con un jugador, si colision el jugador y un enemigo,
 * se le añade un punto al jugador y el enemigo entra en estado de explosión
 * 
 * @pre El enemigo debe ser distinto de NULL y el player tambien
 * @param Enemy Puntero a estructura tipo enemigo
 * @param Player Puntero a estructura tipo player
 */
void colision_enemy_player(Enemy Enemy, Player player);

/**
 * @brief Libera la memoria de un enemigo
 * @pre El enemigo debe ser distinto de NULL
 * @param Enemy Puntero a estructura tipo enemigo
 */
void libera_enemy(Enemy Enemy);




#endif


