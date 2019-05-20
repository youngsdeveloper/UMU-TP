/**
 * @file Player.h
 * @author Enrique
 * @brief Fichero de cabecera para poder usar las funciones del Player
 * @date 2019-05-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __Player_H__
#define __Player_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Pantalla.h"



/**
 * @brief TDA Jugador
 * 
 */
typedef struct PlayerRep * Player;


/**
 * @brief Crea e inicializa un jugador
 * 
 * @return Player 
 */
Player crea_player();

/**
 * @brief Obtiene la coordenada x de un jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return double Coordenada x
 */
double get_player_x(Player player);

/**
 * @brief Obtiene la coordenada y de un jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return double Coordenada y
 */
double get_player_y(Player player);


/**
 * @brief Obtiene la velocidad de la cordenada x de un jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return double Velocidad en el eje x
 */
double get_player_vx(Player player);

/**
 * @brief Obtiene la velocidad de la cordenada y de un jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return double Velocidad en el eje y
 */
double get_player_vy(Player player);

/**
 * @brief Cambia el signo de la velocidad x, aplicandole un porcentaje de perdida de velocidad
 * 
 * @pre El player debe ser distinto de NULL y el porcentaje debe estar entre 0 y 1
 * @param player Puntero a estructura tipo jugador
 * @param percent Porcentaje de perdidad de velocidad
 */
void togglePlayerVx(Player player, double percent); 

/**
 * @brief Cambia el signo de la velocidad y, aplicandole un porcentaje de perdida de velocidad
 * 
 * @pre El player debe ser distinto de NULL y el porcentaje debe estar entre 0 y 1
 * @param player Puntero a estructura tipo jugador
 * @param percent Porcentaje de perdidad de velocidad
 */
void togglePlayerVy(Player player, double percent);

/**
 * @brief Obtiene la anchura de Player
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return int Anchura de Player
 */
int get_player_w(Player player);

/**
 * @brief Obtiene la altura de Player
  * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return int Altura de Player
 */
int get_player_h(Player player);

/**
 * @brief Libera la memoria de Player
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 */
void libera_player(Player player);


/**
 * @brief Obtiene el angulo de rotacion horizontal de la pelota
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return double Angulo de rotacion horizontal
 */
double get_player_animacion_angulo(Player player);


/**
 * @brief Establece el angulo de rotacion horizontal de la pelota
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @param angulo Angulo de rotacion horizontal de la pelota
 */
void set_player_animacion_angulo(Player player, double angulo);


/**
 * @brief Establece la coordenada x del jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @param x Coordenada x
 */
void set_player_x(Player player, double x);

/**
 * @brief Establece la coordenada y del jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @param y Coordenada y
 */
void set_player_y(Player player, double y);


/**
 * @brief Establece la velocidad x del jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @param vx Velocidad en el eje x
 */
void set_player_vx(Player player, double vx);

/**
 * @brief Establece la velocidad y del jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @param vy Velocidad en el eje y
 */
void set_player_vy(Player player, double vy);

/**
 * @brief Inicia la animacion del lanzamiento parabolico de jugador
 * @pre El player debe ser distinto de NULL, no puede iniciarse un disparo si ya hay un disparo en proceso
 * @param player Puntero a estructura tipo jugador
 * @param angulo Angulo en radianes con el que se va a realizar el disparo
 * @param fuerza_disparo Fuerza con la que se realiza el disparo [Minimo: 50] [Maximo:250]
 */
void iniciarDisparo(Player player, double angulo, double fuerza_disparo);

/**
 * @brief Mueve el jugador, dependiendo de su velocidad
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 */
void mueve_player(Player player);

/**
 * @brief Detecta colisiones con los limites del mapa, si ha detectado una colision hace un rebote
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 */
void colision_player(Player player);

/**
 * @brief Dibuja el jugador en la pantallla
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 */
void dibuja_player(Player player);

/**
 * @brief Devuelve si se está realizando un lanzamiento parabolico en ese momento o no
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return Devuelve si se está realizando un lanzamiento parabolico en ese momento o no
 */
int isDisparando(Player player);

/**
 * @brief Suma puntos al jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @param puntos Numero de puntos a sumar, si es negativa, en vez de sumar, resta.
 */
void añadePunto(Player player, int puntos);

/**
 * @brief Devuelve el numero de puntos de un jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return Puntos de un jugador en la partida
 */
int getPuntos(Player player);

/**
 * @brief Suma vidas al jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @param vidas Numero de vidas a sumar, si es negativa, en vez de sumar, resta.
 */
void añadeVidas(Player player, int vidas);

/**
 * @brief Devuelve el numero de vidas de un jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return Vidas de un jugador en la partida
 */
int getVidas(Player player);

/**
 * @brief Devuelve si un jugador esta en estado de explosión o no
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @return Estado de explosión de un jugador [1 ha explotado, 0 si no]
 */
int getExp_player(Player player);

/**
 * @brief Establece el estado de explosión de un jugador
 * @pre El player debe ser distinto de NULL
 * @param player Puntero a estructura tipo jugador
 * @param Estado de explosión de un jugador [1 ha explotado, 0 si no]
 */
void setExp_player(Player player, int exp);


#endif



