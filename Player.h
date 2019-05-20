
#ifndef __Player_H__
#define __Player_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Pantalla.h"




typedef struct PlayerRep * Player;

Player crea_player();

double get_player_x(Player player);
double get_player_y(Player player);

double get_player_x_pantalla(Player player);
double get_player_y_pantalla(Player player);


double get_player_vx(Player player);
double get_player_vy(Player player);

void togglePlayerVx(Player player, double percent); 
void togglePlayerVy(Player player, double percent);

int get_player_w(Player player);
int get_player_h(Player player);

void libera_player(Player player);

double get_player_animacion_angulo(Player player);
void set_player_animacion_angulo(Player player, double angulo);


void set_player_x(Player player, double x);
void set_player_y(Player player, double y);


void set_player_vx(Player player, double vx);
void set_player_vy(Player player, double vy);

void iniciarDisparo(Player player, double angulo, double fuerza_disparo);

void mueve_player(Player player);

void colision_player(Player player);

void dibuja_player(Player player);

int isDisparando(Player player);

void añadePunto(Player player, int puntos);
int getPuntos(Player player);


void añadeVidas(Player player, int vidas);
int getVidas(Player player);

int getVidasAviso(Player player);

int getExp_player(Player player);
void setExp_player(Player player, int exp);


#endif



