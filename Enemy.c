#include "Enemy.h"


struct EnemyRep{
    double x;
    double y;
    double vx;
    double vy;
    int w;
    int h;
};

Enemy crea_enemy(){
    Enemy enemy = malloc(sizeof(struct EnemyRep));
    enemy -> x = 250;
    enemy -> y = 250;
    enemy -> vx = 10;
    enemy -> vy = 10;
    enemy -> w = 50;
    enemy -> h = 50;
    return enemy;
}

double get_enemy_x(Enemy enemy){
    return enemy->x;
}

double get_enemy_y(Enemy enemy){
    return enemy->y;
}

double get_enemy_vx(Enemy enemy){
    return enemy->vx;
}

double get_enemy_vy(Enemy enemy){
    return enemy->vy;
}

int get_enemy_w(Enemy enemy){
    return enemy->w;
}

int get_enemy_h(Enemy enemy){
    return enemy->h;
}

void set_enemy_x(Enemy enemy, double x){
    enemy -> x = x;
}

void set_enemy_y(Enemy enemy, double y){
    enemy -> y = y;
}



void mueve_enemy(Enemy enemy, Player player){
    //Movimiento del enemigo


    /*
        enemy->vx = get_player_x(player) - enemy->x;
        enemy->vy = get_player_y(player) - enemy->y;



        double m = sqrt( enemy->vx*enemy->vx + enemy->vy*enemy->vy );

        if ( m > 0 ) {
          enemy->vx = enemy->vx / m;
          enemy->vy = enemy->vy / m;
        }


        enemy->vx = enemy->vx * 6;
        enemy->vy = enemy->vy * 6;


        enemy->x += enemy->vx;
        enemy->y += enemy->vy;
        */

}

