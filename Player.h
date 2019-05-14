
#ifndef __Player_H__
#define __Player_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>




typedef struct PlayerRep * Player;

Player crea_player();

double get_player_x(Player player);
double get_player_y(Player player);

double get_player_x_pantalla(Player player);
double get_player_y_pantalla(Player player);


double get_player_vx(Player player);
double get_player_vy(Player player);
int get_player_w(Player player);
int get_player_h(Player player);

double get_player_animacion_angulo(Player player);


void set_player_x(Player player, double x);
void set_player_y(Player player, double y);

void iniciarDisparo(Player player, double angulo, double fuerza_disparo);

void mueve_player(Player player);

void colision_player(Player player);

int isDisparando(Player player);


#endif



