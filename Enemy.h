
#ifndef __Enemy_H__
#define __Enemy_H__

#include "Bala.h"
#include "Player.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct EnemyRep * Enemy;

Enemy crea_enemy(double x, double y, Imagen * imagenes);

double get_enemy_x(Enemy Enemy);
double get_enemy_y(Enemy Enemy);
double get_enemy_vx(Enemy Enemy);
double get_enemy_vy(Enemy Enemy);
int get_enemy_w(Enemy Enemy);
int get_enemy_h(Enemy Enemy);

void dibuja_enemy(Enemy Enemy);


void set_enemy_x(Enemy Enemy, double x);
void set_enemy_y(Enemy Enemy, double y);

void mueve_enemy(Enemy Enemy); 

void colision_enemy_player(Enemy Enemy, Player player);

void libera_enemy(Enemy Enemy);




#endif


